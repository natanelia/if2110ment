/* ADT Queue List */

/* File: QueueList.c */

#include "QueueList.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

/**** Prototype manajemen memori ****/
void AlokasiQueue (address *P, infotype X)
/* I.S. P sembarang, X terdefinisi */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = Nil */
/* P = Nil jika alokasi gagal */
{/* Kamus Lokal */
/* Algoritma */
	//Algortima
	*P = (address)malloc(sizeof(ElmtQueue));
	if (P != Nil) {
		Info(*P) = X;
		Next(*P) = Nil;
	}
	else 
		P = Nil;
}

void DealokasiQueue (address P)
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
	address P;
/* Algoritma */
	count=0;
	P=Head(Q);
	while(P!=Nil) {
		count=count+1;
		P=Next(P);
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
void AddQueue (Queue *Q, infotype X)
/* Proses : Mengalokasi X dan menambahkan X pada bagian TAIL dari Q jika alokasi
berhasil; jika alokasi gagal Q tetap */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
{ /* Kamus Lokal*/
	address Pt;
/* Algoritma */
	AlokasiQueue(&Pt,X);
	if(Pt!=Nil) {
		if(IsQueueEmpty(*Q)) {
			Head(*Q)=Pt;
			Tail(*Q)=Pt;
		}
		else {
			Next(Tail(*Q))=Pt;
			Tail(*Q)=Pt;
		}
	}
}

void DelQueue (Queue *Q, infotype *X)
/* Proses : Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
{ /* Kamus Lokal */
	address Pt;
/* Algoritma */
	Pt=Head(*Q);
	*X=InfoHead(*Q);
	if(Next(Pt)==Nil) {
		Tail(*Q)=Nil;
	}
	Head(*Q)=Next(Pt);
	Next(Pt)=Nil;
	DealokasiQueue(Pt);
}

/**** PROSES SEMUA ELEMEN QUEUE *****/
void PrintInfoQueue (Queue Q)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */
{/*Kamus Lokal */
	address P;
/* Algoritma */
	if(IsQueueEmpty(Q)) printf("Queue kosong\n");
	else {
		P=Head(Q);
		while(P!=Nil) {
			printf("%d ",Info(P));
			P=Next(P);
		}
		printf("\n");
	}
}


