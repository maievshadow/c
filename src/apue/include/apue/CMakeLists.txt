#mod1/CMakeLists.txt
cmake_minimum_required(VERSION 2.8)

#ADD_LIBRARY(hello SHARED ${HELLOlib_src})
#添加编译库命令：
#SHARED，动态库，libhello.so
#STATIC，静态库，libhello.a

SET(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")
#ELIBRARY_OUTPUT_PATH是cmake默认变量，修改它可以把库文件的路径修改，本例子中修改为build/lib

add_library(APUE_STATIC STATIC
  bufargs.c cliconn.c clrfl.c daemonize.c error.c errorlog.c lockreg.c locktest.c
  nspipe.c openmax.c  pathalloc.c popen.c prexit.c prmask.c ptyfork.c
  ptyopen.c readn.c recvfd.c semaph.c senderr.c sendfd.c servaccept.c servlisten.c
  setfd.c  setfl.c signal.c signalintr.c sleep.c sleepus.c spipe.c strerror.c
  tellwait.c ttymodes.c writen.c
)

#add_library(APUE SHARED
#  bufargs.c cliconn.c clrfl.c daemonize.c error.c errorlog.c lockreg.c locktest.c
#  nspipe.c openmax.c  pathalloc.c popen.c prexit.c prmask.c ptyfork.c
#  ptyopen.c readn.c recvfd.c semaph.c senderr.c sendfd.c servaccept.c servlisten.c
#  setfd.c  setfl.c signal.c signalintr.c sleep.c sleepus.c spipe.c strerror.c
#  tellwait.c ttymodes.c writen.c
#)

#INCLUDE_DIRECTORIES(“${PROJECT_SOURCE_DIR}/src/hellolib/include”)
#头文件目录包含指令

#SET_TARGET_PROPERTIES(hello_static PROPERTIES OUTPUT_NAME “hello”)
#GET_TARGET_PROPERTY (OUTPUT_VALUE hello_static OUTPUT_NAME)

#一般我们希望同时编译出静态库和动态库，并且命名一致，但是cmake的target不允许重名，所以我们把静态库命名为hello_static，然后通过上述语句修改其输出的名字，为hello，这样就可以在lib目录下生成libhello.a和lobhello.so。

#SET_TARGET_PROPERTIES(hello PROPERTIES CLEAN_DIRECT_OUTPUT 1)
#如果执行make后只生成了一种库，说明生成第二个库的时候删除了同名的其他库。上面的语句可以显示指定不删除同名的库。

#SET_TARGET_PROPERTIES(hello PROPERTIES VERSION 1.2 SOVERSION 1)
#一般动态库会包含一个版本号，使用上述命令可以携带版本号：VERSION代表同太苦版本，SOVERSION指代API版本。

SET_TARGET_PROPERTIES(APUE_STATIC PROPERTIES OUTPUT_NAME "APUE")
GET_TARGET_PROPERTY (OUTPUT_VALUE APUE_STATIC OUTPUT_NAME)
MESSAGE (STATUS "This is the APUE_STATIC OUTPUT_NAME: " ${OUTPUT_VALUE})

SET_TARGET_PROPERTIES(APUE_STATIC PROPERTIES CLEAN_DIRECT_OUTPUT 1)
#SET_TARGET_PROPERTIES(APUE PROPERTIES CLEAN_DIRECT_OUTPUT 1)
#SET_TARGET_PROPERTIES(APUE PROPERTIES VERSION 1.2 SOVERSION 1)

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb") # Debug模式下的编译指令

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib) #设置库文件的输出目录 
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/lib)    
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/lib) 

#INSTALL (TARGETS APUE APUE_STATIC LIBRARY DESTINATION lib
#
#ARCHIVE DESTINATION lib)

#INSTALL (FILES apue.h DESTINATION include/apue)


INSTALL (TARGETS APUE_STATIC ARCHIVE DESTINATION $(PROJECT_BINARY_DIR)/lib)
