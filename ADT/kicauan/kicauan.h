#ifndef KICAUAN_H
#define KICAUAN_H

#include "../time/time.h"
#include "../datetime/datetime.h"

/* Struktur Kicauan */
/* Kicauan memiliki id, teks, like, author, datetime */
/* Kicauan juga bisa menjadi sebuah utas */
typedef struct
{
  int id;
  int like;
  char author; /* TO DO: CONNECT KE ADT PENGGUNA */
  DATETIME datetime;
} Kicauan;

/* Selektor Kicauan */
#define ID(k) (k).id
#define LIKE(k) (k).like
#define AUTHOR(k) (k).author
#define DATETIME(k) (k).datetime

/* Prosedur pemanggilan pembuatan Kicau (bersama validasi2nya) */
/* I.S. Sembarang,tidak terbentuk kicauan */
/* F.S. Bila data yang diinput valid, maka akan terbentuk kicauan dengan id, teks, like, author, datetime sesuai input (ditambahkan ke global var list kicauan)
   Bila data yang diinput tidak valid atau melawan constraint tertentu, maka output pesan kesalahan */
void Kicau();

/* Prosedur Menampilkan Kicauan */
/* I.S. Sembarang */
/* F.S. Menampilkan seluruh kicauan buatan diri sendiri dan orang2 yang berada di list teman terurut berdasarkan waktu */
void Kicauan();

/* Prosedur like kicauan */
/* I.S. Sembarang */
/* F.S. Bila idKicau valid, maka jumlah like kicauan dengan id idKicau bertambah satu (update global var list kicauan)
  Bila idKicau tidak valid, maka keluarkan pesan kicauan tidak ditemukan */
void SukaKicauan(int idKicau);

/* Prosedur Ubah Kicauan */
/* I.S. Sembarang */
/* F.S. Bila idKicau valid, maka kicauan dengan suatu id idKicau diperbarui (update global var list kicauan)
  Bila idKicau tidak valid, maka keluarkan pesan kicauan tidak ditemukan */
void UbahKicauan(int idKicau);

#endif KICAUAN_H