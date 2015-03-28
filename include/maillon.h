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
typedef maillon* maillon_t;

/**
 * Modifie la k-ieme lettre d'un maillon
 * @param k : indice entier compris entre 0 et 5
 * @param c : caractère à inserer
 * @param m : maillon à modifier
 */
void set_charnum(int k, char c, maillon m);

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
