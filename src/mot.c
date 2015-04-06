#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

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

int compare_mot(mot_t m1, mot_t m2){
	/*m1 et m2 sont des mots non nuls*/
	char* c1, c2;

	//les mots ne sont pas vides, on récupère les chaines de caractère
	c1=maillon_to_string(m1.tete_mot);
	c2=maillon_to_string(m2.tete_mot);
 
	return strcmp(c1, c2);
}



void insertion_dico(dico* d, mot_t m){
	/*Insère un mot m non nul dans un dico d quelconque*/
	dico* d_suiv=d;

	//Parcourir dico tant que d_suiv est non nul
	while(d_suiv!=NULL){
		bool b=compare_mot((*d_suiv).mot.tete_mot,m);
		//Tester si le mot auquel on a à faire est identique
		if(b==0)){
			ajoute_mot(d_suiv,m);
		}
		else{ 		//Si non : Si il est plus grand (alphabétiquement) on continue
			if(b<0){
				d_suiv=(*d_suiv).suiv;
			}else{ //Si il est plus petit, on l'insère avant
				insere_mot(d_suiv,m);
			}
		}
	}
	//Si d_suiv est nul insérer le mot m
	insere_mot(d_suiv,m);
}