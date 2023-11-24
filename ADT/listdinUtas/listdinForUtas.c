#include <stdio.h>
#include <stdlib.h>
#include "listdinForUtas.h"
#include "../listlinierUtas/listlinierForUtas.h"

/* Fungsi/Posedur untuk List Dinamis Utas  */
void CreateListUtas(ListUtas *u, int capacity)
// Membuat List berisi utas-utas
{
  BUFFERListDinUtas(*u) = (UTAS *)malloc(capacity * sizeof(UTAS));
  NEFFListDinUtas(*u) = 0;
  CAPACITYListDinUtas(*u) = capacity;
}

// Mengirimkan kosong jika listUtas Kosong (Belum ada Utas)
boolean isEmptyListDinUtas(ListUtas u)
{
  return (NEFFListDinUtas(u) == 0);
}

// Mengirimkan true jika Utas Efektif = capacity
boolean isFullListDinUtas(ListUtas u)
{
  return (NEFFListDinUtas(u) == CAPACITYListDinUtas(u));
}

// Mengirimkan banyaknya Kicaun utama pada ListUtas
int listUtasLength(ListUtas u)
{
  return (NEFFListDinUtas(u));
}

// Menambah capacity u sebesar num
void expandListDinUtas(ListUtas *u, int num)
{
  int capacity = num + CAPACITYListDinUtas(*u);
  BUFFERListDinUtas(*u) = realloc(BUFFERListDinUtas(*u), capacity * sizeof(UTAS));
  CAPACITYListDinUtas(*u) += num;
}

// Memasukkan Utas baru kedalam list utas
void insertUtas(UTAS U, ListUtas *lu)
{
  if (isFullListDinUtas(*lu))
  {
    expandListDinUtas(lu, CAPACITYListDinUtas(*lu));
  }

  BUFFERListDinUtas(*lu)[NEFFListDinUtas(*lu)] = U;

  // printf("test2\n");
  // IDUtas(BUFFERListDinUtas(*lu)[NEFFListDinUtas(*lu)]) = NEFFListDinUtas(*lu) + 1; // dah bener
  // printf("test3\n");
  // KicauanSambungan(BUFFERListDinUtas(*lu)[NEFFListDinUtas(*lu)]) = KicauanSambungan(U);
  // printf("test4\n");
  // printf("===========================UTAS===================\n");
  // displayUtas(*U);
  // printf("======================DINAMIS=====================\n");
  // displayUtas(BUFFERListDinUtas(*lu)[NEFFListDinUtas(*lu)]);
  // printf("==================================================\n");
  NEFFListDinUtas(*lu) += 1;

  // displayUtas(BUFFERListDinUtas(*lu)[NEFFListDinUtas(*lu) - 1]);
}

// Menghapus Kicauan Sambungan pada utas dengan index tertentu
void deleteSambungan(UTAS *u, int idx)
{
  if (idx == 1)
  {
    AddressUtas P = KicauanSambungan(*u);
    if (lengthThreads(KicauanSambungan(*u)) == 1)
    {
      KicauanSambungan(*u) = NULL;
      free(P);
    }
    else
    {
      KicauanSambungan(*u) = NextThread(P);
      free(P);
    }
  }
  else
  {
    AddressUtas P = KicauanSambungan(*u), prevP = NULL;
    for (int i = 1; i < idx; i++)
    {
      prevP = P;
      P = NextThread(P);
    }
    NextThread(prevP) = NextThread(P);
    free(P);
  }
}