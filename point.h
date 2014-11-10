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


/* Kelompok operasi relasional terhadap POINT */
boolean Point_EQ ( POINT P1, POINT P2 );
// { Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama }

boolean Point_NEQ ( POINT P1, POINT P2 );
// { Mengirimkan true jika P1 tidak sama dengan P2 }

/* Kelompok menentukan di mana P berada */
boolean Point_IsOrigin (POINT P);
// { Mengirimkan true jika P1 tidak sama dengan P2 }

boolean Point_IsOnSbX (POINT P);
// { Menghasilkan true jika P terletak Pada sumbu X }

boolean Point_IsOnSbY (POINT P);
// { Menghasilkan true jika P terletak pada sumbu Y }

int Point_Kuadran (POINT P);
// { Menghasilkan kuadran dari P: 1, 2, 3, atau 4 }
// { Prekondisi : P bukan Titik Origin, }
// { dan P tidak terletak di salah satu sumbu }

/* Kelompok operasi lain terhadap type */
POINT Point_NextX (POINT P);
// { Mengirim salinan P dengan absis ditambah satu }

POINT Point_NextY (POINT P);
// { Mengirim salinan P dengan ordinat ditambah satu }

POINT Point_PlusDelta (POINT P, point_infotype deltaX, point_infotype deltaY);
// { Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah
// Ordinat(P) + deltaY }

POINT Point_MirrorOf (POINT P, boolean SbX);
// { Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu }
// { Jika SbX bernilai true, maka dicerminkan terhadap sumbu X }
// { Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y }

float Point_Jarak0 (POINT P);
// { Menghitung jarak P ke (0,0) }

float Point_Panjang (POINT P1, POINT P2);
// { Menghitung panjang garis yang dibentuk P1 dan P2 }
// { Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis.

void Point_Geser (POINT *P, point_infotype deltaX, point_infotype deltaY);
// { I.S. P terdefinisi }
// { F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY }

void Point_GeserKeSbX (POINT *P);
// { I.S. P terdefinisi }
// { F.S. P berada pada sumbu X dengan absis sama dengan absis semula. }
// { Proses : P digeser ke sumbu X. }
// { Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) }

void Point_GeserKeSbY (POINT *P);
// { I.S. P terdefinisi}
// { F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. }
// { Proses : P digeser ke sumbu Y. }
// { Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) }

void Point_Mirror (POINT *P, boolean SbX);
// { I.S. P terdefinisi }
// { F.S. P dicerminkan tergantung nilai SbX atau SbY }
// { Jika SbX true maka dicerminkan terhadap sumbu X }
// { Jika SbX false maka dicerminkan terhadap sumbu Y }

void Point_Putar (POINT *P, point_infotype Sudut);
// { I.S. P terdefinisi }
// { F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) }

#endif
