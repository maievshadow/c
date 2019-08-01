<<<<<<< HEAD
#mod1/CMakeLists.txt
cmake_minimum_required(VERSION 2.8)
add_library(Stack STATIC
        stack.c
        )
=======
cmake_minimum_required(VERSION 2.8)
#SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb") # Debug模式下的编译指令
add_definitions("-g -Wall") # <= 新增的编译选项
add_executable(Hash 
    #pointer.c
    main.c
    hash2.c
)
>>>>>>> 1991f6f33cf9473db02c5853cc0f23a4693e947d
