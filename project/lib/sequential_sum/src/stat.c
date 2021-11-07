#include "stat.h"

#include <stdio.h>
#include <sys/mman.h>


error_e initsum(matrix_t* obj)
{
    int* tsum = (int*)mmap(NULL, (obj->dim * 2 - 1) * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (tsum == MAP_FAILED)
        return ERR_MMAP;

    if (obj->dim == 1) {
        tsum[0] = obj->matrix[0][0];
        obj->dsum = tsum;
        return NO_ERROR;
    }

    size_t shift = 0;
    while (shift < obj->dim) {
        for (size_t i = 0; i + shift < obj->dim; ++i)
            tsum[(obj->dim - 1) + shift] += obj->matrix[i][i + shift];

        if (shift)
            for (size_t i = 0; i + shift < obj->dim; ++i)
                tsum[(obj->dim - 1) - shift] += obj->matrix[i + shift][i];

        ++shift;
    }

    obj->dsum = tsum;

    return NO_ERROR;
}
