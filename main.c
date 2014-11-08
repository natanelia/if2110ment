#include<stdio.h>
#include<string.h>
#include "boolean.h"
#include "matriks.h" //untuk merepresentasikan board permainan
#include "mesinkar.h" //untuk mesinkata
#include "mesinkata1.h" //untuk membaca kamus data dan file eksternal

//KAMUS GLOBAL
MATRIKS boards[10];
typedef char * word;
word *dictionary;

void ReadBoards()
//I.S sembarang
//F.S MATRIKS boards berisi semua board yang ada di folder boards.
{
    char filename[13];
    int i,j,k;

    strcpy(filename, "boards/");
    strcat(filename, " .txt");

    for (i=0;i<=9;i++)
    {
        filename[7]=(char)i+48;
        STARTKATA(filename);

        MakeMATRIKS(4,4,&boards[i]);
        for (j=FirstIdxBrs(boards[i]);j<=LastIdxBrs(boards[i]);j++)
        {
            for (k=FirstIdxKol(boards[i]);k<=LastIdxKol(boards[i]);k++)
            {
                SetEl(&boards[i],j,k,CKata.TabKata[1]);
                ADVKATA();
            }
        }
    }
}

void ReadDictionary()
//I.S sembarang
//F.S MATRIKS boards berisi semua board yang ada di folder boards.
{

}

int main()
{
    int i;

    ReadBoards();
    for (i=0;i<=9;i++)
    {
        TulisMATRIKS(boards[i]);
    }

    return 0;
}
