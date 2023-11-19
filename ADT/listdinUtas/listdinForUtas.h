#include "../tree/tree.h"
#include "../listlinierUtas/listlinierForUtas.h"

#ifndef LISTUTAS_H
#define LISTUTAS_H

#include "../boolean.h"

// TIPE BENTUKAN UTAS
typedef struct
{
   Kicauan *KicauanUtama;    // Alamat kicauan utama
   int IDUtas;               // ID Utas
   threads KicauanSambungan; // Alamat kicauan sambungan pertama
   char AuthorUtas[20];
} UTAS;

#define KicauanUtama(u) (u).KicauanUtama
#define IDUtas(u) (u).IDUtas
#define KicauanSambungan(u) (u).KicauanSambungan
#define AuthorUtas(u) (u).AuthorUtas

// List dinamis untuk menyimpan sekumpulan utas
typedef struct
{
   UTAS *buffer; // memori tempat penyimpan UTAS
   int NEFF;     // >=0, banyaknya elemen efektif
   int CAPACITY; // ukuran buffer
} ListUtas;

#define NEFFListDinUtas(lu) (lu).NEFF // fyi, lu = list utas
#define BUFFERListDinUtas(lu) (lu).buffer
#define CAPACITYListDinUtas(lu) (lu).CAPACITY

/* Fungsi/Posedur untuk Tipe Bentukan Utas  */
void CreateUtas(UTAS *u, Kicauan *kicauan, int id);

// Menyambung utas, dipastikan index valid
void SambungUtas(UTAS *u, char text[MAX_CHAR], int index);

/* Fungsi/Posedur untuk List Dinamis Utas  */
void CreateListUtas(ListUtas *u, int capacity);

// Mengirimkan kosong jika listUtas Kosong (Belum ada Utas)
boolean isEmptyListDinUtas(ListUtas u);

// Mengirimkan true jika Utas Efektif = capacity
boolean isFullListDinUtas(ListUtas u);

// Mengirimkan banyaknya Kicaun utama pada ListUtas
int listLength(ListUtas u);

// Menambah capacity u sebesar num
void expandListDinUtas(ListUtas *u, int num);

// Menampilkan Utas dengan format pada spek
void displayUtas(UTAS u);

// Memasukkan Utas baru kedalam list utas
void insertUtas(ListUtas *lu, UTAS U);

// Menghapus Kicauan Sambungan pada utas dengan index tertentu
void deleteSambungan(UTAS *u, int idx);

#endif