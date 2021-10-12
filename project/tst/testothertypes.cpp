#include "gtest/gtest.h"

extern "C" {
#include "rdlist.h"
#include "rdnetwork.h"
}

TEST(RDTEST, Assert_3_3_1)
{
    appendroad((rdnetwork_t){999, ASPHALT, BAD,    3});
    appendroad((rdnetwork_t){998, ASPHALT, NORM,   3});
    appendroad((rdnetwork_t){997, ASPHALT, GOOD,   3});

    EXPECT_EQ((int)getrdquality(ASPHALT, 3), (int)NORM);

    freenetwork();
}

TEST(RDTEST, Assert_3_4_1)
{
    appendroad((rdnetwork_t){999, CONCRETE, BAD,    3});
    appendroad((rdnetwork_t){998, ASPHALT, NORM,    3});
    appendroad((rdnetwork_t){997, ASPHALT, GOOD,    3});

    EXPECT_EQ((int)getrdquality(ASPHALT, 3), (int)GOOD);

    freenetwork();
}

TEST(RDTEST, Assert_3_5_1)
{
    appendroad((rdnetwork_t){999, CONCRETE, GREAT, 2});
    appendroad((rdnetwork_t){919, CONCRETE, GREAT, 2});
    appendroad((rdnetwork_t){969, CONCRETE, GREAT, 2});

    EXPECT_EQ((int)getrdquality(CONCRETE, 2), (int)GREAT);

    freenetwork();
}

TEST(RDTEST, Assert_3_4_2)
{
    appendroad((rdnetwork_t){999, GRASS,    TERRIBLE,    1});
    appendroad((rdnetwork_t){998, ASPHALT,  BAD,         3});
    appendroad((rdnetwork_t){997, ASPHALT,  BAD,         3});
    appendroad((rdnetwork_t){996, GRASS,    GOOD,        2});
    appendroad((rdnetwork_t){995, CONCRETE, NORM,        4});

    EXPECT_EQ((int)getrdquality(GRASS, 2), (int)GOOD);

    freenetwork();
}

TEST(RDTEST, Assert_3_1_1)
{
    appendroad((rdnetwork_t){999, GRASS,    TERRIBLE,    1});
    appendroad((rdnetwork_t){998, ASPHALT,  BAD,         3});
    appendroad((rdnetwork_t){997, ASPHALT,  BAD,         3});
    appendroad((rdnetwork_t){996, GRASS,    GOOD,        2});
    appendroad((rdnetwork_t){995, CONCRETE, NORM,        4});

    EXPECT_EQ((int)getrdquality(GRASS, 1), (int)TERRIBLE);

    freenetwork();
}

TEST(RDTEST, Assert_3_2_1)
{
    appendroad((rdnetwork_t){999, GRASS,    TERRIBLE,    1});
    appendroad((rdnetwork_t){998, ASPHALT,  BAD,         3});
    appendroad((rdnetwork_t){997, ASPHALT,  BAD,         3});
    appendroad((rdnetwork_t){996, GRASS,    GOOD,        2});
    appendroad((rdnetwork_t){995, CONCRETE, NORM,        4});

    EXPECT_EQ((int)getrdquality(ASPHALT, 3), (int)BAD);

    freenetwork();
}

TEST(RDTEST, Assert_3_m1_1)
{
    appendroad((rdnetwork_t){999, GRASS,    TERRIBLE,    1});
    appendroad((rdnetwork_t){998, ASPHALT,  BAD,         3});
    appendroad((rdnetwork_t){997, ASPHALT,  BAD,         3});
    appendroad((rdnetwork_t){996, GRASS,    GOOD,        2});
    appendroad((rdnetwork_t){995, CONCRETE, NORM,        4});

    EXPECT_EQ((int)getrdquality(CONCRETE, 3), (int)ERROR);

    freenetwork();
}
