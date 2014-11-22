#ifndef set_h
#define set_h
#include "mesinkata1.h"
#include "boolean.h"

#define MaxEl 100
typedef Kata infosettype;
typedef struct
{
    infosettype T[MaxEl];
    int NbElmt;
} Set;

/*Deklarasi: S : Set
  Definisi akses (diimplementasikan sebagai selektor): NbMember(S) adalah S.NbElmt*/

boolean IsSetEmpty(Set S);
/*Tes terhadap S: true jika S kosong, false jika S tidak kosong*/

boolean IsSetFull(Set S);
//Tes terhadap S: true jika S sudah penuh, false jika tidak penuh

int SetNbElmt(Set S);
//Mengirimkan banyaknya elemen S

void CreateEmptySet(Set *S);
//Membuat sebuah Set kosong

void InsertSet(Set *S, infosettype X);
//Menambahkan X ke S, jika S belum terdapat di dalam S

void DeleteSet (Set *S, infosettype X);
//Menghapus X dari S

boolean IsSetMember (Set S, infosettype X);
//Mengembalikan true jika X adalah member dari S

boolean IsSetEqual (Set S1, Set S2);
//Mengembalikan true jika S1 dan S2 memiliki elemen yang sama

void UnionSet (Set S1, Set S2, Set *S3);
//Menghasilkan gabungan S1 dan S2

void IntersectionSet (Set S1, Set S2, Set *S3);
//Menghasilkan irisan S1 dan S2

void SetDifference (Set S1, Set S2, Set *S3);
//Menghasilkan S1 dikurangi S2

//infosettype SetMin (Set S);
//Menghasilkan elemen S terkecil

//infosettype SetMax (Set S);
//Menghasilkan elemen S terbesar

void CopySet(Set S1, Set *S2);
//Menghasilkan elemen S terbesar

void TulisSet(Set S);
#endif // set_h
