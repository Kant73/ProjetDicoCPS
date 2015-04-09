/**
* @file mot.c
* @author Elsa Navarro & Quentin Dunand
* @date 04/2015
*/

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

typedef struct emplacement
{
    int ligne;
    int colonne;
    struct emplacement* suiv;
} emplacement_t; 
//typedef emplacement* emplacement_t;


typedef struct mot
{
    maillon* tete_mot;
    maillon* queue_mot;
    emplacement_t* tete_liste;
    emplacement_t* queue_liste;
    struct mot* suiv;
} mot_t; 
//typedef mot* mot_t;



/**
* Affiche un mot et ses emplacements dans le texte
* @param m : mot à afficher
*/
void print_mot(mot_t m);

/**
* Crée un mot à partir de son emplacement dans le texte
* @param word : mot que l'on veut créer (chaine de caractères)
* @param num_ligne : ligne où se trouve le mot
* @param num_col : colonne où se trouve le mot
* @param mot : mot dans lequel on veut créer le mot
*/
void create_mot(char* word, int num_ligne, int num_col, mot_t* mot);

/**
* Compare deux mots selon leur ordre alphabétique
* @param m1 :
* @param m2 :
* @return :
*/
int compare_mot(mot_t m1, mot_t m2);

int compare_mot2(mot_t m1, mot_t m2);


/**
* @param dico : dictionnaire (pointeur sur une cellule de mot)
*/
void affiche_dico(mot_t* dico);

void ajoute_empl(mot_t* mot_cour, mot_t mot);

/**
* Insère un mot dans le dictionnaire dans l'ordre alphabtique
* @param d :
* @param m : mot à afficher
*/
void insertion_dico(mot_t** dico, mot_t* mot);