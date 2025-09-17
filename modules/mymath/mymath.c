// mymath.c
#include "py/runtime.h"

// 1. 定义实际的C函数
STATIC mp_obj_t mymath_add(mp_obj_t a_obj, mp_obj_t b_obj) {
    // 从MicroPython对象中提取整数值
    mp_int_t a = mp_obj_get_int(a_obj);
    mp_int_t b = mp_obj_get_int(b_obj);

    // 执行计算并将结果转换回MicroPython整数对象
    return mp_obj_new_int(a + b);
}
// 2. 将这个函数包装成MicroPython可调用的对象
STATIC MP_DEFINE_CONST_FUN_OBJ_2(mymath_add_obj, mymath_add);

// 3. 定义模块的全局字典（包含模块的所有属性和方法）
STATIC const mp_rom_map_elem_t mymath_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_mymath) },
    { MP_ROM_QSTR(MP_QSTR_add), MP_ROM_PTR(&mymath_add_obj) },
};
STATIC MP_DEFINE_CONST_DICT(mymath_module_globals, mymath_module_globals_table);

// 4. 定义模块对象
const mp_obj_module_t mymath_user_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&mymath_module_globals,
};

// 5. 注册模块到MicroPython
// 第三个参数 MP_REGISTER_MODULE 必须是1（默认启用）或一个可以通过编译器标志控制的宏
MP_REGISTER_MODULE(MP_QSTR_mymath, mymath_user_cmodule, 1);