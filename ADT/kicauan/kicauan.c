#include <stdio.h>
#include "kicauan.h"
#include "../time/time.h"
#include "../boolean.h"
#include "../datetime/datetime.h"
#include "../listdinkicauan/listdinkicauan.h"
#include "../masukan/masukan.h"
#include "time.h"

/* Prosedur Mendefinisikan Sebuah Kicauan */
void CreateKicauan(Kicauan *k, int id, char text[], int like, char author, DATETIME datetime)
/* I.S. Sembarang, data id, text, like, author, datetime valid */
/* F.S. Terbentuk kicauan dengan id, teks, like, author, datetime sesuai input */
{
  ID(*k) = id;
  AUTHOR(*k) = author;
  LIKE(*k) = like;
  DATETIME(*k) = datetime;

  // Update text
  int i;
  for (i = 0; i < 280; i++)
  {
    TEXT(*k)
    [i] = text[i];
  }
}

/* Prosedur pemanggilan pembuatan Kicau (bersama validasi2nya) */
void BuatKicauan()
/* I.S. User sudah masuk, tidak terbentuk kicauan */
/* F.S. Bila data yang diinput valid, maka akan terbentuk kicauan dengan id, teks, like, author, datetime sesuai input (ditambahkan ke global var list kicauan)
   Bila data yang diinput tidak valid atau melawan constraint tertentu, maka output pesan kesalahan */
{
  // ID Kicauan paling terakhir
  int idKicauanTerakhir = listLength(listKicauan);
  int idKicauanBaru = idKicauanTerakhir + 1;

  printf("Masukkan kicauan:\n");
  printf(">> ");

  // Masukan pesan kicauan
  MASUKAN pesanKicauan;
  baca(&pesanKicauan);

  // Validasi masukan kicauan
  if (isAllSpace)
  {
    printf("Kicauan tidak boleh hanya berisi spasi!\n");
    return;
  }

  // Dapatkan waktu dari library time.h
  DATETIME waktuKicauan;
  GetCurrentLocalDATETIME(&waktuKicauan);

  // Buat kicauan baru
  Kicauan kicauanBaru;
  // TO DO: CONNECT KE GLOBAL VARIABLE CURRENT USER
  // CreateKicauan(&kicauanBaru, idKicauanBaru, pesanKicauan, 0, currentUser, waktuKicauan);
  insertLast(&listKicauan, &kicauanBaru);

  // Cetak pesan
  printf("Selamat! kicauan telah diterbitkan!\n");
  pritnf("Detil kicauan:\n");
  printDetailKicauan(kicauanBaru);
}

/* Prosedur Menampilkan Detail Kicauan */
void printDetailKicauan(Kicauan k)
/* I.S. Sembarang */
/* F.S. Mencetak detail sebuah kicauan */
{
  // ID
  printf("| ID = %d\n", ID(k));

  // Author
  printf("| %s\n", AUTHOR(k));

  // Tanggal
  printf("| ");
  TulisDATETIME(DATETIME(k));
  printf("\n");

  // Pesan
  printf("| %s\n", TEXT(k));

  // Likes
  printf("| Disukai: %d\n", LIKE(k));
}

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