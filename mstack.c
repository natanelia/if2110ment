#include <stdio.h>
#include <string.h>
#include "stacklist.h"

void PrintStack(Stack S) {
	address P;
	P = Top(S);
	while (P != Nil) {
		printf("%d ",Info(P));
		P = Next(P);
	}
	printf("\n");
}

int main()
{
	int d,pilihan;
	Stack S;
	CreateEmpty(&S);
	while ((pilihan != 4))
	{
		printf("Masukkan pilihan : \n[1 : pop, 2 : push, 3 : print, 4 : keluar]\n");
		scanf("%d",&pilihan);
		if (pilihan ==1) {
			if (IsEmpty(S))
				printf("Stack Kosong. Tidak bisa dipop\n");
			else {
				Pop(&S,&d);
				printf("yang dikeluarkan : %d\n",d);
			}
		}
		else if (pilihan == 2) {
			printf("Masukkan nilai yg akan dimasukkan :");
			scanf("%d",&d);
			Push(&S,d);
		}
		else if (pilihan == 3) 
			PrintStack(S);
		getch();
	}			 
	return 0;
}
