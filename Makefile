SOURCE=src/
CCFLAGS=gcc -c -o
OBJDIR=$(SOURCE)obj
fork2:
	gcc -c $(SOURCE)fork2.c -o $(OBJDIR)/fork2.o
install:
	gcc -o $(SOURCE)bin/fork $(OBJDIR)/fork2.o
.PHONY:
	install clean fork2
clean:
	rm $(SOURCE)bin/* *.o
