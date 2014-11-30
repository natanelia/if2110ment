#include "map.h"
#include "boolean.h"
#include <stdio.h>
boolean IsMapEmpty(Map M)
{
    return (M.NbMapElmt == 0);
}

void CreateEmptyMap(Map *M)
{
    (*M).NbMapElmt = 0;
}

void InsertMap(keytype K, infomaptype V, Map *M)
{
    int i=1;
    boolean found = false;
    while ((!found)&&(i<=(*M).NbMapElmt))
    {
        if ((*M).T[i].key == K)
            found = true;
        else
            i++;
    }
    if (!found)
    {
        (*M).T[(*M).NbMapElmt+1].key = K;
        (*M).T[(*M).NbMapElmt+1].value = V;
        (*M).NbMapElmt++;
    }
    else
    {
        (*M).T[i].key = K;
        (*M).T[i].value = V;
    }
}

void DeleteMap(keytype K, Map *M)
{
    int i=1,j;
    boolean found = false;
    while ((!found)&&(i<=(*M).NbMapElmt))
    {
        if ((*M).T[i].key == K)
            found = true;
        else
            i++;
    }
    if (found)
    {
        for (j=i; j<=(*M).NbMapElmt; j++)
        {
            (*M).T[j].key=(*M).T[j+1].key;
            (*M).T[j].value=(*M).T[j+1].value;
        }
        (*M).NbMapElmt--;
    }
}

void ReassignMap(keytype K, infomaptype V, Map *M)
{
    int i=1;
    boolean found = false;
    while ((!found)&&(i<=(*M).NbMapElmt))
    {
        if ((*M).T[i].key == K)
            found = true;
        else
            i++;
    }
    if (found)
        (*M).T[i].value = V;
}

infomaptype ValueOfMap (keytype K, Map M)
{
    int i=1;
    boolean found = false;
    while ((!found)&&(i<=M.NbMapElmt))
    {
        if (M.T[i].key == K)
        {
            found = true;
            return M.T[i].value;
        }
        else
            i++;
    }
    return 0;
}


void TulisMap(Map M)
/* I.S Sembarang
   F.S Mencetak isi Map ke layar */
{
    int i;
    if (IsMapEmpty(M))
        printf("Map kosong\n");
    else
    {
        for (i=1; i<=M.NbMapElmt; i++)
        {
            printf("(%c,%d)\n",M.T[i].key,M.T[i].value);
        }
    }
}

/* MAIN PROGRAM RELATED CODE */
void InitScoreMap()
/* I.S. M Terdefinisi
   F.S. M berisi map huruf ke skornya */
{
    CreateEmptyMap(&M);
    InsertMap('E',1,&M);
    InsertMap('A',2,&M);
    InsertMap('I',2,&M);
    InsertMap('N',2,&M);
    InsertMap('O',2,&M);
    InsertMap('R',2,&M);
    InsertMap('S',2,&M);
    InsertMap('T',2,&M);
    InsertMap('C',3,&M);
    InsertMap('D',3,&M);
    InsertMap('L',3,&M);
    InsertMap('G',4,&M);
    InsertMap('H',4,&M);
    InsertMap('M',4,&M);
    InsertMap('P',4,&M);
    InsertMap('U',4,&M);
    InsertMap('B',5,&M);
    InsertMap('F',5,&M);
    InsertMap('Y',5,&M);
    InsertMap('K',6,&M);
    InsertMap('V',6,&M);
    InsertMap('W',6,&M);
    InsertMap('Z',8,&M);
    InsertMap('X',9,&M);
    InsertMap('J',10,&M);
    InsertMap('Q',10,&M);
}

int Score (Kata K)
// Mengeluarkan skor yang dihasilkan dari kata K
{
    int nilai = 0;
    int i = 1;
    while (i <= K.Length)
    {
        nilai = nilai + ValueOfMap(K.TabKata[i],M);
        i++;
    }
    if (K.Length >= 10)
        nilai = nilai + 100;
    return nilai;
}

int TotalScore(Set S1)
// Mengeluarkan total skor dari seluruh kata dalam Set S1
{
    int i;
	int skortot = 0;
    for (i=1; i<=SetNbElmt(S1); i++)
    {
        skortot = skortot + Score(S1.T[i]);
    }
    return skortot;
}
