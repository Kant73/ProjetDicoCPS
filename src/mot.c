#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>




typedef struct emplacement emplacement;
struct emplacement
{
    int ligne;
    int colonne;
    struct emplacement *suiv;
}; 
typedef emplacement* emplacement_t;


typedef struct mot mot;
struct mot
{
    maillon_t *tete_mot;
    maillon_t *queue_mot;
    emplacement_t *tete_liste;
    emplacement_t *queue_liste;
    struct mot *suiv;
}; 
typedef mot* mot_t;