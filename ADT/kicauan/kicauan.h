#ifndef KICAUAN_H
#define KICAUAN_H

#include "../datetime/datetime.h"
#include "../listdinkicauan/listdinkicauan.h"

/* Struktur Kicauan */
/* Kicauan memiliki id, teks, like, author, datetime */
/* Kicauan juga bisa menjadi sebuah utas */
typedef struct
{
  int id;
  char text[280];
  int like;
  char author; /* TO DO: CONNECT KE ADT PENGGUNA */
  DATETIME datetime;
} Kicauan;

/* Selektor Kicauan */
#define ID(k) (k).id
#define TEXT(k) (k).text
#define LIKE(k) (k).like
#define AUTHOR(k) (k).author
#define DATETIME(k) (k).datetime

/* Konstruktor kicauan */
void CreateKicauan(Kicauan *k, int id, char *text, char author, DATETIME datetime);
/* I.S. kicauan sembarang, id, text, author, datetime terdefinisi */
/* Kicauan terdefinisi */
/* F.S. kicauan terdefinisi sesuai parameter */

/* Prosedur pemanggilan pembuatan Kicau (bersama validasi2nya) */
void BuatKicauan();
/* I.S. User sudah masuk, tidak terbentuk kicauan */
/* F.S. Bila data yang diinput valid, maka akan terbentuk kicauan dengan id, teks, like, author, datetime sesuai input (ditambahkan ke global var list kicauan)
   Bila data yang diinput tidak valid atau melawan constraint tertentu, maka output pesan kesalahan */

/* Prosedur Menampilkan Detail Kicauan */
void printDetailKicauan(Kicauan k);
/* I.S. Sembarang */
/* F.S. Mencetak detail sebuah kicauan */

/* Prosedur Menampilkan Kicauan */
void TampilkanKicauan();
/* I.S. Sembarang */
/* F.S. Menampilkan seluruh kicauan buatan diri sendiri dan orang2 yang berada di list teman terurut berdasarkan waktu */

/* Prosedur like kicauan */
/* I.S. Sembarang */
void SukaKicauan(int idKicau);
/* F.S. Bila idKicau valid, maka jumlah like kicauan dengan id idKicau bertambah satu (update global var list kicauan)
  Bila idKicau tidak valid, maka keluarkan pesan kicauan tidak ditemukan */

/* Prosedur Ubah Kicauan */
/* I.S. Sembarang */
void UbahKicauan(int idKicau);
/* F.S. Bila idKicau valid, maka kicauan dengan suatu id idKicau diperbarui (update global var list kicauan)
  Bila idKicau tidak valid, maka keluarkan pesan kicauan tidak ditemukan */

#endif KICAUAN_H