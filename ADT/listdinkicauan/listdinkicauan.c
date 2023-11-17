/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#include <stdio.h>
#include <stdlib.h>
#include "../datetime/datetime.h"
#include "../listdinkicauan/listdinkicauan.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDinKicauan(ListDinKicauan *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
  CAPACITY_LDK(*l) = capacity;
  NEFF_LDK(*l) = 0;
  BUFFER_LDK(*l) = (ElTypeListDinKicauan *)malloc(CAPACITY_LDK(*l) * sizeof(ElTypeListDinKicauan));
}

void dealocateListDinKicauan(ListDinKicauan *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY_LDK(l)=0; NEFF_LDK(l)=0 */
{
  CAPACITY_LDK(*l) = 0;
  NEFF_LDK(*l) = 0;
  free(BUFFER_LDK(*l));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listDinKicauanLength(ListDinKicauan l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
  return NEFF_LDK(l);
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdxListDinKicauan(ListDinKicauan l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
{
  return IDX_MIN;
}
IdxType getLastIdxListDinKicauan(ListDinKicauan l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
  return NEFF_LDK(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidListDinKicauan(ListDinKicauan l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
  return (i >= getFirstIdxListDinKicauan(l) && i < CAPACITY_LDK(l));
}

boolean isIdxEffListDinKicauan(ListDinKicauan l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF_LDK(l) */
{
  return (i >= getFirstIdxListDinKicauan(l) && i <= getLastIdxListDinKicauan(l));
}

/* Prosedur mengecek apakah ada kicauan dengan idKicauan */
boolean isKicauanExist(int idKicauan)
/* Mengembalikan true bila kicauan ada, mengembalikan false bila tidak. */
{
  // Kicauan tidak bisa di delete sehingga idKicau yang valid adalah >= 1 <= listLength(listKicauan)
  return (idKicauan >= 1 && idKicauan <= listDinKicauanLength(listKicauan));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyListDinKicauan(ListDinKicauan l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
{
  return NEFF_LDK(l) == 0;
}

/* *** Test list penuh *** */
boolean isFullListDinKicauan(ListDinKicauan l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
  return NEFF_LDK(l) == CAPACITY_LDK(l);
}

/* ********** OPERASI LAIN ********** */
/* Sortir kicauan berdasarkan datetime */
ListDinKicauan sortKicauanByDateTime(ListDinKicauan l, boolean asc)
/* Menghasilkan list baru list dinamis kicauan yang sudah disortir berdasarkan tanggalnya */
{
  ListDinKicauan lNew;
  CreateListDinKicauan(&lNew, CAPACITY_LDK(l));
  copyListDinKicauan(l, &lNew);

  // Bubble sort
  IdxType i, j;
  for (i = getFirstIdxListDinKicauan(lNew); i <= getLastIdxListDinKicauan(lNew); i++)
  {
    for (j = getFirstIdxListDinKicauan(lNew); j <= getLastIdxListDinKicauan(lNew); j++)
    {
      DATETIME d1 = DATETIME(InfoKicauan(ELMT_LDK(l, i)));
      DATETIME d2 = DATETIME(InfoKicauan(ELMT_LDK(lNew, j)));
      if (asc)
      {
        if (DLT(d1, d2))
        {
          ElTypeListDinKicauan temp = ELMT_LDK(lNew, i);
          ELMT_LDK(lNew, i) = ELMT_LDK(lNew, j);
          ELMT_LDK(lNew, j) = temp;
        }
      }
      else
      {
        if (DGT(d1, d2))
        {
          ElTypeListDinKicauan temp = ELMT_LDK(lNew, i);
          ELMT_LDK(lNew, i) = ELMT_LDK(lNew, j);
          ELMT_LDK(lNew, j) = temp;
        }
      }
    }
  }

  return lNew;
}

void copyListDinKicauan(ListDinKicauan lIn, ListDinKicauan *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
{
  int i;
  CreateListDinKicauan(lOut, CAPACITY_LDK(lIn));
  NEFF_LDK(*lOut) = NEFF_LDK(lIn);
  for (i = getFirstIdxListDinKicauan(lIn); i <= getLastIdxListDinKicauan(lIn); i++)
  {
    ELMT_LDK(*lOut, i) = ELMT_LDK(lIn, i);
  }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListDinKicauan(ListDinKicauan *l, ElTypeListDinKicauan val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
  if (isEmptyListDinKicauan(*l))
  {
    ELMT_LDK(*l, IDX_MIN) = val;
  }
  else
  {
    if (!isFullListDinKicauan(*l))
    {
      ELMT_LDK(*l, getLastIdxListDinKicauan(*l) + 1) = val;
    }
  }
  NEFF_LDK(*l) += 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListDinKicauan(ListDinKicauan *l, ElTypeListDinKicauan *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
  if (!isEmptyListDinKicauan(*l))
  {
    *val = ELMT_LDK(*l, getLastIdxListDinKicauan(*l));
    NEFF_LDK(*l) -= 1;
  }
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListDinKicauan(ListDinKicauan *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
  ListDinKicauan lNew;
  CreateListDinKicauan(&lNew, CAPACITY_LDK(*l) + num);
  NEFF_LDK(lNew) = NEFF_LDK(*l);

  IdxType i;
  for (i = getFirstIdxListDinKicauan(*l); i <= getLastIdxListDinKicauan(*l); i++)
  {
    ELMT_LDK(lNew, i) = ELMT_LDK(*l, i);
  }
  dealocateListDinKicauan(l);
  *l = lNew;
}

void shrinkListDinKicauan(ListDinKicauan *l, int num)
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
  ListDinKicauan lNew;
  CreateListDinKicauan(&lNew, CAPACITY_LDK(*l) - num);
  if (NEFF_LDK(*l) < CAPACITY_LDK(*l) - num)
  {
    NEFF_LDK(lNew) = NEFF_LDK(*l);
  }
  else
  {
    NEFF_LDK(lNew) = CAPACITY_LDK(*l) - num;
  }

  IdxType i;
  for (i = getFirstIdxListDinKicauan(*l); i <= getLastIdxListDinKicauan(*l); i++)
  {
    ELMT_LDK(lNew, i) = ELMT_LDK(*l, i);
  }
  dealocateListDinKicauan(l);
  *l = lNew;
}

void compressListDinKicauan(ListDinKicauan *l)
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */
{
  ListDinKicauan lNew;
  CreateListDinKicauan(&lNew, NEFF_LDK(*l));
  NEFF_LDK(lNew) = NEFF_LDK(*l);

  IdxType i;
  for (i = getFirstIdxListDinKicauan(*l); i <= getLastIdxListDinKicauan(*l); i++)
  {
    ELMT_LDK(lNew, i) = ELMT_LDK(*l, i);
  }
  dealocateListDinKicauan(l);
  *l = lNew;
}
