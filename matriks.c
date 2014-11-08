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
                scanf("%lf",&X);
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
// yaitu NBElmt(M1) = NBElmt(M2) dan }
// untuk setiap i,j yang merupakan indeks baris dan kolom }
// M1(i,j) = M2(i,j) }
{
    boolean eq;
    indeks i,j;
    if (NbElmt(M1) != NbElmt(M2) || GetNBrsEff(M1) != GetNKolEff(M2) || GetNKolEff(M1) != GetNKolEff(M2)) {
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
    return (NbElmt(M1) < NbElmt(M2));
}

// ********** Operasi lain ********** }
int NbElmt(MATRIKS M)
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

boolean IsSparse(MATRIKS M)
//  Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
//hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 }
{
    el_type sum = 0;
    indeks i,j;
    for (i=FirstIdxBrs(M);i<=LastIdxBrs(M);i++)
    {
        for (j=FirstIdxKol(M);j<=LastIdxKol(M);j++)
        {
            if (GetElmt(M,i,j) != 0)
            {
                sum+=1;
            }
        }
    }
    return (sum/NbElmt(M) <= 0.05);
}

MATRIKS InversN(MATRIKS M)
//  Menghasilkan salinan M dg setiap elemen "di-invers", yaitu dinegasikan }
{
    MATRIKS M1;
    indeks i,j;
    MakeMATRIKS(GetNBrsEff(M),GetNKolEff(M),&M1);
    for (i=FirstIdxBrs(M);i<=LastIdxBrs(M);i++)
    {
        for (j=FirstIdxKol(M);j<=LastIdxKol(M);j++)
        {
            SetEl(&M1,i,j,(-1)*GetElmt(M,i,j));
        }
    }
    return M1;
}

MATRIKS InversM(MATRIKS M)
//  Menghasilkan salinan M dg setiap elemen "di-invers", yaitu di-invers sesuai
//dengan aturan inversi matriks }
{
    indeks i,j,k,l;
    indeks idMax;
    el_type nilMax,pengali;
    el_type tempRow[GetNKolEff(M)*2+1]; //Untuk operasi penukaran baris
    MATRIKS MW;
    boolean inversable = true;

    /* ALGORITMA */
    MakeMATRIKS(GetNBrsEff(M),GetNKolEff(M)*2,&MW);
    if (IsBujurSangkar(M))
    {
        //Isi MW dengan isi matriks M
        for (i=FirstIdxBrs(M);i<=LastIdxBrs(M);i++)
        {
            for (j=FirstIdxKol(M);j<=LastIdxKol(M);j++)
                SetEl(&MW,i,j,GetElmt(M,i,j));
        }
        //Isi sebelah kanan MW dengan matriks identitas
        for (i=FirstIdxBrs(M);i<=LastIdxBrs(M);i++)
        {
            for (j=LastIdxKol(M)+1;j<=LastIdxKol(M)*2;j++)
                if (i==j-LastIdxKol(M))
                    SetEl(&MW,i,j,1);
                else
                    SetEl(&MW,i,j,0);
        }
//        printf("PHASE 1\n");
//        TulisMATRIKS(MW);

        //Lakukan operasi gaussian elimination
        i=FirstIdxBrs(MW);
        j=FirstIdxKol(MW);
        while (i<=LastIdxBrs(MW) && j<=LastIdxKol(MW) && inversable)
        {
            //Selalu pindahkan row dengan awalan maksimal ke baris awal
            //Cari elemen kolom dengan nilai maksimal
            nilMax=GetElmt(MW,i,j);
            idMax = i;
            for (k=i+1; k<=LastIdxBrs(MW);k++)
            {
                //supaya aman di absolute aja
                if (GetElmt(MW,k,j) > nilMax)
                {
                    nilMax=GetElmt(MW,k,j);
                    idMax = k;
                }
            }
            //Hindari satu kolom 0 semua
            if (nilMax != 0)
            {
                //lakukan penukaran row dengan awalan maksimal ke baris awal
                if (i!=idMax)
                {
                    for(l=FirstIdxKol(MW);l<=LastIdxKol(MW);l++)
                    {
                        tempRow[l] = GetElmt(MW,i,l);
                    }

                    for(l=FirstIdxKol(MW);l<=LastIdxKol(MW);l++)
                    {
                        SetEl(&MW,i,l,GetElmt(MW,idMax,l));
                    }

                    for(l=FirstIdxKol(MW);l<=LastIdxKol(MW);l++)
                    {
                        SetEl(&MW,idMax,l,tempRow[l]);
                    }
                }
//                printf("PHASE 2\n");
//                TulisMATRIKS(MW);

                //buatlah awalan row tersebut menjadi 1 dengan membaginya dengan bilangan itu sendiri
                for (l=FirstIdxKol(MW);l<=LastIdxKol(MW);l++)
                {
                    SetEl(&MW,i,l,(GetElmt(MW,i,l)/nilMax));
                }

//                printf("PHASE 3\n");
//                TulisMATRIKS(MW);

                //kita perlu membuat nilai awal row selain row tersebut menjadi 0 (dengan batasan row matriks M)
                for (k=FirstIdxBrs(MW);k<=LastIdxBrs(MW);k++)
                {
                    if (k!=i)
                    {
                        pengali=GetElmt(MW,k,j);
                        for (l=FirstIdxKol(MW);l<=LastIdxKol(MW);l++)
                        {
                            SetEl(&MW,k,l, GetElmt(MW,k,l)-(GetElmt(MW,i,l)*pengali));
                            if (GetElmt(MW,k,l) < 0.0000000001 && GetElmt(MW,k,l) > -0.0000000001)
                            {
                                SetEl(&MW,k,l,0);
                            }
                        }
                    }
                }
//                printf("PHASE 4\n");
//                TulisMATRIKS(MW);


                //Berpindah secara diagonal
                i++;
            } else {
                inversable=false;
            }
            j++;
        }
        boolean satuan = true;
        for (i=FirstIdxBrs(M);i<=LastIdxBrs(M) && satuan;i++)
        {
            for (j=FirstIdxKol(MW);j<=LastIdxKol(M) && satuan;j++)
            {
                if (i==j && GetElmt(MW,i,j) != 1)
                    satuan = false;
                else if (i!=j && (GetElmt(M,i,j) >= 0.0000000001 && GetElmt(M,i,j) <= -0.00000000001))
                    satuan = false;
            }
        }
        if (satuan && inversable) {
            for (i=FirstIdxBrs(MW);i<=LastIdxBrs(MW);i++)
            {
                for (j=FirstIdxKol(M);j<=LastIdxKol(M);j++)
                {
                    SetEl(&MW,i,j,GetElmt(MW,i,LastIdxKol(M)+j));
                }
            }
            SetKolEff(&MW,GetNKolEff(M));
        } else {
            printf("Matriks tidak memiliki invers!\n");
            for (i=FirstIdxBrs(MW);i<=LastIdxBrs(MW);i++)
            {
                for (j=FirstIdxKol(M);j<=LastIdxKol(M);j++)
                {
                    SetEl(&MW,i,j,NAN);
                }
            }
            SetKolEff(&MW,GetNKolEff(M));
        }
    } else {

            printf("Matriks tidak memiliki invers!\n");
            for (i=FirstIdxBrs(MW);i<=LastIdxBrs(MW);i++)
            {
                for (j=FirstIdxKol(M);j<=LastIdxKol(M);j++)
                {
                    SetEl(&MW,i,j,NAN);
                }
            }
            SetKolEff(&MW,GetNKolEff(M));
    }

    return MW;
}

el_type Determinan (MATRIKS M)
//  Prekondisi: IsBujurSangkar(M) }
//  Menghitung nilai determinan M }
{
    indeks i,j,k,l;
    indeks idMax;
    el_type nilMax,pengali;
    el_type tempRow[GetNKolEff(M)*2+1]; //Untuk operasi penukaran baris
    MATRIKS MW;
    el_type det = 0;

    /* ALGORITMA */
    MakeMATRIKS(GetNBrsEff(M),GetNKolEff(M)*2,&MW);
    if (IsBujurSangkar(M))
    {
        det = 1;
        //Isi MW dengan isi matriks M
        for (i=FirstIdxBrs(M);i<=LastIdxBrs(M);i++)
        {
            for (j=FirstIdxKol(M);j<=LastIdxKol(M);j++)
                SetEl(&MW,i,j,GetElmt(M,i,j));
        }
        //Isi sebelah kanan MW dengan matriks identitas
        for (i=FirstIdxBrs(M);i<=LastIdxBrs(M);i++)
        {
            for (j=LastIdxKol(M)+1;j<=LastIdxKol(M)*2;j++)
                if (i==j-LastIdxKol(M))
                    SetEl(&MW,i,j,1);
                else
                    SetEl(&MW,i,j,0);
        }
//        printf("PHASE 1\n");
//        TulisMATRIKS(MW);

        //Lakukan operasi gaussian elimination
        i=FirstIdxBrs(MW);
        j=FirstIdxKol(MW);
        while (i<=LastIdxBrs(MW) && j<=LastIdxKol(MW))
        {
            //Selalu pindahkan row dengan awalan maksimal ke baris awal
            //Cari elemen kolom dengan nilai maksimal
            nilMax=GetElmt(MW,i,j);
            idMax = i;
            for (k=i+1; k<=LastIdxBrs(MW);k++)
            {
                //supaya aman di absolute aja
                if (GetElmt(MW,k,j) > nilMax)
                {
                    nilMax=GetElmt(MW,k,j);
                    idMax = k;
                }
            }
            //Hindari satu kolom 0 semua
            if (nilMax != 0)
            {
                //lakukan penukaran row dengan awalan maksimal ke baris awal
                if (i!=idMax)
                {
                    for(l=FirstIdxKol(MW);l<=LastIdxKol(MW);l++)
                    {
                        tempRow[l] = GetElmt(MW,i,l);
                    }

                    for(l=FirstIdxKol(MW);l<=LastIdxKol(MW);l++)
                    {
                        SetEl(&MW,i,l,GetElmt(MW,idMax,l));
                    }

                    for(l=FirstIdxKol(MW);l<=LastIdxKol(MW);l++)
                    {
                        SetEl(&MW,idMax,l,tempRow[l]);
                    }
                    det = -det;
                }
//                printf("PHASE 2\n");
//                TulisMATRIKS(MW);

                //buatlah awalan row tersebut menjadi 1 dengan membaginya dengan bilangan itu sendiri
                for (l=FirstIdxKol(MW);l<=LastIdxKol(MW);l++)
                {
                    SetEl(&MW,i,l,(GetElmt(MW,i,l)/nilMax));
                }
                det*=nilMax;

//                printf("PHASE 3\nDETERMINAN=%.2f\n",det);
//                TulisMATRIKS(MW);

                //kita perlu membuat nilai awal row selain row tersebut menjadi 0 (dengan batasan row matriks M)
                for (k=FirstIdxBrs(MW);k<=LastIdxBrs(MW);k++)
                {
                    if (k>i)
                    {
                        pengali=GetElmt(MW,k,j);
                        for (l=FirstIdxKol(MW);l<=LastIdxKol(MW);l++)
                        {
                            SetEl(&MW,k,l, GetElmt(MW,k,l)-(GetElmt(MW,i,l)*pengali));
                        }
                    }
                }
//                printf("PHASE 4\n");
//                TulisMATRIKS(MW);


                //Berpindah secara diagonal
                i++;
            } else {
                return 0;
            }
            j++;
        }
        return det;
    }
}

void InversN1(MATRIKS *M)
//  I.S. M terdefinisi }
//  F.S. M di-invers, yaitu setiap elemennya dinegasikan }
{
    CopyMATRIKS(InversN(*M),M);
}

void InversM1(MATRIKS *M)
//  I.S. M terdefinisi }
//  F.S. M "di-invers", yaitu diproses sesuai dengan aturan invers matriks }
{
    CopyMATRIKS(InversM(*M),M);
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
