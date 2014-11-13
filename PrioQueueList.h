/* ADT Priority Queue List */

/* File: PrioQueueList.h */

#ifndef _PrioQueueList_H
#define _PrioQueueList_H
#include "boolean.h"
#include <stdlib.h>

/*** KAMUS UMUM ***/

#define Nil NULL

/*** Definisi Type Queue ***/
typedef int infotype;
typedef struct tElmtPrioQueue *addressprio;
typedef struct tElmtPrioQueue {
		infotype info;
		addressprio next;
		int prio;
} ElmtQ;

/* Type Queue dengan ciri HEAD */
typedef struct { 
	addressprio HEAD; 
} PrioQueue;

/* Selektor */
#define Head(Q) (Q).HEAD
#define InfoHead(Q) (Q).HEAD->info
#define Prio(P) (P)->prio
#define Next(P) (P)->next
#define Info(P) (P)->info


/**** Prototype manajemen memori ****/
void AlokasiPrio (addressprio *P, infotype X, int Pr);
/* I.S. P sembarang, X terdefinisi */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = Nil */
/* P = Nil jika alokasi gagal */
void DealokasiPrio (addressprio P);
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

/**** Predikat Pemeriksaan Kondisi Queue ****/
boolean IsPrioQueueEmpty (PrioQueue Q);
/* Mengirim true jika Q kosong: HEAD(Q) = Nil and TAIL(Q) = Nil */
int NBElmtPrio (PrioQueue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/**** Konstruktor ****/
void CreatePrioQueueEmpty (PrioQueue *Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */

/***** Primitif Add/Delete *****/
void AddPrio (PrioQueue *Q, infotype X, int Pr);
/* Proses : Mengalokasi X dan menambahkan X pada bagian TAIL dari Q jika alokasi
berhasil dengan memperhatikan prioritas; jika alokasi gagal Q tetap */
/* I.S. Q mungkin kosong, X terdefinisi */
/* F.S. X menjadi elemen Q sesuai prioritas Pr,
Q tetap terurut mengecil sesuai prioritas */
void DelPrio (PrioQueue *Q, infotype *X, int *Pr);
/* Proses : Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD,
X berisi elemen dengan prioritas tertinggi */
/* I.S. Q tidak kosong */
/* F.S. X = nilai elemen HEAD dan Pr = nilai elemen prioritas HEAD pd I.S.,
HEAD "maju" */

/**** PROSES SEMUA ELEMEN QUEUE *****/
void PrintInfoPrio (PrioQueue Q);
/* I.S. queue mungkin kosong */
/* F.S. Jika queue tidak kosong, */
/* Semua info yg disimpan pada elemen queue diprint */
/* Jika queue kosong, hanya menuliskan "queue kosong" */

#endif
