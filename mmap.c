#include <stdio.h>
#include <stdlib.h>
#include "map.h"
Map M1, M2;
int main()
{
    CreateEmptyMap(M1);
    CreateEmptyMap(M2);
    TulisMap(M1);
    TulisMap(M2);
    InsertMap(5,1,&M1);
    InsertMap(7,5,&M1);
    InsertMap(8,4,&M1);
    InsertMap(9,7,&M1);
    InsertMap(10,9,&M2);
    InsertMap(1,4,&M2);
    InsertMap(2,5,&M2);
    InsertMap(3,6,&M2);
    TulisMap(M1);
    printf("\n");
    TulisMap(M2);
    printf("\n");
    DeleteMap(10,&M1);
    DeleteMap(10,&M2);
    TulisMap(M1);
    printf("\n");
    TulisMap(M2);
    printf("\n");
    printf("Elemen M1 dengan key 7 : %d\n",ValueOfMap(7,M1));
    printf("Elemen M2 dengan key 10 : %d\n",ValueOfMap(10,M2));
    printf("Mengubah value key 9 pada M1 menjadi 10\n");
    ReassignMap(9,10,&M1);
    TulisMap(M1);
    printf("\n");
    printf("Mengubah value key 7 pada M2 menjadi 3\n");
    ReassignMap(7,3,&M2);
    TulisMap(M2);
    return 0;
}
