/* NIM/Nama : 13513038/Tjan, Marco Orlando
Nama file :ADT_MultiList.c
Topik :multilist untuk highscore*/


#include "ADT_MultiList.h"
#include "boolean.h"



//fungsi2 alokasi dan dealokasi
AdrBoard AlokasiBoard(BoardNb Nb)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P */
/* Jika alokasi gagal, mengirimkan Nil */
{
	AdrBoard P;
	P = (AdrBoard) malloc (sizeof (ElmBoard));
	if (P != 0 )  /*alokasi berhasil */
	{
		InfoBoard(P) = Nb;
		NextBoard(P) = Nil;
		FirstUser(P) = Nil;
	}
	return P; 
}


AdrUser AlokasiUser(UserName User)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P */
/* Jika alokasi gagal, mengirimkan Nil */
{
	AdrUser P;
	P = (AdrUser) malloc (sizeof (ElmUser));
	if (P != 0 )  /*alokasi berhasil */
	{
		InfoUser (P) = User;
		NextUser(P) = Nil;
		FirstRecord (P) = Nil;
	}
	return P; 
}

AdrRecord AlokasiRecord (InfoRecord Info)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P */
/* Jika alokasi gagal, mengirimkan Nil */
{
	AdrRecord P;
	P = (AdrRecord) malloc (sizeof (ElmRecord));
	if (P != 0 )  /*alokasi berhasil */
	{
		Info(P) = Info;
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

void DealokasiUser (AdrUser P)
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
	Head(*L) = Nil;
}




//penambahan elemen ke dalam list
void InsertBoard (List *L, AdrBoard P)
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	if (First(*L) == Nil) //list kosong
		{
			First(*L) = P;
		}
		else
		{
			Next(P) = First(*L);
			First(*L)=P;
		}
}


void InsertUser (AdrBoard Z, AdrUser P)
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama pada List User ddengan AdrBoard Z */
{
	if (FirstUser (Z) == Nil) //Board belum memiliki user yang pernah bermain
		{
			FirstUser (Z) = P;
		}
		else
		{
			Next(P) = FirstUser (Z);
			FirstUser (Z) =P;
		}
}



void InsertFRecord(AdrUser Z, AdrRecord P)
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama pada list Record dengan AdrUser Z */
{
	if (FirstRecord (Z) == Nil) //User belum pernah bermain
		{
			FirstRecord (Z) = P;
		}
		else
		{
			Next(P) = FirstRecord(Z);
			FirstRecord (Z) =P;
		}
}


void InsVBoard (List *L, BoardNb X)
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
		InsertBoard(L,P);
	}
}

void InsVUser (AdrBoard Z, UserName X)
/* I.S. Next(Z) mungkin Nil */
/* F.S. X ditambahkan sebagai Next(Z) */
/* Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
nilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. */
{
	AdrUser P;
	P= AlokasiUser(X);
	if (P!=Nil) //alokasi berhasil
	{
		InsertUser(Z,P);
	}
}



void InsVRecord (AdrUser Z, InfoRecord X)
/* I.S. Next(Z) mungkin Nil */
/* F.S. X ditambahkan sebagai Next(Z) */
/* Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
nilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. */
{
	AdrRecord P;
	P= AlokasiRecord(X);
	if (P!=Nil) //alokasi berhasil
	{
		InsertFRecord(Z,P);
	}
}




//penambahan score pada user dengan menjaga keterurutan score (besar -->kecil
void InsertAfterRecord (AdrUser Z, AdrRecord P, AdrRecord Prec)
/* I.S. Prec adalah elemen User. Dimungkinkan Prec bernilai Nil*/
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec,
 * jika Prec bernilai Nil, artinya P diinsert sebagai elemen pertama*/
{
	//kamus
	//algoritma
	if (Prec == Nil)
	{
		InsertFRecord(Z,P);
	}
	else
	{
		NextRecord(P) = NextRecord(Prec);
		NextRecord(Prec) = P;
	}
}


void DeleteAfterRecord (AdrUser Z,AdrRecord *Pdel,AdrRecord Prec)
/* I.S. FirstRecord(Z) bukan Nil,  Prec adalah AdrRecord pada User Z. */
/* F.S. Menghapus NextRecord(Prec) : Pdel adalah AdrRecord yang dihapus */
{
	*Pdel = NextRecord (Prec);
	NextRecord(Prec) = NextRecord(*Pdel);
	NextRecord(*Pdel) = Nil;
}


void InsertSortedRecord (AdrUser Z, InfoRecord X)
/* I.S: sembarang, FirstRecord(Z) boleh sama dengan Nil */
/*F.S: alokasi X, kemudian insert address X pada list Record dari User Z dengan menjaga keterurutan nilai Record dari besar ke kecil */
/* record diurutkan berdasarkan InfoRecord.Nilai */
{
	AdrRecord P, After, Pass, PDel;
	boolean Inserted;
	
	//algoritma
	/*inisialisasi*/
	Inserted = false;
	Pass = Nil;
	InsVRecord(Z, X);
	P = FirstRecord(Z);
	After = NextRecord(P);
	
	//pencarian posisi yang pas dengan menjaga keterurutan
	while (After != Nil && !(Inserted)) 
	{
		if (Info(P).Score >= Info(After).Score) //posisi P sudah pas
		{
			Inserted = true;
		}
		else //posisi P belum pas
		{
			After = NextRecord(After);
			DeleteAfterRecord(Z, &PDel, P);
			InsertAfterRecord(Z, PDel, Pass);
			Pass = PDel;
		}
	}
}




//Penambahan Record berdasarkan Board dan User tertentu (penambahana database)
void InsertGameScore (List *L, BoardNb Board, UserName User, InfoRecord Record)	
/* I.S. List boleh kosong, Board dan User mungkin sudah ada, Record belum ada dalam List */
/*F.S. Record telah dimasukan ke dalam isi List */
/*proses: Jika Board belum ada pada List, InsertBoard
 * Jika User belum ada pada board, InsertUser*/
 {
	 //kamus 
	 AdrBoard PBoard;
	 AdrUser PUser;
	 boolean FoundBoard, FoundUser;
	 
	 
	 //algoritma
	 /*pencarian board yang pas */
		 PBoard = Head(*L);
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
		if (!(FoundBoard)) // Board belum pernah dimainkan
		{
			PBoard = AlokasiBoard(Board);
			InsertBoard(L,PBoard);
		}
		
	/*pencarian user yang pas */
		PUser = FirstUser(PBoard);
		FoundUser = false;
		while (PUser !=Nil && !(FoundUser))
		{
			if (InfoUser(PUser) == User)
			{
				FoundUser = true;
			}
			else
			{
				PUser=NextUser(PUser);
			}
		}
		if (!(FoundUser)) // User belum pernah bermain pada board tersebut
		{
			PUser = AlokasiUser(User);
			InsertUser(PBoard, PUser);
		}
		
	/*sudah ditemukan board dan user yang pas*/
	/*record diinsertkan ke dalam List */
	InsertSortedRecord(PUser, Record);
}
	
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 








