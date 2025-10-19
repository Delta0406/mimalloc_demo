add_library(MyDll SHARED
    src/mylib.cpp
    src/mylib.h
)

# 链接 mimalloc 静态库
target_link_libraries(MyDll PRIVATE mimalloc-static)

# 给 MyDll 添加 mimalloc 的头文件路径
target_include_directories(MyDll PRIVATE
    "${PROJECT_SOURCE_DIR}/mimalloc/include"
)
