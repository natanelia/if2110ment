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
    } else
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
        for (j=i;j<=(*M).NbMapElmt;j++)
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
}

void TulisMap(Map M)
{
    int i;
    if (IsMapEmpty(M))
        printf("Map kosong\n");
    else
    {
        for (i=1;i<=M.NbMapElmt;i++)
        {
            printf("(%c,%d)\n",M.T[i].key,M.T[i].value);
        }
    }
}
