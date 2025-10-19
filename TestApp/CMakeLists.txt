add_executable(TestApp
    src/main.cpp
)

# 链接 MyDll
target_link_libraries(TestApp PRIVATE MyDll)

# 添加头文件搜索路径（MyDll 和 mimalloc）
target_include_directories(TestApp PRIVATE
    ${PROJECT_SOURCE_DIR}/MyDll/src
#    ${PROJECT_SOURCE_DIR}/mimalloc/include
)


add_custom_command(TARGET TestApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:MyDll>    # 自动获取 MyDll.dll 的路径
        $<TARGET_FILE_DIR:TestApp>  # 拷贝到 TestApp.exe 所在目录
)
