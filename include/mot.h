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

/*Constantes utilisées pour les couleurs dans le shell */
#ifndef COULEUR
#define COULEUR
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#endif

/**
* @file mot.c
* @author Elsa Navarro & Quentin Dunand
* @date 04/2015
*/


typedef struct emplacement
{
    int ligne;
    int colonne;
    struct emplacement* suiv;
} emplacement_t; 


typedef struct mot
{
    maillon_t* tete_mot;
    maillon_t* queue_mot;
    emplacement_t* tete_liste;
    emplacement_t* queue_liste;
    struct mot* suiv;
} mot_t; 



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
* Compare deux mots selon leur ordre alphabétique avec la fonction strcmp (non utilisé dans le projet)
* @param m1 : 1er mot
* @param m2 : 2ème mot
* @return : 0 si les mots sont identiques, un nombre négatif si le 1er est inférieur au second, un nombre positif sinon.
*/
int compare_mot(mot_t m1, mot_t m2);

/**
* Compare deux mots selon leur ordre alphabétique (fonction utilisée dans le projet en utilisant get_charnum)
* @param m1 : 1er mot
* @param m2 : 2ème mot
* @return : 0 si les mots sont identiques, un nombre négatif si le 1er est inférieur au second, un nombre positif sinon.
*/
int compare_mot2(mot_t m1, mot_t m2);


/**
* Affiche le dictionnaire passé en paramètre
* @param dico : dictionnaire (pointeur sur une cellule de mot)
*/
void affiche_dico(mot_t* dico);


/**
* Ajoute l'emplacement contenu dans mot à la suite de la liste d'emplacements de mot_cour
* @param mot_cour : mot contenant une liste d'emplacements
* @param mot : mot contenant un unique emplacement
*/
void ajoute_empl(mot_t* mot_cour, mot_t mot);

/**
* Insère un mot dans le dictionnaire dans l'ordre alphabtique
* @param dico : pointeur sur un dictionnaire (un pointeur de mot)
* @param mot : pointeur sur le mot à insérer dans le dico
*/
void insertion_dico(mot_t** dico, mot_t* mot);