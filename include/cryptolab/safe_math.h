#pragma once

namespace cryptolab {

// 如果 a + b 安全，返回 true，并把结果存入 result；如果溢出，返回 false
inline bool safe_add_builtin(int a, int b, int& result) {
    // __builtin_add_overflow 在溢出时返回 true，为了符合我们的语义，前面加 !
    return !__builtin_add_overflow(a, b, &result);
}

}
