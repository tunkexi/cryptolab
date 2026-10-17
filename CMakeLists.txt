cmake_minimum_required(VERSION 3.14)
project(cryptolab VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

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
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(cryptolab_tests
    tests/test_main.cpp
)
target_link_libraries(cryptolab_tests PRIVATE cryptolab GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(cryptolab_tests)

# ---- 基准测试目标 ----
add_executable(cryptolab_benches
    benches/bench_main.cpp
)
target_link_libraries(cryptolab_benches PRIVATE cryptolab)
