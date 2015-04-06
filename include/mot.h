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
} mot_t; 
//typedef mot* mot_t;

typedef struct dico 
{
	mot_t mot;
	mot_t* suiv;
} dico_t;


void print_mot(mot_t m);

void create_mot(char* word, int num_ligne, int num_col, mot_t mot);