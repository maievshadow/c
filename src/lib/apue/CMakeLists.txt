#mod1/CMakeLists.txt
cmake_minimum_required(VERSION 2.8)
add_library(Apue STATIC
  bufargs.c cliconn.c clrfl.c daemonize.c error.c errorlog.c lockreg.c locktest.c
  nspipe.c openmax.c Orecvfd.c pathalloc.c popen.c prexit.c prmask.c ptyfork.c
  ptyopen.c readn.c recvfd.c semaph.c senderr.c sendfd.c servaccept.c servlisten.c
  setfd.c  setfl.c singla.c singalintr.c sleep.c sleepus.c spipe.c strerror.c
  tellwait.c ttymodes.c writen.c
)