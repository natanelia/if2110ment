
/*
	NIM/NAMA	: 13513076 / Lie, Albert Tri Adrian
	NAMA FILE	: mmesinkata.c
	TOPIK		: Mesin Kata
	TANGGAL		: 2 Oktober 2014 
	DESKRIPSI	: Driver Mesin Kata

*/
#include "mesinkata.h" 
#include<stdio.h>
#include"boolean.h"


	Kata KataWHILE;
	int NWHILE,i;
	
int main(){
	
	printf("\n********* Menuliskan isi pita ke layar **********\n");
	STARTKATA();
	while (!EndKata)
    {
        for (i=1; i<=CKata.Length;i++)
        {
            printf("%c", CKata.TabKata[i]);
        }
        printf("\n");
        ADVKATA();
    }
	
	printf("\n ******************* Menuliskan jumlah kata WHILE dari pita\n");
	
	
	KataWHILE.TabKata[1] = 'W';
	KataWHILE.TabKata[2] = 'H';
	KataWHILE.TabKata[3] = 'I';
	KataWHILE.TabKata[4] = 'L';
	KataWHILE.TabKata[5] = 'E';
	KataWHILE.Length = 5;
	NWHILE = 0;
	
	EndKata = false;
	STARTKATA();
	while(!EndKata){
		if(IsKataSama(KataWHILE,CKata)){
			NWHILE++;
		}
		ADVKATA();
	}
	
	printf("\n %d \n",NWHILE);
	return 0;
}
