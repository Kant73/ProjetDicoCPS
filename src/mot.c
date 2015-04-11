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
 * @date 11/04/2015
 */


void print_mot(mot_t m)
{
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
	maillon_t* ma;
	(*mot).tete_mot = (maillon_t*) malloc(sizeof(maillon_t));	//malloc pour allouer la mémoire nécéssaire
	(*mot).queue_mot = (maillon_t*) malloc(sizeof(maillon_t));	//pour les pointeurs sur maillons
	string_to_maillon(word, (*mot).tete_mot);

	emplacement_t* empl;
	empl = (emplacement_t*) malloc(sizeof(emplacement_t));		//idem qu'au dessus mais pour un emplacement_t
	(*empl).ligne = num_ligne;
	(*empl).colonne = num_col;

	(*mot).tete_liste = empl;	//Lors de la création d'un mot, il n'existe qu'a un seul emplacement
	(*mot).queue_liste = empl;	//conséquence: (*mot).tete_liste == (*mot).queue_liste
	
	ma = (*mot).tete_mot;	//On veut le dernier maillon du mot pour faire pointer
	while((*ma).suiv!=NULL)	//(*mot).queue_mot dessus
	{						
		ma = (*ma).suiv;
	}

	(*mot).queue_mot = ma; 	//On fait pointer (*mot).queue_mot sur le dernier maillon qui compose le mot

	(*mot).suiv = NULL;		//Il n'y a pas de mot suivant, on init le pointeur suiv à NULL
	
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

int compare_mot2(mot_t m1, mot_t m2){
	//m1 et m2 sont des mots non nuls
	int i=0;
	maillon_t mail1=(*(m1.tete_mot));
	maillon_t mail2=(*(m2.tete_mot));
	char c1=get_charnum(i,mail1);
	char c2=get_charnum(i,mail2);


	#ifdef _DEBUG
	printf("maillon_to_string c1\n");
 	printf("maillon_to_string c2\n");
 	printf("c1: %s\n", c1);
 	printf("c2: %s\n", c2);
	#endif

 	while(char_to_num(c1)!=0){
 		if(c2==c1){//Les caractères sont égaux
 				//On avance dans les mots
		 	i++;
		 	//Si 
		 	if(i==6){	//On a fini un maillon
		 		i=0;
		 		if(mail1.suiv==NULL){	//Si le maillon 1 est nul
		 			if(mail2.suiv==NULL) return 0; //Si le 2e l'est aussi ils sont égaux
		 			return -1;	//Sinon le 2e est plus grand, on renvoie un nb négatif
		 		}
		 		if(mail2.suiv==NULL) return 1;//Ici le maillon 2 est nul mais pas le maillon 1 => on retourne un entier positif
		 		//On est ici assuré que l'on peut accéder au maillon suivant

		 		mail2=*(mail2.suiv);
		 		mail1=*(mail1.suiv);

				c1=get_charnum(i,mail1);
				c2=get_charnum(i,mail2);
		 	}
		 	else{	//On passe au caractère suivant du maillon

			c1=get_charnum(i,mail1);
			c2=get_charnum(i,mail2);
		 	}
 		}
 		else{
 			return char_to_num(c1)-char_to_num(c2);
 		}
 	}
 	
	return char_to_num(c1)-char_to_num(c2);
}


void affiche_dico(mot_t* dico){
	printf("%s**************\n", KRED);
	printf("Dictionnaire : \n");
	printf("**************%s\n", KNRM);;
	mot_t* dico_temp=dico;

	while(dico_temp!=NULL){
		print_mot(*dico_temp);
		dico_temp=(*dico_temp).suiv;
	}
}


void ajoute_empl(mot_t* ptr_mot_init, mot_t mot_ajout){
	//On crée un nouvel emplacement
	emplacement_t* nouv_empl=(emplacement_t*)malloc(sizeof(emplacement_t));
	(*nouv_empl).ligne=(*mot_ajout.tete_liste).ligne;			 //On lui assigne les valeurs de l'emplacement de mot_ajout
	(*nouv_empl).colonne=(*mot_ajout.tete_liste).colonne;
	(*nouv_empl).suiv=NULL;
	(*((*ptr_mot_init).queue_liste)).suiv=nouv_empl; 		//On chaine le dernier emplacement du mot initial à la nouvelle valeur
	(*ptr_mot_init).queue_liste=nouv_empl;					//Et on modifie la queue de liste du mot initial
		}



//gère le cas d'insertion en fin du dico, en tête de dico et dans un dico vide
void insertion_dico(mot_t** dico, mot_t* mot){
	//Insère un mot m non nul dans un dico d quelconque
	mot_t* mot_cour=*dico;	//On initialise notre pointeur de parcours sur le début du dictionnaire
	mot_t* mot_prec=NULL;
	mot_t* mot_ajout=(mot_t*)malloc(sizeof(mot_t));
	(*mot_ajout)=(*mot);
			#ifdef _DEBUG
			printf("DEBUT TEST INSERT DICO\n");
			if(mot_cour!=NULL) print_mot(**dico);
			printf("MILIEU TEST INSERT DICO\n");
			#endif
	
	while(mot_cour!=NULL){ //tant que le dictionnaire n'est pas vide
		int cmp=compare_mot2(*mot_ajout, *mot_cour);

		#ifdef _DEBUG
		if((cmp!=compare_mot(*mot_ajout, *mot_cour))&&(cmp*compare_mot(*mot_ajout, *mot_cour)<0)){
			printf("Compare mot incorrect !!!!\n"); //Si c'est différent et que leur produit est négatif, alors le résultat de cmp est faux !!!
		}
		#endif

		if(cmp==0){						//mot et mot_cour sont identiques
			ajoute_empl(mot_cour, *mot_ajout);	//On ajoute l'emplacement de mot dans mot_cour
			if(mot_prec!=NULL){			//Si le mot présédent existe
				(*mot_prec).suiv=mot_cour;		//mot_prec.suiv pointe sur le nouveau mot
			}							//Sinon on est en tête de dictionnaire, mot_cour==*dico on ne fait rien
			return;							//Le mot a été placé, on quitte l'insertion
		}
		else{
			if(cmp<0){			//mot est plus petit que mot_cour, on le place juste avant:
				(*mot_ajout).suiv=mot_cour;		//On chaine le mot avant le mot courant
				if(mot_prec!=NULL){			//Si le mot présédent existe
					(*mot_prec).suiv=mot_ajout;		//On le raccroche au mot
				}else{						//Sinon on est en tête de dictionnaire
					*dico=mot_ajout;					//On raccroche celui ci au mot
				}
				return;						//Le mot a été placé, on quitte l'insertion
			}else{				//mot est plus grand que mot_cour, 
								//on continue le parcours de dico sauf si le mot suivant est nul
				if((*mot_cour).suiv!=0){
					mot_prec=mot_cour;			//le mot courant devient le mot précédent
					mot_cour=(*mot_cour).suiv;	//le mot suivant devient le mot courant
				}else{			//dans ce cas on place le mot à la fin du dico
					(*mot_ajout).suiv=NULL;		//On chaine le mot comme étant la fin du dico
					(*mot_cour).suiv=mot_ajout;	//On raccroche le mot courant au mot
					return;					//On a placé le mot, on quitte l'insertion
				}
			}
		}
	}
	//Ici le dico est vide :
	//On insère le mot en tete de dico :
	(*mot_ajout).suiv=mot_cour;		//On chaine le mot en tête du dictionnaire (il est vide alors ces pointeurs sont nuls)
	mot_cour=mot_ajout;				//On raccroche la tete du dictionnaire au mot
	*dico=mot_cour;
}