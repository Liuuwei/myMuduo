cmake_minimum_required(VERSION 3.12)
project(mymuduo)

# 设置动态库路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
# 设置编译信息
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

#定义参与编译的源文件
aux_source_directory(. SRC_LIST)

add_library(mymuduo SHARED ${SRC_LIST})