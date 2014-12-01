#include "mesinkar.h"
#include "boolean.h"
#include <stdio.h>

extern char CC;

int main(){
	printf("awal pita \n");
	START();
	while(!EOP()){
		printf("%c",CC);
		ADV();
	}
	printf("\n ... akhir, Bye \n");
	return 0;
}
