#include "parser.h"
//#include "stat.h"
#include "paral.h"

#include <stdio.h>

int main(int argc, char* argv[])
{
    matrix_t* testmat = getmatrix(argv[1]);
    initsum(testmat);

    for (size_t i = 0; i < 2 * testmat->dim - 1; ++i)
        printf("%d ", testmat->dsum[i]);
    printf("\n");

    deinit(testmat);
    free(testmat);

    return 0;
}
