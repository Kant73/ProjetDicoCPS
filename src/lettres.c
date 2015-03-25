#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "lettres.h"


int char_to_num(char c){ 
	/*Il faut c<='z'*/
	return (c-'a'+1);
}

char num_to_char(int n){
	return (char)(n+'a'-1);
}

int main(void){
	return 0;
}