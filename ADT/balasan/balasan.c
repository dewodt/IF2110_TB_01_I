#include <stdio.h>
#include "../masukan/masukan.h"
#include "../balasan/balasan.h"
#include "../listdinkicauan/listdinkicauan.h"

/* Prosedur Balas */
void BuatBalasan(int idKicau, int idBalasan)
/* I.S. Sembarang */
/* F.S. Bila idKicau valid dan idBalasan -1, maka membalas kicau
  Bila idKicau valid dan idBalasan valid, maka balas balasan
  Bila akun privat dan belum berteman dengan author, output pesan tidak dapat membalas
  Bila idKicau tidak valid, output pesan tidak terdapat kicauan
  Bila idKicau valid namun idBalasan tidak valid, output pesan tidak terdapat balasan */
{
  // Validasi sudah masuk atau belum
  // TODO: CONNECT WITH GLOBAL VAR CURRENT USER
  boolean isUserLoggedIn = true;
  if (!isUserLoggedIn)
  {
    printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    return;
  }

  // Kasus idKicau tidak valid (kicauan tidak ditemukan)
  // Kicauan tidak bisa di delete sehingga idKicau yang valid adalah >= 1 <= listLength(listKicauan)
  if (!isKicauanExist(listKicauan, idKicau))
  {
    printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
    return;
  }

  // Kasus idKicau valid, idBalasan = -1 (membalas kicauan)
  TreeKicauan kicauan = ELMT(listKicauan, idKicau);
  if (idBalasan == -1)
  {
    // TO DO: CONNECT DGN ADT CEK TEMAN & CEK PRIVAT PENGGUNA
    boolean isCurrentUserCanSee = true;
    if (!isCurrentUserCanSee)
    {
      // Kasus tidak bisa membalas kicauan
      // idKicau valid, idBalasan = -1, akun privat dan belum berteman
      printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebu!\n");
    }
    else
    {
      // Kasus bisa membalas kicauan
      // idKicau valid, idBalasan = -1, akun tidak privat atau sudah berteman

      // Dapatkan input balasan
      printf("Masukkan balasan:\n");
      MASUKAN textBalasan;
      baca(&textBalasan);
      printf("\n");

      // Dapatkan node balasan paling terakhir
      AddressBalasan latestBalasan = getLatestBalasan(kicauan);
      int nextId = ID(InfoBalasan(latestBalasan)) + 1;

      // Buat balasan baru
      Balasan balasan;
      // CreateBalasan(&balasan, nextId, textBalasan, 'A', getCurrentDateTime());

      // Balas
      balasKicauan(kicauan, balasan);
    }
    return;
  }

  AddressBalasan balasan = getBalasan(kicauan, idBalasan);
  // Kasus balasan tidak ketemu
  if (balasan == NULL)
  {
    printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
    return;
  }

  // Kasus balasan privat
  boolean isCurrentUserCanSee = true;
  if (!isCurrentUserCanSee)
  {
    // Kasus tidak bisa membalas kicauan
    // idKicau valid, idBalasan = -1, akun privat dan belum berteman
    printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebu!\n");
    return;
  }

  // Kasus idKicau valid, idBalasan valid (membalas balasan)
  // Dapatkan input balasan
  printf("Masukkan balasan:\n");
  MASUKAN textBalasan;
  baca(&textBalasan);
  printf("\n");

  // Dapatkan node balasan paling terakhir
  AddressBalasan latestBalasan = getLatestBalasan(kicauan);
  int nextId = ID(InfoBalasan(latestBalasan)) + 1;

  // Buat balasan baru
  Balasan infoBalasan;
  // CreateBalasan(&balasan, nextId, textBalasan, 'A', getCurrentDateTime());

  // Balas
  balasBalasan(balasan, infoBalasan);
}

/* Prosedur Mencetak Balasan */
void TampilkanBalasan(int idKicau);
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