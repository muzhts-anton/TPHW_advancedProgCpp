#ifndef PARSE_H
#define PARSE_H

#include <stdlib.h>

#define BAD_VAL -1

typedef struct {
    int** matrix;
    size_t dim;
    int* dsum;
} matrix_t;

matrix_t* getmatrix(const char filename[]);
void deinit(matrix_t* obj);

#endif
