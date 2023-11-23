#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include "simpan.h"
#include "../masukan/masukan.h"
#include "../tree/tree.h"
#include "../listdinkicauan/listdinkicauan.h"         // global variable listKicauan
#include "../modifiedliststatik/modifiedliststatik.h" // global variable listPengguna
#include "../pengguna/pengguna.h"                     // global variable currentUser
#include "../masukan/masukanFile.h"
#include "../masukan/masukanint.h"
#include "../teman/teman.h"
#include "../Utas/utas.h"
#include "../listdinUtas/listdinForUtas.h"
#include "../listlinierUtas/listlinierForUtas.h"

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
    mkdir(folderDir);

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
  SimpanPengguna(folderDir);
  // SimpanKicauan(folderDir);
  // SimpanBalasan(folderDir);
  // SimpanDraf();
  // SimpanUtas();

  // Cetak pesan berhasil
  printf("Penyimpanan berhasil dilakukan.\n");
  printf("\n");
}

// menyimpan pengguna
void SimpanPengguna(char *folderDir)
{
  /* Get full directory */
  char *fileDir = concatStr(folderDir, "/pengguna.config");
  FILE *fptr;

  // Open file
  fptr = fopen(fileDir, "w");
  int countPengguna = listLength(listUser);
  fprintf(fptr, "%d", countPengguna);

  int i;
  // Iterate each user
  for (i = 0; i < countPengguna; i++)
  {
    User pengguna;
    pengguna = listUser.contents[i];

    // Nama
    char *nama;
    nama = pengguna.username;
    fprintf(fptr, "\n%s", nama);

    // Password
    char *pw;
    pw = pengguna.password;
    fprintf(fptr, "\n%s", pw);

    // Bio
    char *bio;
    bio = pengguna.bio;
    fprintf(fptr, "\n%s", bio);

    // Hp
    char *noHp;
    noHp = pengguna.phone_num.TabMASUKAN;
    fprintf(fptr, "\n%s", noHp);

    // Weton
    char *weton = pengguna.weton;
    fprintf(fptr, "\n%s", weton);

    // Jenis akun
    boolean jenisAkun;
    jenisAkun = pengguna.isPrivate;
    if (jenisAkun)
    {
      fprintf(fptr, "\n%s", "Privat");
    }
    else
    {
      fprintf(fptr, "\n%s", "Publik");
    }

    // Matriks Profile Picture
    // Pre-Newline
    fprintf(fptr, "\n");
    // Iterate row
    int a;
    for (a = 0; a < 5; a++)
    {
      // Iterate columns
      int b;
      for (b = 0; b < 10; b++)
      {
        if (b == 9)
        {
          // Print
          fprintf(fptr, "%c", ELMT_MTX(PROFILE(listUser, i), a, b));

          // Print newline if end column and not last row
          if (a != 4)
          {
            fprintf(fptr, "\n");
          }
        }
        else
        {
          // If not last column, print space
          fprintf(fptr, "%c ", ELMT_MTX(PROFILE(listUser, i), a, b));
        }
      }
    }
  }

  // Matriks Pertemanan
  // Pre-Newline
  fprintf(fptr, "\n");
  // Iterate matriks pertemanan
  // Iterate row
  int c;
  for (c = 0; c < listLength(listUser); c++)
  {
    // Iterate col
    int d;
    for (d = 0; d < listLength(listUser); d++)
    {
      // Already friends
      if (ELMT_MTX(RelasiPertemanan, c, d) == 1 && ELMT_MTX(RelasiPertemanan, d, c) == 1)
      {
        // Last column
        if (d == listLength(listUser) - 1)
        {
          fprintf(fptr, "%d", 1);

          // If not last row & not last column
          if (c != listLength(listUser) - 1)
          {
            fprintf(fptr, "\n");
          }
        }
        else
        {
          fprintf(fptr, "%d ", 1);
        }
      }
      // Not friends or on friend request
      else
      {
        // Last column
        if (d == listLength(listUser) - 1)
        {
          fprintf(fptr, "%d", 0);

          // If not last row & not last column
          if (c != listLength(listUser) - 1)
          {
            fprintf(fptr, "\n");
          }
        }
        else
        {
          fprintf(fptr, "%d ", 0);
        }
      }
    }
  }

  // Matriks request pertemanan
  int countReqPertemanan = 0;
  int e;
  for (e = 0; e < listLength(listUser); e++)
  {
    int f;
    for (f = e; f < listLength(listUser); f++)
    {
      if (ELMT_MTX(RelasiPertemanan, e, f) == 1 && ELMT_MTX(RelasiPertemanan, f, e) == 0)
      {
        countReqPertemanan += 1;
      }
      else if (ELMT_MTX(RelasiPertemanan, e, f) == 0 && ELMT_MTX(RelasiPertemanan, f, e) == 1)
      {
        countReqPertemanan += 1;
      }
    }
  }

  // Hitung jumlah pertemanan
  fprintf(fptr, "\n%d", countReqPertemanan);

  // Pre new line
  fprintf(fptr, "\n");
  // Matriks pertemanan
  int m;
  for (m = 0; m < listLength(listUser); m++)
  {
    int n;
    for (n = 0; n < listLength(listUser); n++)
    {
      if (ELMT_MTX(RelasiPertemanan, m, n) == 1 && ELMT_MTX(RelasiPertemanan, n, m) == 0)
      {
        int pop;
        pop = 0;
        int o;
        for (o = 0; o < listLength(listUser); o++)
        {
          if (o != m)
          {
            if (ELMT_MTX(RelasiPertemanan, m, o) == 1 && ELMT_MTX(RelasiPertemanan, o, m) == 1)
            {
              pop += 1;
            }
          }
        }
        fprintf(fptr, "%d %d %d\n", m, n, pop);
      }
      else if (ELMT_MTX(RelasiPertemanan, m, n) == 0 && ELMT_MTX(RelasiPertemanan, n, m) == 1)
      {
        int pop;
        pop = 0;
        int o;
        for (o = 0; o < listLength(listUser); o++)
        {
          if (o != n && o != m)
          {
            if (ELMT_MTX(RelasiPertemanan, n, o) == 1 && ELMT_MTX(RelasiPertemanan, o, n) == 1 && ELMT_MTX(RelasiPertemanan, m, o) == 1 && ELMT_MTX(RelasiPertemanan, o, m) == 1)
            {
              // pop += 1;
            }
          }
        }
        // fprintf(fptr, "%d %d %d\n", n, m, pop);
      }
    }
  }

  // Close file
  fclose(fptr);
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

void saveDraf(char *folderDir)
{
  char *fileDir = concatStr(folderDir, "/draf.config");

  FILE *fptr;

  fptr = fopen(fileDir, "w");

  Stack s;
  int i;
  int n = 0;
  for (i = 0; i < listLength(listUser); i++)
  {
    s = DRAF(listUser, i);
    if (!IsEmptyStack(s))
    {
      n++;
    }
  }
  fprintf(fptr, "%d", n);

  int j;
  for (j = 0; j < listLength(listUser); j++)
  {
    s = DRAF(listUser, j);
    if (!IsEmptyStack(s))
    {
      Stack temp;
      temp = s;
      int count = 0;
      while (!IsEmptyStack(temp))
      {
        infotype elmt;
        PopStack(&temp, &elmt);
        count++;
      }
      char *nama;
      nama = USERNAME(listUser, j);
      fprintf(fptr, "\n%s %d", nama, count);
      Stack temp2;
      temp2 = s;
      while (!IsEmptyStack(temp2))
      {
        infotype elmt;
        PopStack(&temp2, &elmt);
        fprintf(fptr, "\n%s", elmt.text);
        DATETIME DT = elmt.datetime;
        fprintf(fptr, "\n%d/%d/%d %02d:%02d:%02d", Day(DT), Month(DT), Year(DT), Hour(Time(DT)), Minute(Time(DT)), Second(Time(DT)));
      }
    }
  }
}

void SimpanUtas(char *folderDir)
{
  char *fileDir = concatStr(folderDir, "/utas.config");

  FILE *fptr;

  fptr = fopen(fileDir, "w");

  int countUtas;
  countUtas = listUtasLength(listUtas);
  fprintf(fptr, "%d", countUtas);
  int i;
  for (i = 0; i < countUtas; i++)
  {
    UTAS utasUtama;
    utasUtama = listUtas.buffer[i];

    fprintf(fptr, "\n%d", ID(*(utasUtama.KicauanUtama)));

    AddressUtas p;
    p = KicauanSambungan(utasUtama);
    int x;
    x = lengthThreads(p);
    fprintf(fptr, "\n%d", x);

    while (p != NULL)
    {
      char *text = p->textThread;
      fprintf(fptr, "\n%s", text);

      char *username = (AUTHOR(*(utasUtama.KicauanUtama)))->username;
      fprintf(fptr, "\n%s", username);

      DATETIME DT = p->timeThread;
      fprintf(fptr, "\n%d/%d/%d %02d:%02d:%02d", Day(DT), Month(DT), Year(DT), Hour(Time(DT)), Minute(Time(DT)), Second(Time(DT)));
      p = p->nextThread;
    }
  }
}