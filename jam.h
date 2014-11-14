/* ADT JAM */

#ifndef JAM_C
#define JAM_C
#include "boolean.h"

/* Definisi TYPE JAM <HH:MM:SS> */
typedef struct {
	int HH;
	int MM;
	int SS;
} JAM;

/*** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya ***/
JAM MakeJAM (int HH, int MM, int SS);
// Membentuk sebuah JAM dari komponen-komponennya yang valid
// Prekondisi : HH, MM, SS valid untuk membentuk JAM

/*** Selektor ***/
#define Jam(J) (J).HH
#define Menit(J) (J).MM
#define Detik(J) (J).SS

/*** FUNGSI LAIN ***/
boolean IsJamEqual (JAM J1, JAM J2);
// Menghasilkan true jika J1 = J2
JAM JamEarly (JAM J1, JAM J2);
// Menghasilkan jam yang lebih dulu di antara J1 dan J2
// Prekondisi : J1 != J2
void PrintJam (JAM J);
// Menampilkan jam pada layar dengan format HH:MM:SS

#endif
