/* ADT JAM */

#ifndef JAM_C
#define JAM_C

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
#define Hour(J) (J).HH
#define Minute(J) (J).MM
#define Second(J) (J).SS

/*** FUNGSI LAIN ***/
JAM JamEarly (JAM J1, JAM J2);
// Menghasilkan jam yang lebih dulu di antara J1 dan J2
// Prekondisi : J1 != J2

#endif