#ifndef listlinierforutas_H
#define listlinierforutas_H

#include "../time/time.h"
#include "../datetime/datetime.h"
#include "../boolean.h"
#include "../tree/tree.h"
#include "../masukan/masukan.h"

#define MAX_CHAR 280

/* Definisi Node : */
typedef int ElType;
typedef struct nodeUtas *AddressUtas;
typedef struct nodeUtas
{
    char textThread[MAX_CHAR];
    AddressUtas nextThread;
    DATETIME timeThread;
} ThreadNode;

#define TextThread(p) (p)->textThread // p berupa alamat
#define NextThread(p) (p)->nextThread
#define TimeThread(p) (p)->timeThread

typedef AddressUtas threads; // thread -> thread -> thread

/* TIPE BENTUKAN UTAS */
typedef struct
{
    Kicauan *KicauanUtama;    // Alamat kicauan utama
    int IDUtas;               // ID Utas
    threads KicauanSambungan; // Alamat kicauan sambungan pertama
} UTAS;

#define KicauanUtama(u) (u).KicauanUtama
#define IDUtas(u) (u).IDUtas
#define KicauanSambungan(u) (u).KicauanSambungan
#define AuthorUtas(u) (*((*KicauanUtama(u)).author)).username

#define FIRST(l) (l)

// Mengembalikan waktu lokal dalam tipe bentukan DATETIME
DATETIME getCurrTime();

// Menampilkan date dengan format "DD/MM/YYYY H:M:S" tanpa karakter setelah dan sebelumnya
void displayTime(DATETIME time);

/* List linier */
// Membuat kicauan sambungan
AddressUtas newThreadNode(char text[MAX_CHAR], DATETIME time);

// Membuat UTAS baru
void CreateThreads(threads *l);

// Mengembalikan true jika UTAS kosong
boolean isThreadsEmpty(threads l);

// Memasukkan kicauan sambungan di awal threads
void insertFirstThreads(threads *l, char text[MAX_CHAR]);

// Memasukkan elemen terakhirpada utas
void insertLastThreads(threads *l, char text[MAX_CHAR]);

// Memasukkan Elemen pada indeks tertentu, indeks dipastikan valid, index dimulai dari 1
void insertAtThreads(threads *l, char text[MAX_CHAR], int idx);

// Memasukkan kicauan sambungan terakhir pada utas
void insertLastThreadForConfig(UTAS *utas, char text[MAX_CHAR], DATETIME time);

// Menghapus Elemen pertama pada utas
void deleteFirstThreads(threads *l);

// Menghapus Elemen dengan index pertama dimulai dari 1, dipastikan indeks valid
void deleteAtThreads(threads *l, int idx);

// Mengembalikan jumlah kicauan sambungan pada threads
int lengthThreads(threads l);

// Menampilkan threads secara keseluruhan, kicauan utama tidak ditampilkan
void displayThreads(threads l, char author[20]);

// Konstruktor Utas
void CreateUtas(UTAS *u, Kicauan *kicauan, int id);

// Menyambung utas pada elemen terakhir, dipastikan index valid
void SambungUtasLast(UTAS *u, char text[MAX_CHAR]);

// Menyambung utas pada index tertentu, dipastikan index valid. INDEX DIMULAI DARI 1
void SambungUtasAt(UTAS *u, char text[MAX_CHAR], int index);

// Menyambung utas pada index tertentu, dipastikan index valid. INDEX DIMULAI DARI 1
void HapusUtasAt(UTAS *u, int index);

// Menampilkan Utas dengan format pada spek
void displayUtas(UTAS u);

#endif