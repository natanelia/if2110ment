/* ADT Queue List */

/* File: QueueList.h */

#ifndef _QueueList_H
#define _QueueList_H
#include "boolean.h"
#include "mesinkata1.h"
#include <stdlib.h>

/*** KAMUS UMUM ***/

#define Nil NULL

/*** Definisi Type Queue ***/
typedef Kata infoqtype;
typedef struct tElmtQueue *qaddress;
typedef struct tElmtQueue {
		infoqtype info;
		qaddress next;
} ElmtQueue;

/* Type Queue dengan ciri HEAD dan TAIL */
typedef struct {
	qaddress HEAD;
	qaddress TAIL;
} Queue;

/* Selektor */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).HEAD->info
#define InfoTail(Q) (Q).TAIL->info
#define NextQ(P) (P)->next
#define InfoQ(P) (P)->info

/**** Prototype manajemen memori ****/
void AlokasiQueue (qaddress *P, infoqtype X);
/* I.S. P sembarang, X terdefinisi */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = Nil */
/* P = Nil jika alokasi gagal */
void DealokasiQueue (qaddress P);
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

/**** Predikat Pemeriksaan Kondisi Queue ****/
boolean IsQueueEmpty (Queue Q);
/* Mengirim true jika Q kosong: HEAD(Q) = Nil and TAIL(Q) = Nil */
int NBElmtQueue (Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/**** Konstruktor ****/
void CreateQueueEmpty (Queue *Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */

/***** Primitif Add/Delete *****/
void AddQueue (Queue *Q, infoqtype X);
/* Proses : Mengalokasi X dan menambahkan X pada bagian TAIL dari Q jika alokasi
berhasil; jika alokasi gagal Q tetap */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
void DelQueue (Queue *Q, infoqtype *X);
/* Proses : Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */

/**** PROSES SEMUA ELEMEN QUEUE *****/
void PrintInfoQueue (Queue Q);
/* I.S. queue mungkin kosong */
/* F.S. Jika queue tidak kosong, */
/* Semua info yg disimpan pada elemen queue diprint */
/* Jika queue kosong, hanya menuliskan "queue kosong" */

/**** Searching *****/
boolean SearchQueue(Queue Q, infoqtype Kata);
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */

#endif
