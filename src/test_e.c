#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef LETTRES
#define LETTRES
#include "lettres.h"
#endif

#ifndef MAILLON
#define MAILLON
#include "maillon.h"
#endif

#ifndef MOT
#define MOT
#include "mot.h"
#endif

//Executable utilisé pour les tests
int main(void)
{

	mot_t mot1;
	create_mot("arbre", 1, 1, &mot1);

	mot_t mot2;
	//mot2.tete_mot = (maillon*) malloc(sizeof(struct maillon));
	//mot2.queue_mot = (maillon*) malloc(sizeof(struct maillon));
	create_mot("elephant", 8, 10, &mot2);

	mot_t mot3;
	create_mot("pc", 48, 7, &mot3);

	mot_t mot4;
	create_mot("statue", 1, 5, &mot4);

	printf("CREATE_MOT DONE\n");

	printf("mot1: \n");
	print_mot(mot1);
	printf("mot2: \n");
	print_mot(mot2);
	printf("mot3: \n");
	print_mot(mot3);
	printf("mot4: \n");
	print_mot(mot4);

	//Tests de dico
/*
	printf("mot1.suiv :'%d\n", mot1.suiv);
	printf("mot2.suiv :'%d\n", mot2.suiv);
	printf("adresse de mot1 : %d\n", &mot1);
	printf("adresse de mot2 : %d\n", &mot2);*/

	mot_t* dico=NULL; //On crée un dico et on l'initialise à NULL
	printf("dico :'%d\n On ajoute mot2 à dico (vide)\n", dico);
	insertion_dico(&dico, &mot2); //On ajoute mot2 à dico
	affiche_dico(dico);
	printf("dico :'%d\n On ajoute mot1 à dico (tete de liste non vide)\n", dico);
	insertion_dico(&dico, &mot1); //On ajoute mot1 à dico
	affiche_dico(dico);
	printf("dico :'%d\n On ajoute mot4 à dico (fin de dico)\n", dico);
	insertion_dico(&dico, &mot4); //On ajoute mot4 à dico
	affiche_dico(dico);
	printf("dico :'%d\n On ajoute mot3 à dico (milieu de dico)\n", dico);
	insertion_dico(&dico, &mot3); //On ajoute mot3 à dico
	affiche_dico(dico);
	//printf("dico :'%d\n", dico);
/*
	printf("adresse de mot1 : %d\n", &mot1);
	printf("adresse de mot2 : %d\n", &mot2);

	printf("mot2.suiv (devrait être égal à l'adresse de mot1): %d\n", mot2.suiv);*/

	affiche_dico(dico);

	return 0;

	




	return 0;
}