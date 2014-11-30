/* DRIVER ADT TANGGAL */

#include "tanggal.h"
#include "boolean.h"
#include <stdio.h>

int main ()
{
	TANGGAL T1,T2;
	int d,m,y;
	
	printf("Tanggal 1: ");
	scanf("%d %d %d",&d,&m,&y);
	T1=MakeTANGGAL(d,m,y);
	PrintTanggal(T1);
	printf("\n\nTanggal 2: ");
	scanf("%d %d %d",&d,&m,&y);
	T2=MakeTANGGAL(d,m,y);
	PrintTanggal(T2);
	
	if (IsTanggalEqual(T1,TanggalEarly(T1,T2)))
		printf("\nT1 lebih awal dari T2");
	else
		printf("\nT2 lebih awal dari T1");

	return 0;
}