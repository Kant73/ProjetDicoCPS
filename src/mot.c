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
		//printf("BEGIN PRINT MOT\n");
	printf("%s ", maillon_to_string(m.tete_mot));

	emplacement_t* tete = m.tete_liste;
	do
	{		//printf("(*tete).suiv =%d\n", (*tete).suiv);
		printf("(%d, %d) ", (*tete).ligne, (*tete).colonne);
		tete = (*tete).suiv;
			//printf("tete = %d\n", tete);
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


void ajoute_empl(mot_t* ptr_mot_init, mot_t mot_ajout){
	//On crée un nouvel emplacement
	emplacement_t* nouv_empl=(emplacement_t*)malloc(sizeof(emplacement_t));
	(*nouv_empl).ligne=(*mot_ajout.tete_liste).ligne;			 //On lui assigne les valeurs de l'emplacement de mot_ajout
	(*nouv_empl).colonne=(*mot_ajout.tete_liste).colonne;
	(*nouv_empl).suiv=NULL;
		//printf("On le rajoute à la queue_liste de mot initial : \nAvant :(*((*ptr_mot_init).queue_liste)).suiv= %d\n", (*((*ptr_mot_init).queue_liste)).suiv);
	(*((*ptr_mot_init).queue_liste)).suiv=nouv_empl; 		//On chaine le dernier emplacement du mot initial à la nouvelle valeur
		//printf("Après :(*((*ptr_mot_init).queue_liste)).suiv= %d\n", (*((*ptr_mot_init).queue_liste)).suiv);
		//printf("nouv_empl= %d\n", nouv_empl);
	(*ptr_mot_init).queue_liste=nouv_empl;					//Et on modifie la queue de liste du mot initial
		//printf("La queue de liste pointe vers nouv_empl : \n (*ptr_mot_init).queue_liste= %d \n nouv_empl= %d\n", (*ptr_mot_init).queue_liste, nouv_empl);
}

/*void insertion_dico_tete(mot_t** dico, mot_t* mot){
	mot_t* mot_cour=*dico;	//On initialise notre pointeur de parcours sur le début du dictionnaire
		//On insère le mot en tete du dictionnaire dico 
	(*mot).suiv=mot_cour;		//On chaine le mot en tête du dictionnaire
	mot_cour=mot;				//On raccroche la tete du dictionnaire au mot
		//print_mot(*mot_cour);
	*dico=mot_cour;
	}*/


//gère le cas d'insertion en fin du dico, en tête de dico et dans un dico vide
void insertion_dico(mot_t** dico, mot_t* mot){
	//Insère un mot m non nul dans un dico d quelconque
	mot_t* mot_cour=*dico;	//On initialise notre pointeur de parcours sur le début du dictionnaire
	mot_t* mot_prec=NULL;
			#ifdef _DEBUG
			printf("DEBUT TEST INSERT DICO\n");
			if(mot_cour!=NULL) print_mot(**dico);
			printf("MILIEU TEST INSERT DICO\n");
			#endif
	
	while(mot_cour!=NULL){ //tant que le dictionnaire n'est pas vide
			printf("On compare les deux mots : mot= %d, mot_cour=%d, mot_prec=%d\n", mot, mot_cour, mot_prec);
		int cmp =compare_mot(*mot, *mot_cour);
			printf("Les deux mots ont été comparés\n");
		if(cmp==0){						//mot et mot_cour sont identiques
				//printf("Le mot existe déjà dans le dico\n");
			ajoute_empl(mot_cour, *mot);	//On ajoute l'emplacement de mot dans mot_cour
				//printf("On a ajouté l'emplacement du mot à insérer\n");
			if(mot_prec!=NULL){			//Si le mot présédent existe
				(*mot_prec).suiv=mot_cour;		//mot_prec.suiv pointe sur le nouveau mot
			}							//Sinon on est en tête de dictionnaire, mot_cour==*dico on ne fait rien
			return;							//Le mot a été placé, on quitte l'insertion
		}
		else{
			if(cmp<0){			//mot est plus petit que mot_cour, on le place juste avant:
				(*mot).suiv=mot_cour;		//On chaine le mot avant le mot courant
				printf("On place le mot avant mot_cour \n mot_prec=%d\n", mot_prec);
				if(mot_prec!=NULL){			//Si le mot présédent existe
					(*mot_prec).suiv=mot;		//On le raccroche au mot
				}else{						//Sinon on est en tête de dictionnaire
					*dico=mot;					//On raccroche celui ci au mot
				}
				return;						//Le mot a été placé, on quitte l'insertion
			}else{				//mot est plus grand que mot_cour, 
								//on continue le parcours de dico sauf si le mot suivant est nul
				if((*mot_cour).suiv!=0){
					mot_prec=mot_cour;			//le mot courant devient le mot précédent
					mot_cour=(*mot_cour).suiv;	//le mot suivant devient le mot courant
				}else{			//dans ce cas on place le mot à la fin du dico
					(*mot).suiv=NULL;		//On chaine le mot comme étant la fin du dico
					(*mot_cour).suiv=mot;	//On raccroche le mot courant au mot
					return;					//On a placé le mot, on quitte l'insertion
				}
			}
		}
	}
	//Ici le dico est vide :
	//On insère le mot en tete de dico :
	(*mot).suiv=mot_cour;		//On chaine le mot en tête du dictionnaire (il est vide alors ces pointeurs sont nuls)
	mot_cour=mot;				//On raccroche la tete du dictionnaire au mot
		//print_mot(*mot_cour);
	*dico=mot_cour;

	//printf("FIN TEST INSERT DICO\n");
}