#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
* @file lettres.c
* @author Elsa Navarro & Quentin Dunand
* @date 04/2015
*/



int char_to_num(char c){ 
	/*Il faut c<='z'*/
	return (c-'a'+1);
}

char num_to_char(int n){
	return (char)(n+'a'-1);
}