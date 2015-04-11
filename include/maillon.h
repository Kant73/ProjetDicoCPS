#include <stdio.h>
#include <stdlib.h>
#include "lettres.h"

typedef struct maillon maillon;
struct maillon
{
    lettres val;
    struct maillon *suiv;
}; 

// Inutile, du moins pour le moment
//typedef maillon* maillon_t;


/**
 * Modifie la k-ieme lettre d'un maillon
 * @param k : indice entier supérieur à 0
 * @param c : caractère à inserer
 * @param m : maillon à modifier
 */
void set_charnum(int k, char c, maillon *m);


/**
 * Consulte la k-ieme lettre du maillon
 * @param k : indice entier compris entre 0 et 5
 * @param m : maillon à consulter
 */
char get_charnum(int k, maillon m);


/**
 * Retourne le nombre de bits d'un entier
 * @param  a L'entier dont on veut connaitre le nombre de bits
 * @return   Le nombre de bits de l'entier "a"
 */
int get_nb_bits(int a);


/**
 * Retourne le nombre de lettre d'un maillon
 * @param  m [description]
 * @return   [description]
 */
int get_nb_lettres(maillon* m);

/**
 * Convertit une chaine de caractère en liste de maillons
 * @param chaine : chaine à convertir
 * @param m : maillon converti
 * @param der_m : pointeur vers le ddernier maillon
 */
void string_to_maillon(char* chaine, maillon* m);

/**
 * Convertit une liste de maillons en chaine de caractères
 * @param m : maillon à convertir
 * @param taille : taille du mot
 * @return : la chaine de caractères convertie
 */
char* maillon_to_string(maillon* m);






/**
 * C version 0.4 char* style "itoa":
 * Written by Lukás Chmela
 * Released under GPLv3.

 * Utilisation d'une fonction C existante mais qui n'est plus présente avec GCC, peut être obselète...
 * Permet de convertir un int "value" en une string "result" qui est la représentation du "value" en base "base"
 * @param value  L'entier dont on veut la representation dans la base "base"
 * @param result La chaine résulat qui va contenir la représentation de "value" dans la base "base"
 * @param base 	 La base dans laquelle on veut obtenir la représentation de "value". "base" doit être compris entre 2 et 36.
 * @return 		 L'entier "value" dans la base "base" sous la forme d'une chaîne de caractère
*/
char* itoa(int value, char* result, int base);


maillon ajouter_maillon(maillon ajoute, maillon m);

