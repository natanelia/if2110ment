#include <stdio.h>
#include "boolean.h"
#include "matriks.h"
#include <string.h>

/*void Baca(MATRIKS *M)
{
    int NB, NK;
    do
    {
        printf("Masukkan nilai efektif matriks!\n");
        printf("Baris Efektif: "); scanf("%d",&NB);
        printf("Kolom Efektif: "); scanf("%d",&NK);

        if (!IsIdxValid(NB,NK))
            printf("Entah nilai efektif baris [%d..%d] atau kolomnya [%d..%d] salah, bang.\n", GetIdxBrsMin(),GetIdxBrsMax(),GetIdxKolMin(),GetIdxKolMax());
    }
    while (!IsIdxValid(NB,NK));
    BacaMATRIKS(M,NB,NK);
}

int main()
{
    MATRIKS M1,M2,M3;
    indeks i,j;

    Baca(&M1);

    Baca(&M2);

    printf("\nMatriks M1\n");
    TulisMATRIKS(M1);


    printf("\n-- Uji Transpose M1\n");
    Transpose(&M1);
    TulisMATRIKS(M1);

    printf("Matriks Invers M1\n");
    TulisMATRIKS(InversM(M1));

    printf("Determinan: %.2f\n",Determinan(M1));

    printf("\n////Basic Selector\\\\\n");
    printf("First Index Baris = %d\nFirst Index Kolom = %d\nLast Index Baris = %d\nLast Index Kolom = %d\n",FirstIdxBrs(M1),FirstIdxKol(M1),LastIdxBrs(M1),LastIdxKol(M1));
    printf("Banyak baris efektif = %d\nBanyak kolom efektif = %d\n", GetNBrsEff(M1), GetNKolEff(M1));

    printf("\nMasukkan index cek kolom efektif [i,j]: "); scanf("%d %d",&i,&j);
    if (IsIdxEff(M1,i,j))
        printf("Indeks efektif.\n");
    else
        printf("Bukan indeks efektif!\n");

    printf("\nBerikut adalah elemen diagonal matriks:\n");
    for (i=FirstIdxBrs(M1);i<=LastIdxBrs(M1);i++)
    {
        printf("%.2lf ",GetElmtDiagonal(M1,i));
    }

    printf("\n\nTrim baris terakhir (SetBrsEff)...\n");
    SetBrsEff(&M1,LastIdxBrs(M1)-1);
    TulisMATRIKS(M1);
    printf("Trim kolom terakhir (SetKolEff)...\n");
    SetKolEff(&M1,LastIdxKol(M1)-1);
    TulisMATRIKS(M1);

    printf("Rolling back trimming action...\n");
    SetBrsEff(&M1,LastIdxBrs(M1)+1);
    SetKolEff(&M1,LastIdxKol(M1)+1);
    TulisMATRIKS(M1);

    printf("-- Hasil CopyMatriks( M1, M3 )\n");
    CopyMATRIKS(M1,&M3);
    TulisMATRIKS(M3);

    TulisMATRIKS(M1);
    TulisMATRIKS(M2);
    printf("--  PlusMatriks M1,M2\n");
    TulisMATRIKS(PlusMATRIKS(M1,M2));

    printf("-- Hasil MinMatriks M1,M2\n");
    TulisMATRIKS(MinMATRIKS(M1,M2));

    printf("-- Hasil KaliMatriks M1,M2\n");
    TulisMATRIKS(KaliMATRIKS(M1,M2));

    printf("-- Hasil KaliKonsMatriks M1,3\n");
    TulisMATRIKS(KonsMATRIKSa(M1,3));

    printf("-- Uji Kesamaan M1,M2\n");
    if (IsEQ(M1,M2))
        printf("Matriks sama\n");
    else
        printf("Matriks tidak sama\n");

    printf("\n-- Uji EqSize M1,M2\n");
    if (EQSize(M1,M2))
        printf("Ukuran sama\n");
    else
        printf("Ukuran berbeda\n");

    printf("\n-- Uji IsLess M1,M2\n");
    if (IsLess(M1,M2))
        printf("Ukuran M1 < M2\n");
    else
        printf("Ukuran M1 >= M2\n");

    printf("\n-- NbElmt(M1): %d",NbElmt(M1));

    printf("\n-- Uji IsBujurSangkar(M1)\n");
    if (IsBujurSangkar(M1))
        printf("\nMatriks bujursangkar\n");
    else
        printf("\nMatriks tidak bujursangkar\n");

    printf("\n-- Uji IsSymetri(M3)\n");
    Baca(&M3);
    TulisMATRIKS(M3);
    if (IsSymetri(M3))
        printf("\nMatriks simetri\n");
    else
        printf("\nMatriks tidak simetri\n");

    printf("\n-- Uji IsSatuan(M3)\n");
    Baca(&M3);
    if (IsSatuan(M3))
        printf("\nMatriks satuan\n");
    else
        printf("\nMatriks tidak satuan\n");

    printf("\n-- Uji IsSparse(M3)\n");
    Baca(&M3);
    if (IsSparse(M3))
        printf("\nMatriks sparse\n");
    else
        printf("\nMatriks tidak sparse\n");

    printf("\n-- Uji Matriks Negasi M1\n");
    TulisMATRIKS(M1);
    TulisMATRIKS(InversN(M1));

    printf("\n-- Uji Transpose M1\n");
    Transpose(&M1);
    TulisMATRIKS(M1);

    scanf("%d",&i);

    return 0;
}

*/

int main()
{
    printf("//Selamat Datang//\n");
    printf("///INI PROGRAM INVERS LOH!///\n");

    int strExit;
    int panjang;
    MATRIKS M;
L1:
    do
    {
        printf("Masukkan panjang sisi matriks: "); scanf("%d",&panjang);

        if (!IsIdxValid(panjang,panjang))
            printf("Entah nilai efektif baris [%d..%d] atau kolomnya [%d..%d] salah, bang.\n", GetIdxBrsMin(),GetIdxBrsMax(),GetIdxKolMin(),GetIdxKolMax());
    }
    while (!IsIdxValid(panjang,panjang));


    BacaMATRIKS(&M,panjang,panjang);
    printf("*****MATRIKS ANDA*****\n");
        TulisMATRIKS(M);

    printf("*****INVERS MATRIKS*****\n");
    if (Determinan(M) != 0)
        TulisMATRIKS(InversM(M));
    else
        printf("Matriks tidak memiliki invers\n");

    do {
        printf("Ketik 999 untuk keluar atau ketik -999 untuk ulang lagi...\n");
        scanf("%d",&strExit);
        if (strExit == -999)
            goto L1;
    } while (strExit != 999);

    return 0;
}

