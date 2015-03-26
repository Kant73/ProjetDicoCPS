CC=gcc
CFLAGS=-I../include/ -Wall 
FLAGSSO=-L../lib/liblinux64/ -ltokenize
SRCS=TODO
EXEC=main

all:
	gcc $(CFLAGS) -Wall main.c -o $(EXEC) $(FLAGSSO)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
	