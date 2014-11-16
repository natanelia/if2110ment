/* NIM/Nama : 13513038/Tjan, Marco Orlando
Nama file : ADT_MultiList_Driver.c
Topik :multilist untuk highscore*/


#include "ADT_MultiList.h"	
#include "boolean.h"
#include <stdio.h>	

//KAMUS
List L1;
Kata Kata1;


int main()
{
	BacaDataBaseScore(&L1);
	printf("check check check \n");
	Kata1.TabKata[1] = 'M'; Kata1.TabKata[1] = 'A'; Kata1.TabKata[1] = 'R'; Kata1.TabKata[1] = 'C'; Kata1.TabKata[1] = 'O'; Kata1.Length = 5;
	printf("check check check \n");
	ViewMyHighscore(L1, 1, Kata1 ); //kosong
	printf("check check check \n");
	//ViewAllHighscore(L1, 1);  //jebol



return 0;
}

