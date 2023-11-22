#include <stdio.h>
#include <stdlib.h>
#include "draf.h"
#include "../masukan/masukan.h"
#include "../kicauan/kicauan.h"
#include "../modifiedliststatik/modifiedliststatik.h" // Global variable listUser
#include "../listdinkicauan/listdinkicauan.h"         // Global variable listDinKicauan
#include "../pengguna/pengguna.h"                     // Global variable currentUser
#include "../stackdraf/stackdraf.h"

void CreateDraf(Draf *Draf, char *text, DATETIME datetime)
/* I.S. Draf sembarang, id, text, author, datetime terdefinisi */
/* Draf terdefinisi */
/* F.S. Draf terdefinisi sesuai parameter */
{
  // Datetime
  DATETIME(*Draf) = datetime;

  // Text
  strcpy(TEXT(*Draf), text);
}

void BuatDraf()
/**
 * Prosedur untuk MASUKAN BUAT_DRAF
 */
{
  // Validasi sudah masuk atau belum
  if (!isUserLoggedIn())
  {
    printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
    return;
  }

  // Masukan pesan Draf
  printf("\nMasukkan Draf:\n");
  // Masukan
  MASUKAN drafMasukan;
  baca(&drafMasukan);
  // Str
  char *drafStr = MASUKANToStr(drafMasukan);
  printf("\n");

  // ASUMSI:
  // Karena draf kicauan mirip dengan kicauan, maka validasi draf sama dengan validasi kicauan yaitu tidak boleh spasi semua
  if (isAllSpace(drafMasukan))
  {
    printf("Draf tidak boleh hanya berisi spasi!\n\n");
    return;
  }

  // Dapatkan waktu sekarang
  DATETIME currentDateTime;
  GetCurrentLocalDATETIME(&currentDateTime);

  // Buat Draf baru
  Draf newDraf;
  CreateDraf(&newDraf, drafStr, currentDateTime);

  // Get stack (pointer) dari currentUser
  Stack *stackDraf = &(currentUser->draf);

  // Pilihan menu
  printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
  // Masukan
  MASUKAN pilihan;
  baca(&pilihan);
  printf("\n");

  // Validasi pilihan
  if (isSame(pilihan, "SIMPAN"))
  {
    // Simpan
    SimpanDraf(stackDraf, newDraf);
  }
  else if (isSame(pilihan, "HAPUS"))
  {
    // Hapus, draf (cancel draft, tidak ada apa2)
    printf("Draf telah berhasil dihapus!\n\n");
  }
  else if (isSame(pilihan, "TERBIT"))
  {
    PushStack(stackDraf, newDraf);
    TerbitDraf(stackDraf);
  }
  else
  {
    printf("Pilihan tidak valid!\n\n");
  }
}

void LihatDraf()
/**
 * Prosedur untuk MASUKAN LIHAT_DRAF
 */
{
  // Validasi sudah masuk atau belum
  if (!isUserLoggedIn())
  {
    printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
    return;
  }

  // Get stack dari currentUser
  Stack *stackDraf = &(currentUser->draf);

  // Kasus bila stack kosong
  if (IsEmptyStack(*stackDraf))
  {
    // Kasus tidak ada draf
    printf("\nYah, anda belum memiliki draf apapun! Buat dulu ya :D\n\n");
    return;
  }

  // Kasus ada draf
  Draf topDraf = InfoTop(*stackDraf);

  // Cetak pesan
  printf("\nIni draf terakhir anda:\n");
  DisplayDetailDraf(topDraf);
  printf("\n");

  // Pilihan menu
  printf("Apakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
  MASUKAN pilihan;
  baca(&pilihan);
  printf("\n");

  // Validasi pilihan
  if (isSame(pilihan, "UBAH"))
  {
    UbahDraf(stackDraf);
  }
  else if (isSame(pilihan, "HAPUS"))
  {
    HapusDraf(stackDraf);
  }
  else if (isSame(pilihan, "TERBIT"))
  {
    TerbitDraf(stackDraf);
  }
  else if (isSame(pilihan, "KEMBALI"))
  {
    // Do nothing
  }
  else
  {
    printf("Pilihan tidak valid!\n\n");
  }
}

void DisplayDetailDraf(Draf DrafInfo)
/**
 * Prosedur untuk menampilkan informasi sebuah draf
 */
{
  // Tanggal
  printf("| ");
  TulisDATETIME(DATETIME(DrafInfo));
  printf("\n");

  // Pesan
  printf("| %s\n", TEXT(DrafInfo));
}

void HapusDraf(Stack *stackDraf)
/* I.S. stackDraf terdefinisi dan tidak kosong */
/* F.S. elemen stackDraf berkurang satu, yaitu elemen paling atasnya */
{
  // Pop
  Draf tempDraf;
  PopStack(stackDraf, &tempDraf);

  // Cetak pesan
  printf("Draf telah berhasil dihapus!\n\n");
}

void SimpanDraf(Stack *stackDraf, Draf newDraf)
/* I.S. stackDraf terdefinisi dan newDraf terdefinisi */
/* F.S. stack stackDraf bertambah newDraf pada posisi paling atasnya */
{
  // Push
  PushStack(stackDraf, newDraf);

  // Pesan
  printf("Draf telah berhasil disimpan!\n\n");
}

void TerbitDraf(Stack *stackDraf)
/* I.S. stackDraf terdefinisi dan tidak kosong */
/* F.S. stackDraf berkurang satu elemennya (paling atas), dan terbentuk elemen baru pada listDinKicauan */
{
  // Ambil kicauan paling atas
  // Pop
  Draf topDraf;
  PopStack(stackDraf, &topDraf);

  // ID Kicauan paling terakhir
  int idKicauanTerakhir = listDinKicauanLength(listKicauan);
  int idKicauanBaru = idKicauanTerakhir + 1;

  // Dapatkan tanggal sekarang
  DATETIME currentDateTime;
  GetCurrentLocalDATETIME(&currentDateTime);

  // Buat kicauan baru
  Kicauan kicauanBaru;
  CreateKicauan(&kicauanBaru, idKicauanBaru, TEXT(topDraf), 0, currentUser, currentDateTime);
  TreeKicauan nodeKicauan = newNodeKicauan(kicauanBaru);
  insertLastListDinKicauan(&listKicauan, nodeKicauan);

  printf("Selamat! Draf kicauan telah diterbitkan!\n");
  printf("Detil kicauan:\n");
  printDetailKicauan(kicauanBaru);
  printf("\n");
}

void UbahDraf(Stack *stackDraf)
/*
 * Prosedur untuk mengubah draf
 * I.S. stackDraf terdefinisi dan tidak kosong
 * F.S. 3 kemungkinan:
 *  1. Draf dihapus
 *  2. Draf disimpan
 *  3. Draf diTERBIT
 */
{
  // Masukan pesan Draf
  printf("Masukkan draf yang baru:\n");
  // Masukan
  MASUKAN drafMasukan;
  baca(&drafMasukan);
  // Sre
  char *drafStr = MASUKANToStr(drafMasukan);
  printf("\n");

  // Validasi masukan Draf
  if (isAllSpace(drafMasukan))
  {
    printf("Draf tidak boleh hanya berisi spasi!\n");
    return;
  }

  // Ubah draf yang baru
  // Dapatkan top
  Draf *topDraf = &(InfoTop(*stackDraf));

  printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
  // Masukan
  MASUKAN pilihan;
  baca(&pilihan);
  // Str
  char *pilihanStr = MASUKANToStr(pilihan);
  printf("\n");

  // Validasi pilihan
  if (isSame(pilihan, "SIMPAN"))
  {
    // Update draf
    strcpy(TEXT(*topDraf), drafStr);

    // Ubah waktu
    DATETIME waktuDraf;
    GetCurrentLocalDATETIME(&waktuDraf);
    DATETIME(*topDraf) = waktuDraf;

    // Pesan
    printf("Draf telah berhasil disimpan!\n\n");
  }
  else if (isSame(pilihan, "HAPUS"))
  {
    // Hapus
    printf("Draf telah berhasil dihapus!\n\n");
  }
  else if (isSame(pilihan, "TERBIT"))
  {
    // Ubah text
    strcpy(TEXT(*topDraf), drafStr);

    // Ubah waktu
    DATETIME waktuDraf;
    GetCurrentLocalDATETIME(&waktuDraf);
    DATETIME(*topDraf) = waktuDraf;

    // TERBIT
    TerbitDraf(stackDraf);
  }
  else
  {
    printf("Pilihan tidak valid!\n\n");
  }
}