/* ADT TANGGAL */

#include "tanggal.h"
#include "boolean.h"
#include <stdio.h>

/*** KONSTRUKTOR ***/
TANGGAL MakeTANGGAL (int h, int b, int t)
// Membentuk TANGGAL dari tanggal h, bulan b, dan tahun t.
// Prekondisi : h, b, t dapat membentuk TANGGAL yang valid.
{
	/* KAMUS LOKAL */
	TANGGAL T;
	
	/* ALGORITMA */
	T.DD=h;
	T.MM=b;
	T.YY=t;
	return(T);
}

/*** FUNGSI LAIN ***/
boolean IsTanggalEqual (TANGGAL T1, TANGGAL T2)
// Menghasilkan true jika T1 = T2
{
	return((Hari(T1)==Hari(T2))&&(Bulan(T1)==Bulan(T2))&&(Tahun(T1)==Tahun(T2)));
}
TANGGAL TanggalEarly (TANGGAL T1, TANGGAL T2)
// Menghasilkan tanggal yang lebih dulu di antara T1 dan T2
// Prekondisi : T1 != T2
{
	if (Tahun(T1)<Tahun(T2))
		return (T1);
	else if (Tahun(T1)>Tahun(T2))
			return (T2);
		 else
			if (Bulan(T1)<Bulan(T2))
				return (T1);
			else if (Bulan(T1)>Bulan(T2))
					return (T2);
				 else
					if (Hari(T1)<Hari(T2))
						return (T1);
					else
						return (T2);
}
void PrintTanggal (TANGGAL T)
// Menampilkan tanggal pada layar dengan format DD/MM/YYYY
{
	printf("%02i/%02i/%d",Hari(T),Bulan(T),Tahun(T));
}
