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

#ifndef MOT
#define MOT
#include "mot.h"
#endif

//Executable utilisé pour les tests
int main(void)
{
	maillon m;
	//m.val = 0b100100010100011100100010100011;	// lettre 0 = r, lettre 1 = e, lettre 2 = c
	//m.val = 0b100100010100011000000000000001;
	m.val = 0b000000000000000000000000000001;
	m.suiv = NULL;
	char c2 = 'g';

	/*
	char c = get_charnum(0, m);
	printf("%c\n", c);*/

	//Test get_charnum
	printf("NB_BITS: %d\n",get_nb_bits(m.val));
	char c = get_charnum(0, m);
	printf("Lettre n°0: %c\n", c);
	c = get_charnum(1, m);
	printf("Lettre n°1: %c\n", c);
	c = get_charnum(5, m);
	printf("Lettre n°5: %c\n", c);

	//Test de set_charnum
	set_charnum(1, c2, &m);
	c = get_charnum(1, m);
	printf("Lettre n°1: %c\n", c);


	//Test de string_to_maillon
	char* chaine = "luciaboly";
	char* chaine2 = NULL;
	maillon m1;
	maillon m2;

	//maillon* m_der = NULL;
	//m_der = (maillon*) malloc(sizeof(struct maillon));

	m1.val = 0;
	//m_der.val = 0;

/*
	m1 = string_to_maillon2(chaine);


	int j = 0;
	for (j = 0; j <= 5; j++)
	{
		c = get_charnum(j, m1);
		printf("Lettre n°%d: %c\n",j, c);
	}


*/
	string_to_maillon(chaine, &m1);
	//printf("SALUT LES ENFANTS\n");

	printf("m1: %d\n", &m1 );
	//printf("m_der: %d\n", m_der );


	printf("CACA\n");
	int j = 0;
	for (j = 0; j <= 5; j++)
	{
		c = get_charnum(j, m1);
		printf("Lettre n°%d: %c\n",j, c);
	}

	printf("m1.suiv: %d\n", m1.suiv);
	//printf("m_der = m1.suiv ?: %d\n", m_der );
	for (j = 0; j <= 5; j++)
	{
		c = get_charnum(j, *(m1.suiv));
		printf("Lettre n°%d: %c\n",j, c);
	}

	chaine2 = maillon_to_string(&m1);
	printf("chaine2 : %s\n", chaine2);

	/////////////////
	//Test de mot.c//
	/////////////////

	//Test de create_mot
	//void create_mot(char* word, int num_ligne, int num_col, mot_t mot);

	mot_t mot1;
	mot1.tete_mot = (maillon*) malloc(sizeof(struct maillon));
	mot1.queue_mot = (maillon*) malloc(sizeof(struct maillon));
	create_mot("salutleszi", 12, 18, &mot1);

	



	//Test de print_mot
	//void print_mot(mot_t m);
	
	print_mot(mot1);



	return 0;
}