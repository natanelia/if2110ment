/* NIM/Nama : 13513038/Tjan, Marco Orlando
Nama file : ADT_MultiList_Driver.c
Topik :multilist untuk highscore*/


#include "ADT_MultiList.h"	
#include "boolean.h"
#include <stdio.h>	

//KAMUS
List L1;
Kata Kata1;
int test;
RecordType NewRecord;


int main()
{
	BacaDataBaseScore(&L1);
	Kata1.TabKata[1] = 'M'; Kata1.TabKata[2] = 'a'; Kata1.TabKata[3] = 'r'; Kata1.TabKata[4] = 'c'; Kata1.TabKata[5] = 'o'; Kata1.Length = 5;
	printf("view my high score \n");
	ViewMyHighscore(L1, 1, Kata1 );
	printf("view all high score \n");
	ViewAllHighscore(L1, 1);
	NewRecord.UserName = Kata1;
	NewRecord.Score = 999;
	Day(NewRecord.Time) = 17;
	Month(NewRecord.Time) = 11;
	Year(NewRecord.Time) = 2004;
	Hour(NewRecord.Time) = 17;
	Minute(NewRecord.Time) = 17;
	Second(NewRecord.Time) = 17;
	InsertGameScore(&L1, 2, NewRecord);
	TulisDataBaseScore(L1);


return 0;
}

