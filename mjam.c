/* DRIVER ADT JAM */

#include "jam.h"
#include "boolean.h"
#include <stdio.h>

int main ()
{
	JAM J1,J2;
	int h,m,d;
	
	printf("Jam 1: ");
	scanf("%d %d %d",&h,&m,&d);
	J1=MakeJAM(h,m,d);
	PrintJam(J1);
	printf("\n\nJam 2: ");
	scanf("%d %d %d",&h,&m,&d);
	J2=MakeJAM(h,m,d);
	PrintJam(J2);
	if (IsJamEqual(J1,JamEarly(J1,J2)))
		printf("\nJ1 lebih awal dari J2");
	else
		printf("\nJ2 lebih awal dari J1");
	return 0;
}