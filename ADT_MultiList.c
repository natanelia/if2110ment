/* NIM/Nama : 13513038/Tjan, Marco Orlando
Nama file :ADT_MultiList.c
Topik :multilist untuk highscore*/
// gcc ADT_MultiList.c ADT_MultiList_Driver.c waktu.c jam.c tanggal.c mesinkar.c mesinkata1.c -o test

#include "ADT_MultiList.h"
#include "boolean.h"
#include <stdio.h>


//fungsi2 alokasi dan dealokasi
AdrBoard AlokasiBoard(BoardType X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P */
/* Jika alokasi gagal, mengirimkan Nil */
{
	AdrBoard P;
	P = (AdrBoard) malloc (sizeof (ElmBoard));
	if (P != 0 )  /*alokasi berhasil */
	{
		InfoBoard(P) = X;
		NextBoard(P) = Nil;
		FirstRecord(P) = Nil;
	}
	return P;
}


AdrRecord AlokasiRecord (RecordType X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P */
/* Jika alokasi gagal, mengirimkan Nil */
{
	AdrRecord P;
	P = (AdrRecord) malloc (sizeof (ElmRecord));
	if (P != 0 )  /*alokasi berhasil */
	{
		InfoRecord(P) = X;
		NextRecord(P) = Nil;
	}
	return P;
}


void DealokasiBoard (AdrBoard P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(P);
}

void DealokasiRecord (AdrRecord P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(P);
}

void CreateList (List *L)
/* I.S. Sembarang */
/* F.S. Terbentuk list L kosong */
{
	FirstBoard(*L) = Nil;
}




//penambahan elemen ke dalam list
void InsertBoard (List *L, AdrBoard P)
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	if (FirstBoard(*L) == Nil) //list kosong
		{
			FirstBoard(*L) = P;
		}
		else
		{
			NextBoard(P) = FirstBoard(*L);
			FirstBoard(*L)=P;
		}
}


void InsertRecord(AdrBoard Z, AdrRecord P)
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama pada list Record dengan AdrRecord Z */
{
	if (FirstRecord(Z) == Nil)
		{
			FirstRecord (Z) = P;
		}
		else
		{
			NextRecord(P) = FirstRecord(Z);
			FirstRecord (Z) =P;
		}
}


void InsVBoard (List *L, BoardType X)
/* I.S. L mungkin kosong */
/* F.S. X ditambahkan sebagai elemen pertama L */
/* Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
nilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. */
{
	AdrBoard P;
	P= AlokasiBoard(X);
	if (P!=Nil) //alokasi berhasil
	{
		InsertBoard(L, P);
	}
}

void InsVRecord (AdrBoard Z, RecordType X)
/* I.S. FirstRecord(Z) mungkin Nil */
/* F.S. X ditambahkan sebagai FirstRecord(Z) */
/* Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
nilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. */
{
	AdrRecord P;
	P= AlokasiRecord(X);
	if (P!=Nil) //alokasi berhasil
	{
		InsertRecord(Z,P);
	}
}

AdrBoard SearchBoard (List L, BoardType Board)
/* Mengirimkan AdrBoard dimana Board yang dicari ditemukan */
/*mengembalikan Nil jika Board tidak ditemukkan */
/* List mungkin Kosong */
 {
	 //kamus
	 AdrBoard PBoard;
	 boolean FoundBoard;

	 //algoritma
		 PBoard = FirstBoard(L);
		 FoundBoard = false;
		 while (PBoard !=Nil && !(FoundBoard))
		 {
			 if (InfoBoard(PBoard) == Board)
			 {
				 FoundBoard = true;
			}
			else
			{
			PBoard = NextBoard(PBoard);
			}
		}
		return PBoard;
}




//Penambahan Record berdasarkan Board dan User tertentu (penambahana database)
void InsertGameScore (List *L, BoardType Board,RecordType Record)
/* I.S. List boleh kosong, Board mungkin sudah ada, Record belum ada dalam List */
/*F.S. Record telah dimasukan ke dalam isi List */
/*proses: Jika Board belum ada pada List, InsertBoard terlebih dahulu */
/*dilanjutkan dengan proses InserRecord pada Board tersebut*/
{
	// Kamus
	AdrBoard Z;

	//Algoritma
	Z = SearchBoard (*L, Board);
	if (Z == Nil) // Board belum pernah dimainkan (tidak ada)
	{
		Z = AlokasiBoard(Board);
		if (Z != Nil)
		{
			InsertBoard (L,Z);
		}
	}
	InsVRecord(Z, Record);
}



 //Keperluan HighScore Game
int NbBoardRecord (List L, BoardType Board)
/* mengembalikan jumlah Record yang ada pada board tertentu */
/*Jika Board tidak ada dalam list, maka akan mengembalikan 0 */
{
	//Kamus
	AdrBoard P;
	AdrRecord PRecord;
	int CountRecord = 0;

	//Algoritma
	P = SearchBoard(L,Board);
	if (P == Nil) //Board tidak ada dalam List
	{
		return 0;
	}
	else
	{
		PRecord = FirstRecord(P);
		while (PRecord != Nil)
		{
			CountRecord++;
			PRecord = NextRecord(PRecord);
		}
		return CountRecord;
	}
}


void MakeTabRecordEmpty (int N,TabRecord *T)
/*{ I.S. sembarang }
{ F.S. Terbentuk tabel T kosong dengan ukuran N }*/
{
    T->TR = (RecordType*) malloc(N * sizeof(RecordType));
    T->Size = N;
    T->TNeff = 0;
}

void MoveBoardRecordToArray (List L, BoardType Board, TabRecord *T)
/* I.S. Board sudah ada dalam List, sudah ada record dalam Board */
/* F.S. Semua record yang ada dalam board akan dipindahkan ke dalam TabRecord T */
{
	//Kamus
	int NRecord; //jumlah record yang akan dipindahkan ke array
	AdrBoard PBoard = Nil;
	AdrRecord PRecord = Nil;
	int Index = 1; //index array


	//Algoritma
	NRecord = NbBoardRecord (L, Board);
	MakeTabRecordEmpty(NRecord+1, T);
	PBoard = SearchBoard(L,Board);
	if (PBoard != Nil)
	{
	PRecord = FirstRecord(PBoard);
	}

	while (PRecord != Nil)
	{
		T->TR[Index] = InfoRecord(PRecord);
		Index++;
		T->TNeff++;
		PRecord = NextRecord(PRecord);
	}
}

void SortTabRecord (TabRecord *T)
/* I.S. TabRecord T mungkin kosong */
/* F.S. Elemen-elemen dalam TabRecord T sudah terurut berdasarkan Record.Score */
/*Jika ada lebih dari 2 skor yang sama, maka diurutkan berdasarkan waktu secara ascending. */
{
	//KAMUS LOKAL
	RecordType Max;
	int i,j,idx; //untuk proses transversal
	int idxmax = (T->TNeff);

	//ALGORITMA
	for(i=1;i<=idxmax;i++)
	{
		Max= T->TR[i];
		idx = i;
		for (j=i;j<=idxmax;j++)
		{
			if(T->TR[j].Score > Max.Score)
			{
				Max = T->TR[j];
				idx = j;
			}
			else if (T->TR[j].Score == Max.Score)
			{
				if (IsWaktuEarly(T->TR[j].Time, Max.Time))
				{
					Max = T->TR[j];
					idx = j;
				}
			}
		}
        T->TR[idx] = T->TR[i];
        T->TR[i] = Max;
	}
}

void ViewMyHighscore (List L, BoardType Board, UserNameType UserName)
/* I.S. List mungkin kosong*/
/* F.S. menampilkan 10 skor tertinggi pada board yang sedang dipilih yang didapatkan user tersebut */
/*Tampilan high score akan menampilkan skor secara terurut mengecil dan waktu(tanggal+jam) pencapaian skor tersebut*/
/*Jika ada lebih dari 2 skor yang sama, maka diurutkan berdasarkan waktu secara ascending. */
{
	//kamus
	int Number =1;
	int Last;
	int i=1;
	TabRecord T;

	//algoritma
	MoveBoardRecordToArray(L, Board, &T);
	SortTabRecord(&T);
	Last = T.TNeff;
	if (i>Last)
        printf("  You haven't played the board.\n");
	else
	{
        printf(        " ┌──────┬───────┬─────────────────────┐\n");
        printf(        " │ Rank │ Score │        Time         │\n");
        printf(        " ├──────┼───────┼─────────────────────┤\n");
        while (i <= Last && Number<=10)
        {
            if (IsKataSama(T.TR[i].UserName,UserName))
            {
                printf(" │ %4d │ %5d │ ", Number, T.TR[i].Score);
                PrintWaktu(T.TR[i].Time); printf(" │\n");
                Number++;
            }
            i++;
        }
        printf(        " └──────┴───────┴─────────────────────┘\n");
	}
}

void ViewAllHighscore (List L, BoardType Board)
/* I.S. TabRecord T tidak kosong */
/* F.S. menampilkan 10 skor tertinggi pada board yang sedang dipilih yang didapatkan dari semua user yang terdaftar. */
/*Tampilan high score akan menampilkan skor secara terurut mengecil,
 * nama user yang mendapatkan skor tersebut, dan waktu(tanggal+jam) pencapaian skor tersebut */
 /*Jika ada lebih dari 2 skor yang sama, maka diurutkan berdasarkan waktu secara ascending.*/
{
	//kamus
	int Number =1;
	int Last;
	int i=1;
	int j;
	char username[11];
	TabRecord T;

	//algoritma
	MoveBoardRecordToArray(L, Board, &T);
	SortTabRecord(&T);
	Last = T.TNeff;
	if (i>Last)
        printf("  No one has played the board yet.\n");
	else
	{
        printf(        " ┌──────┬─────────────┬───────┬─────────────────────┐\n");
        printf(        " │ Rank │ User Name   │ Score │        Time         │\n");
        printf(        " ├──────┼─────────────┼───────┼─────────────────────┤\n");
        while (i <= Last && Number<=10)
        {
            printf(" │ %4d │ ", Number);

            for (j=0;j<=10;j++)
                username[j] = ' ';

            for (j=1;j<=T.TR[i].UserName.Length;j++)
                username[j-1] = T.TR[i].UserName.TabKata[j];

            for (j=0;j<=10;j++)
                printf("%c", username[j]);

            printf(" │ %5d │ ", T.TR[i].Score);
            PrintWaktu(T.TR[i].Time); printf(" │\n");
            Number++;
            i++;
        }
        printf(        " └──────┴─────────────┴───────┴─────────────────────┘\n");
    }
}


void BacaDataBaseScore (List *L)
/*I.S. File eksternal DataBaseScore Mungkin kosong */
/* F.S. Semua database disalin ke dalam multilist */
{
	//kamus
	BoardType Board;
	RecordType Record;

	//algoritma
	STARTKATA("DataBaseScore.txt");

    while (!(EndKata))
    {
        Board = GetIntegerFromKata(CKata);
        ADVKATA();
        CopyKata(CKata, &Record.UserName);
        ADVKATA();
        Record.Score= GetIntegerFromKata(CKata);
        ADVKATA();
        Day(Record.Time) = GetIntegerFromKata(CKata);
        ADVKATA();
        Month(Record.Time) = GetIntegerFromKata(CKata);
        ADVKATA();
        Year(Record.Time) = GetIntegerFromKata(CKata);
        ADVKATA();
        Hour(Record.Time) = GetIntegerFromKata(CKata);
        ADVKATA();
        Minute(Record.Time) = GetIntegerFromKata(CKata);
        ADVKATA();
        Second(Record.Time) = GetIntegerFromKata(CKata);
        ADVKATA();
        InsertGameScore(L, Board,Record);
    }

}

 void TulisDataBaseScore (List L)
 /* I.S. List mungkin kosong */
 /*Isi multilist dipindahkan ke dalam file DataBaseScore.txt */
 /*format penulisan tiap score = Board UserName Score TangalBulanTahunJamMenitDetik */
 /* contoh : 2 Marco 100 26 12 2014 15 30 45 */
 /*akhir file txt ditandai dengan '.' */
 {
	 //kamus
	 FILE *fp;
	 AdrBoard PBoard;
	 AdrRecord PRecord;

	//algoritma
   fp = fopen("DataBaseScore.txt", "w+");
   PBoard = FirstBoard(L);
   while (PBoard != Nil)
   {
	   PRecord = FirstRecord(PBoard);
	   while (PRecord != Nil)
	   {
		     fprintf(fp,"%d", InfoBoard(PBoard));
           fputs(" ",fp);
             printKataToText(fp, InfoRecord(PRecord).UserName);
           fputs(" ",fp);
		     fprintf(fp, "%d", InfoRecord(PRecord).Score);
           fputs(" ",fp);
		     fprintf(fp, "%d",Day(InfoRecord(PRecord).Time));
		   fputs(" ",fp);
		     fprintf(fp, "%d",Month(InfoRecord(PRecord).Time));
		   fputs(" ",fp);
		     fprintf(fp, "%d",Year(InfoRecord(PRecord).Time));
		   fputs(" ",fp);
		     fprintf(fp, "%d",Hour(InfoRecord(PRecord).Time));
		   fputs(" ",fp);
		     fprintf(fp, "%d",Minute(InfoRecord(PRecord).Time));
		   fputs(" ",fp);
		     fprintf(fp, "%d",Second(InfoRecord(PRecord).Time));
		   fputs("\n",fp);
            PRecord = NextRecord(PRecord);
		}
		PBoard = NextBoard(PBoard);
	}
   fputs(".", fp);
   fclose(fp);
 }
