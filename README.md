【C/C++】从零开始的cmake教程

通过编写CMakeLists.txt，然后运行cmake命令可以自动生成对应Makefile，从而控制make的编译过程。因此在学习cmake之前，建议先对make有个大致的了解。（欢迎阅读本人编写的另一篇博客【C/C++】从零开始的Make教程）。

 
1.单个源文件的编译

如果你的项目只有一个源文件main.cpp，那么只需要在同一个目录下新建一个名为CMakeLists.txt的文件，并添加下面的两行代码即可。

cmake_minimum_required(VERSION 2.8)
add_executable(Main main.cpp)

    1
    2

然后运行下面的命令,直接生成目标可执行文件Main。

cmake .
make

    1
    2

如果要添加编译选项，可以通过下面的方法：

cmake_minimum_required(VERSION 2.8)
add_definitions("-Wall -std=c++11") # <= 新增的编译选项
add_executable(Main main.cpp)

    1
    2
    3

 
2.单目录多源文件的编译

假如你的项目中只有下面4个源文件main.cpp、mod.hpp、mod_func1.cpp、mod_func2.cpp。因为cmake可以很轻松地解析出各文件的依赖关系，因此CMakeLists.txt其实十分简单：

cmake_minimum_required(VERSION 2.8)
add_executable(Main
  main.cpp
  mod_func1.cpp
  mod_func2.cpp
)

    1
    2
    3
    4
    5
    6

 
3.多目录程序的编译

假如你的项目的文件结构如下：

项目名/
  main.cpp
  mod1.hpp
  mod1/
    func1.cpp
    func2.cpp
  mod2.hpp
  mod2/
    func1.cpp
    func2.cpp

    1
    2
    3
    4
    5
    6
    7
    8
    9
    10

一般有以下两种方法：

 
1.整个项目仅编写单个CMakeLists.txt

在项目的根目录下编写CMakeLists.txt：

cmake_minimum_required(VERSION 2.8)
add_executable(Main
  main.cpp
  mod1/func1.cpp
  mod1/func2.cpp
  mod2/func1.cpp
  mod2/func2.cpp
)

    1
    2
    3
    4
    5
    6
    7
    8

 
2.每个目录均编写一个CMakeLists.txt

#CMakeLists.txt
cmake_minimum_required(VERSION 2.8)
add_subdirectory(mod1) 
add_subdirectory(mod2) 
add_executable(Main main.cpp)
target_link_libraries(Main Mod1 Mod2) 

    1
    2
    3
    4
    5
    6

#mod1/CMakeLists.txt
cmake_minimum_required(VERSION 2.8)
add_library(Mod1 STATIC
  func1.cpp
  func2.cpp
)

    1
    2
    3
    4
    5
    6

#mod2/CMakeLists.txt
cmake_minimum_required(VERSION 2.8)
add_library(Mod2 STATIC
  func1.cpp
  func2.cpp
)

    1
    2
    3
    4
    5
    6

我个人更推荐使用这种方法，虽然它看似要编写的代码会增多，但由于更加模块化，管理起来会更加轻松。

 
add_library

如果加上了STATIC，那么就是生成静态库，比如上面的例子将生成mod1/libMod1.a和mod2/libMod2.a两个库文件。

 
add_subdirectory

用于添加cmake管理的目录，如果该目录下没有CMakeLists.txt文件，将会直接报错。通过add_definitions和set定义的变量可以传送到对于的子目录，但在子目录设置的变量将不会影响到父目录。

 
target_link_libraries

将库文件链接到指定的可执行文件，最终生成的linux命令类似于-lMod1 -lMod2。camke会自动寻找对应名称的库文件，而无需书写类似“mod1/Mod1”这样的完整路径。
