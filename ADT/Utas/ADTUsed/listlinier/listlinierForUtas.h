#ifndef listlinierforutas_H
#define listlinierforutas_H

#include "../time/time.h"
#include "../datetime/datetime.c"
#include "../boolean.h"

#define MAX_CHAR 280

/* Definisi Node : */
typedef int ElType;
typedef struct node *Address;
typedef struct node
{
    char textThread[MAX_CHAR];
    Address nextThread;
    DATETIME timeThread;
} ThreadNode;

#define TextThread(p) (p)->textThread // p berupa alamat
#define NextThread(p) (p)->nextThread
#define TimeThread(p) (p)->timeThread

typedef Address threads; // thread -> thread -> thread

#define IDX_UNDEF (-1)
#define FIRST(l) (l)

// Membuat kicauan sambungan
Address newThreadNode(char text[MAX_CHAR]);

// Mengembalikan waktu lokal dalam tipe bentukan DATETIME
DATETIME getCurrTime();

// Menampilkan date dengan format "DD/MM/YYYY H:M:S" tanpa karakter setelah dan sebelumnya
void displayTime(DATETIME time);

// Meng-copy word
void copyText(char textIn[MAX_CHAR], char *textOut[MAX_CHAR]);

// Membuat UTAS baru
void CreateThreads(threads *l);

// Mengembalikan true jika UTAS kosong
boolean isThreadsEmpty(threads l);

// Memasukkan kicauan sambungan di awal threads
void insertFirstThreads(threads *l, char text[MAX_CHAR]);

// Memasukkan elemen terakhirpada utas
void insertLastThreads(threads *l, char text[MAX_CHAR]);

// Menghapus Elemen pertama pada utas
void deleteFirstThreads(threads *l);

// Menghapus Elemen dengan index pertama dimulai dari 1
void deleteAtThreads(threads *l, int idx);

// Mengembalikan jumlah kicauan sambungan pada threads
int lengthThreads(threads l);

// Menampilkan threads secara keseluruhan, kicauan utama tidak ditampilkan
void displayThreads(threads l);

#endif