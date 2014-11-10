/* ADT TANGGAL */

#include "tanggal.h"

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
	return((Day(T1)==Day(T2))&&(Month(T1)==Month(T2))&&(Year(T1)==Year(T2)));
}
TANGGAL TanggalEarly (TANGGAL T1, TANGGAL T2)
// Menghasilkan tanggal yang lebih dulu di antara T1 dan T2
// Prekondisi : T1 != T2
{
	if (Year(T1)<Year(T2))
		return (T1);
	else if (Year(T1)>Year(T2))
			return (T2);
		 else
			if (Month(T1)<Month(T2))
				return (T1);
			else if (Month(T1)>Month(T2))
					return (T2);
				 else
					if (Day(T1)<Day(T2))
						return (T1);
					else
						return (T2);
}