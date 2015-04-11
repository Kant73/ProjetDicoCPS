#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
* @file mot.c
* @author Elsa Navarro & Quentin Dunand
* @date 04/2015
*/

typedef uint32_t lettres;

/**
 * Convertit un char en entier (entre 1 et 26)
 * @param c : caractère à convertir qui vérifie 'a'<=c<='z'
 */
int char_to_num(char c);

/**
 * Convertit un entier (entre 1 et 26) en caractère (lettre de l'alphabet minuscule)
 * @param n : entier à convertir
 */
char num_to_char(int n);
