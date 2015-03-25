CC=gcc
CFLAGS=-I../include/ -Wall 
FLAGSSO=-L../lib/liblinux64/ -ltokenize
SRCS= 
EXEC=main

all: $(EXEC)
	gcc $(CFLAGS) main.c $(FLAGSSO) -o $(EXEC)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
	