/* ADT WAKTU */

#ifndef waktu_h
#define waktu_h
#include "boolean.h"
#include "jam.h"
#include "tanggal.h"

/*** DEFINISI DAN SPESIFIKASI TYPE TANGGAL ***/
typedef struct {
	TANGGAL T;
	JAM J;
} WAKTU;

/*** Konstruktor: Membentuk sebuah WAKTU dari komponen-komponennya ***/
WAKTU MakeWAKTU (TANGGAL TT, JAM JJ);
// Membentuk sebuah WAKTU dari komponen-komponennya yang valid
// Prekondisi : TT, JJ valid untuk membentuk WAKTU

/*** Selektor ***/
#define Day(W) (W).T.DD
#define Month(W) (W).T.MM
#define Year(W) (W).T.YY
#define Hour(W) (W).J.HH
#define Minute(W) (W).J.MM
#define Second(W) (W).J.SS

/*** FUNGSI LAIN ***/
void PrintWaktu (WAKTU W);
// Mencetak waktu di layar dengan format DD/MM/YYYY HH:MM:SS
boolean IsWaktuEarly (WAKTU W1, WAKTU W2);
// Menghasilkan true jika W1 lebih awal dari W2
// Asumsi W1 != W2

#endif
