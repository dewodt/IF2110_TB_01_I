#include "listlinier.h"
#include "stdio.h"
#include "stdlib.h"

Address newNode(ElType val)
{
  /* Definisi List : */
  /* List kosong : FIRST(l) = NULL */
  /* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
  /* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */
  Address p = (Address)malloc(sizeof(Node));
  if (p != NULL)
  {
    INFO(p) = val;
    NEXT(p) = NULL;
  }
  return p;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
  FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
/* Mengirim true jika list kosong */
{
  return FIRST(l) == NULL;
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
{
  Address p = FIRST(l);

  // Geser
  int i = 0;
  while (i < idx)
  {
    p = NEXT(p);
    i++;
  }
  // Current p = idx

  return INFO(p);
}

void setElmt(List *l, int idx, ElType val)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
{
  Address p = FIRST(*l);

  // Geser
  int i = 0;
  while (i < idx)
  {
    p = NEXT(p);
    i++;
  }
  // Current p = idx

  INFO(p) = val;
}

int indexOf(List l, ElType val)
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
{
  boolean found = false;
  int i = 0;
  Address p = FIRST(l);

  while (!found && p != NULL)
  {
    if (val == INFO(p))
    {
      found = true;
    }
    else
    {
      p = NEXT(p);
      i += 1;
    }
  }

  if (found)
  {
    return i;
  }
  else
  {
    return IDX_UNDEF;
  }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
{
  Address p = newNode(val);
  if (p != NULL)
  {
    NEXT(p) = *l;
    *l = p;
  }
}

void insertLast(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
  if (isEmpty(*l))
  {
    insertFirst(l, val);
  }
  else
  {
    Address p = newNode(val);
    if (p != NULL)
    {
      Address temp = FIRST(*l);
      while (NEXT(temp) != NULL)
      {
        temp = NEXT(temp);
      }
      NEXT(temp) = p;
    }
  }
}

void insertAt(List *l, ElType val, int idx)
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
  if (idx == 0)
  {
    insertFirst(l, val);
  }
  else
  {
    Address p = newNode(val);
    if (p != NULL)
    {
      Address temp = FIRST(*l);
      int i = 0;
      while (i < idx - 1)
      {
        temp = NEXT(temp);
        i++;
      }
      // i = idx - 1
      // temp berada di idx - 1

      NEXT(p) = NEXT(temp);
      NEXT(temp) = p;
    }
  }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
{
  Address temp = FIRST(*l);
  *val = INFO(temp);
  *l = NEXT(temp);
  free(temp);
}

void deleteLast(List *l, ElType *val)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
{
  Address temp = FIRST(*l);
  Address loc = NULL;

  while (NEXT(temp) != NULL)
  {
    loc = temp;
    temp = NEXT(temp);
  }

  if (loc == NULL)
  {
    // Kasus satu elemen doang
    *l = NULL;
  }
  else
  {
    NEXT(loc) = NULL;
  }

  *val = INFO(temp);
  free(temp);
}

void deleteAt(List *l, int idx, ElType *val)
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
{
  if (idx == 0)
  {
    deleteFirst(l, val);
  }
  else
  {
    int i = 0;
    Address loc = FIRST(*l);
    while (i < idx - 1)
    {
      i++;
      loc = NEXT(loc);
    }

    Address p = NEXT(loc);
    *val = INFO(p);
    NEXT(loc) = NEXT(p);
    free(p);
  }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
  printf("[");
  Address p = FIRST(l);
  while (p != NULL)
  {
    printf("%d", INFO(p));
    p = NEXT(p);
    if (p != NULL)
    {
      printf(",");
    }
  }
  printf("]");
}

int length(List l)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
  int count = 0;
  Address p = FIRST(l);
  while (p != NULL)
  {
    count++;
    p = NEXT(p);
  }
  return count;
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2)
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
  List l3;
  CreateList(&l3);

  Address p1 = FIRST(l1);
  while (p1 != NULL)
  {
    insertLast(&l3, INFO(p1));
    p1 = NEXT(p1);
  }

  Address p2 = FIRST(l2);
  while (p2 != NULL)
  {
    insertLast(&l3, INFO(p2));
    p2 = NEXT(p2);
  }

  return l3;
}