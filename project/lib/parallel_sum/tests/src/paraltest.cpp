#include "gtest/gtest.h"

extern "C" {
#include "paral.h"
#include "parser.h"
}

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>

TEST(PARAL, Assert_1)
{
    const char filename[] = "test11.txt";
    FILE* testfile = fopen(filename, "w");
    const char matrix[] = "1\n\n";
    fwrite(matrix, (int)sizeof(matrix) - 1, 1, testfile);
    fclose(testfile);

    int matfd = open(filename, O_RDONLY);

    matrix_t* test = getmatrix(matfd);

    close(matfd);

    initsum(test);

    EXPECT_EQ(test->dsum[0], 1);

    deinit(test);
    free(test);
}

TEST(PARAL, Assert_2)
{
    const char filename[] = "test12.txt";
    FILE* testfile = fopen(filename, "w");
    const char matrix[] = "1 2 3\n4 5 6\n7 8 9\n\n";
    fwrite(matrix, (int)sizeof(matrix) - 1, 1, testfile);
    fclose(testfile);

    int matfd = open(filename, O_RDONLY);

    matrix_t* test = getmatrix(matfd);

    close(matfd);

    initsum(test);

    EXPECT_EQ(test->dsum[0], 7);
    EXPECT_EQ(test->dsum[1], 12);
    EXPECT_EQ(test->dsum[2], 15);
    EXPECT_EQ(test->dsum[3], 8);
    EXPECT_EQ(test->dsum[4], 3);

    deinit(test);
    free(test);
}
