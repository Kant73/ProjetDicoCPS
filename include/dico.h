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

#ifndef DICO
#define DICO
#include "dico.h"
#endif

typedef struct dico 
{
	mot_t mot;
	mot_t* suiv;
} dico_t;


/**
* Insère un mot dans le dictionnaire dans l'ordre alphabtique
* @param d :
* @param m : mot à afficher
*/
void insertion_dico(dico_t* d, mot_t m);