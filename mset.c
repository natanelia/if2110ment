#include <stdio.h>
#include <stdlib.h>
#include "set.h"
Set S1,S2,S3;
infotype input;
int main()
{
    CreateEmptySet(&S1);
    CreateEmptySet(&S2);
    CreateEmptySet(&S3);
    TulisSet(S1);
    printf("\n");
    TulisSet(S2);
    printf("\n");
    InsertSet(&S1,5);
    InsertSet(&S1,6);
    InsertSet(&S1,7);
    InsertSet(&S1,8);
    InsertSet(&S1,9);
    InsertSet(&S2,1);
    InsertSet(&S2,5);
    InsertSet(&S2,6);
    InsertSet(&S2,3);
    InsertSet(&S2,10);
    TulisSet(S1);
    printf("\n");
    TulisSet(S2);
    printf("\n");
    UnionSet(S1,S2,&S3);
    TulisSet(S3);
    printf("\n");
    CreateEmptySet(&S3);
    IntersectionSet(S1,S2,&S3);
    TulisSet(S3);
    printf("\n");
    SetDifference(S1,S2,&S3);
    TulisSet(S3);
    printf("\n");
    printf("Elemen terkecil Set S1 : %d\n",SetMin(S1));
    printf("Elemen terbesar Set S2 : %d\n",SetMax(S2));
    return 0;
}
