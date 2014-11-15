/* File : ArrayOfKata.c */

#include "ArrayOfKata.h"
#include <stdio.h>
#include "boolean.h"

	
/* KONSTRUKTOR */
void MakeAKEmpty (TabK *T)
/*	I.S. sembarang
	F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
	(*T).Neff=0;
}

/* SELEKTOR */
int NbElmt (TabK T)
/* Mengirimkan banyaknya elemen efektif tabel. Mengirimkan nol jika tabel kosong */
{
	return (T.Neff);
}
int MaxNbEl (TabK T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	return (IdxMax-IdxMin+1);
}
void SetNeff (TabK *T, IdxType N)
/*	I.S. T terdefinisi, sembarang
	F.S. Nilai indeks efektif T bernilai N
	Mengeset nilai indeks elemen efektif sehingga bernilai N */
{
	(*T).Neff=N;
}
/* Selektor INDEKS */
IdxType GetFirstIdx (TabK T)
/*	Prekondisi : Tabel T tidak kosong
	Mengirimkan indeks elemen pertama */
{
	return (IdxMin);
}
IdxType GetLastIdx (TabK T)
/*	Prekondisi : Tabel T tidak kosong
	Mengirimkan indeks elemen terakhir */
{
	return (IdxMin+T.Neff-1);
}

/* TEST KOSONG/PENUH */
boolean IsAKEmpty (TabK T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
	boolean temp;
	if (NbElmt(T)==0)
		temp=true;
	else
		temp=false;
	return(temp);
}
boolean IsAKFull (TabK T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	boolean temp;
	if (NbElmt(T)==MaxNbEl(T))
		temp=true;
	else
		temp=false;
	return(temp);
}

/* FUNGSI DAN PROSEDUR LAIN */
boolean SearchB (TabK T, ElType X)
/*	Search apakah ada elemen tabel T yang bernilai X
	Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
{
	IdxType i;
	boolean Found;

	Found=false;
	if (IsAKEmpty(T))
	{	printf("yes");return Found;}
	else
	{	i=GetFirstIdx(T);
		while ((!Found)&&(i<=GetLastIdx(T)))
		{	if (IsKataSama(Elmt(T,i),X))
				Found=true;
			else
				i++; }
		return(Found);	}
}
void AddAsLastEl (TabK *T, ElType X)
/*	Menambahkan X sebagai elemen terakhir tabel
	I.S. Tabel boleh kosong, tetapi tidak penuh
	F.S. X adalah elemen terakhir T yang baru
	Proses : Menambahkan sebagai elemen ke-i yang baru */
{
	IdxType i;
	
	if (IsAKEmpty(*T))
		CopyKata(X,&Elmt(*T,IdxMin));
	else
	{	i=GetLastIdx(*T);
		i++;
		CopyKata(X,&Elmt(*T,i));	}
	SetNeff(T,NbElmt(*T)+1);	
}
