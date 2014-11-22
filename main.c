#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <time.h>
#include "boolean.h"
#include "matriks.h" //untuk merepresentasikan board permainan
#include "mesinkar.h" //untuk mesinkata
#include "mesinkata1.h" //untuk membaca kamus data dan file eksternal
#include "point.h"
#include "stacklist.h"
#include "ADT_MultiList.h"
#include "ArrayOfKata.h" //untuk membaca file berisi nama-nama user dan menyimpannya di array
#include "map.c"
#include "set.c"
#include "PrioQueueList.h"

#define ANSI_BACKGROUND_BLACK "\e[37m\e[40m"
#define ANSI_BACKGROUND_RED "\e[37m\e[41m"
#define ANSI_BACKGROUND_GREEN "\e[37m\e[42m"
#define ANSI_BACKGROUND_YELLOW "\e[37m\e[43m"
#define ANSI_BACKGROUND_BLUE "\e[37m\e[44m"
#define ANSI_BACKGROUND_MAGENTA "\e[37m\e[45m"
#define ANSI_BACKGROUND_CYAN "\e[37m\e[46m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

//gcc -o coba ADT_MultiList.c ArrayOfKata.c jam.c main.c map.c matriks.c mesinkar.c mesinkata1.c point.c PrioQueueList.c QueueList.c set.c stacklist.c tanggal.c waktu.c -lm

//KAMUS GLOBAL
MATRIKS boards[10];
Kata kamusKata[109000];
int kamusKataNeff;
int selectedBoard;
POINT kursor;
POINT kursorTemp;
POINT chosen;
int tempTime; //sisa waktu dalam sekon
int playTime; //waktu permainan dalam sekon
TabK users;	//array of Kata, isinya nama-nama user yg udah pernah diregister-in
Kata namauser;	//nama user yang saat ini sedang log in
short isSHit; // Counter penghitung tombol 's' sudah dipencet berapa kali
Stack StackKata;
Kata InsertedKata;
ARRAYPOINT P;
char nama[15];
Kata AcceptedKata;
//int acceptedKataNeff;
Map M;
Set S1;
List HighScoreList;
PrioQueue PQ;


// FUNGSI DAN PROSEDUR
void resetTermios();
void initTermios();
int kbhit();
char getch();
boolean IsInDictionary(Kata K);
void PauseScreen();
void Play(double seconds);
void InitBoard();
void UpdateLayout();
void ReadBoards();
void ReadDictionary();
void clrscr(void);
void DisplayBoard();
void MainMenu();
void PreparationMenu ();
void ResultMenu();
void ReadUser();
void Register (Kata *namauser);
void Login (Kata *namauser);
void SalinKeEks(TabK users);
void InitScoreMap();
void PrintChosenWords(PrioQueue PQ);
int TotalScore();
int Score (Kata K);
void PutarBoard (MATRIKS *M);
void InsertPrioQueue (Set S, PrioQueue *PQ);
void MyHighScoreMenu ();
void AllHighScoreMenu ();


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
    char word;
    int stackPop;
    int i;

    InitBoard();
    InsertedKata.Length = 0;
    initTermios(); // initailize new terminal setting to make kbhit() and getch() work
    char cc;
    const double TIME_LIMIT = seconds * CLOCKS_PER_SEC;
    clock_t startTime = clock();
    tempTime = 0; //added
    //CreateEmptyStack(&StackKata);
    while ((clock() - startTime) <= TIME_LIMIT) {
        if (tempTime != (clock() - startTime)/CLOCKS_PER_SEC)
        {
            tempTime = (clock() - startTime)/CLOCKS_PER_SEC;
            UpdateLayout();
        }
        if (kbhit()) {
            cc = getch();
            resetTermios(); // reset terminal setting to enable buffer i/o and echo (printf)
            kursorTemp.X = kursor.X;
            kursorTemp.Y = kursor.Y;
            switch(cc)
            {
                case 'q' :  if (kursor.X > FirstIdxBrs(boards[selectedBoard]) && (kursor.Y > FirstIdxKol(boards[selectedBoard])))
                            {
                                kursor.X--;
                                kursor.Y--;
                            }
                            break;

                case 'w' :  if (kursor.X > FirstIdxBrs(boards[selectedBoard]))
                            {
                                kursor.X--;
                            }
                            break;

                case 'e' :  if (kursor.X > FirstIdxBrs(boards[selectedBoard]) && (kursor.Y < LastIdxKol(boards[selectedBoard])))
                            {
                                kursor.X--;
                                kursor.Y++;
                            }
                            break;

                case 'a' :  if (kursor.Y > FirstIdxKol(boards[selectedBoard]))
                            {
                                kursor.Y--;
                            }
                            break;

                case 's' :  if (isSHit == 0)
                            {
                                chosen.X = kursor.X;
                                chosen.Y = kursor.Y;
                                isSHit=1; //Ditekan
                            }
                            else if (isSHit == 1)
                            {
                                isSHit=2; //Submit kata
                                chosen.X = 0;
                                chosen.Y = 0;
                            }
                            break;

                case 'd' :  if (kursor.Y < LastIdxKol(boards[selectedBoard]))
                            {
                                kursor.Y++;
                            }
                            break;

                case 'z' :  if (kursor.X < LastIdxBrs(boards[selectedBoard]) && (kursor.Y > FirstIdxKol(boards[selectedBoard])))
                            {
                                kursor.X++;
                                kursor.Y--;
                            }
                            break;

                case 'x' :  if (kursor.X < LastIdxBrs(boards[selectedBoard]))
                            {
                                kursor.X++;
                            }
                            break;

                case 'c' :  if (kursor.X < LastIdxBrs(boards[selectedBoard]) && (kursor.Y < LastIdxKol(boards[selectedBoard])))
                            {
                                kursor.X++;
                                kursor.Y++;
                            }
                            break;
		case 'r' : PutarBoard(&boards[selectedBoard]);
			   break;
            }

            //Bila pencetan keyboard tidak membuat kursor keluar dari board, lakukan
            if (kursorTemp.X != kursor.X || kursorTemp.Y != kursor.Y || cc=='s')
            {
                stackPop = SearchArrayPoint(P,kursor);
                if ((cc != 's') && (stackPop != -1)){
                    //Set kursor di posisi stackPop
                    if (chosen.X != 0 && chosen.Y !=0) {
                        kursor.X = P.point[stackPop].X;
                        kursor.Y = P.point[stackPop].Y;
                    }

                    for (i=P.neff-stackPop;i>=1;i--)
                    {
                        Pop(&StackKata,&word);
                        P.neff--;
                    }
                }
                /* Jika ada point yang sudah dilewati kursor (setelah menekan tombol s),
                maka pop semua kata sehingga tersisa huruf awal saat menekan s saja */
                 else
                 {
                    if (isSHit==2){
                        //Proses kata ke dictionary
                        StackKata = reverseStack(StackKata);
                        while(!IsEmptyStack(StackKata)){
                            Pop(&StackKata,&word);
                            InsertedKata.Length++;
                            InsertedKata.TabKata[InsertedKata.Length] = word;
                            P.neff = 0;
                        }
                        if (IsInDictionary(InsertedKata))
                        {
                            //acceptedKataNeff++;
                            CopyKata(InsertedKata,&AcceptedKata);
                            InsertSet(&S1,AcceptedKata);
                        }
                        InsertedKata.Length=0;

                        isSHit = 0;
                    }
                    else if (isSHit==1){
                        P.neff++;
                        SetAbsis(&P.point[P.neff],kursor.X);
                        SetOrdinat(&P.point[P.neff],kursor.Y);
                        Push(&StackKata,GetElmt(boards[selectedBoard],kursor.X,kursor.Y));
                    }
                 }
            }

	    InsertPrioQueue(S1, &PQ);
            UpdateLayout();

            initTermios(); // use new terminal setting again to make kbhit() and getch() work
        }
    }
    /*printf("\nTime Up\n");
    printf("Kata-kata yang berhasil dibentuk : \n");
    TulisSet(S1);
    getch();*/
    resetTermios(); // restore default terminal setting
    ResultMenu();
}

void InitBoard()
{
    kursor = MakePoint(1,1);
    isSHit = 0;
    P.neff = 0;
    chosen.X = 0;
    chosen.Y = 0;
    //acceptedKataNeff = 0;
    CreateEmptySet(&S1);
    InitScoreMap();

    UpdateLayout();
}

void UpdateLayout() {


    clrscr();
    printf("\n");
    printf(" User: ");
    printKata(namauser);
    //Print Time
    printf("%17d:%02d\n",(playTime - tempTime)/60,(playTime - tempTime)%60);

    //Print Matriks
    int i,j;
    POINT sel;
    printf("\n" "        " ANSI_BACKGROUND_BLACK "                  " ANSI_COLOR_RESET "\n");
    for (i=FirstIdxBrs(boards[selectedBoard]);i<=LastIdxBrs(boards[selectedBoard]);i++)
    {

        printf("       " ANSI_BACKGROUND_BLACK "    " ANSI_COLOR_RESET);
        for (j=FirstIdxKol(boards[selectedBoard]);j<=LastIdxKol(boards[selectedBoard]);j++)
        {
            sel.X = i; sel.Y = j;
            if (chosen.X == i && chosen.Y == j)
            {
                printf(ANSI_BACKGROUND_RED " %c " ANSI_COLOR_RESET, GetElmt(boards[selectedBoard],i,j));
            }
            else if (SearchArrayPoint(P,sel) != -1)
            {
                printf(ANSI_BACKGROUND_MAGENTA " %c " ANSI_COLOR_RESET, GetElmt(boards[selectedBoard],i,j));
            }
            else if (kursor.X == i && kursor.Y == j)
            {
                printf(ANSI_BACKGROUND_CYAN " %c " ANSI_COLOR_RESET, GetElmt(boards[selectedBoard],i,j));
            }
            else
            {
                printf(ANSI_BACKGROUND_BLACK " %c " ANSI_COLOR_RESET, GetElmt(boards[selectedBoard],i,j));
            }
        }
        printf(ANSI_BACKGROUND_BLACK "    " ANSI_COLOR_RESET);
        printf("\n");
    }
    printf("        " ANSI_BACKGROUND_BLACK "                  " ANSI_COLOR_RESET "\n\n");
    printf(" "); PrintStack(reverseStack(StackKata));
    printKata(InsertedKata);
    if (SetNbElmt(S1)>=1)
    {
        printf(" GOT "); printKata(AcceptedKata); printf("!\n");
        printf(" Total Score : %d\n",TotalScore());
	}
	printf(" ");
    //printf("  "); printf("%c\n",GetElmt(boards[selectedBoard],kursor.X,kursor.Y)); // process character
}

int TotalScore() {
    int i;
	int skortot = 0;
	for (i=1;i<=SetNbElmt(S1);i++)
	{
		skortot = skortot + Score(S1.T[i]);
	}
    return skortot;
}

void ReadBoards() {
//I.S sembarang
//F.S MATRIKS boards berisi semua board yang ada di folder boards.
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

void ReadDictionary() {
//I.S sembarang
//F.S MATRIKS boards berisi semua board yang ada di folder boards.
    int i = 0;
    STARTKATA("Dictionary.txt");
    while (!EndKata)
    {
        CopyKata(CKata,&kamusKata[i]);
        i++;
        ADVKATA();
    }
    kamusKataNeff = i-1;
}

boolean IsInDictionary(Kata K) {
//Mencari kata K dalam kamus dan return true bila ada.
    int i = 0;
    boolean found = false;
    while (i<=kamusKataNeff && !found)
    {
        if (K.Length == kamusKata[i].Length)
        {
            if (IsKataSama(K,kamusKata[i]))
                found = true;
        }
        i++;
    }
    return found;
}

void clrscr(void) {
  //system("clear");
  printf("\033\143");
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
    clrscr();
    printf("===========================WELCOME TO FAKEWORDAMENT===========================\n");
	printf(ANSI_COLOR_RED  "[1] Register      " ANSI_COLOR_RESET ANSI_COLOR_CYAN  "[2] Login     "  ANSI_COLOR_RESET ANSI_COLOR_GREEN   "[3] How To Play     "   ANSI_COLOR_RESET ANSI_COLOR_YELLOW  "[4] About     "  ANSI_COLOR_RESET ANSI_COLOR_MAGENTA "[5] Quit    " ANSI_COLOR_RESET);
    	printf("\n\n");
	printf("Menu yang dipilih: ");
    	scanf("%d",&pil);
    	switch (pil) {
		case 1:{clrscr(); Register(&namauser); break;}
		case 2:{clrscr(); Login(&namauser); break;}
		case 3:{clrscr(); PreparationMenu(); break;}
		case 4:{clrscr(); PreparationMenu(); break;}
		case 5:{clrscr(); break;}
	}
}

void PreparationMenu () {
/* Kamus Lokal */
	int pil = 0;
	int pilboard; //pilihan board
/* Algoritma */
    do {
	ReadBoards();
        clrscr();
        printf("User: "); printKata(namauser); printf("                                                  Selected Board: %d\n\n",selectedBoard);
        printf(ANSI_COLOR_RED  "          [1] Play Game     " ANSI_COLOR_RESET ANSI_COLOR_CYAN  "[2] Select Board    "  ANSI_COLOR_RESET ANSI_COLOR_GREEN   "[3] View My Highscore    \n"   ANSI_COLOR_RESET ANSI_COLOR_YELLOW  "                    [4] View All Highscore    "  ANSI_COLOR_RESET ANSI_COLOR_MAGENTA "[5] Logout   \n" ANSI_COLOR_RESET);

        printf("\nMenu yang dipilih: ");
        scanf("%d",&pil);
        switch (pil)
        {
            case 1 : Play(playTime); break;
            case 2 : clrscr();
                     DisplayBoard();
                     printf("Masukkan pilihan board: ");
                     scanf("%d",&pilboard);
                     clrscr();
                     selectedBoard=pilboard;
                     PreparationMenu();
                     break;
            case 3 : MyHighScoreMenu();
                     break;
            case 4 : AllHighScoreMenu();
                     break;
            case 5 : MainMenu();
                     break;
            default: printf("ERROR: Masukan salah, coba ulangi!\n");
                     getch();
                     PauseScreen(1);

        }
    } while (pil < 1 || pil > 5);
}

void ResultMenu () {
//Shows complete statistic including username, score, date, board, words formed, and top 5 high scores for that board.
    time_t t = time(0);
    struct tm *infoTime = localtime(&t);

    clrscr();
    printf(" ==TIME UP, " ANSI_COLOR_CYAN); printKata(namauser); printf(ANSI_COLOR_RESET "!==\n");
    printf("  Board No.  : %d\n", selectedBoard);
    printf("  Your Score : %d\n", TotalScore());
    printf("  Words Found:\n"); PrintChosenWords(PQ);

    //Save Result to File
    RecordType NewRecord;

	NewRecord.UserName = namauser;
	NewRecord.Score = TotalScore();
	Day(NewRecord.Time) = infoTime->tm_mday;
	Month(NewRecord.Time) = infoTime->tm_mon;
	Year(NewRecord.Time) = infoTime->tm_year+1900;
	Hour(NewRecord.Time) = infoTime->tm_hour;
	Minute(NewRecord.Time) = infoTime->tm_min;
	Second(NewRecord.Time) = infoTime->tm_sec;
	InsertGameScore(&HighScoreList, selectedBoard, NewRecord);
	TulisDataBaseScore(HighScoreList);


    printf("\n >> Press ENTER to continue...");
    getch();
    PreparationMenu();
}

void MyHighScoreMenu () {
    clrscr();
    printf("==============================================================================\n");
    printf("========================MY HIGHSCORE for BOARD No. %d==========================\n",selectedBoard);
    printf("==============================================================================\n");
    ViewMyHighscore(HighScoreList,selectedBoard,namauser);
    printf("\n >> Press ENTER to return...");
    getch(); getch();
    PreparationMenu();
}

void AllHighScoreMenu() {
    clrscr();
    printf("==============================================================================\n");
    printf("==========================HIGHSCORE for BOARD No. %d===========================\n",selectedBoard);
    printf("==============================================================================\n");
    ViewAllHighscore(HighScoreList,selectedBoard);
    printf("\n >> Press ENTER to return...");
    getch(); getch();
    PreparationMenu();
}

void ReadUser() {
//I.S sembarang
//F.S Array users berisi nama-nama user di file NamaUser.txt
    MakeAKEmpty(&users);
    STARTKATA("NamaUser.txt");
    while (!EndKata)
    {
        AddAsLastEl(&users,CKata);
        ADVKATA();
    }
}

void Register (Kata *namauser)
{
	/* KAMUS */

	int i=1;
	FILE *fileku;
	char filename[20];

	/* ALGORITMA */
	do
	{	printf("REGISTER\n\n");
		printf("Masukkan nama (tanpa spasi): ");
		scanf("%s",nama);
		(*namauser).Length=strlen(nama);
		for (i=1;i<=(*namauser).Length;i++)
			(*namauser).TabKata[i]=nama[i-1];
		if (SearchB (users, *namauser))
		{
            printf("\n");
            printf(ANSI_BACKGROUND_RED "                                   \n" ANSI_COLOR_RESET);
			printf(ANSI_BACKGROUND_RED "   ERROR: Nama sudah terdaftar!    \n" ANSI_COLOR_RESET);
			printf(ANSI_BACKGROUND_RED "   Ketik 'EXIT' untuk kembali...   \n" ANSI_COLOR_RESET);
			printf(ANSI_BACKGROUND_RED "                                   \n" ANSI_COLOR_RESET);
            PauseScreen(2);
        }
		else
		{
            if (strcmp(nama,"EXIT"))
            {
                printf("\n");
                printf(ANSI_COLOR_RED "Welcome ");
                printKata(*namauser);
                printf("!" ANSI_COLOR_RESET "\n");
                PauseScreen(1);
            }
		}
		clrscr();
	} while (SearchB (users, *namauser));
	if (strcmp(nama,"EXIT"))
	{
        AddAsLastEl(&users,*namauser);
        SalinKeEks(users);
        strcpy(filename, nama);
        strcat(filename, ".txt");
        fileku=fopen(filename, "w");
        fclose(fileku);
        PreparationMenu();
    }
    else
        MainMenu();
}

void SalinKeEks(TabK users)
{
	/* KAMUS */
	static FILE *fileku;
	static int retval;
	int i,j;

	/* ALGORITMA */
	fileku = fopen("NamaUser.txt","w");
	for (i=1; i<=users.Neff; i++)
	{
		for(j=1; j<=users.TI[i].Length; j++) {
			retval=fprintf(fileku, "%c", users.TI[i].TabKata[j] );
		}
		fprintf(fileku, "\n");
	}
	retval=fprintf(fileku, ".");
	fclose(fileku);
}

void Login (Kata *namauser)
{
	/* KAMUS */
	char nama[15];
	int i=1;
	int count=0;
	char pil;

	/* ALGORITMA */
	do
	{
		printf(ANSI_COLOR_CYAN "LOGIN\n\n" ANSI_COLOR_RESET);
		printf("Masukkan nama (tanpa spasi): ");
		scanf("%s",nama);
		(*namauser).Length=strlen(nama);
		for (i=1;i<=(*namauser).Length;i++)
			(*namauser).TabKata[i]=nama[i-1];
		if (!(SearchB (users, *namauser)))
		{
            printf("\n");
            printf(ANSI_BACKGROUND_RED "                                      \n" ANSI_COLOR_RESET);
			printf(ANSI_BACKGROUND_RED "   ERROR! Nama Anda belum terdaftar!  \n" ANSI_COLOR_RESET);
			printf(ANSI_BACKGROUND_RED "                                      \n" ANSI_COLOR_RESET);
            PauseScreen(1);
			count++;
		}
		else
		{
            		printf("\n");
			printf(ANSI_COLOR_CYAN "Welcome ");
			printKata(*namauser);
			printf("!" ANSI_COLOR_RESET "\n");
            		PauseScreen(1);
		}
		clrscr();
	}
	while ((!SearchB(users, *namauser))&&(count<3));
	if (count==3)
	{	printf(ANSI_COLOR_CYAN "LOGIN\n\n" ANSI_COLOR_RESET);
		printf("Apakah anda ingin register? (y/n) ");
		getch();
		scanf("%c",&pil);
		clrscr();
		if (pil=='y')
			Register(namauser);
		else
			MainMenu();
	}
	else
    PreparationMenu();
}

void PauseScreen (int seconds)
{
    const double TIME_LIMIT = seconds * CLOCKS_PER_SEC;
    clock_t startTime = clock();
    //CreateEmptyStack(&StackKata);
    while ((clock() - startTime) <= TIME_LIMIT) {

    }
}

void InitScoreMap()
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

void InsertPrioQueue (Set S, PrioQueue *PQ)
{/* Kamus Lokal */
	int nilai;
	int i;
/* Algoritma */
	CreatePrioQueueEmpty(PQ);
	if(!(IsSetEmpty(S))) {
		for (i=1;i<=SetNbElmt(S);i++) {
			nilai=Score(S.T[i]);
			AddPrio (PQ, S.T[i] , nilai);
        	}
	}
}
	

void PrintChosenWords(PrioQueue PQ)
{/* Kamus Lokal */
 	addressprio P;
/* Algoritma */
    	if (IsPrioQueueEmpty(PQ))
        	printf("-\n");
   	 else {
       		P=HeadPrio(PQ);
		while(P!=Nil) {
        	    	printf("    %2d ", Prio(P));
			printKata(InfoPrio(P));
			printf("\n");
			P=NextPrio(P);
        	}
        //printf(" Press ENTER to continue...");
    }

}

void PutarBoard(MATRIKS *M)
{ /* Kamus Lokal */
	MATRIKS Mputar;
	int i,j,k;
/* Algoritma */
	MakeMATRIKS(4, 4, &Mputar);
	for (i=FirstIdxBrs(*M); i<=LastIdxBrs(*M); i++) {
		k=LastIdxKol(*M);
		for(j=FirstIdxKol(*M); j<=LastIdxKol(*M); j++ ) {
				SetEl(&Mputar, i, j, GetElmt(*M,k,i));
				k--;
		}
	}
	CopyMATRIKS(Mputar, M);
}

int main()
{
    playTime = 30;

    selectedBoard = 0;
    ReadBoards();
    ReadDictionary();
    ReadUser();
    BacaDataBaseScore(&HighScoreList);
    clrscr();
    MainMenu();



    return 0;
}
