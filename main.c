#include<stdio.h>
#include<string.h>
#include "boolean.h"
#include "matriks.h" //untuk merepresentasikan board permainan
#include "mesinkar.h" //untuk mesinkata
#include "mesinkata1.h" //untuk membaca kamus data dan file eksternal

//KAMUS GLOBAL
MATRIKS boards[10];


void ReadBoards()
{
    char filename[6];
    int i;
    for (i=0;i<=9;i++)
    {
        strcpy(filename, "");
        strcat(filename,(char)i);
        strcat(filename, ".txt");
        STARTKATA(filename);

        return
    }
}

int main()
{
    ReadBoards();
    ReadDictionary();

    return 0;
}
