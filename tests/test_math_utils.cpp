#include <gtest/gtest.h>
#include "cryptolab/math_utils.h"

using namespace cryptolab;

TEST(GcdTest, NormalTest) {
    EXPECT_EQ(zuidagongyinzi(46, 240), 2);
    EXPECT_EQ(zuidagongyinzi(23, 25), 1);
    EXPECT_EQ(zuidagongyinzi(462, 1071), 21);
}
