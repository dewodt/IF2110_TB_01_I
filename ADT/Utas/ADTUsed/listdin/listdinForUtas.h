#include "../../utas.h"

#ifndef LISTUTAS_H
#define LISTUTAS_H

#include "../boolean.h"

#define IDX_MIN 0
#define IDX_UNDEF -1

typedef struct
{
   UTAS *buffer; // memori tempat penyimpan UTAS
   int NEFF;     // >=0, banyaknya elemen efektif
   int CAPACITY; // ukuran buffer
} ListUtas;

#define NEFFUtas(u) (u).NEFF
#define BUFFERUtas(u) (u).buffer
#define CAPACITYUtas(u) (u).CAPACITY

/* Konstruktor : create listUtas kosong  */
void CreateListUtas(ListUtas *u, int capacity);
// Membuat List berisi utas-utas

void dealocateUtas(ListUtas *u);
// Menghapus List secara kesluruhan

int listLength(ListUtas u);
// Mengirimkan banyaknya Kicaun utama pada ListUtas

boolean isEmpty(ListUtas u);
// Mengirimkan kosong jika listUtas Kosong (Belum ada Utas)

boolean isFull(ListUtas u);
// Mengirimkan true jika Utas Efektif = capacity

void expandList(ListUtas *u, int num);
// Menambah capacity u sebesar num

#endif