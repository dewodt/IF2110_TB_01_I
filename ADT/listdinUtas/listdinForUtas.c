#include <stdio.h>
#include <stdlib.h>
#include "listdinForUtas.h"
#include "../listlinierUtas/listlinierForUtas.h" // Janlup ganti jadi.h

/* Fungsi/Posedur untuk Tipe Bentukan Utas  */
void CreateUtas(UTAS *u, Kicauan *kicauan, int id)
{
  KicauanUtama(*u) = kicauan;
  IDUtas(*u) = id;
  KicauanSambungan(*u) = NULL;
  for (int i = 0; i < 20; i++)
  {
    (AuthorUtas(*u))[i] = (AUTHOR(*kicauan))[i];
  }
}

// Menyambung utas, dipastikan index valid
void SambungUtas(UTAS *u, char text[MAX_CHAR], int index)
{

  Address P = KicauanSambungan(*u); // P merupakan alamat kicauan sambungan pertama
  if (P == NULL)
  {
    Address N = newThreadNode(text);
    KicauanSambungan(*u) = N;
  }
  else
  {
    insertAtThreads(&KicauanSambungan(*u), text, index);
  }
}

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
int listLength(ListUtas u)
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

// Menampilkan Utas dengan format pada spek
void displayUtas(UTAS u)
{
  // Cetak kicauan utama
  printf(" |%d\n", ID(*(KicauanUtama(u))));
  printf(" |%s\n", AuthorUtas(u));
  printf(" |");
  displayTime(DATETIME(*(KicauanUtama(u))));
  printf("\n");
  printf(" |%s\n", TEXT(*(KicauanUtama(u))));
  printf("\n");

  // Cetak kicauan sambungan
  displayThreads(KicauanSambungan(u), AuthorUtas(u));
}

// Memasukkan Utas baru kedalam list utas
void insertUtas(ListUtas *lu, UTAS U)
{
  if (isFullListDinUtas(*lu))
  {
    expandListDinUtas(lu, 2 * CAPACITYListDinUtas(*lu));
  }

  KicauanUtama(BUFFERListDinUtas(*lu)[NEFFListDinUtas(*lu)]) = KicauanUtama(U);
  IDUtas(BUFFERListDinUtas(*lu)[NEFFListDinUtas(*lu)]) = NEFFListDinUtas(*lu) + 1;
  KicauanSambungan(BUFFERListDinUtas(*lu)[NEFFListDinUtas(*lu)]) = KicauanSambungan(U);
  // Copy String Author
  for (int i = 0; i < 20; i++)
  {
    (AuthorUtas(BUFFERListDinUtas(*lu)[NEFFListDinUtas(*lu)]))[i] = AuthorUtas(U)[i];
  }

  NEFFListDinUtas(*lu) += 1;
}

// Menghapus Kicauan Sambungan pada utas dengan index tertentu
void deleteSambungan(UTAS *u, int idx)
{
  if (idx == 1)
  {
    Address P = KicauanSambungan(*u);
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
    Address P = KicauanSambungan(*u), prevP = NULL;
    for (int i = 1; i < idx; i++)
    {
      prevP = P;
      P = NextThread(P);
    }
    NextThread(prevP) = NextThread(P);
    free(P);
  }
}