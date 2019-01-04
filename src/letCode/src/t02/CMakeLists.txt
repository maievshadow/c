cmake_minimum_required(VERSION 2.8)
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb") # Debug模式下的编译指令
add_library(T02 STATIC
        list.c
        )
