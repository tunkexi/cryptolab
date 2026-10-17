#include <gtest/gtest.h>
#include "cryptolab/bit_printer.h"

using namespace cryptolab;

TEST(BitPrinterTest, NormalCases) {
    EXPECT_EQ(zhuanhuan(5u), "00000000000000000000000000000101");
    EXPECT_EQ(zhuanhuan(0u), "00000000000000000000000000000000");
    EXPECT_EQ(zhuanhuan(0xFFFFFFFFu), "11111111111111111111111111111111");
}
