#include "gtest/gtest.h"

extern "C" {
#include "parser.h"
}

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>

TEST(PARSER, Assert_1)
{
    const char filename[] = "test01.txt";
    FILE* testfile = fopen(filename, "w");
    const char matrix[] = "1\n\n";
    fwrite(matrix, (int)sizeof(matrix) - 1, 1, testfile);
    fclose(testfile);

    int matfd = open(filename, O_RDONLY);

    matrix_t* test = getmatrix(matfd);

    close(matfd);

    EXPECT_EQ(test->matrix[0][0], 1);

    deinit(test);
    free(test);
}

TEST(PARSER, Assert_2)
{
    const char filename[] = "test02.txt";
    FILE* testfile = fopen(filename, "w");
    const char matrix[] = "1 2 3\n4 5 6\n7 8 9\n\n";
    fwrite(matrix, (int)sizeof(matrix) - 1, 1, testfile);
    fclose(testfile);

    int matfd = open(filename, O_RDONLY);

    matrix_t* test = getmatrix(matfd);

    close(matfd);

    EXPECT_EQ(test->matrix[0][0], 1);
    EXPECT_EQ(test->matrix[0][1], 2);
    EXPECT_EQ(test->matrix[0][2], 3);
    EXPECT_EQ(test->matrix[1][0], 4);
    EXPECT_EQ(test->matrix[1][1], 5);
    EXPECT_EQ(test->matrix[1][2], 6);
    EXPECT_EQ(test->matrix[2][0], 7);
    EXPECT_EQ(test->matrix[2][1], 8);
    EXPECT_EQ(test->matrix[2][2], 9);

    deinit(test);
    free(test);
}
