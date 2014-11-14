/* ADT JAM */

#include "jam.h"
#include "boolean.h"
#include <stdio.h>

/*** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya ***/
JAM MakeJAM (int HH, int MM, int SS)
// Membentuk sebuah JAM dari komponen-komponennya yang valid
// Prekondisi : HH, MM, SS valid untuk membentuk JAM
{
	/* KAMUS LOKAL */
	JAM J;
	
	/* ALGORITMA */
	J.HH=HH;
	J.MM=MM;
	J.SS=SS;
	return(J);
}

/*** FUNGSI LAIN ***/
boolean IsJamEqual (JAM J1, JAM J2)
// Menghasilkan true jika J1 = J2
{
	return((Jam(J1)==Jam(J2))&&(Menit(J1)==Menit(J2))&&(Detik(J1)==Detik(J2)));
}
JAM JamEarly (JAM J1, JAM J2)
// Menghasilkan jam yang lebih dulu di antara J1 dan J2
// Prekondisi : J1 != J2
{
	if (Jam(J1)<Jam(J2))
		return (J1);
	else if (Jam(J1)>Jam(J2))
			return (J2);
		 else
			if (Menit(J1)<Menit(J2))
				return (J1);
			else if (Menit(J1)>Menit(J2))
					return (J2);
				 else
					if (Detik(J1)<Detik(J2))
						return (J1);
					else
						return (J2);
}
void PrintJam (JAM J)
// Menampilkan jam pada layar dengan format HH:MM:SS
{
	printf("%02i:%02i:%02i",Jam(J),Menit(J),Detik(J));
}
