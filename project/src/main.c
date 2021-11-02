#include "parser.h"

#ifdef BUILD_PARAL
#include "paral.h"
#else
#include "stat.h"
#endif

#include <time.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    struct timespec start, finish;
    double elapsed;

    matrix_t* testmat = getmatrix(argv[1]);
    printf("dimension: %ld\n", testmat->dim);

    clock_gettime(CLOCK_MONOTONIC, &start);

    // block content
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
