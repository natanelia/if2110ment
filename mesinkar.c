#include <stdio.h>
#include "mesinkar.h"
char CC;
boolean EOP;
static FILE *pita;
static int retval;

void START(char *filename) {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
Karakter pertama yang ada pada pita posisinya adalah pada jendela.
I.S. : sembarang
F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka
EOP akan padam (false). Jika CC = MARK maka EOP akan menyala (true)
*/

    /* Algoritma */
    pita = fopen(filename,"r+");
    ADV();
}

void ADV() {
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela =
CC, CC != MARK
F.S. : CC adalah karakter
berikutnya dari CC yang
lama,
CC mungkin = MARK
Jika CC = MARK maka EOP
akan menyala (true) */

/* Algoritma */
    retval = fscanf(pita,"%c",&CC);
    EOP = (CC == MARK);
    if (EOP) {
        fclose(pita);
    }
}

int charToInteger(char num) {
	switch (num){
        case '1' : return 1;	break;
        case '2' : return 2;	break;
        case '3' : return 3;	break;
        case '4' : return 4;	break;
        case '5' : return 5;	break;
        case '6' : return 6;	break;
        case '7' : return 7;	break;
        case '8' : return 8;	break;
        case '9' : return 9;    break;
        default  : return 0;
	}
}

char integerToChar(int num){
	switch (num){
        case 1 : return '1';	break;
        case 2 : return '2';	break;
        case 3 : return '3';	break;
        case 4 : return '4';	break;
        case 5 : return '5';	break;
        case 6 : return '6';	break;
        case 7 : return '7';	break;
        case 8 : return '8';	break;
        case 9 : return '9';    break;
        default  : return '0';
	}
}
