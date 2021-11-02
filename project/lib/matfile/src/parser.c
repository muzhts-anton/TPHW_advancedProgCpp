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
    if (unlikely(!matrix))
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
    if (unlikely(!row))
        return NULL;

    for (size_t i = 0; i < msize; ++i) {
        char* tmp = *matrix;
        row[i] = strtol(*matrix, &tmp, 10);
        *matrix = tmp + 1;
    }

    return row;
}

static int** parsefile(char* matfile, size_t msize)
{
    int** matrix = (int**)malloc(msize * sizeof(int*));
    if (unlikely(!matrix))
        return NULL;

    char* s = matfile;
    for (size_t i = 0; i < msize; ++i) {
        if (unlikely(!(matrix[i] = getrow(&s, msize))))
            return NULL;
    }
    return matrix;
}

matrix_t* getmatrix(const char filename[])
{
    int matfd = open(filename, O_RDONLY);
    if (unlikely(matfd == BAD_VAL))
        return NULL;

    struct stat buff;
    fstat(matfd, &buff);
    char* matfile = (char*)mmap(NULL, buff.st_size, PROT_READ, MAP_PRIVATE, matfd, 0);
    if (unlikely(matfile == MAP_FAILED))
        return NULL;

    matrix_t* tmp = (matrix_t*)malloc(sizeof(matrix_t));
    if (unlikely(!tmp))
        return NULL;

    tmp->dsum = NULL;
    if (likely(tmp->dim = getsize(matfile)))
        tmp->matrix = parsefile(matfile, tmp->dim);
    else
        tmp->matrix = NULL;

    if (unlikely(munmap(matfile, buff.st_size) == BAD_VAL))
        return NULL;

    if (unlikely(close(matfd)))
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
