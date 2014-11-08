#include "mesinkata1.h"
boolean EndKata;
Kata CKata;
void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
I.S. : CC sembarang
F.S. : CC
≠ BLANK atau CC = MARK */
{ /* Kamus Lokal */
/* Algoritma */
    while (((CC == BLANK) || (CC == ENTER)) && (CC != MARK)) {
        ADV();
    } /* CC != BLANK or CC = MARK */
}

void STARTKATA(char *filename)
/* I.S. : CC sembarang
F.S. : EndKata = true, dan CC = Mark;
atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
CC karakter pertama sesudah karakter terakhir kata */
{
    /* Kamus Lokal */
    /* Algoritma*/
    START(filename);
    IgnoreBlank();
    if ((CC == MARK) || (CC == ENTER)) {
    EndKata = true;
    } else /* CC != MARK */ {
        EndKata = false;
        SalinKata();
    }
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
CC adalah karakter pertama dari kata berikutnya,
mungkin MARK
Proses : Akuisisi kata menggunakan procedure SalinKata */
{ /* Kamus Lokal */
/* Algoritma*/
    IgnoreBlank();
    if ((CC == MARK) || (CC == ENTER)) {
        EndKata = true;
    } else /* CC != MARK */ {
        SalinKata();
    }
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
I.S. : CC adalah karakter pertama dari kata
F.S. : CKata berisi kata yang sudah diakuisisi;
CC = BLANK atau CC = MARK;
CC adalah karakter sesudah karakter terakhir yang
diakuisisi */
{ /* Kamus Lokal */
    int i = 1; /* inisialisasi */
    /* Algoritma*/
    for (;;) {
        CKata.TabKata[i] = CC;
        ADV();
        if ((CC == MARK) || (CC == ENTER) || (CC == BLANK)) {
            break;
        } else {
            i++;
        }
    } /* CC = MARK or CC = BLANK */
    CKata.Length = i;
}

// ***** Operasi Lain ***** }
boolean IsKataSama (Kata K1, Kata K2)
// Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama dan
// urutan karakter yang menyusun kata juga sama }
{
    int i;
    boolean isSama = true;
    if (K1.Length == K2.Length)
    {
        i=1;
        while (i<=K1.Length && isSama)
        {
            if (K1.TabKata[i] != K2.TabKata[i])
                isSama = false;
            i++;
        }
        return isSama;
    } else {
        return false;
    }
}
