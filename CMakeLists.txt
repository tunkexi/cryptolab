cmake_minimum_required(VERSION 3.10)
project(cryptolab VERSION 0.1.0 LANGUAGES CXX)

# C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 导出编译命令，方便 clangd 等工具使用
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---- 库目标 ----
add_library(cryptolab
    src/cryptolab.cpp
)
target_include_directories(cryptolab
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# ---- 测试目标 ----
enable_testing()
add_executable(cryptolab_tests
    tests/test_main.cpp
)
target_link_libraries(cryptolab_tests PRIVATE cryptolab)
add_test(NAME cryptolab_tests COMMAND cryptolab_tests)

# ---- 基准测试目标（可选）----
add_executable(cryptolab_benches
    benches/bench_main.cpp
)
target_link_libraries(cryptolab_benches PRIVATE cryptolab)
