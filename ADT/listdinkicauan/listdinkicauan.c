/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#include <stdio.h>
#include <stdlib.h>
#include "../listdinkicauan/listdinkicauan.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDinKicauan(ListDinKicauan *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
  CAPACITY(*l) = capacity;
  NEFF(*l) = 0;
  BUFFER(*l) = (ElType *)malloc(CAPACITY(*l) * sizeof(ElType));
}

void dealocateList(ListDinKicauan *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
  CAPACITY(*l) = 0;
  NEFF(*l) = 0;
  free(BUFFER(*l));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDinKicauan l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
  return NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDinKicauan l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
{
  return IDX_MIN;
}
IdxType getLastIdx(ListDinKicauan l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
  return NEFF(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDinKicauan l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
  return (i >= getFirstIdx(l) && i < CAPACITY(l));
}

boolean isIdxEff(ListDinKicauan l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
{
  return (i >= getFirstIdx(l) && i <= getLastIdx(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDinKicauan l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
{
  return NEFF(l) == 0;
}

/* *** Test list penuh *** */
boolean isFull(ListDinKicauan l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
  return NEFF(l) == CAPACITY(l);
}

/* ********** OPERASI LAIN ********** */
ListDinKicauan sortListDinKicauanByDateTime(ListDinKicauan l, boolean asc)
/* Menghasilkan list baru list dinamis kicauan yang sudah disortir berdasarkan tanggalnya */
{
  ListDinKicauan lNew;
  CreateListDinKicauan(&lNew, CAPACITY(l));
  copyList(l, &lNew);

  // Bubble sort
  IdxType i, j;
  for (i = getFirstIdx(lNew); i <= getLastIdx(lNew); i++)
  {
    for (j = getFirstIdx(lNew); j <= getLastIdx(lNew); j++)
    {
      DATETIME d1 = DATETIME(INFOKICAUAN(ELMT(lNew, i)));
      DATETIME d2 = DATETIME(INFOKICAUAN(ELMT(lNew, j)));
      if (asc)
      {
        if (DLT(d1, d2))
        {
          ElType temp = ELMT(lNew, i);
          ELMT(lNew, i) = ELMT(lNew, j);
          ELMT(lNew, j) = temp;
        }
      }
      else
      {
        if (DGT(d1, d2))
        {
          ElType temp = ELMT(lNew, i);
          ELMT(lNew, i) = ELMT(lNew, j);
          ELMT(lNew, j) = temp;
        }
      }
    }
  }

  return lNew;
}

void copyList(ListDinKicauan lIn, ListDinKicauan *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
{
  int i;
  CreateListDinKicauan(lOut, CAPACITY(lIn));
  NEFF(*lOut) = NEFF(lIn);
  for (i = getFirstIdx(lIn); i <= getLastIdx(lIn); i++)
  {
    ELMT(*lOut, i) = ELMT(lIn, i);
  }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDinKicauan *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
  if (isEmpty(*l))
  {
    ELMT(*l, IDX_MIN) = val;
  }
  else
  {
    if (!isFull(*l))
    {
      ELMT(*l, getLastIdx(*l) + 1) = val;
    }
  }
  NEFF(*l) += 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDinKicauan *l, ElType *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
  if (!isEmpty(*l))
  {
    *val = ELMT(*l, getLastIdx(*l));
    NEFF(*l) -= 1;
  }
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDinKicauan *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
  ListDinKicauan lNew;
  CreateListDinKicauan(&lNew, CAPACITY(*l) + num);
  NEFF(lNew) = NEFF(*l);

  IdxType i;
  for (i = getFirstIdx(*l); i <= getLastIdx(*l); i++)
  {
    ELMT(lNew, i) = ELMT(*l, i);
  }
  dealocateList(l);
  *l = lNew;
}

void shrinkList(ListDinKicauan *l, int num)
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
  ListDinKicauan lNew;
  CreateListDinKicauan(&lNew, CAPACITY(*l) - num);
  if (NEFF(*l) < CAPACITY(*l) - num)
  {
    NEFF(lNew) = NEFF(*l);
  }
  else
  {
    NEFF(lNew) = CAPACITY(*l) - num;
  }

  IdxType i;
  for (i = getFirstIdx(*l); i <= getLastIdx(*l); i++)
  {
    ELMT(lNew, i) = ELMT(*l, i);
  }
  dealocateList(l);
  *l = lNew;
}

void compressList(ListDinKicauan *l)
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */
{
  ListDinKicauan lNew;
  CreateListDinKicauan(&lNew, NEFF(*l));
  NEFF(lNew) = NEFF(*l);

  IdxType i;
  for (i = getFirstIdx(*l); i <= getLastIdx(*l); i++)
  {
    ELMT(lNew, i) = ELMT(*l, i);
  }
  dealocateList(l);
  *l = lNew;
}
