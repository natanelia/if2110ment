/* ADT Priority Queue List */

/* File: PrioQueueList.c */

#include "PrioQueueList.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

/**** Prototype manajemen memori ****/
void AlokasiPrio (addressprio *P, infopriotype X, int Pr)
/* I.S. P sembarang, X terdefinisi */
/* F.S. Alamat P dialokasi, jika berhasil maka InfoPrio(P) = X dan NextPrio(P) = Nil */
/* P = Nil jika alokasi gagal */
{/* Kamus Lokal */
/* Algoritma */
	//Algortima
	*P = (addressprio)malloc(sizeof(ElmtQ));
	if (P != Nil) {
		InfoPrio(*P) = X;
		NextPrio(*P) = Nil;
		Prio(*P)=Pr;
	}
	else 
		P = Nil;
}

void DealokasiPrio (addressprio P)
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{ /* Kamus Lokal */
/* Algoritma */
	free(P);
}

/**** Predikat Pemeriksaan Kondisi Queue ****/
boolean IsPrioQueueEmpty (PrioQueue Q)
/* Mengirim true jika Q kosong: HeadPrio(Q) = Nil*/
{ /* Kamus Lokal */
/* Algoritma */
	return(HeadPrio(Q)==Nil);
}

int NBElmtPrio (PrioQueue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{ /* Kamus Lokal */
	int count;
	addressprio P;
/* Algoritma */
	count=0;
	P=HeadPrio(Q);
	while(P!=Nil) {
		count=count+1;
		P=NextPrio(P);
	}
	return(count);
}

/**** Konstruktor ****/
void CreatePrioQueueEmpty (PrioQueue *Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
{/* Kamus Lokal */
/* Algoritma */
	HeadPrio(*Q)=Nil;
}

/***** Primitif Add/Delete *****/
void AddPrio (PrioQueue *Q, infopriotype X, int Pr)
/* Proses : Mengalokasi X dan menambahkan X pada bagian TAIL dari Q jika alokasi
berhasil dengan memperhatikan prioritas; jika alokasi gagal Q tetap */
/* I.S. Q mungkin kosong, X terdefinisi */
/* F.S. X menjadi elemen Q sesuai prioritas Pr,
Q tetap terurut mengecil sesuai prioritas */
{ /* Kamus Lokal */
	addressprio P,Pt,Prec;
	boolean found;
/* Algoritma */
	AlokasiPrio(&Pt,X,Pr);	
	if(Pt!=Nil) {
		P=HeadPrio(*Q);
		Prec=Nil;
		found=false;
		while ( P!=Nil && !(found) ) {
			if(Prio(P)<Pr) { 
				found=true;
			}
			//prio dengan angka terkecil memiliki prioritas paling kecil
			else {
				Prec=P;
				P=NextPrio(P);
			}
		}
		if(Prec==Nil) {
			NextPrio(Pt)=HeadPrio(*Q);
			HeadPrio(*Q)=Pt;
		}
		else {
			NextPrio(Pt)=NextPrio(Prec);
			NextPrio(Prec)=Pt;
		}
	}	
}

void DelPrio (PrioQueue *Q, infopriotype *X, int *Pr)
/* Proses : Menghapus X pada bagian HeadPrio dari Q dan mendealokasi elemen HeadPrio,
X berisi elemen dengan prioritas tertinggi */
/* I.S. Q tidak kosong */
/* F.S. X = nilai elemen HeadPrio dan Pr = nilai elemen prioritas HeadPrio pd I.S.,
HeadPrio "maju" */
{ /* Kamus Lokal */
	addressprio Pt;
/* Algoritma */
	Pt=HeadPrio(*Q);
	*X=InfoHead(*Q);
	*Pr=Prio(Pt);
	HeadPrio(*Q)=NextPrio(Pt);
	NextPrio(Pt)=Nil;
	DealokasiPrio(Pt);
}

/**** PROSES SEMUA ELEMEN QUEUE *****/
void PrintInfoPrioPrio (PrioQueue Q)
/* I.S. queue mungkin kosong */
/* F.S. Jika queue tidak kosong, */
/* Semua InfoPrio yg disimpan pada elemen queue diprint */
/* Jika queue kosong, hanya menuliskan "queue kosong" */
{/*Kamus Lokal */
	addressprio P;
/* Algoritma */
	if(IsPrioQueueEmpty(Q)) {}
	else {
		P=HeadPrio(Q);
		while(P!=Nil) {
			printKata(InfoPrio(P));
			P=NextPrio(P);
		}
		printf("\n");
	}
}

