cmake_minimum_required(VERSION 2.8)
add_subdirectory(src/lib)
add_subdirectory(src/apue)
add_executable(Main
src/main.c
src/apue/apue.c
)
target_link_libraries(Main 
APUE
) 
