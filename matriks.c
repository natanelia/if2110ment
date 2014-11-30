//  ********** Definisi TYPE MATRIKS dengan indeks integer ********** }
//  Ukuran minimum dan maksimum baris dan kolom }
#include<stdio.h>
#include<math.h>
#include "boolean.h"
#include "matriks.h"


//  ********** DEFINISI PROTOTIPE PRIMITIF ********** }
//  *** Konstruktor membentuk MATRIKS *** }
void MakeMATRIKS(int NB, int NK, MATRIKS *M)
//  Membentuk sebuah MATRIKS “kosong” berukuran NB x NK di “ujung kiri” memori }
//  I.S. NB dan NK adalah valid untuk memori matriks yang dibuat }
//  F.S. Matriks M sesuai dengan definisi di atas terbentuk }
{
    M->NBrsEff = NB;
    M->NKolEff = NK;
}

//  *** Selektor "DUNIA MATRIKS" *** }
indeks GetIdxBrsMin()
//  Mengirimkan indeks baris minimum matriks apapun }
{
    return BrsMin;
}

indeks GetIdxKolMin()
//  Mengirimkan indeks kolom minimum matriks apapun }
{
    return KolMin;
}

indeks GetIdxBrsMax()
//  Mengirimkan indeks baris maksimum matriks apapun }
{
    return BrsMax;
}

indeks GetIdxKolMax()
//  Mengirimkan indeks kolom maksimum matriks apapun }
{
    return KolMax;
}

boolean IsIdxValid (int i, int j)
//  Mengirimkan true jika i, j adalah indeks yang valid }
{
    return (i >= BrsMin && i <= BrsMax && j>=KolMin && j<= KolMax);
}

//  *** Untuk sebuah matriks M yang terdefinisi: *** }
indeks FirstIdxBrs(MATRIKS M)
//  Mengirimkan indeks baris terkecil M }
{
    return GetIdxBrsMin();
}

indeks FirstIdxKol(MATRIKS M)
//  Mengirimkan indeks kolom terkecil M }
{
    return GetIdxKolMin();
}

indeks LastIdxBrs(MATRIKS M)
//  Mengirimkan indeks baris terbesar M }
{
    return M.NBrsEff;
}

indeks LastIdxKol(MATRIKS M)
//  Mengirimkan indeks kolom terbesar M }
{
    return M.NKolEff;
}

int GetNBrsEff(MATRIKS M)
//  Mengirimkan banyaknya baris efektif M }
{
    return M.NBrsEff;
}

int GetNKolEff(MATRIKS M)
//  Mengirimkan banyaknya kolom efektif M }
{
    return M.NKolEff;
}

boolean IsIdxEff(MATRIKS M, indeks i, indeks j)
//  Mengirimkan true jika i, j adalah indeks efektif bagi M }
{
    return (FirstIdxBrs(M) <= i && i <= LastIdxBrs(M) && FirstIdxKol(M) <= j && j <= LastIdxKol(M));
}

el_type GetElmt(MATRIKS M, indeks i, indeks j)
//  Mengirimkan elemen M dg nomor baris i dan nomor kolom j }
{
    return M.Mem[i][j];
}

el_type GetElmtDiagonal(MATRIKS M, indeks i)
// Mengirimkan elemen M(i,i) }
{
    return M.Mem[i][i];
}

// *** Operasi mengubah nilai elemen matriks: Set / Assign *** }
void SetBrsEff(MATRIKS *M, int NB)
// I.S. M sudah terdefinisi }
// F.S. Nilai M.BrsEff diisi dengan NB, }
{
    M->NBrsEff = NB;
}

void SetKolEff(MATRIKS *M, int NK)
// I.S. M sudah terdefinisi }
// F.S. Nilai M.NKolEff diisi dengan NK }
{
    M->NKolEff = NK;
}

void SetEl(MATRIKS *M, int i, int j, el_type X)
// I.S. M sudah terdefinisi }
// F.S. M(i,j) bernilai X }
// Proses: Mengisi M(i,j) dengan X }
{
    M->Mem[i][j] = X;
}


// ********** Assignment MATRIKS ********** }
void CopyMATRIKS(MATRIKS MIn, MATRIKS *MHsl)
// Melakukan assignment MHsl ← Min }
{
    indeks i,j;
    MakeMATRIKS(GetNBrsEff(MIn), GetNKolEff(MIn), MHsl);
    for (i=FirstIdxBrs(MIn);i<=LastIdxBrs(MIn);i++)
    {
        for (j=FirstIdxKol(MIn);j<=LastIdxKol(MIn);j++)
        {
            SetEl(MHsl, i, j, GetElmt(MIn,i,j));
        }
    }
}

// ********** KELOMPOK BACA/TULIS ********** }
void BacaMATRIKS(MATRIKS *M, int NB, int NK)
// I.S. IsIdxValid(NB,NK) }
// F.S. M terdefinisi nilai elemen efektifnya, dan berukuran NB x NK }
// Melakukan MakeMatriks(M,NB,NK) dan mengisi nilai efektifnya }
// dari pembacaan dengan traversal per baris }
{
    indeks i,j;
    el_type X;
    if (IsIdxValid(NB,NK))
    {
        MakeMATRIKS(NB,NK,M);
        for (i=FirstIdxBrs(*M);i<=LastIdxBrs(*M);i++)
        {
            for (j=FirstIdxKol(*M);j<=LastIdxKol(*M);j++)
            {
                scanf("%c",&X);
                SetEl(M,i,j,X);
            }
        }
    } else {
        printf("Nilai efektif baris atau/dan kolom salah!\n");
    }
}

void TulisMATRIKS(MATRIKS M)
// I.S. M terdefinisi }
// F.S. Sama dengan I.S, dan nilai M(i,j) ditulis ke layar}
// Menulis nilai setiap indeks dan elemen M ke layar dengan traversal per baris }
{
    indeks i,j;
    for (i=FirstIdxBrs(M);i<=LastIdxBrs(M);i++)
    {
        for (j=FirstIdxKol(M);j<LastIdxKol(M);j++)
        {
            printf("%c ",GetElmt(M,i,j));
        }
        printf("%c\n",GetElmt(M,i,j));
    }
    printf("\n");
}

int SearchArrayPoint(ARRAYPOINT P,POINT kursor)
//Mengecek apakah point merupakan member dari ARRAYPOINT P
{
		int i = 1 ;
		boolean found= false;

		while(i <= P.neff && !found ) {
			if (IsPointSama(P.point[i],kursor)){
				found = true;
			}
			else {
				i++;
			}
		}

		if (found)
            return i;
        else
            return -1;
}
