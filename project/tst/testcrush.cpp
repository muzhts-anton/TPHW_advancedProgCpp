#include "gtest/gtest.h"

extern "C" {
#include "rdlist.h"
#include "rdnetwork.h"
}

TEST(RDTEST, Assert_2_3_1)
{
    appendroad((rdnetwork_t){999, PRIMING, TERRIBLE,    4});
    appendroad((rdnetwork_t){998, PRIMING, BAD,         4});
    appendroad((rdnetwork_t){997, PRIMING, BAD,         4});
    appendroad((rdnetwork_t){996, PRIMING, GOOD,        4});
    appendroad((rdnetwork_t){995, PRIMING, NORM,        4});
    appendroad((rdnetwork_t){994, PRIMING, NORM,        4});
    appendroad((rdnetwork_t){993, PRIMING, BAD,         4});
    appendroad((rdnetwork_t){992, PRIMING, TERRIBLE,    4});
    appendroad((rdnetwork_t){991, PRIMING, GREAT,       4});
    appendroad((rdnetwork_t){990, PRIMING, GREAT,       4});
    appendroad((rdnetwork_t){989, PRIMING, TERRIBLE,    4});
    appendroad((rdnetwork_t){988, PRIMING, BAD,         4});
    appendroad((rdnetwork_t){987, PRIMING, NORM,        4});

    EXPECT_EQ((int)getrdquality(PRIMING, 4), (int)NORM);

    freenetwork();
}

TEST(RDTEST, Assert_2_2_1)
{
    appendroad((rdnetwork_t){999, PRIMING, TERRIBLE,    4});
    appendroad((rdnetwork_t){998, PRIMING, BAD,         4});
    appendroad((rdnetwork_t){997, PRIMING, BAD,         4});
    appendroad((rdnetwork_t){996, PRIMING, GOOD,        4});
    appendroad((rdnetwork_t){995, PRIMING, NORM,        4});
    appendroad((rdnetwork_t){994, PRIMING, NORM,        4});
    appendroad((rdnetwork_t){993, PRIMING, BAD,         4});
    appendroad((rdnetwork_t){992, PRIMING, TERRIBLE,    4});
    appendroad((rdnetwork_t){991, PRIMING, GREAT,       1});  //
    appendroad((rdnetwork_t){990, PRIMING, GREAT,       1});  //
    appendroad((rdnetwork_t){989, PRIMING, TERRIBLE,    4});
    appendroad((rdnetwork_t){988, PRIMING, BAD,         4});
    appendroad((rdnetwork_t){987, PRIMING, NORM,        4});

    EXPECT_EQ((int)getrdquality(PRIMING, 4), (int)BAD);

    freenetwork();
}

TEST(RDTEST, Assert_2_3_2)
{
    appendroad((rdnetwork_t){999, GRASS,    TERRIBLE,    4});  //
    appendroad((rdnetwork_t){998, PRIMING,  BAD,         4});
    appendroad((rdnetwork_t){997, PRIMING,  BAD,         4});
    appendroad((rdnetwork_t){996, PRIMING,  GOOD,        4});
    appendroad((rdnetwork_t){995, PRIMING,  NORM,        4});
    appendroad((rdnetwork_t){994, PRIMING,  NORM,        4});
    appendroad((rdnetwork_t){993, PRIMING,  BAD,         4});
    appendroad((rdnetwork_t){992, GRASS,    TERRIBLE,    4});  //
    appendroad((rdnetwork_t){991, PRIMING,  GREAT,       1});  //
    appendroad((rdnetwork_t){990, PRIMING,  GREAT,       1});  //
    appendroad((rdnetwork_t){989, ASPHALT,  TERRIBLE,    4});  //
    appendroad((rdnetwork_t){988, PRIMING,  BAD,         4});
    appendroad((rdnetwork_t){987, PRIMING,  NORM,        4});

    EXPECT_EQ((int)getrdquality(PRIMING, 4), (int)NORM);

    freenetwork();
}

TEST(RDTEST, Assert_2_4_1)
{
    appendroad((rdnetwork_t){999, GRASS,    TERRIBLE,    4});  //
    appendroad((rdnetwork_t){998, PRIMING,  BAD,         4});
    appendroad((rdnetwork_t){997, PRIMING,  BAD,         4});
    appendroad((rdnetwork_t){996, PRIMING,  GOOD,        4});
    appendroad((rdnetwork_t){995, PRIMING,  NORM,        4});
    appendroad((rdnetwork_t){994, PRIMING,  NORM,        4});
    appendroad((rdnetwork_t){993, PRIMING,  BAD,         4});
    appendroad((rdnetwork_t){992, GRASS,    TERRIBLE,    4});  //
    appendroad((rdnetwork_t){991, PRIMING,  GREAT,       1});  //
    appendroad((rdnetwork_t){990, PRIMING,  GREAT,       1});  //
    appendroad((rdnetwork_t){989, ASPHALT,  TERRIBLE,    4});  //
    appendroad((rdnetwork_t){988, PRIMING,  BAD,         4});
    appendroad((rdnetwork_t){987, PRIMING,  NORM,        4});
    appendroad((rdnetwork_t){986, PRIMING,  GREAT,       4});
    appendroad((rdnetwork_t){985, PRIMING,  GREAT,       4});
    appendroad((rdnetwork_t){984, PRIMING,  GREAT,       4});
    appendroad((rdnetwork_t){983, PRIMING,  GREAT,       4});
    appendroad((rdnetwork_t){982, PRIMING,  GREAT,       4});

    EXPECT_EQ((int)getrdquality(PRIMING, 4), (int)GOOD);

    freenetwork();
}

TEST(RDTEST, Assert_2_5_1)
{
    appendroad((rdnetwork_t){999, GRASS,    TERRIBLE,    4});  //
    appendroad((rdnetwork_t){998, PRIMING,  BAD,         4});
    appendroad((rdnetwork_t){997, PRIMING,  BAD,         4});
    appendroad((rdnetwork_t){996, PRIMING,  GOOD,        4});
    appendroad((rdnetwork_t){995, PRIMING,  NORM,        4});
    appendroad((rdnetwork_t){994, PRIMING,  NORM,        4});
    appendroad((rdnetwork_t){993, PRIMING,  BAD,         4});
    appendroad((rdnetwork_t){992, GRASS,    TERRIBLE,    4});
    appendroad((rdnetwork_t){991, PRIMING,  GREAT,       1});  //
    appendroad((rdnetwork_t){990, PRIMING,  GREAT,       1});  //
    appendroad((rdnetwork_t){989, ASPHALT,  TERRIBLE,    4});
    appendroad((rdnetwork_t){988, PRIMING,  BAD,         4});
    appendroad((rdnetwork_t){987, PRIMING,  NORM,        4});
    appendroad((rdnetwork_t){986, PRIMING,  GREAT,       4});
    appendroad((rdnetwork_t){985, PRIMING,  GREAT,       4});
    appendroad((rdnetwork_t){984, PRIMING,  GREAT,       4});
    appendroad((rdnetwork_t){983, PRIMING,  GREAT,       4});
    appendroad((rdnetwork_t){982, PRIMING,  GREAT,       4});

    EXPECT_EQ((int)getrdquality(PRIMING, 1), (int)GREAT);

    freenetwork();
}

TEST(RDTEST, Assert_2_m1_1)
{
    appendroad((rdnetwork_t){999, GRASS,    TERRIBLE,    4});  //
    appendroad((rdnetwork_t){998, PRIMING,  BAD,         4});
    appendroad((rdnetwork_t){997, PRIMING,  BAD,         4});
    appendroad((rdnetwork_t){996, PRIMING,  GOOD,        4});
    appendroad((rdnetwork_t){995, PRIMING,  NORM,        4});
    appendroad((rdnetwork_t){994, PRIMING,  NORM,        4});
    appendroad((rdnetwork_t){993, PRIMING,  BAD,         4});
    appendroad((rdnetwork_t){992, GRASS,    TERRIBLE,    4});
    appendroad((rdnetwork_t){991, PRIMING,  GREAT,       1});  //
    appendroad((rdnetwork_t){990, PRIMING,  GREAT,       1});  //
    appendroad((rdnetwork_t){989, ASPHALT,  TERRIBLE,    4});
    appendroad((rdnetwork_t){988, PRIMING,  BAD,         4});
    appendroad((rdnetwork_t){987, PRIMING,  NORM,        4});
    appendroad((rdnetwork_t){986, PRIMING,  GREAT,       4});
    appendroad((rdnetwork_t){985, PRIMING,  GREAT,       4});
    appendroad((rdnetwork_t){984, PRIMING,  GREAT,       4});
    appendroad((rdnetwork_t){983, PRIMING,  GREAT,       4});
    appendroad((rdnetwork_t){982, PRIMING,  GREAT,       4});

    EXPECT_EQ((int)getrdquality(PRIMING, 2), (int)ERROR);

    freenetwork();
}
