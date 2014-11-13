/* ADT JAM */

#include "jam.h"

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
JAM JamEarly (JAM J1, JAM J2)
// Menghasilkan jam yang lebih dulu di antara J1 dan J2
// Prekondisi : J1 != J2
{
	if (Hour(J1)<Hour(J2))
		return (J1);
	else if (Hour(J1)>Hour(J2))
			return (J2);
		 else
			if (Minute(J1)<Minute(J2))
				return (J1);
			else if (Minute(J1)>Minute(J2))
					return (J2);
				 else
					if (Second(J1)<Second(J2))
						return (J1);
					else
						return (J2);
}