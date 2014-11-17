#ifndef __MESINKATA1_H__
#define __MESINKATA1_H__
#include "mesinkar.h"
#define NMax 50
#define BLANK ' '
#define ENTER '\n'
typedef struct {
    char TabKata[NMax+1];
    int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
I.S. : CC sembarang
F.S. : CC
≠ BLANK atau CC = MARK */

void STARTKATA(char *filename);
/* I.S. : CC sembarang
F.S. : EndKata = true, dan CC = Mark;
atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
CC adalah karakter pertama dari kata berikutnya, mungkin MARK
Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
I.S. : CC adalah karakter pertama dari kata
F.S. : CKata berisi kata yang sudah diakuisisi;
CC = BLANK atau CC = MARK; CC adalah karakter sesudah karakter terakhir yang diakuisisi */

void CopyKata(Kata Kata1,Kata *Kata2);
/* Mengkopi kata yang ada pada Kata1 ke Kata2*/

int GetIntegerFromKata(Kata Kata1);
/*mengembalikan integer hasil convertan kata yang dibaca*/

void printKata(Kata Kata1);
/* mengeprint kata1*/

#endif
