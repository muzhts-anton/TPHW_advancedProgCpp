#include "parser.h"

#include "stat.h"
//#include "paral.h"

#include <time.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    struct timespec start, finish;
    double elapsed;

    clock_gettime(CLOCK_MONOTONIC, &start);

    // block content
    matrix_t* testmat = getmatrix(argv[1]);
    initsum(testmat);

    for (size_t i = 0; i < 2 * testmat->dim - 1; ++i)
        printf("%d ", testmat->dsum[i]);
    printf("\n");

    deinit(testmat);
    free(testmat);
    // endblock

    clock_gettime(CLOCK_MONOTONIC, &finish);

    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

    printf("time: %lf\n", elapsed);

    return 0;
}
