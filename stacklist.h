//ADT STACK DALAM REPRESENTASI LIST LINEAR

#ifndef stacklist_h
#define stacklist_h

#include "boolean.h"
#include <stdlib.h>

#define Nil NULL

/* Deklarasi infotype */
typedef char infotype;
/* Stack dengan representasi berkait dengan pointer */

typedef struct toElmtStack *address;
typedef struct toElmtStack {
	infotype Info;
	address Next;
} ElmtStack;

typedef struct {
	address TOP; /* alamat TOP: elemen puncak */
} Stack;

/* Selektor */
#define Top(S) (S).TOP
#define InfoTop(S) (S).TOP->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info

/* Prototype manajemen memori */
address AlokasiStack(infotype X);
/* Alamat P dialokasi, jika berhasil maka Info(P)=X dan
Next(P)=Nil */
/* P=Nil jika alokasi gagal */

void DealokasiStack (address P);
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmptyStack (Stack S);
/* Mengirim true jika Stack kosong: TOP(S) = Nil */

void CreateEmptyStack (Stack *S);
/* I.S. sembarang */
/* F.S. Membuat sebuah stack S yang kosong */

void Push (Stack *S, infotype X);
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/* jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */

void Pop (Stack *S, infotype *X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/* elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */

void PrintStack(Stack S);

Stack reverseStack(Stack S);
#endif
