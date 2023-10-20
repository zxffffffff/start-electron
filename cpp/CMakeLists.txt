#############################################################################
## MIT License
## 
## Author	: xiaofeng.zhu
## Support	: zxffffffff@outlook.com, 1337328542@qq.com
## 
#############################################################################

message("[start-electron-cpp] -------- start")
cmake_minimum_required (VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

if (WIN32)
    # 源码使用 utf-8 编码格式编译
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
else()
    # APPLE 和 UNIX 编译动态库需要设置-fPIC
    set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
endif()

project ("start-electron-cpp")

message(STATUS "[start-electron-cpp] PROJECT_SOURCE_DIR : ${PROJECT_SOURCE_DIR}")

# src
include_directories(${PROJECT_SOURCE_DIR}/sample-dynamic-lib)
include_directories(${PROJECT_SOURCE_DIR}/sample-main)
add_subdirectory(sample-dynamic-lib)
add_subdirectory(sample-main)

# test

message("[start-electron-cpp] -------- done")