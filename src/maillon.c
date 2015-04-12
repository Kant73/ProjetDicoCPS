#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maillon.h"

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


int get_nb_lettres(maillon_t* m)
{
	lettres l=(*m).val;
	maillon_t* m_courant=m;
    int nb_lettres=0;
    l <<= 2;	// Pour "supprimer" les bits 30 et 31
    while(l)
    {
        l<<=5;
        nb_lettres++;
        if((nb_lettres%6==0)&&((*m_courant).suiv!=NULL)){ 
        //si on a atteint la fin du maillon et qu'il y en a encore à tester
        	m_courant=(*m_courant).suiv; //on teste sur les maillons suivants
        	l=(*m_courant).val; //on récupère la suite du mot
        	l <<= 2;	// Pour "supprimer" les bits 30 et 31
        }
        //printf("nb_lettres: %d\n", nb_lettres);
    }
    return nb_lettres;
}



//get_charnum fonctionnel comme désiré dans le sujet (bit 29-25 : lettre 0, bit 24-20 : lettre 1 etc..)
char get_charnum(int k, maillon_t m){
	int mask = 0b11111;
	//int nb_bits = get_nb_bits(m.val);
	return num_to_char(((m.val & (mask<<(30-(5*(k+1)))))>>(30-(5*(k+1)))));
}


void set_charnum(int k, char c, maillon_t *m){
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

void string_to_maillon(char* chaine, maillon_t* m)
{

	maillon_t* der_m = NULL;
	int i = 0;
	int saut = 0;
	char c=*chaine;

	der_m = m;

	while(c!='\0') //Tant que ce n'est pas la fin du mot
	{
		if(i>5){
			//on passe au maillon suivant lorsque le maillon courant est plein
			(*der_m).suiv = (maillon_t*) malloc(sizeof(maillon_t));
			der_m=(*der_m).suiv;
			(*der_m).val = 0;
			i=0;
			saut = saut + 6;
		}
		set_charnum(i,c, der_m);
		i++;
		c=*(chaine+i+saut);
	}
}


char* maillon_to_string(maillon_t* m)
{
	//Définition des variables locales et initialisation
	char* chaine=NULL;
	int i=0;
	int saut=0;				//variable grâce à laquelle on connait le caractère effectif
	maillon_t* m_temp=m;

	//On calcule la taille du mot que l'on veut récupérer
	int taille=get_nb_lettres(m); 
	#ifdef _DEBUG
	printf("taille :%d\n",taille);
	#endif
	chaine=(char*)malloc(taille*sizeof(char)+1);

	//On parcours le maillon en remplissant la chaine
	while(saut+i<taille){
		*(chaine+i+saut)=get_charnum(i,*m_temp); 

		if(i==5){
			i=0;							//reinitialisation de i à 0
			saut=saut+6;					//on doit sauter 6 lettres
			m_temp= (*m_temp).suiv;			//on passe au maillon suivant
		}else
		{
			i++;			
		}
	}
	*(chaine+taille)='\0';
	return chaine;
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


void libere_maillons(maillon_t* m){
    if(m!=NULL){
        libere_maillons((*m).suiv);
        free(m);
    }
}