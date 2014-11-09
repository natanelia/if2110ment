/* ADT Queue List */

/* File: QueueList.h */

#ifndef _QueueList_H
#define _QueueList_H
#include "boolean.h"
#include <stdlib.h>

/*** KAMUS UMUM ***/

#define Nil NULL

/*** Definisi Type Queue ***/
typedef int infotype;
typedef struct tElmtQueue *address;
typedef struct tElmtQueue {
		infotype info;
		address next;
} ElmtQueue;

/* Type Queue dengan ciri HEAD dan TAIL */
typedef struct { 
	address HEAD;
	address TAIL; 
} Queue;

/* Selektor */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).HEAD->info
#define InfoTail(Q) (Q).TAIL->info
#define Next(P) (P)->next
#define Info(P) (P)->info

/**** Prototype manajemen memori ****/
void Alokasi (address *P, infotype X);
/* I.S. P sembarang, X terdefinisi */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = Nil */
/* P = Nil jika alokasi gagal */
void Dealokasi (address P);
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

/**** Predikat Pemeriksaan Kondisi Queue ****/
boolean IsQueueEmpty (Queue Q);
/* Mengirim true jika Q kosong: HEAD(Q) = Nil and TAIL(Q) = Nil */
int NBElmt (Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/**** Konstruktor ****/
void CreateQueueEmpty (Queue *Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */

/***** Primitif Add/Delete *****/
void Add (Queue *Q, infotype X);
/* Proses : Mengalokasi X dan menambahkan X pada bagian TAIL dari Q jika alokasi
berhasil; jika alokasi gagal Q tetap */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
void Del (Queue *Q, infotype *X);
/* Proses : Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */

/**** PROSES SEMUA ELEMEN QUEUE *****/
void PrintInfo (Queue Q);
/* I.S. queue mungkin kosong */
/* F.S. Jika queue tidak kosong, */
/* Semua info yg disimpan pada elemen queue diprint */
/* Jika queue kosong, hanya menuliskan "queue kosong" */

#endif
