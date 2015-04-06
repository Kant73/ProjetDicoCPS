#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef MOT
#define MOT
#include "mot.h"
#endif

/**
 * Mot.c
 * @author Quentin DUNAND and Elsa Navarro
 * 
 */


void print_mot(mot_t m)
{
	printf("%s ", maillon_to_string(m.tete_mot));
	emplacement_t tete = *(m.tete_liste);
	while (tete.suiv!=NULL)
	{
		printf("(%d, %d) ", tete.ligne, tete.colonne);
		tete = *(tete.suiv);
	}
}


void create_mot(char* word, int num_ligne, int num_col, mot_t mot)
{
	//maillon* ma;
	string_to_maillon(word, mot.tete_mot);
	emplacement_t empl;
	empl.ligne = num_ligne;
	empl.colonne = num_col;
	

	//mot.tete_mot = ma;
	mot.tete_liste = &empl;
	mot.queue_liste = &empl;
	/*
	while((*ma).suiv!=NULL)
	{
		ma = (*ma).suiv;
	}

	mot.queue_mot = ma;
	*/
}