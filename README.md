
cmake -D CMAKE_INSTALL_PREFIX=/usr/local //设置安装前缀

最近遇到了几个问题
1):
编译静态库/动态库问题 --方案可以参考src/test/
2):
APUE学习的时候遇到了err_quit等作者自定义函数报错问题
然后我又重新学习了一下静态库/动态库的编译过程。 因为我把APUE的lib库单独编译成了库 放系统里去
然而还是报undefined err_quit等函数未定义。最后库的问题解决了
又遇到了一个问题errorlog.c 里有一个变量

/*
 * Caller must define and set this: nonzero if
 * interactive, zero if daemon
 */
extern int	log_to_stderr;

请看注释 需要我们自己先定义这个变量。不然加载库的时候会爆这个错误～～

总结：这两天总算解决了一点点自己的问题！昨天真是失败感油然而生！ ---2019-11-08 11:06

移除cmake的教程。可以参考代码里的cmakelist文件～～
