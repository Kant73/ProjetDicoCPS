#include "read_word.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef LETTRES
#define LETTRES
#include "lettres.h"
#endif

#ifndef MAILLON
#define MAILLON
#include "maillon.h"
#endif

#ifndef MOT
#define MOT
#include "mot.h"
#endif

/**
 * Team #4 : (DUNAND & NAVARRO) FOR LIFE
 * @author : Quentin DUNAND & Elsa NAVARRO
 * @project : Projet Dictionnaire CPS 2015 
 */

int main(int argc, char const *argv[])
{
	FILE *fichier = NULL;
	char* mot;
	mot_t* dico;
	unsigned int nbligne = 0;
	unsigned int nbcolonne = 0;
	int i = 1;
	

    if (argc > 2)	// Si on met plus de 2 arguments : message d'erreur
    {
    	printf("Utilisation du main : ./main [nom_de_fichier]\n");
    }
    else
    {
    	
    	if (argc == 2)	//Si nb d'argument = 1, alors on ouvre le fichier passé en argument
	    {
	        fichier = fopen (argv[1], "r"); /* On ouvre le fichier passer en argument argv[1] */
	        
	    } 
	    else // Sinon on utilise l'entrée standard stdin
	    {
    		fichier = stdin;
    	}

    	while (!feof(fichier))	// POur l'instant, le main ne fait que afficher les mots du texte qu'on lui a donné
	    {
	    	mot_t m;
	    	mot = next_word(fichier, &nbligne, &nbcolonne);
	    	create_mot(mot, nbligne,nbcolonne,&m);
	    	insertion_dico(&dico,&m);
	    	printf("Mot n°%d: %s \n",i, mot);
	    	i++;
	    }
	    affiche_dico(dico);
    }

	return 0;
	
}