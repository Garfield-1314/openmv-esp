# micropython.cmake
# 创建一个接口库（INTERFACE library）来代表我们的模块
add_library(usermod_lvgl INTERFACE)

# 将源文件与这个库关联起来
target_sources(usermod_lvgl INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/lvgl_st7789.c
)

# 添加头文件搜索路径
target_include_directories(usermod_lvgl INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)

# 将这个模块链接到主 usermod 目标，使其被编译进固件
target_link_libraries(usermod INTERFACE usermod_lvgl)