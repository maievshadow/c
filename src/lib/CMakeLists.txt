#mod1/CMakeLists.txt
cmake_minimum_required(VERSION 2.8)
add_library(lib STATIC
  bufargs.c
  cliconn.c
  clrfl.c
  daemonize.c
  error.c
  errorlog.c
  lockreg.c
  locktest.c
)