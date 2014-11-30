/* File : mArrayOfKata.c */

#include "ArrayOfKata.h"
#include "mesinkata1.h"
#include <stdio.h>
#include <string.h>
#include "boolean.h"

int main ()
{
	TabK users;
	char nama[20];
	Kata namauser;
	int i;

	MakeAKEmpty(&users);
    STARTKATA("NamaUser.txt");
    while (!EndKata)
    {
        AddAsLastEl(&users,CKata);
        ADVKATA();
    }
	printf("Masukkan nama = ");
	scanf("%s",nama);
    namauser.Length=strlen(nama);
    for (i=1; i<=namauser.Length; i++)
        namauser.TabKata[i]=nama[i-1];
    if (SearchB (users, namauser))
        printf("Nama sudah ada di array");
    else
		printf("Nama belum ada di array");

	return 0;
}