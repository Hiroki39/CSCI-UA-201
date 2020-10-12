cmake_minimum_required (VERSION 3.15)

project (rec02)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
add_compile_options(-Wall -std=c11 -g)

aux_source_directory(. DIR_SRCS)
add_executable(testRoll ${DIR_SRCS})
