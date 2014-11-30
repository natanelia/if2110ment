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



boolean IsPointSama(POINT P1, POINT P2)
//Mengecek apakah kedua pont merupakan point yang sama atau tidak
{
	return (GetAbsis(P1) == GetAbsis(P2) ) && (GetOrdinat(P1) == GetOrdinat(P2)); 
}
