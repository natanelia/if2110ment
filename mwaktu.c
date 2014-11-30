/* DRIVER ADT WAKTU */

#include "boolean.h"
#include "waktu.h"
#include <stdio.h>

int main ()
{
	JAM J1,J2;
	TANGGAL T1,T2;
	WAKTU W1,W2;
	int a,b,c;
	printf("Jam 1: ");
	scanf("%d %d %d",&a,&b,&c);
	J1=MakeJAM(a,b,c);
	printf("\nJam 2: ");
	scanf("%d %d %d",&a,&b,&c);
	J2=MakeJAM(a,b,c);
	printf("\nTanggal 1: ");
	scanf("%d %d %d",&a,&b,&c);
	T1=MakeTANGGAL(a,b,c);
	printf("\nTanggal 2: ");
	scanf("%d %d %d",&a,&b,&c);
	T2=MakeTANGGAL(a,b,c);
	
	W1=MakeWAKTU(T1, J1);
	W2=MakeWAKTU(T2, J2);
	PrintWaktu(W1);
	printf("\n");
	PrintWaktu(W2);
	if (IsWaktuEarly(W1,W2))
		printf("\nW1 lebih awal dari W2");
	else
		printf("\nWT2 lebih awal dari W1");
	return 0;
}