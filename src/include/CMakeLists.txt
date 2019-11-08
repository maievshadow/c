#mod1/CMakeLists.txt
cmake_minimum_required(VERSION 2.8)
#    add_library(APUE_STATIC STATIC
#        bufargs.c cliconn.c clrfl.c daemonize.c error.c errorlog.c lockreg.c locktest.c
#        nspipe.c openmax.c pathalloc.c popen.c prexit.c prmask.c ptyfork.c
#        ptyopen.c readn.c recvfd.c semaph.c senderr.c sendfd.c servaccept.c servlisten.c
#        setfd.c setfl.c signal.c signalintr.c sleep.c sleepus.c spipe.c strerror.c
#        tellwait.c ttymodes.c writen.c
#)

add_library(MAIEV SHARED
                bufargs.c cliconn.c clrfl.c daemonize.c error.c errorlog.c lockreg.c locktest.c
                nspipe.c openmax.c pathalloc.c popen.c prexit.c prmask.c ptyfork.c
                ptyopen.c readn.c recvfd.c semaph.c senderr.c sendfd.c servaccept.c servlisten.c
                setfd.c setfl.c signal.c signalintr.c sleep.c sleepus.c spipe.c strerror.c
                tellwait.c ttymodes.c writen.c
        )

add_library(MAIEV_STATIC STATIC
        maiev.c
        )

SET_TARGET_PROPERTIES(MAIEV_STATIC PROPERTIES OUTPUT_NAME "MAIEV")
GET_TARGET_PROPERTY (OUTPUT_VALUE MAIEV_STATIC OUTPUT_NAME)
MESSAGE (STATUS "This is the MAIEV_STATIC OUTPUT_NAME: " ${OUTPUT_VALUE})

#SET_TARGET_PROPERTIES(MAIEV_STATIC PROPERTIES CLEAN_DIRECT_OUTPUT 1)
SET_TARGET_PROPERTIES(MAIEV PROPERTIES CLEAN_DIRECT_OUTPUT 1)
SET_TARGET_PROPERTIES(MAIEV PROPERTIES VERSION 1.2 SOVERSION 1)

INSTALL (TARGETS MAIEV MAIEV_STATIC LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)

INSTALL (FILES maiev.h apue.h DESTINATION include/maiev)

#add_library(APUE SHARED
#        bufargs.c cliconn.c clrfl.c daemonize.c error.c errorlog.c lockreg.c locktest.c
#        nspipe.c openmax.c pathalloc.c popen.c prexit.c prmask.c ptyfork.c
#        ptyopen.c readn.c recvfd.c semaph.c senderr.c sendfd.c servaccept.c servlisten.c
#        setfd.c setfl.c signal.c signalintr.c sleep.c sleepus.c spipe.c strerror.c
#        tellwait.c ttymodes.c writen.c
#)

#SET_TARGET_PROPERTIES(APUE_STATIC PROPERTIES OUTPUT_NAME "APUE")
#GET_TARGET_PROPERTY (OUTPUT_VALUE APUE_STATIC OUTPUT_NAME)
#MESSAGE (STATUS "This is the APUE_STATIC OUTPUT_NAME: " ${OUTPUT_VALUE})
#
#SET_TARGET_PROPERTIES(APUE_STATIC PROPERTIES CLEAN_DIRECT_OUTPUT 1)
#SET_TARGET_PROPERTIES(APUE PROPERTIES CLEAN_DIRECT_OUTPUT 1)
#SET_TARGET_PROPERTIES(APUE PROPERTIES VERSION 1.2 SOVERSION 1)

#SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb") # Debug模式下的编译指令
#
#SET(LIBRARY_OUTPUT_PATH lib) #设置库文件的输出目录
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY lib)
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/lib)
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/lib)

#INSTALL (TARGETS APUE APUE_STATIC LIBRARY DESTINATION lib
#
#ARCHIVE DESTINATION lib)
#
#INSTALL (FILES apue.h DESTINATION include/)

#INSTALL (TARGETS APUE_STATIC ARCHIVE DESTINATION $(PROJECT_BINARY_DIR)/lib)
