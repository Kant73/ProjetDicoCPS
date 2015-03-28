#include <stdio.h>
#include <stdlib.h>
#include "lettres.h"
#include "maillon.h"

/*
void set_charnum(int k, char c, maillon_t m){

}

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