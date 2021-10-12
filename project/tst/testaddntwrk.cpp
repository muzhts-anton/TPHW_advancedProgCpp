#include "gtest/gtest.h"

extern "C" {
#include "rdlist.h"
#include "rdnetwork.h"
}

TEST(RDTEST, Assert_1_1_1)
{
    addnetwork();
    EXPECT_EQ((int)getrdquality(GRASS, 1), (int)TERRIBLE);
    freenetwork();
}

TEST(RDTEST, Assert_1_2_1)
{
    addnetwork();
    EXPECT_EQ((int)getrdquality(GRASS, 2), (int)BAD);
    freenetwork();
}

TEST(RDTEST, Assert_1_m1_1)
{
    addnetwork();
    EXPECT_EQ((int)getrdquality(GRASS, 6), (int)ERROR);
    freenetwork();
}
