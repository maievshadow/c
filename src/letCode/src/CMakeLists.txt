cmake_minimum_required(VERSION 2.8)
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb") # Debug模式下的编译指令
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
add_definitions("-g -Wall") # <= 新增的编译选项
#add_executable(Sum
#    sum.c
#        link.c link.h main.c)
add_subdirectory(t01)
add_subdirectory(t02)
add_subdirectory(t03)

add_executable(LetCode
        main.c
        tool/comm.c
        )
target_link_libraries(
        LetCode
        T01
        T02
        T03
)
