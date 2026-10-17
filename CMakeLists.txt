cmake_minimum_required(VERSION 3.14)
project(cryptolab VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- 库目标 ----
add_library(cryptolab
    src/cryptolab.cpp
)
target_include_directories(cryptolab
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# ---- 测试 ----
enable_testing()

include(FetchContent)
# 改用 Gitee 镜像源，解决 GitHub 下载 404 问题
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://gitee.com/mirrors/googletest.git
  GIT_TAG v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(cryptolab_tests
    tests/test_main.cpp
    tests/test_safe_math.cpp
    tests/test_bit_printer.cpp
    tests/test_math_utils.cpp
)
target_link_libraries(cryptolab_tests PRIVATE cryptolab GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(cryptolab_tests)

# ---- 基准测试目标 ----
add_executable(cryptolab_benches
    benches/bench_main.cpp
)
target_link_libraries(cryptolab_benches PRIVATE cryptolab)
