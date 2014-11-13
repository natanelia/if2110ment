#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <time.h>
#include "boolean.h"
#include "matriks.h" //untuk merepresentasikan board permainan
#include "mesinkar.h" //untuk mesinkata
#include "mesinkata1.h" //untuk membaca kamus data dan file eksternal
#include "point.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

//KAMUS GLOBAL
MATRIKS boards[10];
Kata kamusKata[109000];
int kamusKataNeff;
int selectedBoard;
POINT kursor;
POINT chosen;

// FUNGSI DAN PROSEDUR
void resetTermios();
void initTermios();
int kbhit();
char getch();
void Play(double seconds);
void InitBoard();
void UpdateLayout();
void ReadBoards();
void ReadDictionary();
void clrscr(void);
void DisplayBoard();
void MainMenu();
void PreparationMenu ();


static struct termios old_termios, new_termios;
/* restore new terminal i/o settings */
void resetTermios() {
    tcsetattr(0,TCSANOW,&old_termios);
}
/* initialize new terminal i/o settings */
void initTermios() {
    tcgetattr(0,&old_termios); // store old terminal
    new_termios = old_termios; // assign to new setting
    new_termios.c_lflag &= ~ICANON; // disable buffer i/o
    new_termios.c_lflag &= ~ECHO; // disable echo mode
    tcsetattr(0,TCSANOW,&new_termios); // use new terminal setting
}
/* detect keyboard press */
int kbhit() {
    struct timeval tv = {0L,0L};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0,&fds);
    return select(1,&fds,NULL,NULL,&tv);
}
/* read 1 character */
char getch() {
    char ch;
    ch = getchar();
    return ch;
}
/* skeleton program for play */
void Play(double seconds){
    InitBoard();
    initTermios(); // initailize new terminal setting to make kbhit() and getch() work
    char cc;
    const double TIME_LIMIT = seconds * CLOCKS_PER_SEC;
    clock_t startTime = clock();
    while ((clock() - startTime) <= TIME_LIMIT) {
        if (kbhit()) {
            cc = getch();
            resetTermios(); // reset terminal setting to enable buffer i/o and echo (printf)

            switch(cc)
            {
                case 'q' :  if (kursor.X > FirstIdxBrs(boards[selectedBoard]) && (kursor.Y > FirstIdxKol(boards[selectedBoard])))
                            {
                                kursor.X--;
                                kursor.Y--;
                            }
                            break;

                case 'w' :  if (kursor.X > FirstIdxBrs(boards[selectedBoard]))
                                kursor.X--;
                            break;

                case 'e' :  if (kursor.X > FirstIdxBrs(boards[selectedBoard]) && (kursor.Y < LastIdxKol(boards[selectedBoard])))
                            {
                                kursor.X--;
                                kursor.Y++;
                            }
                            break;

                case 'a' :  if (kursor.Y > FirstIdxKol(boards[selectedBoard]))
                                kursor.Y--;
                            break;

                case 's' :  chosen.X = kursor.X;
                            chosen.Y = kursor.Y;
                            break;

                case 'd' :  if (kursor.Y < LastIdxKol(boards[selectedBoard]))
                                kursor.Y++;
                            break;

                case 'z' :  if (kursor.X < LastIdxBrs(boards[selectedBoard]) && (kursor.Y > FirstIdxKol(boards[selectedBoard])))
                            {
                                kursor.X++;
                                kursor.Y--;
                            }
                            break;

                case 'x' :  if (kursor.X < LastIdxBrs(boards[selectedBoard]))
                                kursor.X++;
                            break;

                case 'c' :  if (kursor.X < LastIdxBrs(boards[selectedBoard]) && (kursor.Y < LastIdxKol(boards[selectedBoard])))
                            {
                                kursor.X++;
                                kursor.Y++;
                            }
                            break;
            }
            UpdateLayout();

            printf("\nSelected Char: %c\n",GetElmt(boards[selectedBoard],kursor.X,kursor.Y)); // process character
            initTermios(); // use new terminal setting again to make kbhit() and getch() work
        }
    }
    printf("\nTime Up\n");
    resetTermios(); // restore default terminal setting
}

void InitBoard()
{
    kursor = MakePoint(1,1);
    UpdateLayout();
}

void UpdateLayout()
{
    clrscr();
    //Print Matriks
    int i,j;
    for (i=FirstIdxBrs(boards[selectedBoard]);i<=LastIdxBrs(boards[selectedBoard]);i++)
    {
        for (j=FirstIdxKol(boards[selectedBoard]);j<=LastIdxKol(boards[selectedBoard]);j++)
        {
            if (chosen.X == i && chosen.Y == j)
            {
                printf(ANSI_COLOR_CYAN " %c " ANSI_COLOR_RESET, GetElmt(boards[selectedBoard],i,j));
            }
            else if (kursor.X == i && kursor.Y == j)
            {
                printf(ANSI_COLOR_YELLOW " %c " ANSI_COLOR_RESET, GetElmt(boards[selectedBoard],i,j));
            }
            else
            {
                printf(" %c ", GetElmt(boards[selectedBoard],i,j));
            }
        }
        printf("\n");
    }
}

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
        filename[7]=integerToChar(i);
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
        //TulisMATRIKS(boards[i]);
    }
}

void ReadDictionary()
//I.S sembarang
//F.S MATRIKS boards berisi semua board yang ada di folder boards.
{
    int i = 0;
    int j;
    STARTKATA("Dictionary.txt");
    while (!EndKata)
    {
        CopyKata(CKata,&kamusKata[i]);
        i++;
        ADVKATA();
    }
    kamusKataNeff = i-1;
}

void clrscr(void) {
  system("clear");
}

void DisplayBoard() {
/* KAMUS LOKAL */
int i,j;
/* ALGORITMA */
	ReadBoards();
	for (i=FirstIdxBrs(boards[0]);i<=LastIdxBrs(boards[0]);i++){
		for (j=FirstIdxBrs(boards[0]);j<=LastIdxBrs(boards[0]);j++){
			printf(" %c ", GetElmt(boards[0],i,j));
		}
		printf("          ");
		for (j=FirstIdxBrs(boards[1]);j<=LastIdxBrs(boards[1]);j++){
			printf(" %c ", GetElmt(boards[1],i,j));
		}
		printf("          ");
		for (j=FirstIdxBrs(boards[2]);j<=LastIdxBrs(boards[2]);j++){
			printf(" %c ", GetElmt(boards[2],i,j));
		}
		printf("          ");
		for (j=FirstIdxBrs(boards[3]);j<=LastIdxBrs(boards[3]);j++){
			printf(" %c ", GetElmt(boards[3],i,j));
		}
		printf("\n");
	}
	printf(ANSI_COLOR_MAGENTA "   Board 0               Board 1               Board 2              Board 3\n\n" ANSI_COLOR_RESET );
	for (i=FirstIdxBrs(boards[4]);i<=LastIdxBrs(boards[4]);i++){
		for (j=FirstIdxBrs(boards[4]);j<=LastIdxBrs(boards[4]);j++){
			printf(" %c ", GetElmt(boards[4],i,j));
		}
		printf("          ");
		for (j=FirstIdxBrs(boards[5]);j<=LastIdxBrs(boards[5]);j++){
			printf(" %c ", GetElmt(boards[5],i,j));
		}
		printf("          ");
		for (j=FirstIdxBrs(boards[6]);j<=LastIdxBrs(boards[6]);j++){
			printf(" %c ", GetElmt(boards[6],i,j));
		}
		printf("          ");
		for (j=FirstIdxBrs(boards[7]);j<=LastIdxBrs(boards[7]);j++){
			printf(" %c ", GetElmt(boards[7],i,j));
		}
		printf("\n");
	}
	printf(ANSI_COLOR_MAGENTA "   Board 4               Board 5               Board 6              Board 7\n\n" ANSI_COLOR_RESET);
	for (i=FirstIdxBrs(boards[8]);i<=LastIdxBrs(boards[8]);i++){
		printf("                     ");
		for (j=FirstIdxBrs(boards[8]);j<=LastIdxBrs(boards[8]);j++){
			printf(" %c ", GetElmt(boards[8],i,j));
		}
		printf("          ");
		for (j=FirstIdxBrs(boards[9]);j<=LastIdxBrs(boards[9]);j++){
			printf(" %c ", GetElmt(boards[9],i,j));
		}
		printf("\n");
	}
		printf(ANSI_COLOR_MAGENTA "                       Board 8                Board 9\n\n" ANSI_COLOR_RESET);
}
	
void MainMenu() {
/* Kamus Lokal */
	int pil;
/* Algoritma */	
	printf(ANSI_COLOR_RED  "[1] Register      " ANSI_COLOR_RESET ANSI_COLOR_BLUE  "[2] Login     "  ANSI_COLOR_RESET ANSI_COLOR_GREEN   "[3] How To Play     "   ANSI_COLOR_RESET ANSI_COLOR_YELLOW  "[4] About     "  ANSI_COLOR_RESET ANSI_COLOR_MAGENTA "[5] Quit    " ANSI_COLOR_RESET);
    	printf("\n\n");
	printf("Menu yang dipilh= ");
    	scanf("%d",&pil);
    	switch (pil) {
		case 1:{clrscr(); PreparationMenu(); break;}
		case 2:{clrscr(); PreparationMenu(); break;}
		case 3:{clrscr(); PreparationMenu(); break;}
		case 4:{clrscr(); PreparationMenu(); break;}
		case 5:{clrscr(); PreparationMenu(); break;}
	}
}

void PreparationMenu () {
/* Kamus Lokal */
	int pil;
	int pilboard; //pilihan board
/* Algoritma */
	printf(ANSI_COLOR_RED  "          [1] Play Game     " ANSI_COLOR_RESET ANSI_COLOR_BLUE  "[2] Select Board    "  ANSI_COLOR_RESET ANSI_COLOR_GREEN   "[3] View My Highscore    \n"   ANSI_COLOR_RESET ANSI_COLOR_YELLOW  "                    [4] View All Highscore    "  ANSI_COLOR_RESET ANSI_COLOR_MAGENTA "[5] Logout   \n" ANSI_COLOR_RESET);
    	printf("Menu yang dipilh= ");
    	scanf("%d",&pil);
    	switch (pil)
    	{
        	case 1 : Play(120); break;
		case 2 : { clrscr();
		  	DisplayBoard();
		  	printf("Masukkan pilihan board= ");
		  	scanf("%d",&pilboard);
		  	selectedBoard=pilboard;
		  	Play(120);
		  	break;
			}
        	default : break;
	
    }
}


int main()
{
    int pil; //pilihan menu
    

    selectedBoard = 0;
    ReadBoards();
    ReadDictionary();


    /*printf(ANSI_COLOR_RED     "This text is RED!"     ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_GREEN   "This text is GREEN!"   ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_YELLOW  "This text is YELLOW!"  ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_BLUE    "This text is BLUE!"    ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_MAGENTA "This text is MAGENTA!" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_CYAN    "This text is CYAN!"    ANSI_COLOR_RESET "\n");*/

    printf("WORDAMENT!\n");
    printf("Pilih menu\n");
    MainMenu();
   
    

    return 0;
}
