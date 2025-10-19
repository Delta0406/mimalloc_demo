cmake_minimum_required(VERSION 3.15)
project(mimalloc_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加 mimalloc 源码
add_subdirectory(mimalloc)
# 添加自己的 DLL
add_subdirectory(MyDll)
# 添加测试程序
add_subdirectory(TestApp)

# 所有 target 公用的 include
include_directories(
    ${PROJECT_SOURCE_DIR}/mimalloc/include
    ${PROJECT_SOURCE_DIR}/MyDll/src
)
