#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



int char_to_num(char c){ 
	/*Il faut c<='z'*/
	return (c-'a'+1);
}

char num_to_char(int n){
	return (char)(n+'a'-1);
}

/*
int main(void){

	//Test des fonctions
	int b = 3;
	char b2 = num_to_char(b);
	int c = char_to_num(b2);
	printf("%d\n", c);

	return 0;
}*/