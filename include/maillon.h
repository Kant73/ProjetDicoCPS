#include <stdio.h>
#include <stdlib.h>

#ifndef LETTRES
#define LETTRES
#include "lettres.h"
#endif

/**
* @file maillon.c
* @author Elsa Navarro & Quentin Dunand
* @date 04/2015
*/

/**
 * @brief 	Notre type structuré maillon_t qui possède un élément val de type lettres et un pointeur sur un maillon_t
 * @struct 	maillon maillon.h "maillon_t"
 */
typedef struct maillon 
{
    lettres val;
    struct maillon *suiv;
} maillon_t; 


/**
 * @brief Modifie la k-ieme lettre d'un maillon par le caractère "c"
 * @param k 	Indice entier supérieur à 0
 * @param c 	Caractère à inserer à la position "k"
 * @param m 	Maillon dont on veut modifier la k-ième lettre
 */
void set_charnum(int k, char c, maillon_t *m);


/**
 * @brief Retourne la k-ieme lettre du maillon
 * @param k 	Indice entier compris entre 0 et 5
 * @param m 	La maillon dont on veut connaitre la k-ème lettre
 */
char get_charnum(int k, maillon_t m);


/**
 * @brief 		Retourne le nombre de bits d'un entier
 * @param  a 	L'entier dont on veut connaitre le nombre de bits
 * @return   	Le nombre de bits de l'entier "a"
 */
int get_nb_bits(int a);


/**
 * @brief 	Retourne le nombre de lettre d'un maillon
 * @param m Le maillon dont on veut connaitre le nombre de lettre
 * @return 	Le nombre de lettre contenues dans le maillon
 */
int get_nb_lettres(maillon_t* m);

/**
 * @brief Convertit une chaine de caractère en liste de maillons
 * @param chaine 	La chaine à convertir en maillons
 * @param m  		Le maillon qui correspond à la chaine convertie
 */
void string_to_maillon(char* chaine, maillon_t* m);

/**
 * @brief Convertit une liste de maillons en chaine de caractères
 * @param m	La liste de maillons à convertir en chaine de caractères
 * @return 	La liste de maillons convertie en chaine de caractères
 */
char* maillon_to_string(maillon_t* m);


/**
 * C version 0.4 char* style "itoa":
 * Written by Lukás Chmela
 * Released under GPLv3.

 * Utilisation d'une fonction C existante mais qui n'est plus présente avec GCC, peut être obselète...
 * Permet de convertir un int "value" en une string "result" qui est la représentation du "value" en base "base"
 * Non utilisée dans le projet mais utilisé surant la phase de developpement pour debugger certaine fonctions
 * @param value  L'entier dont on veut la representation dans la base "base"
 * @param result La chaine résulat qui va contenir la représentation de "value" dans la base "base"
 * @param base 	 La base dans laquelle on veut obtenir la représentation de "value". "base" doit être compris entre 2 et 36.
 * @return 		 L'entier "value" dans la base "base" sous la forme d'une chaîne de caractère
*/
char* itoa(int value, char* result, int base);

/**
* @brief	Libère l'espace mémoire réservée par un maillon et ses successeurs
* @param m 	Le pointeur sur la tete d'une chaine de maillons qu'on veut libérer
*/
void libere_maillons(maillon_t* m);



