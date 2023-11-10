#include <stdio.h>
#include "listdinForUtas.h"

/* Konstruktor : create listUtas kosong  */
void CreateListUtas(ListUtas *u, int capacity)
// Membuat List berisi utas-utas
{
  BUFFERUtas(*u) = (UTAS *)malloc(capacity * sizeof(UTAS));
  NEFFUtas(*u) = 0;
  CAPACITYUtas(*u) = capacity;
}

void dealocateUtas(ListUtas *u)
// Menghapus List secara kesluruhan ()
{
  free(BUFFERUtas(*u));
  CAPACITYUtas(*u) = 0;
  NEFFUtas(*u) = 0;
}

int listLength(ListUtas u)
// Mengirimkan banyaknya Kicaun utama pada ListUtas
{
  return (NEFFUtas(u));
}

boolean isEmpty(ListUtas u)
// Mengirimkan kosong jika listUtas Kosong (Belum ada Utas)
{
  return (NEFFUtas(u) == 0);
}

boolean isFull(ListUtas u)
// Mengirimkan true jika Utas Efektif = capacity
{
  return (NEFFUtas(u) == CAPACITYUtas(u));
}

void expandList(ListUtas *u, int num)
// Menambah capacity u sebesar num
{
  int capacity = num + CAPACITYUtas(*u);
  BUFFERUtas(*u) = realloc(BUFFER(*u), capacity * sizeof(UTAS));
  CAPACITYUtas(*u) += num;
}
