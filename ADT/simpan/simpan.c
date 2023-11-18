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
  SimpanBalasan(folderDir);
  // SimpanDraf();
  // SimpanUtas();

  // Cetak pesan berhasil
  printf("Penyimpanan berhasil dilakukan.\n");
  printf("\n");
}

void SimpanPengguna()
{
}

/* Prosedur untuk menyimpan data kicauan dalam folder config/foo */
void SimpanKicauan(char *folderDir)
/* I.S. Sembarang */
/* F.S. Data kicauan tersimpan dalam folder config/foo/kicauan */
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

/* Prosedur untuk menyimpan data balasan dalam folder config/foo */
void SimpanBalasan(char *folderDir)
/* I.S. Sembarang */
/* F.S. Data balasan tersimpan dalam folder config/foo/balasan */
{
  // Get full file directory with name
  // ex: config/folder1/kicauan.config
  char *fileDir = concatStr(folderDir, "/balasan.config");

  // File
  FILE *fptr;

  // Open file
  fptr = fopen(fileDir, "w");

  // Get kicauan count that has balasan
  int countKicauanHasBalasan = countKicauanWithBalasan(listKicauan);
  fprintf(fptr, "%d", countKicauanHasBalasan);

  // Iterate through listKicauan
  int i;
  for (i = getFirstIdxListDinKicauan(listKicauan); i <= getLastIdxListDinKicauan(listKicauan); i++)
  {
    // Get kicauan
    TreeKicauan kicauan = ELMT_LDK(listKicauan, i);

    // Check if kicauan has balasan
    if (!isKicauanHasBalasan(kicauan))
    {
      continue;
    }

    // Setidaknya punya satu balasan yang membalas kicauan

    // Get kicauan id
    int id = ID(InfoKicauan(kicauan));
    fprintf(fptr, "\n%d", id);

    // Get balasan count
    int countBalasanOfKicauan = countBalasan(kicauan);
    fprintf(fptr, "\n%d", countBalasanOfKicauan);

    // Iterate through balasan
    writeBalasanDetailFile(fptr, -1, FirstLeftChildBalasan(kicauan));
  }

  // Close file
  fclose(fptr);
}
/* Menuliskan balasan pada file ptr secara rekursif */
void writeBalasanDetailFile(FILE *ptr, int parentId, AddressBalasan nodeBalasan)
/* I.S. ptr file terdefinisi */
/* F.S. seluruh balasan tertulis pada file */
{
  // Base case
  if (nodeBalasan == NULL)
  {
    return;
  }

  // Get balasan id
  int currentId = ID(InfoBalasan(nodeBalasan));
  fprintf(ptr, "\n%d %d", parentId, currentId);

  // Get balasan text
  char *text = TEXT(InfoBalasan(nodeBalasan));
  fprintf(ptr, "\n%s", text);

  // Get balasan author username
  char *username = AUTHOR(InfoBalasan(nodeBalasan))->username;
  fprintf(ptr, "\n%s", username);

  // Get balasan tanggal
  DATETIME DT = DATETIME(InfoBalasan(nodeBalasan));
  fprintf(ptr, "\n%d/%d/%d %02d:%02d:%02d", Day(DT), Month(DT), Year(DT), Hour(Time(DT)), Minute(Time(DT)), Second(Time(DT)));

  // Iterate through right sibling balasan
  AddressBalasan rightSiblingBalasan = RightSiblingBalasan(nodeBalasan);
  writeBalasanDetailFile(ptr, parentId, rightSiblingBalasan);

  // Iterate through left child balasan
  AddressBalasan LeftChildBalasan = LeftChildBalasan(nodeBalasan);
  writeBalasanDetailFile(ptr, currentId, LeftChildBalasan);
}

void SimpanUtas()
{
}