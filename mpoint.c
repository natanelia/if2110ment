/*
	NIM/Nama	: 13513070/Natan
	Nama file	: mpoint.c
	Topik		: ADT Point - Driver
	Tanggal		: 3 September 2014
	Deskripsi	: Driver test dari ADT Point
*/

#include<stdio.h>
#include "point.h"
#include "boolean.h"

int main()
{
	POINT t1, t2;
	float dX,dY,dS;
	SetAbsis(&t1,25.2);
	SetOrdinat(&t1,10.21);
	printf("X Titik 1: %.1f\nY Titik 2: %.1f\n",GetAbsis(t1),GetOrdinat(t1));
	BacaPoint(&t1);
	BacaPoint(&t2);
	printf("Masukan:\n");
	TulisPoint(t1);
	TulisPoint(t2);
	
	if (EQ(t1,t2)) {
		printf("Titik 1 = Titik 2\n");
	} else {
		printf("Titik 1 != Titik 2\n");
	}
	
	if (NEQ(t1,t2)) {
		printf("Titik 1 != Titik 2\n");
	} else {
		printf("Titik 1 = Titik 2\n");
	}
	
	printf("\n");
	
	if (IsOrigin(t1)) {
		printf("Titik 1 adalah titik origin.\n");
	} else {
		printf("Titik 1 bukan titik origin.\n");
	}
	
	printf("\n");
	
	if (IsOnSbX(t1)) {
		printf("Titik 1 ada di sumbu X.\n");
	} else {
		printf("Titik 1 tidak di sumbu X.\n");
	}
	
	printf("\n");
	
	if (IsOnSbY(t1)) {
		printf("Titik 1 ada di sumbu Y.\n");
	} else {
		printf("Titik 1 tidak di sumbu Y.\n");
	}
	
	printf("\n");
	
	printf("Titik 1 berada pada kuadran %d\n", Kuadran(t1));
	
	printf("\n");
	
	printf("Titik 1 dengan X+1: "); TulisPoint(NextX(t1));
	printf("Titik 1 dengan Y+1: "); TulisPoint(NextY(t1));
	
	printf("\n");
	
	printf("Tambahkan titik 1 dengan: ");
	scanf("%f %f",&dX, &dY);
	printf("Hasilnya: "); TulisPoint(PlusDelta(t1,dX,dY));
	
	printf("\n");
	
	printf("Mirror titik 1 ke sumbu X: "); TulisPoint(MirrorOf(t1,true));
	printf("Mirror titik 1 ke sumbu Y: "); TulisPoint(MirrorOf(t1,false));
	
	printf("\n");
	
	printf("Jarak titik 1 ke origin: %.2f\n",Jarak0(t1));
	printf("Jarak titik 1 ke titik 2: %.2f\n",Panjang(t1,t2));
	
	printf("\n");
	
	printf("Geser permanen dari dX dY sebelumnya: ");
	Geser(&t1,dX,dY);
	TulisPoint(t1);
	
	printf("Geser ke sumbu X: ");
	GeserKeSbX(&t1);
	TulisPoint(t1);
	
	printf("Geser ke sumbu Y: ");
	GeserKeSbY(&t1);
	TulisPoint(t1);
	
	printf("Putar titik 2 sebesar: ");
	scanf("%f",&dS);
	printf("Hasilnya: ");
	Putar(&t2,dS);
	TulisPoint(t2);
	
	return 0;
}
