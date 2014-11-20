#include "set.h"
#include "boolean.h"
#include "mesinkata1.h"
#include <stdio.h>
boolean IsSetEmpty(Set S)
{
    return (SetNbElmt(S) == 0);
}

boolean IsSetFull(Set S)
{
    return (SetNbElmt(S) == MaxEl);
}

int SetNbElmt(Set S)
{
    return S.NbElmt;
}

void CreateEmptySet(Set *S)
{
    (*S).NbElmt = 0;
}

void InsertSet(Set *S, infosettype X)
{
    if (IsSetEmpty(*S))
    {
        (*S).T[SetNbElmt(*S)+1] = X;
        (*S).NbElmt++;
    } else
    {
        if (!IsSetMember(*S,X))
        {
            (*S).T[SetNbElmt(*S)+1] = X;
            (*S).NbElmt++;
        }
    }
}

void DeleteSet(Set *S, infosettype X)
{
    int i,j;
    infosettype temp;
    boolean found;
    temp = (*S).T[1];
    found = false;
    while (((i+1)<=SetNbElmt(*S))&& (!found))
    { 
        if (IsKataSama(temp,(*S).T[i]))
            found = true;
        else
            i++;
    }
    for (j=i;j<=SetNbElmt(*S);j++)
        (*S).T[j]=(*S).T[j+1];
    (*S).NbElmt--;
}

boolean IsSetMember(Set S, infosettype X)
{
    int i;
    int j=1;
    int k=1;
    boolean found;
    found = false;
    i = 1;
    while ((i<=SetNbElmt(S)) && (!found))
    {
		if (IsKataSama(S.T[i],X))
            found = true;
        else
            i++;
    }
    return found;
}

boolean IsSetEqual(Set S1, Set S2)
{
    int i;
    boolean equal;
    i = 1;
    equal = true;
    if (SetNbElmt(S1)==SetNbElmt(S2))
    {
        if (SetNbElmt(S1)==0)
            return equal;
        else
        {
            while ((equal) && (i<=SetNbElmt(S1)))
            {
                equal = IsSetMember(S1,S2.T[i]);
                i++;
            }
        }
    }
    else
        return !equal;
}

void UnionSet(Set S1, Set S2, Set *S3)
{
    int i;
    CopySet(S1,&*S3);
    for (i=1;i<=SetNbElmt(S2);i++)
    {
        InsertSet(&*S3,S2.T[i]);
    }
}

void IntersectionSet(Set S1, Set S2, Set *S3)
{
    int i;
    if (SetNbElmt(S2)>=SetNbElmt(S1))
    {
        for (i=1;i<=SetNbElmt(S1);i++)
        {
            if (IsSetMember(S2,S1.T[i]))
                InsertSet(&*S3,S1.T[i]);
        }
    } else
    {
        for (i=1;i<=SetNbElmt(S2);i++)
        {
            if (IsSetMember(S1,S2.T[i]))
                InsertSet(&*S3,S2.T[i]);
        }
    }

}

void SetDifference (Set S1, Set S2, Set *S3)
{
    int i;
    CopySet(S1,&*S3);
    for (i=1;i<=SetNbElmt(S2);i++)
    {
        if (IsSetMember(*S3,S2.T[i]))
            DeleteSet(&*S3,S2.T[i]);
    }
}

/*infosettype SetMin(Set S)
{
    infosettype temp;
    int i;
    temp = S.T[1];
    for (i=1;i<=SetNbElmt(S);i++)
    {
        if (temp > S.T[i])
            temp = S.T[i];
    }
    return temp;

}

infosettype SetMax(Set S)
{
    infosettype temp;
    int i;
    temp = S.T[1];
    for (i=1;i<=SetNbElmt(S);i++)
    {
        if (temp < S.T[i])
            temp = S.T[i];
    }
    return temp;

}*/

void CopySet(Set S1, Set *S2)
{
    (*S2)=S1;
}

void TulisSet(Set S)
{
    int i;
    int j=1;
    if (IsSetEmpty(S))
        printf("Set kosong\n");
    else
    {
        for (i=1;i<=SetNbElmt(S);i++)
        {
			printKata(S.T[i]);
			printf("\n");
        }
        printf("---Press Enter to continue---");
    }

}

