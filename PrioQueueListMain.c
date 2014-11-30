/* Driver Queue List */

/* File: PrioQueueListMain.c */

#include "PrioQueueList.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main () {
/*KAMUS */
	PrioQueue Q;
	infopriotype X;
	char str[15];
	int i,j,n,Pr;
	addressprio P;
	
/* ALGORITMA */	
	CreatePrioQueueEmpty(&Q);
	printf("Masukkan jumlah elemen : "); scanf("%d",&n);
	for(j=1;j<=n;j++) {
		printf("Masukkan kata diikuti angka prioritasnya :");
		scanf("%s", str); scanf("%d", &Pr);
        	X.Length=strlen(str);
        	for (i=1; i<=X.Length; i++)
            		X.TabKata[i]=str[i-1];
		AddPrio(&Q,X,Pr);
	}
	printf("Isi Queue : \n");
	P=HeadPrio(Q);
        while(P!=Nil)
        {
            printf("%2d ", Prio(P));
            printKata(InfoPrio(P));
            printf("\n");
            P=NextPrio(P);
        }
	DelPrio(&Q,&X,&Pr);
	printf("Isi Queue setelah elemen pertama dihapus :\n"); 
	P=HeadPrio(Q);
        while(P!=Nil)
        {
            printf("%2d ", Prio(P));
            printKata(InfoPrio(P));
            printf("\n");
            P=NextPrio(P);
        }
	printf("\n");
return 0;
}
