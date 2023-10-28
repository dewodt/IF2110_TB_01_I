#include <stdio.h>
#include "liststatik.h"

/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l)
{
  int i;
  for (i = 0; i < CAPACITY; i++)
  {
    ELMT(*l, i) = MARK;
  }
}

/* *** Banyaknya elemen *** */
int listLength(ListStatik l)
{
  int i = 0;
  while (ELMT(l, i) != MARK && i < CAPACITY)
  {
    i += 1;
  }
  return i;
}

/* Mengirimkan indeks elemen l pertama */
IdxType getFirstIdx(ListStatik l)
{
  return 0;
}

/* Mengirimkan indeks elemen l terakhir */
IdxType getLastIdx(ListStatik l)
{
  return listLength(l) - 1;
}

/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
boolean isIdxValid(ListStatik l, IdxType i)
{
  return i >= getFirstIdx(l) && i < CAPACITY;
}

/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
boolean isIdxEff(ListStatik l, IdxType i)
{
  return i >= getFirstIdx(l) && i <= getLastIdx(l);
}

/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
boolean isEmpty(ListStatik l)
{
  return listLength(l) == 0;
}

/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
boolean isFull(ListStatik l)
{
  return listLength(l) == CAPACITY;
}

/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l)
{
  int n, item, i;

  // Inisialisasi
  CreateListStatik(l);

  // Baca & Validasi n
  do
  {
    scanf("%d", &n);
  } while ((n < 0 || n > CAPACITY));

  // Baca masukan elemen
  for (i = 0; i < n; i++)
  {
    scanf("%d", &item);
    ELMT(*l, i) = item;
  }
}

/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
void printList(ListStatik l)
{
  int i;
  printf("[");
  for (i = 0; i < listLength(l); i++)
  {
    if (i == getLastIdx(l))
    {
      printf("%d", ELMT(l, i));
    }
    else
    {
      printf("%d,", ELMT(l, i));
    }
  }
  printf("]");
}

/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus)
{
  int i;
  ListStatik l3;

  // Inisialisasi
  CreateListStatik(&l3);

  // Tambahkan
  for (i = 0; i < listLength(l1); i++)
  {
    if (plus)
    {
      ELMT(l3, i) = ELMT(l1, i) + ELMT(l2, i);
    }
    else
    {
      ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);
    }
  }

  return l3;
}

/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua
   elemennya sama */
boolean isListEqual(ListStatik l1, ListStatik l2)
{
  int i;
  boolean isElementEqual = true;

  // Kasus panjang array
  if (listLength(l1) != listLength(l2))
  {
    return false;
  }

  // Kasus panjang sama, cek elemen-elemennya
  for (i = 0; i < listLength(l1); i++)
  {
    if (ELMT(l1, i) != ELMT(l2, i))
    {
      isElementEqual = false;
      break;
    }
  }

  return isElementEqual;
}

/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
int indexOf(ListStatik l, ElType val)
{
  int i;

  for (i = 0; i < listLength(l); i++)
  {
    // Found
    if (ELMT(l, i) == val)
    {
      return i;
    }
  }

  // Not found
  return IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min)
{
  int i;

  // Inisialisasi
  *max = ELMT(l, 0);
  *min = ELMT(l, 0);

  // Loop mencari nilai terkecil & terbesar
  for (i = 0; i < listLength(l); i++)
  {
    if (ELMT(l, i) < *min)
    {
      *min = ELMT(l, i);
    }

    if (ELMT(l, i) > *max)
    {
      *max = ELMT(l, i);
    }
  }
}

/* ********** MENAMBAH ELEMEN ********** */
void insertAt(ListStatik *l, ElType val, IdxType idx)
{
  int i;

  // Geser elemen dgn idx i >= idx
  for (i = getLastIdx(*l); i >= idx; i--)
  {
    ELMT(*l, i + 1) = ELMT(*l, i);
  }

  // Tambahkan element pada i = idx
  ELMT(*l, idx) = val;
}

/* Proses: Menambahkan val sebagai elemen pertama List */
void insertFirst(ListStatik *l, ElType val)
{
  insertAt(l, val, getFirstIdx(*l));
}

/* Proses: Menambahkan val sebagai elemen terakhir List */
void insertLast(ListStatik *l, ElType val)
{
  insertAt(l, val, getLastIdx(*l) + 1);
}

/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatik *l, ElType *val, IdxType idx)
{
  int i;

  // Get deleted value
  *val = ELMT(*l, idx);

  // For larger than 1, move middle values
  for (i = idx; i < listLength(*l) - 1; i++)
  {
    ELMT(*l, i) = ELMT(*l, i + 1);
  }

  // Reset ending values to mark
  ELMT(*l, getLastIdx(*l)) = MARK;
}

/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val)
{
  deleteAt(l, val, getFirstIdx(*l));
}

/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, ElType *val)
{
  deleteAt(l, val, getLastIdx(*l));
}

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc)
{
  int i, j, *a, *b, temp;
  for (i = 0; i < listLength(*l) - 1; i++)
  {
    for (j = 0; j < listLength(*l) - 1 - i; j++)
    {
      a = &ELMT(*l, j + 1);
      b = &ELMT(*l, j);
      if (asc)
      {
        // Ascending sort
        if (*a < *b)
        {
          temp = *b;
          *b = *a;
          *a = temp;
        }
      }
      else
      {
        // Descending sort
        if (*a > *b)
        {
          temp = *b;
          *b = *a;
          *a = temp;
        }
      }
    }
  }
}
