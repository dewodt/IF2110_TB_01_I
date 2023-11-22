#include <stdio.h>
#include <stdlib.h>
#include "draf.h"
#include "../masukan/masukan.h"
#include "../kicauan/kicauan.h"
#include "../modifiedliststatik/modifiedliststatik.h" // Global variable listUser
#include "../listdinkicauan/listdinkicauan.h"         // Global variable listDinKicauan
#include "../pengguna/pengguna.h"                     // Global variable currentUser

void createDraf(Draf *Draf, char *text, DATETIME datetime)
/* I.S. Draf sembarang, id, text, author, datetime terdefinisi */
/* Draf terdefinisi */
/* F.S. Draf terdefinisi sesuai parameter */
{
  // Datetime
  DATETIME(*Draf) = datetime;

  // Text
  strcpy(TEXT(*Draf), text);
}

// CEK LAGIIII
void prosesDraf(Stack *DrafStack, Draf *Draft)
/**
 * Prosedur untuk 4 perintah MASUKAN yang memproses Draf
 */
{
  Draf TempDraf;

  // case-sensitive commands
  MASUKAN PerintahMasukan;
  baca(&PerintahMasukan);
  if (isSame(PerintahMasukan, "HAPUS;"))
  {
    // jika mengakses Top, dari lihatDraf
    if (Draft == &InfoTop(*DrafStack))
    {
      Pop(DrafStack, &TempDraf);
    }
    free(Draft);
    printf("Draf telah berhasil dihapus!");
  }
  else if (isSame(PerintahMasukan, "SIMPAN;") && Draft != &InfoTop(*DrafStack))
  {
    Push(DrafStack, *Draft);
    printf("Draf telah berhasil disimpan!");
  }
  else if (isSame(PerintahMasukan, "TERBIT;"))
  {
    // ID Kicauan paling terakhir
    int idKicauanTerakhir = listDinKicauanLength(listKicauan);
    int idKicauanBaru = idKicauanTerakhir + 1;

    Kicauan KicauanBaru;
    CreateKicauan(&KicauanBaru, idKicauanBaru, Draft->text, 0, currentUser, Draft->datetime);
    TreeKicauan NodeKicauan = newNodeKicauan(KicauanBaru);
    insertLastListDinKicauan(&listKicauan, NodeKicauan);

    // jika mengakses Top, dari lihatDraf
    if (Draft == &InfoTop(*DrafStack))
    {
      Pop(DrafStack, &TempDraf);
    }
    free(Draft);

    printf("Selamat! Draf kicauan telah diterbitkan!");
    printf("Detil kicauan:\n");
    printDetailKicauan(KicauanBaru);
  }
  else if (isSame(PerintahMasukan, "KEMBALI;"))
  {
    // do nothing
  }
  else if (isSame(PerintahMasukan, "UBAH;") && Draft == &InfoTop(*DrafStack))
  {
    // Kasus mengubah setelah lihat info top stack drafnya pengguna
    ubahDraf(DrafStack, Draft);
  }
  else
  {
    // handle commands tidak sesuai, do nothing
  }
}

void tampilkanDraf(Draf DrafInfo)
/**
 * Prosedur untuk menampilkan informasi draf
 */
{
  // Tanggal
  printf("| ");
  TulisDATETIME(DATETIME(DrafInfo));
  printf("\n");

  // Pesan
  printf("| %s\n", TEXT(DrafInfo));
}

void buatDraf(Stack *DrafStack)
/**
 * Prosedur untuk MASUKAN BUAT_DRAF
 */
{
  // Validasi sudah masuk atau belum
  // TODO: CONNECT WITH GLOBAL VAR CURRENT USER
  boolean isUserLoggedIn = true;
  if (!isUserLoggedIn)
  {
    printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    return;
  }

  // Masukan pesan Draf
  printf("Masukkan Draf:\n");
  MASUKAN DrafMasukan;
  baca(&DrafMasukan);
  char *DrafStr = MASUKANToStr(DrafMasukan);

  // Validasi masukan Draf
  if (isAllSpace(DrafMasukan))
  {
    printf("Draf tidak boleh hanya berisi spasi!\n");
    return;
  }

  // Dapatkan waktu dari library time.h
  DATETIME waktuDraf;
  GetCurrentLocalDATETIME(&waktuDraf);

  // Buat Draf baru
  // TO DO: CONNECT KE GLOBAL VARIABLE CURRENT USER
  Draf DrafBaru;
  createDraf(&DrafBaru, DrafStr, waktuDraf);

  printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
  prosesDraf(DrafStack, &DrafBaru);
}

void lihatDraf(Stack *DrafStack)
/**
 * Prosedur untuk MASUKAN LIHAT_DRAF
 */
{
  // Validasi sudah masuk atau belum
  // TODO: CONNECT WITH GLOBAL VAR CURRENT USER
  boolean isUserLoggedIn = true;
  if (!isUserLoggedIn)
  {
    printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    return;
  }

  if (IsEmpty(*DrafStack))
  {
    // Kasus tidak ada draf
    printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D");
  }
  else
  {
    Draf DrafOnTop = InfoTop(*DrafStack);

    printf("Ini draf terakhir anda:\n");
    tampilkanDraf(DrafOnTop);

    printf("Apakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
    prosesDraf(DrafStack, &DrafOnTop);
  }
}

void ubahDraf(Stack *DrafStack, Draf *Draft)
/**
 * Prosedur untuk mengubah Draft setelah melihat draf
 */
{
  // Masukan pesan Draf
  printf("Masukkan Draf:\n");
  MASUKAN DrafMasukan;
  baca(&DrafMasukan);
  char *DrafStr = MASUKANToStr(DrafMasukan);

  // Validasi masukan Draf
  if (isAllSpace(DrafMasukan))
  {
    printf("Draf tidak boleh hanya berisi spasi!\n");
    return;
  }

  strcpy(TEXT(*Draft), DrafStr);

  // Dapatkan waktu dari library time.h
  DATETIME waktuDraf;
  GetCurrentLocalDATETIME(&waktuDraf);
  DATETIME(*Draft) = waktuDraf;

  printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
  prosesDraf(DrafStack, Draft);
}