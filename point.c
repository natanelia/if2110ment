/*
	NIM/Nama	: 13513070/Natan
	Nama file	: point.c
	Topik		: ADT Point - Body
	Tanggal		: 3 September 2014
	Deskripsi	: Badan dari ADT Point
*/

#include<stdio.h>
#include "point.h"
#include<math.h>
#define PI (3.141592653589793)

// { *** DEFINISI PROTOTIPE PRIMITIF *** }
// { *** Konstruktor membentuk POINT *** }
POINT MakePoint ( point_infotype X, point_infotype Y )
// { Membentuk sebuah POINT dari komponen-komponennya }
{
	POINT titik;
	titik.X = X;
	titik.Y = Y;

	return titik;
}


// { *** Operasi terhadap komponen : selektor Get dan Set *** }
// { *** Selektor POINT *** }
point_infotype GetAbsis ( POINT P )
// { Mengirimkan komponen absis dari P }
{
	return P.X;
}

point_infotype GetOrdinat ( POINT P )
// { Mengirimkan komponen ordinat dari P POINT }
{
	return P.Y;
}

// { *** Set nilai komponen *** }
void SetAbsis ( POINT *P, point_infotype newX )
// { Mengubah nilai komponen absis dari P }
{
	P->X = newX;
}

void SetOrdinat ( POINT *P, point_infotype newY)
// { Mengubah nilai komponen ordinat dari P }
{
	P->Y = newY;
}

/* KELOMPOK Interaksi dengan I/O device, BACA/TULIS */
void BacaPoint (POINT *P)
// { Membaca nilai absis dan ordinat dari keyboard dan membentuk POINT P berdasarkan
// dari nilai absis dan ordinat tersebut }
// { I.S. Sembarang }
// { F.S. P terdefinisi }
{
	float X,Y;
	scanf("%f %f", &X, &Y);

	*P = MakePoint(X,Y);
}

void TulisPoint (POINT P)
// { Nilai P ditulis ke layar dengan format "(X,Y)" }
// { I.S. P terdefinisi }
// { F.S. P tertulis di layer dengan format "(X,Y)" }
{
	printf("(%d,%d)\n",GetAbsis(P),GetOrdinat(P));
}


/* Kelompok operasi relasional terhadap POINT */
boolean Point_EQ ( POINT P1, POINT P2 )
// { Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama }
{
	return ((P1.X == P2.X) && (P1.Y == P2.Y));
}

boolean Point_NEQ ( POINT P1, POINT P2 )
// { Mengirimkan true jika P1 tidak sama dengan P2 }
{
	return !(Point_EQ(P1,P2));
}

/* Kelompok menentukan di mana P berada */
boolean Point_IsOrigin (POINT P)
// { Mengirimkan true jika P adalah titik Origin }
{
	return (P.X == 0 && P.Y == 0);
}

boolean Point_IsOnSbX (POINT P)
// { Menghasilkan true jika P terletak Pada sumbu X }
{
	return (P.Y == 0);
}

boolean Point_IsOnSbY (POINT P)
// { Menghasilkan true jika P terletak pada sumbu Y }
{
	return (P.X == 0);
}

int Point_Kuadran (POINT P)
// { Menghasilkan kuadran dari P: 1, 2, 3, atau 4 }
// { Prekondisi : P bukan Titik Origin, }
// { dan P tidak terletak di salah satu sumbu }
{
	if ((P.X > 0) && (P.Y > 0)) { //Kuadran 1
		return 1;
	} else if ((P.X < 0) && (P.Y > 0)) { //Kuadran 2
		return 2;
	} else if ((P.X < 0) && (P.Y < 0)) { //Kuadran 3
		return 3;
	} else if ((P.X > 0) && (P.Y < 0)) { //Kuadran 4
		return 4;
	} else {
		return 0;
	}
}

/* Kelompok operasi lain terhadap type */
POINT Point_NextX (POINT P)
// { Mengirim salinan P dengan absis ditambah satu }
{
	return MakePoint(P.X+1, P.Y);
}

POINT Point_NextY (POINT P)
// { Mengirim salinan P dengan ordinat ditambah satu }
{
	return MakePoint(P.X, P.Y+1);
}

POINT Point_PlusDelta (POINT P, point_infotype deltaX, point_infotype deltaY)
// { Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah
// Ordinat(P) + deltaY }
{
	return MakePoint(P.X+deltaX, P.Y+deltaY);
}

POINT Point_MirrorOf (POINT P, boolean SbX)
// { Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu }
// { Jika SbX bernilai true, maka dicerminkan terhadap sumbu X }
// { Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y }
{
	if (SbX == true) {
		return MakePoint(P.X,0-P.Y);
	} else {
		return MakePoint(0-P.X,P.Y);
	}
}

float Point_Jarak0 (POINT P)
// { Menghitung jarak P ke (0,0) secara skalar }
{
	return sqrt(pow(P.X,2)+pow(P.Y,2));
}

float Point_Panjang (POINT P1, POINT P2)
// { Menghitung panjang garis yang dibentuk P1 dan P2 }
// { Menghitung jarak titik P1 ke titik P2 secara skalar }
{
	return sqrt(pow(P2.X-P1.X,2)+pow(P2.Y-P1.Y,2));
}

void Point_Geser (POINT *P, point_infotype deltaX, point_infotype deltaY)
// { I.S. P terdefinisi }
// { F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY }
{
	*P = Point_PlusDelta(*P, deltaX, deltaY);
}

void Point_GeserKeSbX (POINT *P)
// { I.S. P terdefinisi }
// { F.S. P berada pada sumbu X dengan absis sama dengan absis semula. }
// { Proses : P digeser ke sumbu X. }
// { Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) }
{
	SetOrdinat(P,0);
}

void Point_GeserKeSbY (POINT *P)
// { I.S. P terdefinisi}
// { F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. }
// { Proses : P digeser ke sumbu Y. }
// { Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) }
{
	SetAbsis(P,0);
}

void Point_Mirror (POINT *P, boolean SbX)
// { I.S. P terdefinisi }
// { F.S. P dicerminkan tergantung nilai SbX atau SbY }
// { Jika SbX true maka dicerminkan terhadap sumbu X }
// { Jika SbX false maka dicerminkan terhadap sumbu Y }
{
	*P = Point_MirrorOf (*P, SbX);
}

void Point_Putar (POINT *P, point_infotype Sudut)
// { I.S. P terdefinisi }
// { F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) }
{
	float X,Y;
	float radian = Sudut*PI/180;
	X = (GetAbsis(*P))*(cos(radian)) - (GetOrdinat(*P))*(sin(radian));
	Y = (GetAbsis(*P))*(sin(radian)) + (GetOrdinat(*P))*(cos(radian));
	SetAbsis(P, X);
	SetOrdinat(P, Y);
}

boolean IsPointSama(POINT P1, POINT P2)
//Mengecek apakah kedua pont merupakan point yang sama atau tidak
{
	return (GetAbsis(P1) == GetAbsis(P2) ) && (GetOrdinat(P1) == GetOrdinat(P2)); 
}
