#include "parser.h"

#ifdef BUILD_PARAL
#include "paral.h"
#else
#include "stat.h"
#endif

#include <stdio.h>
#include <time.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define ERR_NUMARGS 10
#define ERR_FILE 11


int main(int argc, char* argv[])
{
    if (argc != 2)
        return ERR_NUMARGS;
    
    int matfd = open(argv[1], O_RDONLY);
    if (matfd == BAD_VAL)
        return ERR_FILE;

    matrix_t* testmat = getmatrix(matfd);
    printf("dimension: %ld\n", testmat->dim);

    if (close(matfd))
        return ERR_FILE;

    struct timespec start, finish;
    double elapsed;

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
