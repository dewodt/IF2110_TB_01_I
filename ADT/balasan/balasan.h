#ifndef BALASAN_H
#define BALASAN_H

#include "../datetime/datetime.h"

/* Struktur Info Balasan */
/* Balasan memiliki id, teks, author, datetime */
typedef struct
{
  int id;
  char text[280];
  char author; /* TO DO: CONNECT KE ADT PENGGUNA */
  DATETIME datetime;
} Balasan;

/* Selektor Balasan */
#define ID(k) (k).id
#define TEXT(k) (k).text
#define AUTHOR(k) (k).author
#define DATETIME(k) (k).datetime

/* Buat balasan baru */
void CreateBalasan(Balasan *b, int id, char *text, char author, DATETIME datetime);
/* I.S. balasan sembarang, id, text, author, datetime terdefinisi */
/* F.S. terbentuk balasan dengan sesuai parameter input */

/* Prosedur Balas */
void BuatBalasan(int idKicau, int idBalasan);
/* I.S. Sembarang */
/* F.S. Bila idKicau valid dan idBalasan -1, maka membalas kicau
  Bila idKicau valid dan idBalasan valid, maka balas balasan
  Bila akun privat dan belum berteman dengan author, output pesan tidak dapat membalas
  Bila idKicau tidak valid, output pesan tidak terdapat kicauan
  Bila idKicau valid namun idBalasan tidak valid, output pesan tidak terdapat balasan */

// Mencetak kedalaman suatu baris dalam balasan
void CetakKedalaman(int depth);
/* I.S. depth valid */
/* F.S. tercetak spasi kedalaman depth */

/* Prosedur mencetak satu detail balasan */
void CetakDetailBalasan(Balasan b, boolean isPrivat, int depth);
/* I.S. Sembarang */
/* F.S. bila privat, akan tercetak privat beserta kedalamannya
        bila bisa dilihat, akan tercetak detail balasan (nama, text, dll tercetak) beserta dengan spasi kedalaman */

/* Prosedur Mencetak Balasan */
void TampilkanBalasan(int idKicau);
void TampilkanBalasanRekursif(AddressBalasan nodeBalasan, int dept);
/* I.S. Sembarang */
/* F.S. Menampilkan seluruh tree balasan dari sebuah idKicau dengan ketentuan
  Bila idKicau tidak valid, output pesan kicauan tidak ada
  Bila Akun yang membuat kicauan privat dan user belum berteman, output pesan kicauan privat
  Bila belum terdapat balasan pada kicauan, output pesan belum terdapat balasan
  Bila pada balasan ada balasan yang privat dan belum berteman, tampilkan balasan PRIVAT */

/* Prosedur Menghapus Balasan */
void HapusBalasan(int idKicau, int idBalasan);
/* I.S. Sembarang */
/* F.S. Bila ditemukan balasan dengan idBalasan pada kicauan dengan idKicau maka balasan terhapus
  Bila tidak ditemukan, output pesan balasan tidak ditemukan
  Bila ditemukan dan bukan miliknya output pesan error */

#endif BALASAN_H