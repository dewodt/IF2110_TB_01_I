#include "../tree/tree.h"
#include "../listlinierUtas/listlinierForUtas.h"

#ifndef LISTUTAS_H
#define LISTUTAS_H

#include "../boolean.h"

// List dinamis untuk menyimpan sekumpulan utas
typedef struct
{
   UTAS *buffer;            // memori tempat penyimpan UTAS
   int NEFF;                // >=0, banyaknya elemen efektif
   int CAPACITYListDinUtas; // ukuran buffer
} ListUtas;

#define NEFFListDinUtas(lu) (lu).NEFF // fyi, lu = list utas
#define BUFFERListDinUtas(lu) (lu).buffer
#define CAPACITYListDinUtas(lu) (lu).CAPACITYListDinUtas

/* Fungsi/Posedur untuk List Dinamis Utas  */
void CreateListUtas(ListUtas *u, int capacity);

// Mengirimkan kosong jika listUtas Kosong (Belum ada Utas)
boolean isEmptyListDinUtas(ListUtas u);

// Mengirimkan true jika Utas Efektif = capacity
boolean isFullListDinUtas(ListUtas u);

// Mengirimkan banyaknya Kicaun utama pada ListUtas
int listUtasLength(ListUtas u);

// Menambah capacity u sebesar num
void expandListDinUtas(ListUtas *u, int num);

// Memasukkan Utas baru kedalam list utas
void insertUtas(ListUtas *lu, UTAS U);

// Menghapus Kicauan Sambungan pada utas dengan index tertentu
void deleteSambungan(UTAS *u, int idx);

#endif