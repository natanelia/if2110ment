/* NIM/Nama : 13513038/Tjan, Marco Orlando
Nama file :ADT_MultiList.h
Topik :multilist untuk highscore*/


#ifndef ADT_MultiList_h
#define ADT_MultiList_h
#include "boolean.h"
#include <stdlib.h>
#include "ADT_Tanggal.h"


/* Representasi address dengan pointer */
/* ADT list dengan double pointer: nextboard dan nextuser*/



/* *** Konstanta *** */
#define Nil NULL


/* *** Definisi Type List *** */
typedef int BoardType;
typedef int ScoreType;
typedef Tanggal DateType;
typedef char[15] UserNameType;

typedef struct tRecord *AdrRecord;
typedef struct
{
	UserNameType UserName;
	ScoreType Score;
	DateType Date;
} RecordType;

typedef struct tRecord 
{
	RecordType InfoRecord;
	AdrRecord NextRecord;
} ElmRecord;



typedef struct tBoard *AdrBoard;
typedef struct tBoard
{
	BoardType InfoBoard;
	AdrRecord FirtsRecord;
	AdrBoard NextBoard;
} ElmBoard;


typedef struct
{
	AdrBoard FirstBoard;
} List;


typedef struct {
	RecordType *TR;
	int Size;
} TabRecord;


/* Selektor */
#define FirstBoard(L) ((L).FirstBoard)
#define InfoBoard(P) ((P).InfoBoard)
#define NextBoard(P) ((P).NextBoard)
#define FirstRecord(P) ((P).FirstRecord)
#define InfoRecord(P) ((P).InfoRecord)
#define NextRecord(P) ((P).NextRecord)



//fungsi2 alokasi dan dealokasi
AdrBoard AlokasiBoard(BoardType X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P */
/* Jika alokasi gagal, mengirimkan Nil */

AdrRecord AlokasiRecord (RecordType X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P */
/* Jika alokasi gagal, mengirimkan Nil */

void DealokasiBoard (AdrBoard P);
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

void InsertRecord(AdrBoard Z, AdrRecord P);
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama pada list Record dengan AdrBoard Z */


void InsVBoard (List *L, BoardType X);
/* I.S. L mungkin kosong */
/* F.S. X ditambahkan sebagai elemen pertama L */
/* Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
nilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. */

void InsVRecord (AdrBoard Z, RecordType X);
/* I.S. Next(Z) mungkin Nil */
/* F.S. X ditambahkan sebagai Next(Z) */
/* Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
nilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. */

AdrBoard SearchBoard (List L, BoardType Board);
/* Mengirimkan AdrBoard dimana Board yang dicari ditemukan */
/*mengembalikan Nil jika Board tidak ditemukkan */
/* List mungkin Kosong */


//Penambahan Record berdasarkan Board tertentu(penambahana database)
void InsertGameScore (List *L, BoardType Board,RecordType Record);
/* I.S. List boleh kosong, Board mungkin sudah ada, Record belum ada dalam List */
/*F.S. Record telah dimasukan ke dalam isi List */
/*proses: Jika Board belum ada pada List, InsertBoard terlebih dahulu */
/*dilanjutkan dengan proses InserRecord pada Board tersebut*/


//Keperluan HighScore Game
int NbBoardRecord (List L, BoardType Board);
/* mengembalikan jumlah Record yang ada pada board tertentu */
/*Jika Board tidak ada dalam list, maka akan mengembalikan 0 */

void MakeTabRecordEmpty (int N,TabRecord *T);
/*{ I.S. sembarang }
{ F.S. Terbentuk tabel T kosong dengan ukuran N }*/

void MoveBoardRecordToArray (List L, BoardType Board, TabRecord *T);
/* I.S. Board sudah ada dalam List, sudah ada record dalam Board */
/* F.S. Semua record yang ada dalam board akan dipindahkan ke dalam TabRecord T */

void SortTabRecord (TabRecord *T);
/* I.S. TabRecord T tidak kosong */
/* F.S. Elemen-elemen dalam TabRecord T sudah terurut berdasarkan Record.Score */
/*Jika ada lebih dari 2 skor yang sama, maka diurutkan berdasarkan waktu secara ascending. */

void ViewMyHighscore (TabRecord T, UserNameType UserName);
/* I.S. TabRecord T tidak kosong */
/* F.S. menampilkan 10 skor tertinggi pada board yang sedang dipilih yang didapatkan user tersebut */
/*Tampilan high score akan menampilkan skor secara terurut mengecil dan waktu(tanggal+jam) pencapaian skor tersebut*/
/*Jika ada lebih dari 2 skor yang sama, maka diurutkan berdasarkan waktu secara ascending. */

void ViewAllHighscore (TabRecord T);
/* I.S. TabRecord T tidak kosong */
/* F.S. menampilkan 10 skor tertinggi pada board yang sedang dipilih yang didapatkan dari semua user yang terdaftar. */
/*Tampilan high score akan menampilkan skor secara terurut mengecil,
 * nama user yang mendapatkan skor tersebut, dan waktu(tanggal+jam) pencapaian skor tersebut */
 /*Jika ada lebih dari 2 skor yang sama, maka diurutkan berdasarkan waktu secara ascending.*/

#endif
