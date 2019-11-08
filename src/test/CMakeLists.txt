cmake_minimum_required(VERSION 2.8)
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb") # Debug模式下的编译指令
LINK_DIRECTORIES(/usr/local/lib)
add_definitions("-g -Wall") # <= 新增的编译选项
#add_executable(Test
#    test.c
#)
#
#add_executable(Client
#        client.c
#        )

add_executable(MAIEV
        a.c
        )

target_link_libraries(MAIEV -lMAIEV)
target_link_libraries(MAIEV libMAIEV.a)