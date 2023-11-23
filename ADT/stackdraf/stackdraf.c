#include "stackdraf.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
  Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
  return Top(S) == Nil;
}
boolean IsFullStack(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
  return Top(S) == MaxElmt - 1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStack(Stack *S, infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
  (*S).T[Top(*S) + 1] = X;
  Top(*S) += 1;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack(Stack *S, infotype *X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
  (*X) = (*S).T[Top(*S)];
  Top(*S) -= 1;
}

void ReverseStack(Stack s, Stack* rs){
  infotype elmt;
  while(!IsEmptyStack(s)){
    PopStack(&s,&elmt);
    PushStack(rs,elmt);
  }
}
