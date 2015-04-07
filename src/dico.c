#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#ifndef DICO
#define DICO
#include "dico.h"
#endif

/**
 * Mot.c
 * @author Quentin DUNAND and Elsa Navarro
 * 
 */


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
