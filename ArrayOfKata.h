/* File : ArrayOfKata.h */

#ifndef arrayofkata_h
#define arrayofkata_h
#include "boolean.h"
#include "mesinkata1.h"

/* Kamus Umum */
#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999  /* indeks tak terdefinisi */

/* Definisi elemen dan koleksi objek */
typedef int IdxType; /* type indeks */
typedef Kata ElType; /* type elemen tabel */
typedef struct {
	ElType TI[IdxMax+1];
	int Neff;
} TabK;

/* KONSTRUKTOR */
void MakeAKEmpty (TabK *T);
/*	I.S. sembarang
	  F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* SELEKTOR */
#define Elmt(T,i) (T).TI[i]

int NbElmt (TabK T);
/* Mengirimkan banyaknya elemen efektif tabel. Mengirimkan nol jika tabel kosong */
int MaxNbEl (TabK T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
void SetNeff (TabK *T, IdxType N);
/*	I.S. T terdefinisi, sembarang
	  F.S. Nilai indeks efektif T bernilai N
	  Mengeset nilai indeks elemen efektif sehingga bernilai N */
/* Selektor INDEKS */
IdxType GetFirstIdx (TabK T);
/*	Prekondisi : Tabel T tidak kosong
  	Mengirimkan indeks elemen pertama */
IdxType GetLastIdx (TabK T);
/*	Prekondisi : Tabel T tidak kosong
  	Mengirimkan indeks elemen terakhir */

/* TEST KOSONG/PENUH */
boolean IsAKEmpty (TabK T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
boolean IsAKFull (TabK T);
/*Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* FUNGSI DAN PROSEDUR LAIN */
boolean SearchB (TabK T, ElType X);
/*	Search apakah ada elemen tabel T yang bernilai X
  	Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
void AddAsLastEl (TabK *T, ElType X);
/*	Menambahkan X sebagai elemen terakhir tabel
  	I.S. Tabel boleh kosong, tetapi tidak penuh
  	F.S. X adalah elemen terakhir T yang baru
	  Proses : Menambahkan sebagai elemen ke-i yang baru */

#endif
