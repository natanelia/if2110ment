//  ********** Definisi TYPE MATRIKS dengan indeks integer ********** }
//  Ukuran minimum dan maksimum baris dan kolom }
#include<stdio.h>
#include<math.h>
#include "boolean.h"
#include "matriks.h"
//typedef int indeks;
//#define BrsMin 1
//#define BrsMax 100
//#define KolMin 1
//#define KolMax 100
//typedef int el_type;
//typedef struct {
//    el_type Mem[BrsMax][KolMax];
//    int NBrsEff;
//    int NKolEff;
//} MATRIKS;

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

// ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** }
MATRIKS PlusMATRIKS(MATRIKS M1, MATRIKS M2)
// Prekondisi : M1 berukuran sama dengan M2 }
// Mengirim hasil penjumlahan matriks: M1 + M2 }
{
    MATRIKS M;
    indeks i,j;
    MakeMATRIKS(GetNBrsEff(M1),GetNKolEff(M1),&M);
    for (i=FirstIdxBrs(M1);i<=LastIdxBrs(M1);i++)
    {
        for (j=FirstIdxKol(M1);j<=LastIdxKol(M1);j++)
        {
            SetEl(&M,i,j,GetElmt(M1,i,j)+GetElmt(M2,i,j));
        }
    }
    return M;
}

MATRIKS MinMATRIKS(MATRIKS M1, MATRIKS M2)
// Prekondisi : M berukuran sama dengan M }
// Mengirim hasil pengurangan matriks: salinan M1 – M2 }
{
    MATRIKS M;
    indeks i,j;
    MakeMATRIKS(GetNBrsEff(M1),GetNKolEff(M1),&M);
    for (i=FirstIdxBrs(M1);i<=LastIdxBrs(M1);i++)
    {
        for (j=FirstIdxKol(M1);j<=LastIdxKol(M1);j++)
        {
            SetEl(&M,i,j,GetElmt(M1,i,j)-GetElmt(M2,i,j));
        }
    }
    return M;
}

MATRIKS KaliMATRIKS(MATRIKS M1, MATRIKS M2)
// Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 }
// Mengirim hasil perkalian matriks: salinan M1 * M2 }
{
    MATRIKS M;
    indeks i,j,k;
    el_type temp;
    MakeMATRIKS(GetNBrsEff(M1),GetNKolEff(M1),&M);
    for (i=FirstIdxBrs(M1);i<=LastIdxBrs(M1);i++)
    {
        for (j=FirstIdxKol(M1);j<=LastIdxKol(M1);j++)
        {
            temp=0;
            for (k=FirstIdxKol(M1);k<=LastIdxKol(M1);k++)
            {
                //Assuming Kol = Brs in multiplying (k = k)
                temp+=GetElmt(M1,i,k)*GetElmt(M2,k,j);
            }
            SetEl(&M,i,j,temp);
        }
    }
    return M;
}

MATRIKS KonsMATRIKSa(MATRIKS M, int X)
// Mengirim hasil perkalian setiap elemen M dengan X }
{
    MATRIKS M1;
    indeks i,j;
    MakeMATRIKS(GetNBrsEff(M),GetNKolEff(M),&M1);
    for (i=FirstIdxBrs(M);i<=LastIdxBrs(M);i++)
    {
        for (j=FirstIdxKol(M);j<=LastIdxKol(M);j++)
        {
            SetEl(&M1,i,j,GetElmt(M,i,j)*X);
        }
    }
    return M1;
}

void KonsMATRIKSb(MATRIKS *M, int K)
// Mengalikan setiap elemen M dengan K }
{
    indeks i,j;
    for (i=FirstIdxBrs(*M);i<=LastIdxBrs(*M);i++)
    {
        for (j=FirstIdxKol(*M);j<=LastIdxKol(*M);j++)
        {
            SetEl(M,i,j,GetElmt(*M,i,j)*K);
        }
    }
}

// ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** }
boolean IsEQ(MATRIKS M1, MATRIKS M2)
// Mengirimkan true jika M1 = M2, }
// yaitu NbElmtMATRIKS(M1) = NbElmtMATRIKS(M2) dan }
// untuk setiap i,j yang merupakan indeks baris dan kolom }
// M1(i,j) = M2(i,j) }
{
    boolean eq;
    indeks i,j;
    if (NbElmtMATRIKS(M1) != NbElmtMATRIKS(M2) || GetNBrsEff(M1) != GetNKolEff(M2) || GetNKolEff(M1) != GetNKolEff(M2)) {
        return false;
    } else {
        eq = true;
        i=FirstIdxBrs(M1);
        j=FirstIdxKol(M1);
        while (i<=LastIdxBrs(M1) && eq)
        {
            while (j<=LastIdxKol(M1) && eq)
            {
                if (GetElmt(M1,i,j) != GetElmt(M2,i,j))
                    eq = false;
                j++;
            }
            i++;
        }
        return eq;
    }
}

boolean NEQ(MATRIKS M1, MATRIKS M2)
// Mengirimkan true jika not strongEQ(M1,M2) }
{
    return !IsEQ(M1,M2);
}

boolean EQSize(MATRIKS M1, MATRIKS M2)
// Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 }
// yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) }
{
    return (GetNBrsEff(M1) == GetNBrsEff (M2) && GetNKolEff (M1) == GetNKolEff (M2));
}

boolean IsLess(MATRIKS M1, MATRIKS M2)
// Mengirimkan true jika ukuran efektif M1 < ukuran efektif M2 }
{
    return (NbElmtMATRIKS(M1) < NbElmtMATRIKS(M2));
}

// ********** Operasi lain ********** }
int NbElmtMATRIKS(MATRIKS M)
// Mengirimkan banyaknya elemen M }
{
    return GetNBrsEff(M)*GetNKolEff(M);
}

// ********** KELOMPOK TEST TERHADAP MATRIKS ********** }
boolean IsBujurSangkar(MATRIKS M)
//  Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama }
{
    return (GetNBrsEff(M) == GetNKolEff(M));
}

boolean IsSymetri(MATRIKS M)
//  Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) dan untuk
//setiap elemen M, M(i,j)=M(j,i) }
{
    boolean sim;
    indeks i,j;
    if (!IsBujurSangkar(M)) {
        return false;
    } else {
        sim = true;
        i=FirstIdxBrs(M);
        j=FirstIdxKol(M);
        while (i<=LastIdxBrs(M) && sim)
        {
            while (j<=LastIdxKol(M) && sim)
            {
                if (GetElmt(M,i,j) != GetElmt(M,j,i))
                    sim = false;
                j++;
            }
            i++;
        }
        return sim;
    }
}

boolean IsSatuan(MATRIKS M)
//  Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan setiap
//elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 }
{
    indeks i,j;
    boolean satuan = true;
    if (IsBujurSangkar(M))
    {
        for (i=FirstIdxBrs(M);i<=LastIdxBrs(M) && satuan;i++)
        {
            for (j=FirstIdxKol(M);j<=LastIdxKol(M) && satuan;j++)
            {
                if (i==j && GetElmt(M,i,j) != 1)
                    satuan = false;
                else if (i!=j && GetElmt(M,i,j) != 0)
                    satuan = false;
            }
        }
        return satuan;
    }
    else
    {
        return false;
    }
}

void Transpose(MATRIKS *M)
//  I.S. M terdefinisi dan IsBujursangkar(M) }
//  F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen
//M(j,i) }
{
    MATRIKS N;
    CopyMATRIKS(*M,&N);
    indeks i,j;


    SetBrsEff(M,GetNKolEff(N));
    SetKolEff(M,GetNBrsEff(N));

    for (i=FirstIdxBrs(N);i<=LastIdxBrs(N);i++)
    {
        for(j=FirstIdxKol(N);j<=LastIdxKol(N);j++)
        {
            SetEl(M,j,i,GetElmt(N,i,j));
        }
    }
}

/*boolean SearchArrayPoint(ARRAYPOINT P,POINT kursor)
//Mengecek apakah point merupakan member dari ARRAYPOINT P
{
		int i = 1 ;
		boolean found= false;

		while(i <= P.neff && !found ){
			if (IsPointSama(P.point[i],kursor)){
				found = true;
			}
			else{
				i++;
			}
		}
		return found;
}*/
