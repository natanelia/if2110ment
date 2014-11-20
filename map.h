#ifndef map_h
#define map_h
#include "mesinkata1.h"
#include "boolean.h"

#define MaxEl 100
typedef int infomaptype;
typedef char keytype;
typedef struct
{
    keytype key;
    infomaptype value;
} Elmt;

typedef struct
{
    Elmt T[MaxEl];
    int NbMapElmt;
}Map;

boolean IsMapEmpty(Map M);
//Tes terhadap M : true jika M kosong, false jika M tidak kosong

void CreateEmptyMap(Map *M);
//Membuat sebuah map kosong

void InsertMap(keytype K, infomaptype V, Map *M);
//Menambahkan pasangan (K,V) jika belum ada elemen dengan nilai key = K pada M

void DeleteMap(keytype K, Map *M);
//Menghapus pasangan dengan nilai key = K dari M

void ReassignMap (keytype K, infomaptype V, Map *M);
//Mengubah nilai value dari pasangan dengan nilai key = K menjadi V

infomaptype ValueOfMap (keytype K, Map M);
//Mengembalikan value dari pasangan dengan nilai key = K

void TulisMap(Map M);
#endif // map_h
