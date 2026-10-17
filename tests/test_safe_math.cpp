#include <gtest/gtest.h>
#include "cryptolab/safe_math.h"
#include <limits>

using namespace cryptolab;

TEST(SafeAddTest, NormalCases) {
    int res = 0;
    
    // 正数 + 正数
    EXPECT_TRUE(safe_add_builtin(10, 20, res));
    EXPECT_EQ(res, 30);
    
    // 负数 + 负数
    EXPECT_TRUE(safe_add_builtin(-10, -20, res));
    EXPECT_EQ(res, -30);
    
    // 正负抵消
    EXPECT_TRUE(safe_add_builtin(-10, 20, res));
    EXPECT_EQ(res, 10);
}

TEST(SafeAddTest, BoundaryCases) {
    int res = 0;
    int max_val = std::numeric_limits<int>::max();
    int min_val = std::numeric_limits<int>::min();

    // 最大值 + 1，应该溢出，返回 false
    EXPECT_FALSE(safe_add_builtin(max_val, 1, res));
    
    // 最小值 + (-1)，应该溢出，返回 false
    EXPECT_FALSE(safe_add_builtin(min_val, -1, res));
    
    // 最大值 + 最大值，肯定溢出
    EXPECT_FALSE(safe_add_builtin(max_val, max_val, res));
    
    // 边界安全：最大值 + 0，最小值 + 0
    EXPECT_TRUE(safe_add_builtin(max_val, 0, res));
    EXPECT_EQ(res, max_val);
    EXPECT_TRUE(safe_add_builtin(min_val, 0, res));
    EXPECT_EQ(res, min_val);
}
