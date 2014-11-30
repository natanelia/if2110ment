#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //untuk manipulasi string
#include <unistd.h>
#include <sys/select.h>
#include <termios.h> //untuk mengcapture huruf yang ditekan user tanpa menampilkannya
#include <time.h> //untuk fungsi clock dan mencatat time sekarang
#include "boolean.h" //untuk penanganan tipe variabel boolean
#include "matriks.h" //untuk merepresentasikan board permainan
#include "mesinkar.h" //untuk mesinkata
#include "mesinkata1.h" //untuk membaca kamus data dan file eksternal
#include "point.h" //untuk menangani board
#include "stacklist.h" //untuk stack kata
#include "ADT_MultiList.h" //untuk score
#include "ArrayOfKata.h" //untuk membaca file berisi nama-nama user dan menyimpannya di array
#include "map.h" //untuk nilai skor huruf dan kata
#include "set.h" //untuk set kata-kata yang sudah dibentuk
#include "PrioQueueList.h" //untuk mengurutkan skor kata
#include "QueueList.h" //untuk suggestion

//KODE ANSI UNTUK MANIPULASI WARNA TEKS, BOLD, DAN BACKGROUND TERMINAL
#define ANSI_BACKGROUND_BLACK "\e[37m\e[40m"
#define ANSI_BACKGROUND_RED "\e[37m\e[41m"
#define ANSI_BACKGROUND_GREEN "\e[37m\e[42m"
#define ANSI_BACKGROUND_YELLOW "\e[37m\e[43m"
#define ANSI_BACKGROUND_BLUE "\e[37m\e[44m"
#define ANSI_BACKGROUND_MAGENTA "\e[37m\e[45m"
#define ANSI_BACKGROUND_CYAN "\e[37m\e[46m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RED_BOLD "\x1b[31;1m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_GREEN_BOLD "\x1b[32;1m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_YELLOW_BOLD "\x1b[33;1m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_BLUE_BOLD "\x1b[34;1m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_MAGENTA_BOLD "\x1b[35;1m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_CYAN_BOLD "\x1b[36;1m"
#define ANSI_COLOR_WHITE_BOLD "\x1b[37;1m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))

//KAMUS GLOBAL
MATRIKS boards[10]; //menyimpan semua board yang ada di folder "board"
Kata kamusKata[109000]; //menyimpan semua baris kamus kata di file "Dictionary.txt"
int kamusKataNeff; //menyimpan nilai efektif kamuskata
int selectedBoard; //menyimpan board mana yang sedang dipilih user (default:0)
POINT kursor; //menyimpan letak di mana user meletakkan kursor
POINT kursorTemp; //menyimpan POINT kursor untuk deteksi perubahan letak kursor
POINT chosen; //menyimpan letak di mana user menekan 's' untuk membentuk kata
int tempTime; //sisa waktu dalam sekon
int playTime; //waktu permainan dalam sekon
TabK users;	//array of Kata, isinya nama-nama user yg udah pernah diregister-in
Kata namauser;	//nama user yang saat ini sedang log in
short isSHit; //Counter penghitung tombol 's' sudah dipencet berapa kali
Stack StackKata; //menyimpan huruf-huruf dalam proses pembentukan
Kata InsertedKata; //kata terakhir yang sedang akan diaccept komputer
ARRAYPOINT P; //array penyimpan indeks-indeks matriks yang digunakan dalam proses pembentukan kata (UI related)
char nama[15]; //menyimpan nama user
Kata AcceptedKata; //menyimpan kata yang telah dicek di dictionary
Set S1; //menyimpan semua kata yang telah diterima
List HighScoreList; //menyimpan score keseluruhan
PrioQueue PQ; //Menyimpan kata yang sudah dibentuk terurut berdasarkan score tertinggi
Queue QSuggest[10]; //Menyimpan Kata-kata yang pernah dibentuk user pada permainan sebelumnya
Kata KataS; //Kata yang di-suggest
int selectedMenu = 1; //Menu yang sedang dipilih
static struct termios old_termios, new_termios, oldest_termios; //restore new terminal i/o settings


/* TERMINAL RELATED PROCEDURES AND FUNCTION */
void resetTermios();
/* I.S old_termios telah diset
   F.S mengembalikan kondisi terminal ke old_termios */
void superResetTermios();
/* I.S oldest_termios telah diset
   F.S mengembalikan kondisi terminal ke oldest_termios, superResetTermios untuk kompabilitas */
void initTermios();
/* I.S sembarang
   F.S mendisable kemampuan terminal menulis input user, getch() dan kbhit() working. old_termios dan new_termios diset */
void superInitTermios();
/* I.S sembarang
   F.S mendisable kemampuan terminal menulis input user, getch() dan kbhit() working. oldest_termios dan new_termios diset,
   superInitTermios untuk kompabilitas */
int kbhit();
//mendeteksi pencetan keyboard
char getch();
//menghasilkan karakter pencetan keyboard

/* INITIATION RELATED PROCEDURES */
void InitBoard();
/* I.S sembarang
   F.S semua variabel yang digunakan dalam permainan direset dan disesuaikan */
void ReadBoards();
/* I.S sembarang
   F.S semua file di folder "board" masuk ke matriks boards */
void ReadDictionary();
/* I.S sembarang
   F.S semua kamus di file "Dictionary.txt" dimasukkan ke array kamusKata[] dengan kamusKataNeff = banyak kata dalam file */
void ReadUser();
/* I.S Sembarang
   F.S Membaca semua user terdaftar dalam file "NamaUser.txt" ke array users*/

/* GUI RELATED PROCEDURES */
void clrscr();
/* I.S sembarang
   F.S layar kosong */
void DisplayBoard();
/* I.S Boards terdefinisi
   F.S Menampilkan pilihan board dari 0..9 ke layar */
void MainMenu();
/* I.S Sembarang
   F.S Menampilkan main menu dengan pilihan menu yang sudah mengarah ke prosedur masing-masing */
void UpdateMainMenu();
/* I.S Main Menu Terdefinisi
   F.S Menampilkan main menu dengan GUI yang sudah dimodifikasi */
void PreparationMenu ();
/* I.S Sembarang
   F.S Menampilkan preparation menu dengan pilihan menu yang sudah mengarah ke prosedur masing-masing */
void UpdatePrepMenu();
/* I.S Preperation Menu Terdefinisi
   F.S Menampilkan preparation menu dengan GUI yang sudah dimodifikasi */
void ResultMenu();
/* I.S Sembarang
   F.S Menampilkan menu hasil permainan user */
void About();
/* I.S sembarang
   F.S menampilkan credits tentang pembuat */
void HowToPlay();
/* I.S sembarang
   F.S menampilkan cara bermain wordament yang bergerak secara otomatis */
void MyHighScoreMenu ();
/* I.S List HighScoreList terisi
   F.S Menampilkan Top Ten High Score dari user yang login untuk board yang dipilih */
void AllHighScoreMenu ();
/* I.S List HighScoreList terisi
   F.S Menampilkan Top Ten High Score untuk board yang dipilih. */
void Statistic();
/* I.S List HighScoreList terisi
   F.S Menampilkan jumlah user berbeda yang pernah memainkan board terpilih,
       rata-rata skor dari seluruh user yang pernah memainkan board tersebut,
       dan ranking kesulitan board berdasarkan rata-rata tsb. */
void Play(double seconds);
/* I.S matriks boards terisi, int selectedBoard terisi, seconds terdefinisi
   F.S melakukan permainan board wordament selama seconds detik. */
void UpdateLayout();
/* I.S sembarang
   F.S memperbarui tampilan board yang sedang dimainkan secara berkala */
void PauseScreen(int seconds);
/* I.S sembarang
   F.S mendisable input user dan mengefreeze layar selama seconds */

/* INTEGRATION CODES & GUI SUPLEMENTARY*/
void Register (Kata *namauser);
/* I.S namauser terdefinisi
   F.S bila namauser belum terdaftar di NamaUser.txt, ditambahkan ke file tsb dan keluarkan pesan Welcome
       bila namauser sudah terdaftar, keluarkan pesan error
       bila namauser berisi EXIT, mengembalikan user ke menu utama */
void Login (Kata *namauser);
/* I.S namauser terdefinisi
   F.S bila namauser sudah terdaftar, memanggil fungsi PreparationMenu()
       bila namauser belum terdaftar, keluarkan pesan error. Bila terjadi 3x, menanyakan user apakah ingin register */
void PrintBoardForTutorial(POINT sel, int pil);
/* I.S sembarang
   F.S menampilkan board untuk tutorial HowToPlay() */
boolean IsInDictionary(Kata K);
//menghasilkan true bila K ada di dalam kamus
void SalinKeEks(TabK users);
/* I.S users terdefinisi
   F.S users disalin ke file eksternal */
void PrintChosenWords(PrioQueue PQ);
/* I.S PQ terdefinisi
   F.S Menulis kata-kata yang sudah dibentuk ke layar */
void PutarBoard (MATRIKS *M);
/* I.S Board terdefinisi sebagai matriks
   F.S Board diputar 90 derajat clockwise */
void InsertPrioQueue (Set S, PrioQueue *PQ);
/* I.S S terdefinisi
   F.S PQ terbentuk dengan elemen merupakan yang berasal dari S terurut score mengecil */
void MoveToQueue();
/* I.S Sembarang
   F.S QSuggest terbentuk, berisi kata-kata yang pernah terbentuk pada permainan sebelumnya */
void MoveQueueToEks();
/* I.S QSuggest terdefinisi
   F.S Memindahkan isi QSuggest ke file eksternal */
Kata Suggestion(int i, Kata K);
/* Menghasilkan Kata yang di-suggest dari board i berdasarkan kata yang sedang dibentuk player (K) */

#endif
