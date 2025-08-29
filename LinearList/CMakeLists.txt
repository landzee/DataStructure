# 指定CMake最低版本
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(LinearList)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加可执行文件
add_executable(LinearList LinearList.cpp)

# 如果需要包含头文件目录，可以取消下面的注释并修改路径
# target_include_directories(LinearList PRIVATE include)

# 如果需要链接其他库，可以在这里添加
# target_link_libraries(LinearList PRIVATE some_library)