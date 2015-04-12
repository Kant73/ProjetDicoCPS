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
 * @file 		main.c
 * @brief 		Programme principal permettant d'obtenir le dictionnaire soit d'un fichier soit d'un texte tapé par l'utilisateur
 * @author		Quentin DUNAND & Elsa NAVARRO
 * @date 		04/2015
 */

/**
 * Programme principal permettant d'obtenir le dictionnaire soit d'un fichier soit d'un texte tapé par l'utilisateur
 * Utilisation du main : ./main [nom_de_fichier]
 * Si l'utilisateur ne tape aucun nom de fichier en argument, alors celui-ci pourra taper son texte lui même au clavier
 * @param  argc 
 * @param  argv 
 * @return      Le code d'erreur
 */
int main(int argc, char const *argv[])
{
	FILE *fichier = NULL;
	char* mot;
	mot_t* dico = NULL;
	unsigned int nbligne = 0;
	unsigned int nbcolonne = 0;
	int i = 0;
	

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

    	while (!feof(fichier))	// Pour l'instant, le main ne fait que afficher les mots du texte qu'on lui a donné
	    {
	    	mot_t m;
	    	mot = next_word(fichier, &nbligne, &nbcolonne);
	    	i++;				//Compteur de mot, on vient d'en lire un, on l'incrémente donc
	    	create_mot(mot, nbligne,nbcolonne,&m);
	    	insertion_dico(&dico,&m);
	    	//printf("Mot n°%d: %s \n",i, mot);
	    }
	    affiche_dico(dico);
	    printf("%s*******************************************\n", KRED);
	    printf("Fin du Dictionnaire, nombre de mots : %d\n", i);
	    printf("*******************************************%s\n", KNRM);
	    //libere_dico(dico); //On libère l'espace mémoire qui a été alloué pour le dico
    }

	return 0;
	
}