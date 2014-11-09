/* ADT Priority Queue List */

/* File: PrioQueueList.c */

#include "PrioQueueList.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

/**** Prototype manajemen memori ****/
void Alokasi (address *P, infotype X, int Pr)
/* I.S. P sembarang, X terdefinisi */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = Nil */
/* P = Nil jika alokasi gagal */
{/* Kamus Lokal */
/* Algoritma */
	//Algortima
	*P = (address)malloc(sizeof(ElmtQ));
	if (P != Nil) {
		Info(*P) = X;
		Next(*P) = Nil;
		Prio(*P)=Pr;
	}
	else 
		P = Nil;
}

void Dealokasi (address P)
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{ /* Kamus Lokal */
/* Algoritma */
	free(P);
}

/**** Predikat Pemeriksaan Kondisi Queue ****/
boolean IsPrioQueueEmpty (Queue Q)
/* Mengirim true jika Q kosong: HEAD(Q) = Nil*/
{ /* Kamus Lokal */
/* Algoritma */
	return(Head(Q)==Nil);
}

int NBElmt (Queue Q)
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
void CreatePrioQueueEmpty (Queue *Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
{/* Kamus Lokal */
/* Algoritma */
	Head(*Q)=Nil;
}

/***** Primitif Add/Delete *****/
void AddPrio (Queue *Q, infotype X, int Pr)
/* Proses : Mengalokasi X dan menambahkan X pada bagian TAIL dari Q jika alokasi
berhasil dengan memperhatikan prioritas; jika alokasi gagal Q tetap */
/* I.S. Q mungkin kosong, X terdefinisi */
/* F.S. X menjadi elemen Q sesuai prioritas Pr,
Q tetap terurut mengecil sesuai prioritas */
{ /* Kamus Lokal */
	address P,Pt,Prec;
	boolean found;
/* Algoritma */
	Alokasi(&Pt,X,Pr);	
	if(Pt!=Nil) {
		P=Head(*Q);
		Prec=Nil;
		found=false;
		while ( P!=Nil && !(found) ) {
			if(Prio(P)<Pr) { 
				found=true;
			}
			//prio dengan angka terkecil memiliki prioritas paling kecil
			else {
				Prec=P;
				P=Next(P);
			}
		}
		if(Prec==Nil) {
			Next(Pt)=Head(*Q);
			Head(*Q)=Pt;
		}
		else {
			Next(Pt)=Next(Prec);
			Next(Prec)=Pt;
		}
	}	
}

void DelPrio (Queue *Q, infotype *X, int *Pr)
/* Proses : Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD,
X berisi elemen dengan prioritas tertinggi */
/* I.S. Q tidak kosong */
/* F.S. X = nilai elemen HEAD dan Pr = nilai elemen prioritas HEAD pd I.S.,
HEAD "maju" */
{ /* Kamus Lokal */
	address Pt;
/* Algoritma */
	Pt=Head(*Q);
	*X=InfoHead(*Q);
	*Pr=Prio(Pt);
	Head(*Q)=Next(Pt);
	Next(Pt)=Nil;
	Dealokasi(Pt);
}

/**** PROSES SEMUA ELEMEN QUEUE *****/
void PrintInfo (Queue Q)
/* I.S. queue mungkin kosong */
/* F.S. Jika queue tidak kosong, */
/* Semua info yg disimpan pada elemen queue diprint */
/* Jika queue kosong, hanya menuliskan "queue kosong" */
{/*Kamus Lokal */
	address P;
/* Algoritma */
	if(IsPrioQueueEmpty(Q)) printf("Queue kosong\n");
	else {
		P=Head(Q);
		while(P!=Nil) {
			printf("%d ",Info(P));
			P=Next(P);
		}
		printf("\n");
	}
}

