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
	create_mot("jesuislemotun", 1, 1, &mot1);

	mot_t mot2;
	//mot2.tete_mot = (maillon*) malloc(sizeof(struct maillon));
	//mot2.queue_mot = (maillon*) malloc(sizeof(struct maillon));
	create_mot("jesuislemotdeux", 8, 10, &mot2);

	printf("CREATE_MOT DONE\n");

	printf("mot1: \n");
	print_mot(mot1);
	printf("mot2: \n");
	print_mot(mot2);

	//Tests de dico

	printf("mot1.suiv :'%d\n", mot1.suiv);
	printf("mot2.suiv :'%d\n", mot2.suiv);
	printf("adresse de mot1 : %d\n", &mot1);
	printf("adresse de mot2 : %d\n", &mot2);

	mot_t* dico=NULL; //On crée un dico et on l'initialise à NULL
	printf("dico :'%d\n", dico);
	insertion_dico(&dico, &mot1); //On ajoute mot1 à dico
	printf("dico :'%d\n", dico);
	insertion_dico(&dico, &mot2); //On ajoute mot1 à dico
	printf("dico :'%d\n", dico);

	printf("adresse de mot1 : %d\n", &mot1);
	printf("adresse de mot2 : %d\n", &mot2);

	printf("mot2.suiv (devrait être égal à l'adresse de mot1): %d\n", mot2.suiv);

	affiche_dico(dico);

	return 0;

	




	return 0;
}