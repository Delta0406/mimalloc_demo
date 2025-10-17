cmake_minimum_required(VERSION 3.15)
project(mimalloc_demo CXX)

set(CMAKE_CXX_STANDARD 11)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# ==== 你自己的 mimalloc 路径 ====
set(MIMALLOC_ROOT "${CMAKE_SOURCE_DIR}/mimalloc")  # 修改这里
set(MIMALLOC_INCLUDE_DIR "${MIMALLOC_ROOT}/include")
set(MIMALLOC_LIB_DIR "${MIMALLOC_ROOT}/build/Release")

include_directories(${MIMALLOC_INCLUDE_DIR})
link_directories(${MIMALLOC_LIB_DIR})

# ==== 生成可执行文件 ====
add_executable(mimalloc_demo main.cpp)

# ==== 链接动态库 ====
# 注意这里链接 mimalloc.dll 的 import lib
target_link_libraries(mimalloc_demo PRIVATE mimalloc.dll.lib)

if(MSVC)
    # This ensures the linker keeps the mi_version symbol even if not used.
    target_link_options(mimalloc_demo PRIVATE "/INCLUDE:mi_version")
endif()