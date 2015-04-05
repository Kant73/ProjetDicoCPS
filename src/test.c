#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "lettres.h"
#include "maillon.h"

//Executable utilisé pour les tests
int main(void)
{
	maillon m;
	//m.val = 0b100100010100011100100010100011;	// lettre 0 = r, lettre 1 = e, lettre 2 = c
	m.val = 0b100100010100011000000000000000;
	m.suiv = NULL;
	char c2 = 'a';
	/*
	char c = get_charnum(0, m);
	printf("%c\n", c);*/

	//Test get_charnum
	printf("NB_BITS: %d\n",get_nb_bits(m.val));
	char c = get_charnum(0, m);
	printf("Lettre n°0: %c\n", c);
	c = get_charnum(1, m);
	printf("Lettre n°1: %c\n", c);
	c = get_charnum(2, m);
	printf("Lettre n°2: %c\n", c);

	//Test de set_charnum
	set_charnum(1, c2, &m);
	c = get_charnum(1, m);
	printf("Lettre n°1: %c\n", c);
	return 0;
}