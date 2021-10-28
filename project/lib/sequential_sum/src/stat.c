#include "stat.h"

#include <stdio.h>

error_e initsum(matrix_t* obj)
{
    int* tsum = (int*)calloc(obj->dim * 2 - 1, sizeof(int));

    if (obj->dim == 1) {
        tsum[0] = obj->matrix[0][0];
        obj->dsum = tsum;
        return NO_ERROR;
    }

    size_t d = 0;
    while (d < obj->dim) {
        for (size_t i = 0; i + d < obj->dim; ++i)
            tsum[(obj->dim - 1) + d] += obj->matrix[i][i + d];

        for (size_t i = 0; i + d < obj->dim; ++i)
            if (i + d != i)
                tsum[(obj->dim - 1) - d] += obj->matrix[i + d][i];

        ++d;
    }

    obj->dsum = tsum;

    return NO_ERROR;
}