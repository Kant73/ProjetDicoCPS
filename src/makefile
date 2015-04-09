# Compilateur utilisé : gcc
CC=gcc
#On précise qu'on va chercher les .h dans le dossier include
CFLAGS=-I../include/ -Wall
FLAGSSO=-L../lib/liblinux64/ -ltokenize
#SRCS temporaire
SRCS= maillon.o lettres.o test_e.o mot.o
EXEC=main

#Première cible : executable de test_e temporaire
test_e: $(SRCS)
	$(CC) -o test_e $(SRCS)

all:
	$(CC) $(CFLAGS) main.c -o $(EXEC) $(FLAGSSO)

lettres.o: lettres.c
	$(CC) -o lettres.o -c lettres.c $(CFLAGS)

maillon.o: maillon.c lettres.o
	$(CC) -o maillon.o -c maillon.c $(CFLAGS)

mot.o: mot.c maillon.o lettres.o
	$(CC) -o mot.o -c mot.c $(CFLAGS)

#dico.o: dico.c mot.o maillon.o lettres.o
#	$(CC) -o dico.o -c dico.c $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf test_e
	