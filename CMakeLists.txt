cmake_minimum_required(VERSION 2.8)
SET(CMAKE_BUILD_TYPE "Debug")  
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")  
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall") 
add_subdirectory(src/student) 
add_subdirectory(src/list.1) 
add_subdirectory(src/apue) 
add_executable(bin/Main 
src/main.c 
)
target_link_libraries(bin/Main 
Stu
List
APUE
) 
