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

/**
* @file test_e.c
* @author Elsa Navarro & Quentin Dunand
* @date 04/2015
*/

//Executable utilisé pour les tests des fonctions dico
int main(void)
{

	mot_t mot1;
	create_mot("elephant", 8, 10, &mot1);

	mot_t* dico=NULL; //On crée un dico et on l'initialise à NULL
	printf("dico :'%p\n On ajoute elephant à dico (vide)\n", dico);
	insertion_dico(&dico, &mot1); //On ajoute mot1 à dico
	affiche_dico(dico);

	create_mot("arbre", 1, 1, &mot1);
	printf("dico :'%p\n On ajoute arbre à dico (tete de dico non vide)\n", dico);
	insertion_dico(&dico, &mot1); //On ajoute mot1 à dico
	affiche_dico(dico);

	create_mot("statue", 1, 5, &mot1);
	printf("dico :'%p\n On ajoute statue à dico (fin de dico non vide)\n", dico);
	insertion_dico(&dico, &mot1); //On ajoute mot1 à dico
	affiche_dico(dico);

	create_mot("pc", 48, 7, &mot1);
	printf("dico :'%p\n On ajoute pc à dico (milieu de dico)\n", dico);
	insertion_dico(&dico, &mot1); //On ajoute mot1 à dico
	affiche_dico(dico);

	create_mot("elephant", 3, 12, &mot1);
	printf("dico :'%p\n On rajoute elephant à dico \n", dico);
	insertion_dico(&dico, &mot1); //On ajoute mot1 à dico
	affiche_dico(dico);

	create_mot("arbre", 3, 12, &mot1);
	printf("dico :'%p\n On rajoute arbre à dico \n", dico);
	insertion_dico(&dico, &mot1); //On ajoute mot1 à dico
	affiche_dico(dico);

	create_mot("arbrea", 9, 2, &mot1);
	printf("dico :'%p\n On rajoute arbrea à dico\n", dico);
	insertion_dico(&dico, &mot1); //On ajoute mot1 à dico
	affiche_dico(dico);

	create_mot("aa", 9, 2, &mot1);
	printf("dico :'%p\n On rajoute aa à dico\n", dico);
	insertion_dico(&dico, &mot1); //On ajoute mot1 à dico
	affiche_dico(dico);

	create_mot("aaaaa", 9, 2, &mot1);
	printf("dico :'%p\n On rajoute aaaaa à dico\n", dico);
	insertion_dico(&dico, &mot1); //On ajoute mot1 à dico
	affiche_dico(dico);

	create_mot("aaaaaa", 9, 2, &mot1);
	printf("dico :'%p\n On rajoute aaaaaa à dico\n", dico);
	insertion_dico(&dico, &mot1); //On ajoute mot1 à dico
	affiche_dico(dico);

	create_mot("aaaaaaa", 9, 2, &mot1);
	printf("dico :'%p\n On rajoute aaaaaaa à dico\n", dico);
	insertion_dico(&dico, &mot1); //On ajoute mot1 à dico
	affiche_dico(dico);

	create_mot("abaaaa", 9, 2, &mot1);
	printf("dico :'%p\n On rajoute abaaaa à dico\n", dico);
	insertion_dico(&dico, &mot1); //On ajoute mot1 à dico
	affiche_dico(dico);

	return 0;
}