cmake_minimum_required(VERSION 2.8)
add_subdirectory(lib)
#include_directories(/usr/local/include/apue)
add_executable(Apue
    main.c
    apue.c
)

target_link_libraries(Apue APUE_STATIC)

