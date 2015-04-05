#include <stdio.h>
#include <stdlib.h>
#include "lettres.h"
#include "maillon.h"

/**
 * Maillon.c
 */

/*
//Version qui fonctionne à l'envers (bit 29-25 : lettre 5, bit 24-20 : lettre 4 etc..)
char get_charnum(int k, maillon m){
	int mask = 0b11111;
	return num_to_char(((m.val & (mask<<(5*k)))>>(5*k)));
}*/

int get_nb_bits(int a)
{
    int nb_bits=0;
    while(a)
    {
        a>>=1;
        nb_bits++;
    }
    return nb_bits;
}

//get_charnum fonctionnel comme désiré dans le sujet (bit 29-25 : lettre 0, bit 24-20 : lettre 1 etc..)
char get_charnum(int k, maillon m){
	int mask = 0b11111;
	int nb_bits = get_nb_bits(m.val);
	return num_to_char(((m.val & (mask<<(nb_bits-(5*(k+1)))))>>(nb_bits-(5*(k+1)))));
}



void set_charnum(int k, char c, maillon *m){
	//Initialisation
	int mask_one = 0b111111111111111111111111111111;
	int mask_char = char_to_num(c); //représentation du caractère c en décimal.

	//On prépare le masque afin d'obtenir des zeros sur les bits qu'on veut modifier et des 1 ailleurs
	mask_one = mask_one << 5;
	int i = 0;
	for(i=0; i<(5*(5-k)); i++)
	{
		mask_one = (mask_one << 1);
		mask_one = mask_one | 1; 
	}

	//On modifie le maillion qu'on veut changer afin de mettre les bits qu'on veut modifier à zero
	(*m).val = (*m).val & mask_one;
	
	//On fait un ou bit à bit sur les bits qu'on vient de mettre à zero afin de changer la valeur du k-ième élement
	(*m).val = (*m).val | (mask_char << (5*(5-k)));
}


char* itoa(int value, char* result, int base) {
		// check that the base if valid
		if (base < 2 || base > 36) { *result = '\0'; return result; }

		char* ptr = result, *ptr1 = result, tmp_char;
		int tmp_value;

		do {
			tmp_value = value;
			value /= base;
			*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
		} while ( value );

		// Apply negative sign
		if (tmp_value < 0) *ptr++ = '-';
		*ptr-- = '\0';
		while(ptr1 < ptr) {
			tmp_char = *ptr;
			*ptr--= *ptr1;
			*ptr1++ = tmp_char;
		}
		return result;
	}