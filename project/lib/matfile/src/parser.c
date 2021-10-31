#include "parser.h"

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

static size_t getsize(char* matrix)
{
    if (matrix == NULL)
        return 0; // FIXME: no magic consts

    size_t size = 0;
    while (*matrix != '\n') {
        if (*matrix == ' ')
            ++size;
        ++matrix;
    }

    return size + 1;
}

static int* getrow(char* matrix, size_t offset)
{
    size_t rowcount = 0;
    while (rowcount != offset) {
        while (*matrix != '\n')
            ++matrix;
        ++matrix;
        ++rowcount;
    }

    size_t msize = getsize(matrix);
    if (!msize)
        return NULL;

    int* row = (int*)malloc(msize * sizeof(int));
    for (size_t i = 0; i < msize; ++i) {
        char* tmp = matrix;
        row[i] = strtol(matrix, &tmp, 10);
        matrix = tmp + 1;
    }

    return row;
}

static int** parsefile(char* matfile, size_t msize)
{
    int** matrix = (int**)malloc(msize * sizeof(int*));
    for (size_t i = 0; i < msize; ++i) {
        matrix[i] = getrow(matfile, i);
    }
    return matrix;
}

matrix_t* getmatrix(const char filename[])
{
    int matfd = open(filename, O_RDONLY);
    if (matfd == -1) // FIXME: no magic consts
        return NULL; // TODO: handle the errors

    struct stat buff;
    fstat(matfd, &buff);
    char* matfile = (char*)mmap(NULL, buff.st_size, PROT_READ, MAP_PRIVATE, matfd, 0);

    matrix_t* tmp = (matrix_t*)malloc(sizeof(matrix_t));
    tmp->dim = getsize(matfile);
    tmp->dsum = NULL;
    if (tmp->dim)
        tmp->matrix = parsefile(matfile, tmp->dim);
    else
        tmp->matrix = NULL;

    munmap(matfile, buff.st_size);

    if (close(matfd))
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
