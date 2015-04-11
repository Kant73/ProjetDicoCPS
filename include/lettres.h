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
 * @brief Convertit un char en entier (entre 1 et 26)
 * @param c 	Le caractère à convertir en entier qui vérifie 'a'<=c<='z'
 */
int char_to_num(char c);

/**
 * @brief Convertit un entier (entre 1 et 26) en caractère (lettre de l'alphabet minuscule)
 * @param n 	L'entier à convertir en caractère qui vérifie 1 <= n <= 26
 */
char num_to_char(int n);
