#include "stat.h"
#include <stdio.h>


const int A[MSIZE][MSIZE] = {
    { 1, 2, 3, 4, 5, 6, 7 },
    { 2, 1, 2, 3, 4, 5, 6 },
    { 3, 2, 1, 2, 3, 4, 5 },
    { 4, 3, 2, 1, 2, 3, 4 },
    { 5, 4, 3, 2, 1, 2, 3 },
    { 6, 5, 4, 3, 2, 1, 2 },
    { 7, 6, 5, 4, 3, 2, 1 },
};

int stat()
{
    int B[MSIZE * 2 - 1] = { 0 };

    size_t i = 0, d = 0;
    while (d < MSIZE) {
        while (i + d < MSIZE) {
            B[(MSIZE - 1) + d] += A[i][i + d];
            printf("%d ", A[i][i + d]);
            ++i;
        }
        printf("\n");
        ++d;
        i = 0;
    }

    for (size_t i = 0; i < (MSIZE * 2 - 1) / 2; ++i)
        B[i] = B[i + MSIZE - 1];

    for (size_t i = 0; i < (MSIZE * 2 - 1); ++i)
        printf("%d ", B[i]);
    printf("\n");

    return 0;
}