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

// ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** }
MATRIKS PlusMATRIKS(MATRIKS M1, MATRIKS M2);
// Prekondisi : M1 berukuran sama dengan M2 }
// Mengirim hasil penjumlahan matriks: M1 + M2 }

MATRIKS MinMATRIKS(MATRIKS M1, MATRIKS M2);
// Prekondisi : M berukuran sama dengan M }
// Mengirim hasil pengurangan matriks: salinan M1 – M2 }

MATRIKS KaliMATRIKS(MATRIKS M1, MATRIKS M2);
// Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 }
// Mengirim hasil perkalian matriks: salinan M1 * M2 }

MATRIKS KonsMATRIKSa(MATRIKS M, int X);
// Mengirim hasil perkalian setiap elemen M dengan X }

void KonsMATRIKSb(MATRIKS *M, int K);
// Mengalikan setiap elemen M dengan K }

// ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** }
boolean IsEQ(MATRIKS M1, MATRIKS M2);
// Mengirimkan true jika M1 = M2, }
// yaitu NBElmt(M1) = NBElmt(M2) dan }
// untuk setiap i,j yang merupakan indeks baris dan kolom }
// M1(i,j) = M2(i,j) }

boolean NEQ(MATRIKS M1, MATRIKS M2);
// Mengirimkan true jika not strongEQ(M1,M2) }

boolean EQSize(MATRIKS M1, MATRIKS M2);
// Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 }
// yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) }

boolean IsLess(MATRIKS M1, MATRIKS M2);
// Mengirimkan true jika ukuran efektif M1 < ukuran efektif M2 }

// ********** Operasi lain ********** }
int NbElmtMATRIKS(MATRIKS M);
// Mengirimkan banyaknya elemen M }

// ********** KELOMPOK TEST TERHADAP MATRIKS ********** }
boolean IsBujurSangkar(MATRIKS M);
//  Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama }

boolean IsSymetri(MATRIKS M);
//  Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) dan untuk
//setiap elemen M, M(i,j)=M(j,i) }

boolean IsSatuan(MATRIKS M);
//  Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan setiap
//elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 }

boolean IsSparse(MATRIKS M);
//  Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
//hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 }

MATRIKS InversN(MATRIKS M);
//  Menghasilkan salinan M dg setiap elemen "di-invers", yaitu dinegasikan }

MATRIKS InversM(MATRIKS M);
//  Menghasilkan salinan M dg setiap elemen "di-invers", yaitu di-invers sesuai
//dengan aturan inversi matriks }

el_type Determinan (MATRIKS M);
//  Prekondisi: IsBujurSangkar(M) }
//  Menghitung nilai determinan M }

void InversN1(MATRIKS *M);
//  I.S. M terdefinisi }
//  F.S. M di-invers, yaitu setiap elemennya dinegasikan }

void InversM1(MATRIKS *M);
//  I.S. M terdefinisi }
//  F.S. M "di-invers", yaitu diproses sesuai dengan aturan invers matriks }

void Transpose(MATRIKS *M);
//  I.S. M terdefinisi dan IsBujursangkar(M) }
//  F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen
//M(j,i) }

//boolean SearchArrayPoint(ARRAYPOINT P,POINT point);
//Mengecek apakah point merupakan member dari ARRAYPOINT P
