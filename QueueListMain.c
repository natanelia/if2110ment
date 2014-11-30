/* Driver Queue List */

/* File: QueueListMain.c */

#include "QueueList.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main () {
/*KAMUS */
	Queue Q;
	infoqtype X;
	char str[15];
	int i,j,n;
	
/* ALGORITMA */	
	CreateQueueEmpty(&Q);
	printf("Masukkan jumlah elemen yang ingin dimasukkan dalam antrian : "); scanf("%d",&n);
	for(j=1;j<=n;j++) {
		printf("Masukkan kata :");
		scanf("%s", str);
        	X.Length=strlen(str);
        	for (i=1; i<=X.Length; i++)
            		X.TabKata[i]=str[i-1];
		AddQueue(&Q,X);
	}
	printf("Isi Queue : "); PrintInfoQueue(Q);
	DelQueue(&Q,&X);
	printf("Isi Queue setelah elemen pertama dihapus :");  PrintInfoQueue(Q);
	printf("Masukkan kata yang ingin dicari: "); 
	scanf("%s", str);
	X.Length=strlen(str);
        for (i=1; i<=X.Length; i++)
            	X.TabKata[i]=str[i-1];
	if (SearchQueue(Q, X)) 
		printf("Kata terdapat dalam antrian \n");
	else
		printf("Kata tidak terdapat dalam antrian \n");
return 0;
}

