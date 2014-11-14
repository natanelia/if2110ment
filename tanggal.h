/* ADT TANGGAL */

#ifndef TANGGAL_C
#define TANGGAL_C
#include "boolean.h"

/*** DEFINISI DAN SPESIFIKASI TYPE TANGGAL ***/
typedef struct {
	int DD;
	int MM;
	int YY;
} TANGGAL;

/*** SELEKTOR ***/
#define Hari(T) (T).DD
#define Bulan(T) (T).MM
#define Tahun(T) (T).YY

/*** KONSTRUKTOR ***/
TANGGAL MakeTANGGAL (int h, int b, int t);
// Membentuk TANGGAL dari tanggal h, bulan b, dan tahun t.
// Prekondisi : h, b, t dapat membentuk TANGGAL yang valid.

/*** FUNGSI LAIN ***/
boolean IsTanggalEqual (TANGGAL T1, TANGGAL T2);
// Menghasilkan true jika T1 = T2
TANGGAL TanggalEarly (TANGGAL T1, TANGGAL T2);
// Menghasilkan tanggal yang lebih dulu di antara T1 dan T2
// Prekondisi : T1 != T2
void PrintTanggal (TANGGAL T);
// Menampilkan tanggal pada layar dengan format DD/MM/YYYY

#endif
