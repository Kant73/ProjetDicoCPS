# Compilateur utilisé : gcc
CC=gcc
#On précise qu'on va chercher les .h dans le dossier include
CFLAGS=-I../include/ -Wall
FLAGSSO=-L../lib/liblinux64/ -ltokenize
#SRCS temporaire
SRCS=maillon.o lettres.o test.o	
EXEC=main

#Première cible : executable de test temporaire
test: $(SRCS)
	$(CC) -o test $(SRCS)

all:
	$(CC) $(CFLAGS) main.c -o $(EXEC) $(FLAGSSO)

lettres.o: lettres.c
	$(CC) -o lettres.o -c lettres.c $(CFLAGS)

maillon.o: maillon.c lettres.o
	$(CC) -o maillon.o -c maillon.c $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf test
	