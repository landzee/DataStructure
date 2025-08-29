# 设置 CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(LinkedList)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加可执行文件
add_executable(LinkedList LinkedList.cpp)

# 如果有头文件，可以这样包含目录
# target_include_directories(LinkedList PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})