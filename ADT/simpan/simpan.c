#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include "simpan.h"
#include "../masukan/masukan.h"
#include "../tree/tree.h"
#include "../listdinkicauan/listdinkicauan.h"         // global variable listKicauan
#include "../modifiedliststatik/modifiedliststatik.h" // global variable listPengguna
#include "../pengguna/pengguna.h"                     // global variable currentUser

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
  // ex: folder1
  char *folderStr = MASUKANToStr(folderMasukan);
  printf("\n");

  // Get config directory
  // ex: config/folder1
  char *folderDir = concatStr("config/", folderStr);

  // Kasus belum ada directory, maka buat directorynya
  struct stat st = {0};
  if (stat(folderDir, &st) != 0 || !S_ISDIR(st.st_mode))
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
    mkdir(folderDir, 0700);

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
  SimpanKicauan(folderDir);
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

void SimpanKicauan(char *folderDir)
{
  // Get full file directory with name
  // ex: config/folder1/kicauan.config
  char *fileDir = concatStr(folderDir, "/kicauan.config");

  // File
  FILE *fptr;

  // Open file
  fptr = fopen(fileDir, "w");

  // Get listKicauan length
  int countKicauan = listDinKicauanLength(listKicauan);
  fprintf(fptr, "%d", countKicauan);

  // Print listKicauan to file
  int i;
  for (i = 0; i < countKicauan; i++)
  {
    // Get kicauan
    Kicauan kicauan = InfoKicauan(ELMT_LDK(listKicauan, i));

    // Get kicauan id
    int id = ID(kicauan);
    fprintf(fptr, "\n%d", id);

    // Get kicauan text
    char *text = TEXT(kicauan);
    fprintf(fptr, "\n%s", text);

    // Get like counts
    int like = LIKE(kicauan);
    fprintf(fptr, "\n%d", like);

    // Get kicauan author username
    char *username = AUTHOR(kicauan)->username;
    fprintf(fptr, "\n%s", username);

    // Get kicauan tanggal
    DATETIME DT = DATETIME(kicauan);
    fprintf(fptr, "\n%d/%d/%d %02d:%02d:%02d", Day(DT), Month(DT), Year(DT), Hour(Time(DT)), Minute(Time(DT)), Second(Time(DT)));
  }

  // Close file
  fclose(fptr);
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