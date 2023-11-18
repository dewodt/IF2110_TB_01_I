#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include "simpan.h"
#include "../masukan/masukan.h"
#include "../listdinkicauan/listdinkicauan.h" // global variable listKicauan
// #include "../modifiedliststatik/modifiedliststatik.h" // global variable listPengguna

/* Prosedur untuk menyimpan seluruh data program dalam folder config/foo */
void Simpan()
/* I.S. Sembarang */
/* F.S. Data program tersimpan dalam folder config/foo */
{
  // Input nama folder penyimpanan
  printf("\n");
  printf("Masukkan nama folder penyimpanan\n");
  // Masukan
  MASUKAN folderMasukan;
  baca(&folderMasukan);
  // String
  char *folderStr = MASUKANToStr(folderMasukan);
  printf("\n");

  // Get config directory
  char *configDir = concatStr("config/", folderStr);

  // Kasus belum ada directory, maka buat directorynya
  struct stat st = {0};
  if (stat(configDir, &st) != 0 || !S_ISDIR(st.st_mode))
  {
    // Cetak pesan
    printf("Belum terdapat %s. Akan dilakukan pembuatan %s terlebih dahulu.\n", folderStr, folderStr);
    printf("\n");
    printf("Mohon tunggu...\n");
    printf("1...\n");
    printf("2...\n");
    printf("3...\n");
    printf("\n");

    // Make Directory
    // 2ND ARGUMENT WAJIB 0700 DI LINUX / WSL.
    mkdir(configDir, 0700);

    // Cetak pesan berhasil
    printf("%s sudah berhasil dibuat.\n", folderStr);
    printf("\n");
  }

  // Simpan file pengguna
  printf("Anda akan melakukan penyimpanan di %s.\n", folderStr);
  printf("\n");
  printf("Mohon tunggu...\n");
  printf("1...\n");
  printf("2...\n");
  printf("3...\n");
  printf("\n");

  // Simpan semua config
  // SimpanPengguna();
  // SimpanKicauan();
  // SimpanBalasan();
  // SimpanDraf();
  // SimpanUtas();

  // Cetak pesan berhasil
  printf("Penyimpanan berhasil dilakukan.\n");
  printf("\n");
}

void SimpanPengguna()
{
}

void SimpanKicauan()
{
}

void SimpanBalasan()
{
}

void SimpanDraf()
{
}

void SimpanUtas()
{
}

int main()
{
  Simpan();
}