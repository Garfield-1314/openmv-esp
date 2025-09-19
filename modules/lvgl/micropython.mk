# micropython.mk
# 获取当前模块目录的绝对路径
MYMATH_MOD_DIR := $(USERMOD_DIR)

# 将您的源文件添加到全局构建列表中
SRC_USERMOD += $(MYMATH_MOD_DIR)/lvgl_st7789.c

# 添加头文件搜索路径（如果您有其他头文件放在模块目录中）
CFLAGS_USERMOD += -I$(MYMATH_MOD_DIR)