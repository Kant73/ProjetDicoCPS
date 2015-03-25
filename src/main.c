#include "read_word.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Team #4 : (DUNAND & NAVARRO) FOR LIFE
 * @author : Quentin DUNAND & Elsa NAVARRO
 * @project : Projet Dictionnaire CPS 2015 
 */

int main(int argc, char const *argv[])
{
	FILE *fichier = NULL;
	char* mot;
	unsigned int nbligne = 0;
	unsigned int nbcolonne = 0;
	int i = 1;
	

    if (argc > 2)
    {
    	printf("Utilisation du main : ./main [nom_de_fichier]\n");
    }
    else
    {
    	
    	if (argc == 2)
	    {
	        fichier = fopen (argv[1], "r"); /* On ouvre le fichier passer en argument argv[1] */
	        
	    } 
	    else 
	    {
    		fichier = stdin;
    	}

    	while (!feof(fichier))
	    {
	    	mot = next_word(fichier, &nbligne, &nbcolonne);
	    	printf("Mot n°%d: %s \n",i, mot);
	    	i++;
	    }
    }

	return 0;
	
}