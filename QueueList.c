/* ADT Queue List */

/* File: QueueList.c */

#include "QueueList.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

/**** Prototype manajemen memori ****/
void AlokasiQueue (qaddress *P, infoqtype X)
/* I.S. P sembarang, X terdefinisi */
/* F.S. Alamat P dialokasi, jika berhasil maka InfoQ(P) = X dan NextQQ(P) = Nil */
/* P = Nil jika alokasi gagal */
{/* Kamus Lokal */
/* Algoritma */
	//Algortima
	*P = (qaddress)malloc(sizeof(ElmtQueue));
	if (P != Nil) {
		InfoQ(*P) = X;
		NextQ(*P) = Nil;
	}
	else 
		P = Nil;
}

void DealokasiQueue (qaddress P)
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{ /* Kamus Lokal */
/* Algoritma */
	free(P);
}

/**** Predikat Pemeriksaan Kondisi Queue ****/
boolean IsQueueEmpty (Queue Q)
/* Mengirim true jika Q kosong: HEAD(Q) = Nil and TAIL(Q) = Nil */
{ /* Kamus Lokal */
/* Algoritma */
	return(Head(Q)==Nil && Tail(Q)==Nil);
}

int NBElmtQueue (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{ /* Kamus Lokal */
	int count;
	qaddress P;
/* Algoritma */
	count=0;
	P=Head(Q);
	while(P!=Nil) {
		count=count+1;
		P=NextQ(P);
	}
	return(count);
}

/**** Konstruktor ****/
void CreateQueueEmpty (Queue *Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
{/* Kamus Lokal */
/* Algoritma */
	Head(*Q)=Nil;
	Tail(*Q)=Nil;
}

/* *** Primitif Add/Delete *** */
void AddQueue (Queue *Q, infoqtype X)
/* Proses : Mengalokasi X dan menambahkan X pada bagian TAIL dari Q jika alokasi
berhasil; jika alokasi gagal Q tetap */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
{ /* Kamus Lokal*/
	qaddress Pt;
/* Algoritma */
	AlokasiQueue(&Pt,X);
	if(Pt!=Nil) {
		if(IsQueueEmpty(*Q)) {
			Head(*Q)=Pt;
			Tail(*Q)=Pt;
		}
		else {
			NextQ(Tail(*Q))=Pt;
			Tail(*Q)=Pt;
		}
	}
}

void DelQueue (Queue *Q, infoqtype *X)
/* Proses : Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
{ /* Kamus Lokal */
	qaddress Pt;
/* Algoritma */
	Pt=Head(*Q);
	*X=InfoHead(*Q);
	if(NextQ(Pt)==Nil) {
		Tail(*Q)=Nil;
	}
	Head(*Q)=NextQ(Pt);
	NextQ(Pt)=Nil;
	DealokasiQueue(Pt);
}

/**** PROSES SEMUA ELEMEN QUEUE *****/
void PrintInfoQueue (Queue Q)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */
{/*Kamus Lokal */
	qaddress P;
/* Algoritma */
	if(IsQueueEmpty(Q)) {}
	else {
		P=Head(Q);
		while(P!=Nil) {
			printKata(InfoQ(P)); printf(" ");
			P=NextQ(P);
		}
		printf("\n");
	}
}

boolean SearchQueue(Queue Q, infoqtype Kata)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{/* Kamus Lokal */
	boolean found;
	qaddress P;
/* Algoritma */
	P=Head(Q);
	found=false;
	while(P!=Nil && !found) {
		if(IsKataSama(InfoQ(P),Kata)) {
			found=true;
		}
		else {
			P=NextQ(P);
		}
	}
	return(found);
}

