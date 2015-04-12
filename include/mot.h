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

/**
 * @brief 	Type structuré emplacement_t composé d'un entier ligne, d'un entier colonne et d'un pointeur sur un emplacement_t
 * @struct 	emplacement mot.h "emplacement_t"
 */
typedef struct emplacement
{
    int ligne;
    int colonne;
    struct emplacement* suiv;
} emplacement_t; 

/**
 * @brief 	Type structuré mot_t composé de deux pointeurs sur des maillon_t (1er et dernier d'un mot) et de deux pointeurs sur des emplacement_t (le 1er et le dernier emplacement)
 * @struct 	mot mot.h "mot_t"
 */
typedef struct mot
{
    maillon_t* tete_mot;
    maillon_t* queue_mot;
    emplacement_t* tete_liste;
    emplacement_t* queue_liste;
    struct mot* suiv;
} mot_t; 



/**
* @brief Affiche un mot et ses emplacements dans le texte
* @param m 	Le mot à afficher
*/
void print_mot(mot_t m);

/**
* @brief Crée un mot à partir de son emplacement dans le texte
* @param word 		Le mot que l'on veut créer (chaine de caractères)
* @param num_ligne 	La ligne où se trouve le mot
* @param num_col 	La colonne où se trouve le mot
* @param mot 		Le mot dans lequel on veut créer le mot "word"
*/
void create_mot(char* word, int num_ligne, int num_col, mot_t* mot);

/**
* @brief Compare deux mots selon leur ordre alphabétique avec la fonction strcmp (non utilisé dans le projet : voir compare_mot2)
* @param m1 	Le 1er mot à comparer
* @param m2 	Le 2ème mot à comparer
* @return 		0 si les mots sont identiques, un nombre négatif si le 1er est inférieur au second, un nombre positif sinon.
*/
int compare_mot(mot_t m1, mot_t m2);

/**
* @brief Compare deux mots selon leur ordre alphabétique (fonction utilisée dans le projet en utilisant get_charnum)
* @param m1 	Le 1er mot à comparer
* @param m2 	Le 2ème mot à comparer
* @return 		0 si les mots sont identiques, un nombre négatif si le 1er est inférieur au second, un nombre positif sinon.
*/
int compare_mot2(mot_t m1, mot_t m2);


/**
* @brief Affiche le dictionnaire passé en paramètre
* @param dico 	Le dictionnaire (pointeur sur une cellule de mot) qu'on veut afficher
*/
void affiche_dico(mot_t* dico);


/**
* @brief Ajoute l'emplacement contenu dans mot à la suite de la liste d'emplacements de mot_cour
* @param mot_cour 	Le mot_t contenant une liste d'emplacements auquel on veut rajouter l'emplacement de mot
* @param mot 		Le mot contenant un unique emplacement qu'on veut rajouter à la liste d'emplacement de mot_cour
*/
void ajoute_empl(mot_t* mot_cour, mot_t mot);

/**
* @brief Insère un mot dans le dictionnaire dans l'ordre alphabtique
* @param dico  	Un pointeur sur un dictionnaire (un pointeur de mot_t)
* @param mot 	Un pointeur sur le mot à insérer dans le dico
*/
void insertion_dico(mot_t** dico, mot_t* mot);

/**
* @brief		Libère l'espace mémoire réservée par un emplacement et ses successeurs
* @param empl 	Le pointeur sur la tete d'une chaine d'emplacements qu'on veut libérer en mémoire
*/
void libere_emplacements(emplacement_t* empl);
 
/**
* @brief		Libère l'espace mémoire réservée par un dictionnaire
* @param dico 	Le dictionnaire (liste chainée de mot_t) dont on veut libérer la mémoire
*/
void libere_dico(mot_t* dico);