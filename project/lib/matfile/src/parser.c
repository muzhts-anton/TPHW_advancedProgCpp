#include "parser.h"

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define unlikely(expr) __builtin_expect(!!(expr), 0)
#define likely(expr) __builtin_expect(!!(expr), 1)

static size_t getsize(char* matrix)
{
    if (!matrix)
        return 0;

    size_t size = 0;
    while (*matrix && *matrix != '\n') {
        if (*matrix == ' ')
            ++size;
        ++matrix;
    }

    return size + 1;
}

static int* getrow(char** matrix, const size_t msize)
{
    int* row = (int*)malloc(msize * sizeof(int));
    if (!row)
        return NULL;

    for (size_t i = 0; i < msize; ++i) {
        char* tmp = *matrix;
        row[i] = strtol(*matrix, &tmp, 10);
        *matrix = tmp + 1;
    }

    return row;
}

static int** parsefile(char* matfile, int** matrix, size_t msize)
{
    char* s = matfile;
    for (size_t i = 0; i < msize; ++i) {
        if (!(matrix[i] = getrow(&s, msize)))
            return NULL;
    }
    return matrix;
}

matrix_t* getmatrix(int matfd)
{
    struct stat buff;
    fstat(matfd, &buff);
    char* matfile = (char*)mmap(NULL, buff.st_size, PROT_READ, MAP_PRIVATE, matfd, 0);
    if (matfile == MAP_FAILED)
        return NULL;

    matrix_t* tmp = (matrix_t*)malloc(sizeof(matrix_t));
    if (!tmp)
        return NULL;

    tmp->dsum = NULL;
    if (likely(tmp->dim = getsize(matfile))) {
        int** matrix = (int**)malloc(tmp->dim * sizeof(int*));
        if (!matrix)
            return NULL;

        tmp->matrix = parsefile(matfile, matrix, tmp->dim);
    } else
        tmp->matrix = NULL;

    if (munmap(matfile, buff.st_size) == BAD_VAL)
        return NULL;

    return tmp;
}

void deinit(matrix_t* obj)
{
    if (obj->dsum && obj->dim > 0) {
        munmap(obj->dsum, (2 * obj->dim - 1) * sizeof(int));
        obj->dsum = NULL;
    }
    if (obj->matrix) {
        for (size_t i = 0; i < obj->dim; ++i)
            free(obj->matrix[i]);
        free(obj->matrix);
        obj->matrix = NULL;
    }
    obj->dim = 0;
}
