/* NIM/Nama : 13513038/Tjan, Marco Orlando
Nama file :ADT_MultiList.h
Topik :multilist untuk highscore*/


#ifndef ADT_MultiList_h
#define ADT_MultiList_h
#include "boolean.h"
#include <stdlib.h>
#include "tanggal.h"


/* Representasi address dengan pointer */
/* ADT list dengan double pointer: nextboard dan nextuser*/



/* *** Konstanta *** */
#define Nil NULL


/* *** Definisi Type List *** */
typedef int Score;
typedef struct tRecord *AdrRecord;
typedef struct
{
	Score Nilai;
	Tanggal Tgl;
} InfoRecord;

typedef struct tRecord
{
	InfoRecord Info;
	AdrRecord NextRecord;
} ElmRecord;


typedef struct tUser *AdrUser;
typedef char[15] UserName;
typedef struct tUser
{
	UserName User;
	AdrRecord FirstRecord;
	AdrUser NextUser;
} ElmUser;


typedef structt tBoard *AdrBoard;
typedef int BoardNb;
typedef struct tBoard
{
	BoardNb Nb;
	AdrUser FirstUser;
	AdrBoard NextBoard;
} ElmBoard;


typedef struct
{
	AdrBoard FirstBoard;
} List;


/* Selektor */
#define Head(L) ((L).FirstBoard)
#define NextBoard(P) ((P).NextBoard))
#define InfoBoard(P) ((P).Nb)
#define FirstUser(P) ((P).FirstUser)
#define InfoUser (P) ((P).User)
#define NextUser(P) ((P).NextUser)
#define FirstRecord(P) ((P).FirstRecord)
#define Info(P) ((P).Info)
#define NextRecord(P) ((P).NextRecord)


//fungsi2 alokasi dan dealokasi
AdrBoard AlokasiBoard(BoardNb Nb);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P */
/* Jika alokasi gagal, mengirimkan Nil */

AdrUser AlokasiUser(UserName User);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P */
/* Jika alokasi gagal, mengirimkan Nil */

AdrRecord AlokasiRecord (InfoRecord Info);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P */
/* Jika alokasi gagal, mengirimkan Nil */

void DealokasiBoard (AdrBoard P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

void DealokasiUser (AdrUser P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

void DealokasiRecord (AdrRecord P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

void CreateList (List *L);
/* I.S. Sembarang */
/* F.S. Terbentuk list L kosong */



//penambahan elemen ke dalam list
void InsertBoard (List *L, AdrBoard P);
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */

void InsertUser (AdrBoard Z, AdrUser P);
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama pada List User ddengan AdrBoard Z */

void InsertFRecord(AdrUser Z, AdrRecord P);
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama pada list Record dengan AdrUser Z */


void InsVBoard (List *L, BoardNb X);
/* I.S. L mungkin kosong */
/* F.S. X ditambahkan sebagai elemen pertama L */
/* Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
nilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. */

void InsVUser (AdrBoard Z, UserName X);
/* I.S. Next(Z) mungkin Nil */
/* F.S. X ditambahkan sebagai Next(Z) */
/* Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
nilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. */

void InsVRecord (AdrUser Z, InfoRecord X);
/* I.S. Next(Z) mungkin Nil */
/* F.S. X ditambahkan sebagai Next(Z) */
/* Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
nilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. */





//penambahan score pada user dengan menjaga keterurutan score (besar -->kecil
void InsertAfterRecord (AdrUser Z, AdrRecord P, AdrRecord Prec);
/* I.S. Prec adalah elemen User. Dimungkinkan Prec bernilai Nil*/
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec,
 * jika Prec bernilai Nil, artinya P diinsert sebagai elemen pertama*/

void DeleteAfterRecord (AdrUser Z,AdrRecord *Pdel,AdrRecord Prec);
/* I.S. FirstRecord(Z) bukan Nil,  Prec adalah AdrRecord pada User Z. */
/* F.S. Menghapus NextRecord(Prec) : Pdel adalah AdrRecord yang dihapus */

void InsertSortedRecord (AdrUser Z, InfoRecord X);
/* I.S: sembarang, FirstRecord(Z) boleh sama dengan Nil */
/*F.S: alokasi X, kemudian insert address X pada list Record dari User Z dengan menjaga keterurutan nilai Record dari besar ke kecil */
/* record diurutkan berdasarkan InfoRecord.Nilai */





//Penambahan Record berdasarkan Board dan User tertentu (penambahana database)
void InsertGameScore (List *L, BoardNb Board, UserName User, InfoRecord Record);
/* I.S. List boleh kosong, Board dan User mungkin sudah ada, Record belum ada dalam List */
/*F.S. Record telah dimasukan ke dalam isi List */
/*proses: Jika Board belum ada pada List, InsertBoard
 * Jika User belum ada pada board, InsertUser*/





#endif
