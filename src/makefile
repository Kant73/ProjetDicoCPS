# Compilateur utilisé : gcc
CC=gcc
#On précise qu'on va chercher les .h dans le dossier include
CFLAGS=-Wall -I../include
FLAGSSO=-L../lib/liblinux64/ -ltokenize
#SRCS temporaire
SRCS= maillon.o lettres.o mot.o main.o
EXEC=main

#Première cible : executable de main temporaire
main: $(SRCS)
	$(CC) -o $(EXEC) $(SRCS) $(CFLAGS) $(FLAGSSO)
	
test_e: $(SRCS)
	$(CC) -o test_e $(SRCS) $(FLAGSSO)

lettres.o: lettres.c
	$(CC) -o lettres.o -c lettres.c $(CFLAGS)

maillon.o: maillon.c lettres.o
	$(CC) -o maillon.o -c maillon.c $(CFLAGS)

mot.o: mot.c maillon.o lettres.o
	$(CC) -o mot.o -c mot.c $(CFLAGS)

main.o: main.c maillon.o lettres.o mot.o
	$(CC) -o main.o -c main.c $(CFLAGS) $(FLAGSSO)

#dico.o: dico.c mot.o maillon.o lettres.o
#	$(CC) -o dico.o -c dico.c $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf test_e
	rm -rf test_q
	rm -rf main
	