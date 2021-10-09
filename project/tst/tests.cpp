#include "gtest/gtest.h"

extern "C" {
#include "rdlist.h"
#include "rdnetwork.h"
}

TEST(RDTEST, Assert_1)
{
    addnetwork();
    EXPECT_EQ((int)getrdquality(GRASS, 1), 1);
    freenetwork();
}

TEST(RDTEST, Assert_2)
{
    addnetwork();
    EXPECT_EQ((int)getrdquality(GRASS, 2), 2);
    freenetwork();
}
