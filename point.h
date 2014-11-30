/*
	NIM/Nama	: 13513070/Natan
	Nama file	: point.h
	Topik		: ADT Point - Header
	Tanggal		: 3 September 2014
	Deskripsi	: Header dari ADT Point
*/

#include "boolean.h"

#ifndef point_h
#define point_h
typedef int point_infotype;

typedef struct {
	point_infotype X; //absis
	point_infotype Y; //ordinat
} POINT;

// { *** DEFINISI PROTOTIPE PRIMITIF *** }
// { *** Konstruktor membentuk POINT *** }
POINT MakePoint ( point_infotype X, point_infotype Y);
// { Membentuk sebuah POINT dari komponen-komponennya }


// { *** Operasi terhadap komponen : selektor Get dan Set *** }
// { *** Selektor POINT *** }
point_infotype GetAbsis ( POINT P );
// { Mengirimkan komponen absis dari P }

point_infotype GetOrdinat ( POINT P );
// { Mengirimkan komponen ordinat dari P POINT }

// { *** Set nilai komponen *** }
void SetAbsis ( POINT *P, point_infotype newX );
// { Mengubah nilai komponen absis dari P }

void SetOrdinat ( POINT *P, point_infotype newY);
// { Mengubah nilai komponen ordinat dari P }

/* KELOMPOK Interaksi dengan I/O device, BACA/TULIS */
void BacaPoint (POINT *P);
// { Membaca nilai absis dan ordinat dari keyboard dan membentuk POINT P berdasarkan
// dari nilai absis dan ordinat tersebut }
// { I.S. Sembarang }
// { F.S. P terdefinisi }

void TulisPoint (POINT P);
// { Nilai P ditulis ke layar dengan format "(X,Y)" }
// { I.S. P terdefinisi }
// { F.S. P tertulis di layer dengan format "(X,Y)" }

boolean IsPointSama(POINT P1, POINT P2);
//Mengecek apakah kedua pont merupakan point yang sama atau tidak

#endif
