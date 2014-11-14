/* ADT WAKTU */

#include "boolean.h"
#include "waktu.h"
#include <stdio.h>


/*** Konstruktor: Membentuk sebuah WAKTU dari komponen-komponennya ***/
WAKTU MakeWAKTU (TANGGAL TT, JAM JJ)
// Membentuk sebuah WAKTU dari komponen-komponennya yang valid
// Prekondisi : TT, JJ valid untuk membentuk WAKTU
{
	/* KAMUS LOKAL */
	WAKTU W;
	
	/* ALGORITMA */
	W.T=TT;
	W.J=JJ;
	return(W);
}


/*** FUNGSI LAIN ***/
void PrintWaktu (WAKTU W)
// Mencetak waktu di layar dengan format DD/MM/YYYY HH:MM:SS
{
	PrintTanggal(W.T);
	printf(" ");
	PrintJam(W.J);
}
boolean IsWaktuEarly (WAKTU W1, WAKTU W2)
// Menghasilkan true jika W1 lebih awal dari W2
// Asumsi W1 != W2
{
	if (IsTanggalEqual(W1.T,W2.T))
	{	if (IsJamEqual(W1.J,JamEarly(W1.J,W2.J)))
			return(true);
		else
			return(false);
	}
	else
	{	if (IsTanggalEqual(W1.T,TanggalEarly(W1.T,W2.T)))
			return(true);
		else
			return(false);
	}
}
