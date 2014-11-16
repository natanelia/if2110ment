#include "stacklist.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

/* Prototype manajemen memori */
address AlokasiStack(infotype X) {
    address P;
	
	P = (address)malloc(sizeof(ElmtStack));
	if (P != Nil){
		Info(P) = X;
		Next(P) = Nil;
	}
	else{
		P = Nil;
	}
	
	return P;
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
Next(P)=Nil */
/* P=Nil jika alokasi gagal */

void DealokasiStack(address P) {
	free(P);
}/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmptyStack (Stack S) {
	return Top(S) == Nil;
}
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
void CreateEmptyStack (Stack *S) {
	Top(*S) = Nil;
}
/* I.S. sembarang */
/* F.S. Membuat sebuah stack S yang kosong */
void Push (Stack *S, infotype X) {
	address P,Pt;
	
	Pt = AlokasiStack(X);
	if (Pt != Nil) {
		P = Top(*S);
		Next(Pt) = P;
		Top(*S) = Pt;
	}
}

/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/* jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
void Pop (Stack *S, infotype *X) {
	address P;
	
	P = Top(*S);
	(*X) = InfoTop(*S);
	Top(*S) = Next(P);
	DealokasiStack(P);
}
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/* elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */

void PrintStack(Stack S){
	address P;
	
	P = Top(S);
	printf("Isi Stack : ");
	if (IsEmptyStack(S)){
		printf("Stack kosong.");
	}
	else{
		while (P != Nil){
			printf("%c ",Info(P) );
			P = Next(P);
		}
	}
}

Stack reverseStack(Stack S) {
	address P,Pt,Px;
	Stack STemp;
	boolean failed;
	CreateEmptyStack(&STemp);
	infotype X;
	
	if (IsEmptyStack(S))
		return (STemp);
	else
		if ((Next(Top(S)))==Nil) {
			Push(&STemp,InfoTop(S));
			return STemp;
		}
		else {
			failed = false;
			P = Top(S);
			Pt = AlokasiStack(Info(P));
				if (Pt != Nil) {
					P = Next(P);
					Px = Pt;
				}
				else
					failed = true;
			while ((P != Nil) && (!failed)) {
				Pt = AlokasiStack(Info(P));
				if (Pt != Nil) {
					P = Next(P);
					Next(Pt) = Px;
					Px = Pt;
				}
				else
					failed = true;
			}
			Top(STemp) = Px;
			if (failed){
				while(!IsEmptyStack(STemp)){
					Pop(&STemp,&X);
				}
			}
			return STemp;
		}
}

