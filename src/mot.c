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
	#ifdef _DEBUG
	printf("BEGIN PRINT MOT\n");
	#endif
	printf("%s ", maillon_to_string(m.tete_mot));

	emplacement_t* tete = m.tete_liste;
	do
	{
		printf("(%d, %d) ", (*tete).ligne, (*tete).colonne);
		tete = (*tete).suiv;
	} while (tete!=NULL);
	printf("\n");
}


void create_mot(char* word, int num_ligne, int num_col, mot_t* mot)
{
	maillon* ma;
	(*mot).tete_mot = (maillon*) malloc(sizeof(struct maillon));
	(*mot).queue_mot = (maillon*) malloc(sizeof(struct maillon));
	string_to_maillon(word, (*mot).tete_mot);

	emplacement_t* empl;
	empl = (emplacement_t*) malloc(sizeof(emplacement_t));
	(*empl).ligne = num_ligne;
	(*empl).colonne = num_col;

	(*mot).tete_liste = empl;
	(*mot).queue_liste = empl;
	
	ma = (*mot).tete_mot;
	while((*ma).suiv!=NULL)
	{
		ma = (*ma).suiv;
	}

	(*mot).queue_mot = ma;

	(*mot).suiv = NULL;
	
}

int compare_mot(mot_t m1, mot_t m2){
	//m1 et m2 sont des mots non nuls
	char* c1;
	char* c2;

	//les mots ne sont pas vides, on récupère les chaines de caractère
	c1=maillon_to_string(m1.tete_mot);
	c2=maillon_to_string(m2.tete_mot);

	#ifdef _DEBUG
	printf("maillon_to_string c1\n");
 	printf("maillon_to_string c2\n");
 	printf("c1: %s\n", c1);
 	printf("c2: %s\n", c2);
	#endif

	return strcmp(c1, c2);
}

#ifdef _DEBUG
int compare_mot2(mot_t m1, mot_t m2)
{
	return 0;
}
#endif


void affiche_dico(mot_t* dico){
	printf("Dictionnaire : \n");
	mot_t* dico_temp=dico;

	while(dico_temp!=NULL){
		print_mot(*dico_temp);
		//printf("dico.suiv :'%d\n", (*dico_temp).suiv);
		dico_temp=(*dico_temp).suiv;
	}
}


void insertion_dico(mot_t** dico, mot_t* mot){
	//Insère un mot m non nul dans un dico d quelconque
	mot_t* dico_cour=*dico;	//On initialise notre pointeur de parcours sur le début du dictionnaire
	//mot_t* dico_prec=NULL;
	#ifdef _DEBUG
	printf("DEBUT TEST INSERT DICO\n");
	if(dico_cour!=NULL) print_mot(**dico);
	printf("MILIEU TEST INSERT DICO\n");
	#endif

	//On insère le mot en tete du dictionnaire dico:
	(*mot).suiv=dico_cour;		//On chaine le mot en tête du dictionnaire
	dico_cour=mot;			//On raccroche la tete du dictionnaire au mot
	//print_mot(*dico_cour); 
	*dico=dico_cour;

	//printf("FIN TEST INSERT DICO\n");
}
/*
void insertion_dico(dico_t* d, mot_t m){
	//Insère un mot m non nul dans un dico d quelconque
	dico_t* d_suiv=d;

	//Parcourir dico tant que d_suiv est non nul
	while(d_suiv!=NULL){
	int ent=compare_mot((*d_suiv).mot.tete_mot,m);
		//Tester si le mot auquel on a à faire est identique
		if(ent==0)){
			ajoute_mot(d_suiv,m);
		}
		else{ 		//Si non : Si il est plus grand (alphabétiquement) on continue
			if(ent<0){
				d_suiv=(*d_suiv).suiv;
			}else{ //Si il est plus petit, on l'insère avant
				insere_mot(d_suiv,m);
			}
		}
	}
	//Si d_suiv est nul insérer le mot m
	insere_mot(d_suiv,m);
}

*/