//  ********** Definisi TYPE MATRIKS dengan indeks integer ********** }
//  Ukuran minimum dan maksimum baris dan kolom }
#include<stdio.h>
#include "point.h"
#include "boolean.h"

typedef int indeks;
#define BrsMin 1
#define BrsMax 100
#define KolMin 1
#define KolMax 100
typedef char el_type;
typedef struct {
    el_type Mem[BrsMax+1][KolMax+1];
    int NBrsEff;
    int NKolEff;
} MATRIKS;

typedef struct {
    POINT point[17];
    int neff;
} ARRAYPOINT;

//  NBrsEff ≥ 1 dan NKolEff ≥ 1 }
//  Memori matriks yang dipakai selalu di "ujung kiri atas" }
//  ********** DEFINISI PROTOTIPE PRIMITIF ********** }
//  *** Konstruktor membentuk MATRIKS *** }
void MakeMATRIKS(int NB, int NK, MATRIKS *M);
//  Membentuk sebuah MATRIKS “kosong” berukuran NB x NK di “ujung kiri” memori }
//  I.S. NB dan NK adalah valid untuk memori matriks yang dibuat }
//  F.S. Matriks M sesuai dengan definisi di atas terbentuk }

//  *** Selektor "DUNIA MATRIKS" *** }
indeks GetIdxBrsMin();
//  Mengirimkan indeks baris minimum matriks apapun }

indeks GetIdxKolMin();
//  Mengirimkan indeks kolom minimum matriks apapun }

indeks GetIdxBrsMax();
//  Mengirimkan indeks baris maksimum matriks apapun }

indeks GetIdxKolMax();
//  Mengirimkan indeks kolom maksimum matriks apapun }

boolean IsIdxValid (int i, int j);
//  Mengirimkan true jika i, j adalah indeks yang valid }
//  *** Untuk sebuah matriks M yang terdefinisi: *** }

indeks FirstIdxBrs(MATRIKS M);
//  Mengirimkan indeks baris terkecil M }

indeks FirstIdxKol(MATRIKS M);
//  Mengirimkan indeks kolom terkecil M }

indeks LastIdxBrs(MATRIKS M);
//  Mengirimkan indeks baris terbesar M }

indeks LastIdxKol(MATRIKS M);
//  Mengirimkan indeks kolom terbesar M }

int GetNBrsEff(MATRIKS M);
//  Mengirimkan banyaknya baris efektif M }

int GetNKolEff(MATRIKS M);
//  Mengirimkan banyaknya kolom efektif M }

boolean IsIdxEff(MATRIKS M, indeks i, indeks j);
//  Mengirimkan true jika i, j adalah indeks efektif bagi M }

el_type GetElmt(MATRIKS M, indeks i, indeks j);
//  Mengirimkan elemen M dg nomor baris i dan nomor kolom j }

el_type GetElmtDiagonal(MATRIKS M, indeks i);
// Mengirimkan elemen M(i,i) }

// *** Operasi mengubah nilai elemen matriks: Set / Assign *** }
void SetBrsEff(MATRIKS *M, int NB);
// I.S. M sudah terdefinisi }
// F.S. Nilai M.BrsEff diisi dengan NB, }

void SetKolEff(MATRIKS *M, int NK);
// I.S. M sudah terdefinisi }
// F.S. Nilai M.NKolEff diisi dengan NK }

void SetEl(MATRIKS *M, int i, int j, el_type X);
// I.S. M sudah terdefinisi }
// F.S. M(i,j) bernilai X }
// Proses: Mengisi M(i,j) dengan X }


// ********** Assignment MATRIKS ********** }
void CopyMATRIKS(MATRIKS MIn, MATRIKS *MHsl);
// Melakukan assignment MHsl ← Min }

// ********** KELOMPOK BACA/TULIS ********** }
void BacaMATRIKS(MATRIKS *M, int NB, int NK);
// I.S. IsIdxValid(NB,NK) }
// F.S. M terdefinisi nilai elemen efektifnya, dan berukuran NB x NK }
// Melakukan MakeMatriks(M,NB,NK) dan mengisi nilai efektifnya }
// dari pembacaan dengan traversal per baris }
void TulisMATRIKS(MATRIKS M);
// I.S. M terdefinisi }
// F.S. Sama dengan I.S, dan nilai M(i,j) ditulis ke layar}
// Menulis nilai setiap indeks dan elemen M ke layar dengan traversal per baris }

int SearchArrayPoint(ARRAYPOINT P,POINT kursor);
//Mengecek apakah point merupakan member dari ARRAYPOINT P
