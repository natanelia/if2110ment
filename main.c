#include "main.h"

//gcc -o coba ADT_MultiList.c ArrayOfKata.c jam.c main.c map.c matriks.c mesinkar.c mesinkata1.c point.c PrioQueueList.c QueueList.c set.c stacklist.c tanggal.c waktu.c -lm

void superResetTermios()
{
    tcsetattr(0,TCSANOW,&oldest_termios);
}

void superInitTermios()
{
    tcgetattr(0,&oldest_termios); // store old terminal
    new_termios = oldest_termios; // assign to new setting
    new_termios.c_lflag &= ~ICANON; // disable buffer i/o
    new_termios.c_lflag &= ~ECHO; // disable echo mode
    tcsetattr(0,TCSANOW,&new_termios); // use new terminal setting
}

void resetTermios()
{
    tcsetattr(0,TCSANOW,&old_termios);
}
/* initialize new terminal i/o settings */
void initTermios()
{
    tcgetattr(0,&old_termios); // store old terminal
    new_termios = old_termios; // assign to new setting
    new_termios.c_lflag &= ~ICANON; // disable buffer i/o
    new_termios.c_lflag &= ~ECHO; // disable echo mode
    tcsetattr(0,TCSANOW,&new_termios); // use new terminal setting
}
/* detect keyboard press */
int kbhit()
{
    struct timeval tv = {0L,0L};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0,&fds);
    return select(1,&fds,NULL,NULL,&tv);
}
/* read 1 character */
char getch()
{
    char ch;
    ch = getchar();
    return ch;
}
/* skeleton program for play */
void Play(double seconds)
/* I.S matriks boards terisi, int selectedBoard terisi, seconds terdefinisi
   F.S melakukan permainan board wordament selama seconds detik. */
{
    char word;
    int stackPop;
    int i;

    MoveToQueue();
    InitBoard();
    InsertedKata.Length = 0;
    initTermios(); // initailize new terminal setting to make kbhit() and getch() work
    char cc;
    const double TIME_LIMIT = seconds * CLOCKS_PER_SEC;
    clock_t startTime = clock();
    tempTime = 0; //added
    //CreateEmptyStack(&StackKata);
    while ((clock() - startTime) <= TIME_LIMIT)
    {
        if (tempTime != (clock() - startTime)/CLOCKS_PER_SEC)
        {
            tempTime = (clock() - startTime)/CLOCKS_PER_SEC;
            UpdateLayout();
        }
        if (kbhit())
        {
            cc = getch();
            resetTermios(); // reset terminal setting to enable buffer i/o and echo (printf)
            kursorTemp.X = kursor.X;
            kursorTemp.Y = kursor.Y;
            switch(cc)
            {
            case 'q' :
                if (kursor.X > FirstIdxBrs(boards[selectedBoard]) && (kursor.Y > FirstIdxKol(boards[selectedBoard])))
                {
                    kursor.X--;
                    kursor.Y--;
                }
                break;

            case 'w' :
                if (kursor.X > FirstIdxBrs(boards[selectedBoard]))
                {
                    kursor.X--;
                }
                break;

            case 'e' :
                if (kursor.X > FirstIdxBrs(boards[selectedBoard]) && (kursor.Y < LastIdxKol(boards[selectedBoard])))
                {
                    kursor.X--;
                    kursor.Y++;
                }
                break;

            case 'a' :
                if (kursor.Y > FirstIdxKol(boards[selectedBoard]))
                {
                    kursor.Y--;
                }
                break;

            case 's' :
                if (isSHit == 0)
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

            case 'd' :
                if (kursor.Y < LastIdxKol(boards[selectedBoard]))
                {
                    kursor.Y++;
                }
                break;

            case 'z' :
                if (kursor.X < LastIdxBrs(boards[selectedBoard]) && (kursor.Y > FirstIdxKol(boards[selectedBoard])))
                {
                    kursor.X++;
                    kursor.Y--;
                }
                break;

            case 'x' :
                if (kursor.X < LastIdxBrs(boards[selectedBoard]))
                {
                    kursor.X++;
                }
                break;

            case 'c' :
                if (kursor.X < LastIdxBrs(boards[selectedBoard]) && (kursor.Y < LastIdxKol(boards[selectedBoard])))
                {
                    kursor.X++;
                    kursor.Y++;
                }
                break;
            case 'r' :
                PutarBoard(&boards[selectedBoard]);
                break;
            }

            //Bila pencetan keyboard tidak membuat kursor keluar dari board, lakukan
            if (kursorTemp.X != kursor.X || kursorTemp.Y != kursor.Y || cc=='s')
            {
                stackPop = SearchArrayPoint(P,kursor);
                if ((cc != 's') && (stackPop != -1))
                {
                    //Set kursor di posisi stackPop
                    if (chosen.X != 0 && chosen.Y !=0)
                    {
                        kursor.X = P.point[stackPop].X;
                        kursor.Y = P.point[stackPop].Y;
                    }

                    for (i=P.neff-stackPop; i>=1; i--)
                    {
                        Pop(&StackKata,&word);
                        P.neff--;
                    }
                }
                /* Jika ada point yang sudah dilewati kursor (setelah menekan tombol s),
                maka pop semua kata sehingga tersisa huruf awal saat menekan s saja */
                else
                {
                    if (isSHit==2)
                    {
                        //Proses kata ke dictionary
                        StackKata = reverseStack(StackKata);
                        while(!IsEmptyStack(StackKata))
                        {
                            Pop(&StackKata,&word);
                            InsertedKata.Length++;
                            InsertedKata.TabKata[InsertedKata.Length] = word;
                            P.neff = 0;
                        }
                        if (IsInDictionary(InsertedKata) && !IsSetMember(S1,InsertedKata))
                        {
                            //acceptedKataNeff++;
                            CopyKata(InsertedKata,&AcceptedKata);
                            InsertSet(&S1,AcceptedKata);
                        }
                        InsertedKata.Length=0;

                        isSHit = 0;
                    }
                    else if (isSHit==1)
                    {
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
    resetTermios(); // restore default terminal setting
    ResultMenu();
}

void InitBoard()
/* I.S sembarang
   F.S semua variabel yang digunakan dalam permainan direset dan disesuaikan */
{
    kursor = MakePoint(1,1);
    isSHit = 0;
    P.neff = 0;
    chosen.X = 0;
    chosen.Y = 0;
    //acceptedKataNeff = 0;
    char word;

    while(!IsEmptyStack(StackKata))
    {
        Pop(&StackKata,&word);
    }
    CreateEmptySet(&S1);
    InitScoreMap();

    UpdateLayout();
}

void UpdateLayout()
/* I.S sembarang
   F.S memperbarui tampilan board yang sedang dimainkan secara berkala */
{
    clrscr();
    printf("\n");
    printf(" User: ");
    printKata(namauser);
    //Print Time
    printf("%17d:%02d\n",(playTime - tempTime)/60,(playTime - tempTime)%60);

    //Print Matriks
    int i,j;
    POINT sel;
    printf("\n\n" "             " ANSI_BACKGROUND_BLACK "                        " ANSI_COLOR_RESET "\n");
    for (i=FirstIdxBrs(boards[selectedBoard]); i<=LastIdxBrs(boards[selectedBoard]); i++)
    {

        printf("             " ANSI_BACKGROUND_BLACK "  " ANSI_COLOR_RESET);
        for (j=FirstIdxKol(boards[selectedBoard]); j<=LastIdxKol(boards[selectedBoard]); j++)
        {
            sel.X = i;
            sel.Y = j;
            if (chosen.X == i && chosen.Y == j)
            {
                printf(ANSI_BACKGROUND_RED "  %c  " ANSI_COLOR_RESET, GetElmt(boards[selectedBoard],i,j));
            }
            else if (SearchArrayPoint(P,sel) != -1)
            {
                printf(ANSI_BACKGROUND_MAGENTA "  %c  " ANSI_COLOR_RESET, GetElmt(boards[selectedBoard],i,j));
            }
            else if (kursor.X == i && kursor.Y == j)
            {
                printf(ANSI_BACKGROUND_CYAN "  %c  " ANSI_COLOR_RESET, GetElmt(boards[selectedBoard],i,j));
            }
            else
            {
                printf(ANSI_BACKGROUND_BLACK "  %c  " ANSI_COLOR_RESET, GetElmt(boards[selectedBoard],i,j));
            }
        }
        printf(ANSI_BACKGROUND_BLACK "  " ANSI_COLOR_RESET);
        printf("\n");
	printf("             " ANSI_BACKGROUND_BLACK "                        \n" ANSI_COLOR_RESET);
    }
    printf("\n\n");
    printf("                "); PrintStack(reverseStack(StackKata));
    ;printKata(InsertedKata);
    //Menampilkan suggestion
    if(!IsQueueEmpty(QSuggest[selectedBoard])) {
	CopyKata(Suggestion(selectedBoard,AcceptedKata),&KataS);
    	printf("          [Suggestion] Try This One : ");
	if(KataS.TabKata[1]=='0') {
		printf(" ");
	}
	else {
		printKata(KataS);
	}
	printf("\n\n");
    }
    if (SetNbElmt(S1)>=1)
    {
        printf(" GOT ");
        printKata(AcceptedKata);
        printf("!\n");
        printf(" Total Score : %d\n",TotalScore(S1));
    }
    printf(" ");
}

void ReadBoards()
{
//I.S sembarang
//F.S MATRIKS boards berisi semua board yang ada di folder boards.
    char filename[13];
    int i,j,k;

    strcpy(filename, "boards/");
    strcat(filename, " .txt");

    for (i=0; i<=9; i++)
    {
        filename[7]=integerToChar(i);
        STARTKATA(filename);

        MakeMATRIKS(4,4,&boards[i]);
        for (j=FirstIdxBrs(boards[i]); j<=LastIdxBrs(boards[i]); j++)
        {
            for (k=FirstIdxKol(boards[i]); k<=LastIdxKol(boards[i]); k++)
            {
                SetEl(&boards[i],j,k,CKata.TabKata[1]);
                ADVKATA();
            }
        }
        //TulisMATRIKS(boards[i]);
    }
}

void ReadDictionary()
{
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

boolean IsInDictionary(Kata K)
{
//menghasilkan true bila K ada di dalam kamus
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

void clrscr(void)
{
    //system("clear");
    printf("\033\143");
}

void DisplayBoard()
/* I.S Boards terdefinisi
   F.S Menampilkan pilihan board dari 0..9 ke layar */
{
    /* KAMUS LOKAL */
    int i,j;
    /* ALGORITMA */
    ReadBoards();
    for (i=FirstIdxBrs(boards[0]); i<=LastIdxBrs(boards[0]); i++)
    {
        for (j=FirstIdxBrs(boards[0]); j<=LastIdxBrs(boards[0]); j++)
        {
            printf(" %c ", GetElmt(boards[0],i,j));
        }
        printf("          ");
        for (j=FirstIdxBrs(boards[1]); j<=LastIdxBrs(boards[1]); j++)
        {
            printf(" %c ", GetElmt(boards[1],i,j));
        }
        printf("          ");
        for (j=FirstIdxBrs(boards[2]); j<=LastIdxBrs(boards[2]); j++)
        {
            printf(" %c ", GetElmt(boards[2],i,j));
        }
        printf("          ");
        for (j=FirstIdxBrs(boards[3]); j<=LastIdxBrs(boards[3]); j++)
        {
            printf(" %c ", GetElmt(boards[3],i,j));
        }
        printf("\n");
    }
    printf(ANSI_COLOR_MAGENTA "   Board 0               Board 1               Board 2              Board 3\n\n" ANSI_COLOR_RESET );
    for (i=FirstIdxBrs(boards[4]); i<=LastIdxBrs(boards[4]); i++)
    {
        for (j=FirstIdxBrs(boards[4]); j<=LastIdxBrs(boards[4]); j++)
        {
            printf(" %c ", GetElmt(boards[4],i,j));
        }
        printf("          ");
        for (j=FirstIdxBrs(boards[5]); j<=LastIdxBrs(boards[5]); j++)
        {
            printf(" %c ", GetElmt(boards[5],i,j));
        }
        printf("          ");
        for (j=FirstIdxBrs(boards[6]); j<=LastIdxBrs(boards[6]); j++)
        {
            printf(" %c ", GetElmt(boards[6],i,j));
        }
        printf("          ");
        for (j=FirstIdxBrs(boards[7]); j<=LastIdxBrs(boards[7]); j++)
        {
            printf(" %c ", GetElmt(boards[7],i,j));
        }
        printf("\n");
    }
    printf(ANSI_COLOR_MAGENTA "   Board 4               Board 5               Board 6              Board 7\n\n" ANSI_COLOR_RESET);
    for (i=FirstIdxBrs(boards[8]); i<=LastIdxBrs(boards[8]); i++)
    {
        printf("                     ");
        for (j=FirstIdxBrs(boards[8]); j<=LastIdxBrs(boards[8]); j++)
        {
            printf(" %c ", GetElmt(boards[8],i,j));
        }
        printf("          ");
        for (j=FirstIdxBrs(boards[9]); j<=LastIdxBrs(boards[9]); j++)
        {
            printf(" %c ", GetElmt(boards[9],i,j));
        }
        printf("\n");
    }
    printf(ANSI_COLOR_MAGENTA "                       Board 8                Board 9\n\n" ANSI_COLOR_RESET);
}

void UpdateMainMenu()
/* I.S Main Menu Terdefinisi
   F.S Menampilkan main menu dengan GUI yang sudah dimodifikasi */
{
    /* Kamus Lokal */
    int pil = selectedMenu;
    /* Algoritma */
    clrscr();
    printf("=========================== WELCOME TO WORDAMENT-0 ============================\n\n");
    printf(ANSI_COLOR_RED    "██╗    ██╗ ██████╗ ██████╗ ██████╗  █████╗ ███╗   ███╗███████╗███╗   ██╗██████╗\n");
    printf(ANSI_COLOR_YELLOW "██║    ██║██╔═══██╗██╔══██╗██╔══██╗██╔══██╗████╗ ████║██╔════╝████╗  ██║╚═██╔═╝\n");
    printf(ANSI_COLOR_GREEN  "██║ █╗ ██║██║   ██║██████╔╝██║  ██║███████║██╔████╔██║█████╗  ██╔██╗ ██║  ██║  \n");
    printf(ANSI_COLOR_CYAN   "██║███╗██║██║   ██║██╔══██╗██║  ██║██╔══██║██║╚██╔╝██║██╔══╝  ██║╚██╗██║  ██║  \n");
    printf(ANSI_COLOR_BLUE   "╚███╔███╔╝╚██████╔╝██║  ██║██████╔╝██║  ██║██║ ╚═╝ ██║███████╗██║ ╚████║  ██║  \n");
    printf(ANSI_COLOR_MAGENTA" ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝  ╚═╝  \n\n" ANSI_COLOR_RESET);

    char b = ' ';
    if (pil == 1)
    {
        b = '=';
        printf(ANSI_COLOR_RED_BOLD);
    }
    printf("                                %c%c REGISTER %c%c \n\n" ANSI_COLOR_RESET, b,b,b,b);
    b = ' ';
    if (pil == 2)
    {
        b = '=';
        printf(ANSI_COLOR_YELLOW_BOLD);
    }
    printf("                                  %c%c LOGIN %c%c \n\n" ANSI_COLOR_RESET, b,b,b,b);
    b = ' ';
    if (pil == 3)
    {
        b = '=';
        printf(ANSI_COLOR_CYAN_BOLD);
    }
    printf("                               %c%c HOW TO PLAY %c%c \n\n" ANSI_COLOR_RESET, b,b,b,b);
    b = ' ';
    if (pil == 4)
    {
        b = '=';
        printf(ANSI_COLOR_GREEN_BOLD);
    }
    printf("                                  %c%c ABOUT %c%c \n\n" ANSI_COLOR_RESET, b,b,b,b);
    b = ' ';
    if (pil == 5)
    {
        b = '=';
        printf(ANSI_COLOR_MAGENTA_BOLD);
    }
    printf("                                  %c%c QUIT %c%c \n\n" ANSI_COLOR_RESET, b,b,b,b);

    printf("\n                      " ANSI_BACKGROUND_BLUE "                                    " ANSI_COLOR_RESET);
    printf("\n                      "ANSI_BACKGROUND_BLUE "  Hint: Use W/A/S/D to navigate...  " ANSI_COLOR_RESET);
    printf("\n                      " ANSI_BACKGROUND_BLUE "                                    " ANSI_COLOR_RESET "\n");
}

void MainMenu()
/* I.S Sembarang
   F.S Menampilkan main menu dengan pilihan menu yang sudah mengarah ke prosedur masing-masing */
{
    selectedMenu = 1;
    UpdateMainMenu();
    superInitTermios();
    initTermios();
    char cc = '\0';
    while (cc != '\n')
    {
        if (kbhit())
        {
            resetTermios();
            cc = getch();
            switch(cc)
            {
            case 'a' :
            case 'w' :
                if (selectedMenu > 1)
                    selectedMenu--;
                break;
            case 'd' :
            case 's' :
                if (selectedMenu < 5)
                    selectedMenu++;
                break;
            }

            UpdateMainMenu();
            initTermios();
        }
    }
    resetTermios();
    cc = '\0';

    superResetTermios();
    switch (selectedMenu)
    {
    case 1:
    {
        clrscr();
        Register(&namauser);
        break;
    }
    case 2:
    {
        clrscr();
        Login(&namauser);
        break;
    }
    case 3:
    {
        clrscr();
        HowToPlay();
        break;
    }
    case 4:
    {
        clrscr();
        About();
        break;
    }
    case 5:
    {
        clrscr();
        break;
    }
    }
}

void UpdatePrepMenu()
/* I.S Preparation Menu Terdefinisi
   F.S Menampilkan preaparatiom menu dengan GUI yang sudah dimodifikasi */
{
    /* Kamus Lokal */
    int pil = selectedMenu;
    /* Algoritma */
    clrscr();
    printf("User: ");
    printKata(namauser);
    printf("                                                  Selected Board: %d\n\n",selectedBoard);

    printf(ANSI_COLOR_RED    "██╗    ██╗ ██████╗ ██████╗ ██████╗  █████╗ ███╗   ███╗███████╗███╗   ██╗██████╗\n");
    printf(ANSI_COLOR_YELLOW "██║    ██║██╔═══██╗██╔══██╗██╔══██╗██╔══██╗████╗ ████║██╔════╝████╗  ██║╚═██╔═╝\n");
    printf(ANSI_COLOR_GREEN  "██║ █╗ ██║██║   ██║██████╔╝██║  ██║███████║██╔████╔██║█████╗  ██╔██╗ ██║  ██║  \n");
    printf(ANSI_COLOR_CYAN   "██║███╗██║██║   ██║██╔══██╗██║  ██║██╔══██║██║╚██╔╝██║██╔══╝  ██║╚██╗██║  ██║  \n");
    printf(ANSI_COLOR_BLUE   "╚███╔███╔╝╚██████╔╝██║  ██║██████╔╝██║  ██║██║ ╚═╝ ██║███████╗██║ ╚████║  ██║  \n");
    printf(ANSI_COLOR_MAGENTA" ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝  ╚═╝  \n\n" ANSI_COLOR_RESET);

    char b = ' ';
    if (pil == 1)
    {
        b = '=';
        printf(ANSI_COLOR_CYAN_BOLD);
    }
    printf("                                 %c%c PLAY GAME %c%c \n\n" ANSI_COLOR_RESET, b,b,b,b);
    b = ' ';
    if (pil == 2)
    {
        b = '=';
        printf(ANSI_COLOR_MAGENTA_BOLD);
    }
    printf("                               %c%c SELECT BOARD %c%c \n\n" ANSI_COLOR_RESET, b,b,b,b);
    b = ' ';
    if (pil == 3)
    {
        b = '=';
        printf(ANSI_COLOR_RED_BOLD);
    }
    printf("                               %c%c MY HIGHSCORES %c%c \n\n" ANSI_COLOR_RESET, b,b,b,b);
    b = ' ';
    if (pil == 4)
    {
        b = '=';
        printf(ANSI_COLOR_YELLOW_BOLD);
    }
    printf("                            %c%c VIEW ALL HIGHSCORES %c%c \n\n" ANSI_COLOR_RESET, b,b,b,b);
    b = ' ';
    if (pil == 5)
    {
        b = '=';
        printf(ANSI_COLOR_GREEN_BOLD);
    }
    printf("                              %c%c VIEW STATISTIC %c%c \n\n" ANSI_COLOR_RESET, b,b,b,b);
    b = ' ';
    if (pil == 6)
    {
        b = '=';
        printf(ANSI_COLOR_WHITE_BOLD);
    }
    printf("                                  %c%c LOGOUT %c%c \n" ANSI_COLOR_RESET, b,b,b,b);

    printf("\n\n                        Hint: Use W/A/S/D to navigate...\n");

}

void PreparationMenu()
/* I.S Sembarang
   F.S Menampilkan preparation menu dengan pilihan menu yang sudah mengarah ke prosedur masing-masing */
{
    superInitTermios();
    int pilboard = 0;
    selectedMenu = 1;
    UpdatePrepMenu();
    getch();
    initTermios();
    char cc = '\0';
    while (cc != '\n')
    {
        if (kbhit())
        {
            resetTermios();
            cc = getch();
            switch(cc)
            {
            case 'a' :
            case 'w' :
                if (selectedMenu > 1)
                    selectedMenu--;
                break;
            case 'd' :
            case 's' :
                if (selectedMenu < 6)
                    selectedMenu++;
                break;
            }

            UpdatePrepMenu();
            initTermios();
        }
    }
    resetTermios();
    superResetTermios();
    switch (selectedMenu)
    {
    case 1 :
        Play(playTime);
        break;
    case 2 :
        clrscr();
        DisplayBoard();
        printf("Masukkan pilihan board: ");
        scanf("%d",&pilboard);
        if ((pilboard<0) || (pilboard>9))
	{
		printf("Board not found!\n");
		printf("--- Press Enter to continue ---");
		getch();
		getch();
	} else {
       		selectedBoard=pilboard;
	}
	clrscr();
        PreparationMenu();
        break;
    case 3 :
        MyHighScoreMenu();
        break;
    case 4 :
        AllHighScoreMenu();
        break;
    case 5 :
        Statistic();
        break;
    case 6 :
        selectedBoard = 0;
        MainMenu();
        break;

    }
}

void ResultMenu ()
{
/* I.S Sembarang
   F.S Menampilkan menu hasil permainan user */
    time_t t = time(0);
    struct tm *infoTime = localtime(&t);


    gotoxy(2,49);
    printf(" ==TIME UP, " ANSI_COLOR_CYAN);
    printKata(namauser);
    printf(ANSI_COLOR_RESET "!==\n");
    gotoxy(4,46); printf("  Board No.  : %d\n", selectedBoard);
    gotoxy(5,46); printf("  Your Score : %d\n", TotalScore(S1));
    gotoxy(6,46); printf("  Words Found:\n");
    gotoxy(7,46); PrintChosenWords(PQ);
    MoveQueueToEks();

    //Save Result to File
    RecordType NewRecord;

    NewRecord.UserName = namauser;
    NewRecord.Score = TotalScore(S1);
    Day(NewRecord.Time) = infoTime->tm_mday;
    Month(NewRecord.Time) = infoTime->tm_mon;
    Year(NewRecord.Time) = infoTime->tm_year+1900;
    Hour(NewRecord.Time) = infoTime->tm_hour;
    Minute(NewRecord.Time) = infoTime->tm_min;
    Second(NewRecord.Time) = infoTime->tm_sec;
    InsertGameScore(&HighScoreList, selectedBoard, NewRecord);
    TulisDataBaseScore(HighScoreList);

    getch();
    PreparationMenu();
}

void MyHighScoreMenu()
/* I.S List HighScoreList terisi
   F.S Menampilkan Top Ten High Score dari user yang login untuk board yang dipilih */
{
    clrscr();
    printf("==============================================================================\n");
    printf("========================MY HIGHSCORE for BOARD No. %d==========================\n",selectedBoard);
    printf("==============================================================================\n");
    ViewMyHighscore(HighScoreList,selectedBoard,namauser);
    printf("\n >> Press ENTER to return...");
    getch();
    PreparationMenu();
}

void AllHighScoreMenu()
/* I.S List HighScoreList terisi
   F.S Menampilkan Top Ten High Score untuk board yang dipilih. */
{
    clrscr();
    printf("==============================================================================\n");
    printf("==========================HIGHSCORE for BOARD No. %d===========================\n",selectedBoard);
    printf("==============================================================================\n");
    ViewAllHighscore(HighScoreList,selectedBoard);
    printf("\n >> Press ENTER to return...");
    getch();
    PreparationMenu();
}

void ReadUser()
{
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
/* I.S namauser terdefinisi
   F.S bila namauser belum terdaftar di NamaUser.txt, ditambahkan ke file tsb dan keluarkan pesan Welcome
       bila namauser sudah terdaftar, keluarkan pesan error
       bila namauser berisi EXIT, mengembalikan user ke menu utama */
{
    /* KAMUS */

    int i=1;
    FILE *fileku;
    char filename[30];

    /* ALGORITMA */
    do
    {
        clear();
        printf(ANSI_COLOR_BLUE"================================= REGISTER =====================================\n\n\n" ANSI_COLOR_RESET);
        printf(
            "                    Enter your name in the box below (one word): \n"
            "                           +-------------------+\n"
            "                           |                   |\n"
            "                           +-------------------+\n"
            );
    	gotoxy(6, 30);
        scanf("%s",nama);
        (*namauser).Length=strlen(nama);
        for (i=1; i<=(*namauser).Length; i++)
            (*namauser).TabKata[i]=nama[i-1];
        if (SearchB (users, *namauser))
        {
            printf("\n\n\n");
            printf("                   " ANSI_BACKGROUND_RED "                                            \n" ANSI_COLOR_RESET);
            printf("                   " ANSI_BACKGROUND_RED "   ERROR: Your name has been registered!    \n" ANSI_COLOR_RESET);
            printf("                   " ANSI_BACKGROUND_RED "   Type 'EXIT' to return...                 \n" ANSI_COLOR_RESET);
            printf("                   " ANSI_BACKGROUND_RED "                                            \n" ANSI_COLOR_RESET);
            PauseScreen(2);
        }
        else
        {
            if (strcmp(nama,"EXIT"))
            {
                printf("\n\n");
                printf("                              " ANSI_COLOR_RED "Welcome ");
                printKata(*namauser);
                printf("!" ANSI_COLOR_RESET "\n");
                PauseScreen(1);
            }
        }
        clrscr();
    }
    while (SearchB (users, *namauser));

    if (strcmp(nama,"EXIT"))
    {
        AddAsLastEl(&users,*namauser);
        SalinKeEks(users);
        //Membentuk file user baru
        strcpy(filename, "users/");
        strcat(filename, nama);
        strcat(filename, ".txt");
        fileku=fopen(filename, "w");
        for(i=0; i<=9; i++)
        {
            fputs(",", fileku);
            fputs("\n",fileku);
        }
        fputs(".",fileku);
        fclose(fileku);
        PreparationMenu();
    }
    else
    {
        getch();
        MainMenu();
    }
}

void SalinKeEks(TabK users)
/* I.S users terdefinisi
   F.S users disalin ke file eksternal */
{
    /* KAMUS */
    static FILE *fileku;
    static int retval;
    int i,j;

    /* ALGORITMA */
    fileku = fopen("NamaUser.txt","w");
    for (i=1; i<=users.Neff; i++)
    {
        for(j=1; j<=users.TI[i].Length; j++)
        {
            retval=fprintf(fileku, "%c", users.TI[i].TabKata[j] );
        }
        fprintf(fileku, "\n");
    }
    retval=fprintf(fileku, ".");
    fclose(fileku);
}

void Login (Kata *namauser)
/* I.S namauser terdefinisi
   F.S bila namauser sudah terdaftar, memanggil fungsi PreparationMenu()
       bila namauser belum terdaftar, keluarkan pesan error. Bila terjadi 3x, menanyakan user apakah ingin register */
{
    /* KAMUS */
    int i=1;
    int count=0;
    char pil;

    /* ALGORITMA */
    do
    {
	clear();
	printf(ANSI_COLOR_CYAN_BOLD "=================================== LOGIN ====================================\n\n\n" ANSI_COLOR_RESET);
   	printf(
        "                        Enter your name in the box below\n"
        "                             +-------------------+\n"
        "                             |                   |\n"
        "                             +-------------------+\n"
    	);
    	gotoxy(6, 32);
        scanf("%s",nama);
        (*namauser).Length=strlen(nama);
        for (i=1; i<=(*namauser).Length; i++)
            (*namauser).TabKata[i]=nama[i-1];
        if (!(SearchB (users, *namauser)))
        {
            printf("\n\n\n");
            printf("                " ANSI_BACKGROUND_RED "                                              \n" ANSI_COLOR_RESET);
            printf("                " ANSI_BACKGROUND_RED "   ERROR! Your name has not been registered!  \n" ANSI_COLOR_RESET);
            printf("                " ANSI_BACKGROUND_RED "                                              \n" ANSI_COLOR_RESET);
            PauseScreen(1);
            count++;
        }
        else
        {
            printf("\n\n");
            printf(ANSI_COLOR_CYAN "                                 Welcome ");
            printKata(*namauser);
            printf("!" ANSI_COLOR_RESET "\n");
            PauseScreen(1);
        }
        clrscr();
    }
    while ((!SearchB(users, *namauser))&&(count<3));

    if (count==3)
    {
        printf(ANSI_COLOR_CYAN "LOGIN\n\n" ANSI_COLOR_RESET);
        printf("Do you want to register? (y/n) ");
        getch();
        scanf("%c",&pil);
        clrscr();
        if (pil=='y')
            Register(namauser);
        else
        {
            getch();
            MainMenu();
        }

    }
    else
        PreparationMenu();
}

void About()
/* I.S sembarang
   F.S menampilkan credits tentang pembuat */
{
    printf("=================================== About ====================================\n\n");
    printf("  Thank you for playing Wordament-0!\n");
    printf("  This application was made to simulate Wordament.\n\n");
    printf("  CREDITS\n  13513010 Zulva Fachrina\n  13513038 Tjan Marco Orlando\n  13513066 Dininta Annisa\n");
    printf("  13513070 Natan\n  13513076 Lie, Albert Tri Adrian\n  13513080 Luminto\n");
    printf("\n  >> Press ENTER to continue...");
    getch();
    clrscr();
    MainMenu();
}

void PrintBoardForTutorial(POINT kursor, int pil)
/* I.S sembarang
   F.S menampilkan board untuk tutorial HowToPlay() */
{
    //Print Matriks
    int i,j;
    printf("\n" "        " ANSI_BACKGROUND_BLACK "                  " ANSI_COLOR_RESET "\n");
    for (i=FirstIdxBrs(boards[selectedBoard]); i<=LastIdxBrs(boards[selectedBoard]); i++)
    {

        printf("       " ANSI_BACKGROUND_BLACK "    " ANSI_COLOR_RESET);
        for (j=FirstIdxKol(boards[selectedBoard]); j<=LastIdxKol(boards[selectedBoard]); j++)
        {

            if ((kursor.X == i && kursor.Y == j)&&(pil==2))
            {
                printf(ANSI_BACKGROUND_RED " %c " ANSI_COLOR_RESET, GetElmt(boards[selectedBoard],i,j));
            }
            /*else if (SearchArrayPoint(P,sel) != -1)
            {
                printf(ANSI_BACKGROUND_MAGENTA " %c " ANSI_COLOR_RESET, GetElmt(boards[selectedBoard],i,j));
            }*/
            else if ((kursor.X == i && kursor.Y == j)&&(pil==1))
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
    printf(" ");
}

void HowToPlay()
/* I.S sembarang
   F.S menampilkan cara bermain wordament yang bergerak secara otomatis */
{
    printf("================================= HOW TO PLAY ================================\n");
    printf("\n Press ENTER to start tutorial.\n");
    PrintBoardForTutorial(MakePoint(1,1),1);
    getch();
    clrscr();
    printf("================================= HOW TO PLAY ================================\n");
    printf("\n Press q,w,e,a,d,z,x,c to move the cursor\n");
    PrintBoardForTutorial(MakePoint(2,1),1);
    printf("           Pressed 'x'\n");
    PauseScreen(1);
    clrscr();
    printf("================================= HOW TO PLAY ================================\n");
    printf("\n Press q,w,e,a,d,z,x,c to move the cursor\n");
    PrintBoardForTutorial(MakePoint(2,2),1);
    printf("           Pressed 'd'\n");
    PauseScreen(1);
    clrscr();
    printf("================================= HOW TO PLAY ================================\n");
    printf("\n Press q,w,e,a,d,z,x,c to move the cursor\n");
    PrintBoardForTutorial(MakePoint(3,3),1);
    printf("           Pressed 'c'\n");
    PauseScreen(1);
    clrscr();
    printf("================================= HOW TO PLAY ================================\n");
    printf("\n Press q,w,e,a,d,z,x,c to move the cursor\n");
    PrintBoardForTutorial(MakePoint(3,2),1);
    printf("           Pressed 'a'\n");
    PauseScreen(1);
    clrscr();
    printf("================================= HOW TO PLAY ================================\n");
    printf("\n Press q,w,e,a,d,z,x,c to move the cursor\n");
    PrintBoardForTutorial(MakePoint(4,1),1);
    printf("           Pressed 'z'\n");
    PauseScreen(1);
    clrscr();
    printf("================================= HOW TO PLAY ================================\n");
    printf("\n Press q,w,e,a,d,z,x,c to move the cursor\n");
    PrintBoardForTutorial(MakePoint(3,2),1);
    printf("           Pressed 'e'\n");
    PauseScreen(1);
    printf("================================= HOW TO PLAY ================================\n");
    clrscr();
    printf("\n Press q,w,e,a,d,z,x,c to move the cursor\n");
    PrintBoardForTutorial(MakePoint(2,2),1);
    printf("           Pressed 'w'\n");
    PauseScreen(1);
    printf("================================= HOW TO PLAY ================================\n");
    clrscr();
    printf("\n Press q,w,e,a,d,z,x,c to move the cursor\n");
    PrintBoardForTutorial(MakePoint(1,1),1);
    printf("           Pressed 'q'\n");
    PauseScreen(1);
    clrscr();
    printf("================================= HOW TO PLAY ================================\n");
    printf("\n Press 's' to select your word\n");
    PrintBoardForTutorial(MakePoint(2,2),1);
    PauseScreen(1);
    clrscr();
    printf("================================= HOW TO PLAY ================================\n");
    printf("\n Press 's' to select your word\n");
    PrintBoardForTutorial(MakePoint(2,2),2);
    printf("           Pressed 's'\n");
    PauseScreen(2);
    clrscr();
    printf("================================= HOW TO PLAY ================================\n");
    printf("\n\n Find as many words as you can\n\n Have fun!");
    getch();
    MainMenu();
}

void PauseScreen (int seconds)
/* I.S sembarang
   F.S mendisable input user dan mengefreeze layar selama seconds */
{
    initTermios();
    const double TIME_LIMIT = seconds * CLOCKS_PER_SEC;
    clock_t startTime = clock();
    //CreateEmptyStack(&StackKata);
    while ((clock() - startTime) <= TIME_LIMIT)
    {
        if (kbhit())
        {
            getch();
            resetTermios();
            initTermios();
        }
    }
    resetTermios();
}

void InsertPrioQueue (Set S, PrioQueue *PQ)
/* I.S S terdefinisi
   F.S PQ terbentuk dengan elemen merupakan yang berasal dari S terurut score mengecil */
{
    /* Kamus Lokal */
    int nilai;
    int i;
    /* Algoritma */
    CreatePrioQueueEmpty(PQ);
    if(!(IsSetEmpty(S)))
    {
        for (i=1; i<=SetNbElmt(S); i++)
        {
            nilai=Score(S.T[i]);
            AddPrio (PQ, S.T[i] , nilai);
        }
    }
}


void PrintChosenWords(PrioQueue PQ)
/* I.S PQ terdefinisi
   F.S Menulis kata-kata yang sudah dibentuk ke layar */
{
    /* Kamus Lokal */
    addressprio P;
    int i;
    /* Algoritma */
    if (IsPrioQueueEmpty(PQ))
        printf("-\n");
    else
    {
        P=HeadPrio(PQ);
	i=9;
        while(P!=Nil)
        {
            gotoxy(i,46); printf("    %2d ", Prio(P));
            printKata(InfoPrio(P));
            printf("\n");
            P=NextPrio(P);
	    i++;
        }
        gotoxy(i+1,46); printf(" Press ENTER to continue...");
    }

}

void PutarBoard(MATRIKS *M)
/* I.S Board terdefinisi sebagai matriks
   F.S Board diputar 90 derajat clockwise */
{
    /* Kamus Lokal */
    MATRIKS Mputar;
    int i,j,k;
    /* Algoritma */
    MakeMATRIKS(4, 4, &Mputar);
    for (i=FirstIdxBrs(*M); i<=LastIdxBrs(*M); i++)
    {
        k=LastIdxKol(*M);
        for(j=FirstIdxKol(*M); j<=LastIdxKol(*M); j++ )
        {
            SetEl(&Mputar, i, j, GetElmt(*M,k,i));
            k--;
        }
    }
    CopyMATRIKS(Mputar, M);
}

void Statistic()
/* I.S List HighScoreList terisi
   F.S Menampilkan jumlah user berbeda yang pernah memainkan board terpilih,
       rata-rata skor dari seluruh user yang pernah memainkan board tersebut,
       dan ranking kesulitan board berdasarkan rata-rata tsb. */
{
    clrscr();
    printf("==============================================================================\n");
    printf("==========================HIGHSCORE for BOARD No. %d===========================\n",selectedBoard);
    printf("==============================================================================\n");
    ViewStatistic(HighScoreList,selectedBoard);
    printf("\n >> Press ENTER to return...");
    getch();
    PreparationMenu();
}

void MoveToQueue ()
/* I.S Sembarang
   F.S QSuggest terbentuk, berisi kata-kata yang pernah terbentuk pada permainan sebelumnya */
{
    /* Kamus Lokal */
    char filename[30];
    int i;
    /* Algoritma */
    for(i=0; i<=9; i++)
    {
        CreateQueueEmpty(&QSuggest[i]);
    }
    strcpy(filename, "users/");
    strcat(filename, nama);
    strcat(filename, ".txt");
    STARTKATA(filename);
    i=0;
    while (!EndKata)
    {
        while(CKata.TabKata[1]!=',')
        {
            AddQueue(&QSuggest[i],CKata);
            ADVKATA();
        }
        i++;
        ADVKATA();
    }
}

void MoveQueueToEks()
/* I.S QSuggest terdefinisi
   F.S Memindahkan isi QSuggest ke file eksternal */
{
    /* Kamus Lokal */
    static FILE *fileku;
    static int retval;
    int i,j;
    qaddress P;
    char filename[30];


    /* Algoritma */
    for(i=1; i<=SetNbElmt(S1); i++)
    {
        if(!(SearchQueue(QSuggest[selectedBoard], S1.T[i])))
        {
            AddQueue (&QSuggest[selectedBoard], S1.T[i]);
        }
    }
    strcpy(filename, "users/");
    strcat(filename, nama);
    strcat(filename, ".txt");
    fileku = fopen(filename,"w+");
    for (i=0; i<=9; i++)
    {
        P=Head(QSuggest[i]);
        while(P!=Nil)
        {
            for(j=1; j<=InfoQ(P).Length; j++)
            {
                retval=fprintf(fileku, "%c", InfoQ(P).TabKata[j] );
            }
            P=NextQ(P);
            fputs(" ", fileku);
        }
        fputs(",", fileku);
        fputs("\n", fileku);
    }
    fputs(".", fileku);
    fclose(fileku);
}

Kata Suggestion(int i, Kata K)
/* Menghasilkan Kata yang di-suggest dari board i berdasarkan kata yang sedang dibentuk player (K) */
{
    /* Kamus Lokal */
    Kata KSuggest, S, Kosong, K1;
    //KSuggest=Kata yang di-suggest, S=Kata yang dipindah, K1=Kata pada InfoHead
    /* Algoritma */
    Kosong.TabKata[1]='0'; // Inisialisasi kata kosong, diisi jika suggestion habis
    Kosong.Length=1;
    CopyKata(InfoHead(QSuggest[i]),&K1);
    if(!(IsKataSama(InfoHead(QSuggest[i]),K)))   //acceptedKata!=InfoHead(Q)
    {
        CopyKata(InfoHead(QSuggest[i]),&KSuggest);
    }
    else
    {
        DelQueue(&QSuggest[i], &S);
        AddQueue (&QSuggest[i], S);
        if(IsKataSama(InfoHead(QSuggest[i]),K1))   //InfoHead(Q)==K1, semua kata sudah di display
        {
            CopyKata(Kosong,&KSuggest);
        }
        else
        {
            while(IsSetMember(S1, InfoHead(QSuggest[i])) && !IsKataSama(InfoHead(QSuggest[i]),K1))
            {
                DelQueue(&QSuggest[i], &S);
                AddQueue (&QSuggest[i], S);
            } //InfoHead(Q) tidak ada di Set atau Suggestion sudah habis
            if(IsKataSama(InfoHead(QSuggest[i]),K1))
            {
                CopyKata(Kosong,&KSuggest);
            }
            else
            {
                CopyKata(InfoHead(QSuggest[i]),&KSuggest);
            }
        }
    }
    return(KSuggest);
}

int main()
{
    playTime = 120;

    selectedBoard = 0;
    ReadBoards();
    ReadDictionary();
    ReadUser();
    BacaDataBaseScore(&HighScoreList);
    clrscr();
    MainMenu();

    return 0;
}
