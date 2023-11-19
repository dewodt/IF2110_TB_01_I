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

/* Konstruktor : create listUtas kosong  */
void CreateListUtas(ListUtas *lu, int capacity);
// Membuat List berisi utas-utas

boolean isEmptyListDinUtas(ListUtas lu);
// Mengirimkan kosong jika listUtas Kosong (Belum ada Utas)

boolean isFullListDinUtas(ListUtas lu);
// Mengirimkan true jika Utas Efektif = capacity

int listLength(ListUtas lu);
// Mengirimkan banyaknya Kicaun utama pada ListUtas

void expandListDinUtas(ListUtas *lu, int num);
// Menambah capacity u sebesar num

void insertUtas(ListUtas *lu, UTAS U);
// Memasukkan Utas baru kedalam list utas

void deleteSambungan(UTAS *u, int idx);
// Menghapus Kicauan Sambungan pada utas dengan index tertentu

void displayUtas(UTAS u);

#endif