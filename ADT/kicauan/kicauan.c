#include <stdio.h>
#include "../masukan/masukan.h"
#include "../kicauan/kicauan.h"
#include "../listdinkicauan/listdinkicauan.h" // Global variable listDinKicauan

/* Konstruktor kicauan */
void CreateKicauan(Kicauan *k, int id, char *text, char author, DATETIME datetime)
/* I.S. kicauan sembarang, id, text, author, datetime terdefinisi */
/* Kicauan terdefinisi */
/* F.S. kicauan terdefinisi sesuai parameter */
{
  ID(*k) = id;
  LIKE(*k) = 0;
  AUTHOR(*k) = author;
  DATETIME(*k) = datetime;
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
  // Validasi sudah masuk atau belum
  // TODO: CONNECT WITH GLOBAL VAR CURRENT USER
  boolean isUserLoggedIn = true;
  if (!isUserLoggedIn)
  {
    printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    return;
  }

  // ID Kicauan paling terakhir
  int idKicauanTerakhir = listLength(listKicauan);
  int idKicauanBaru = idKicauanTerakhir + 1;

  // Masukan pesan kicauan
  printf("Masukkan kicauan:\n");
  printf(">> ");
  MASUKAN pesanKicauan;
  baca(&pesanKicauan);

  // Validasi masukan kicauan
  if (isAllSpace(pesanKicauan))
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
  // CreateKicauan(&kicauanBaru, idKicauanBaru, pesanKicauan, currentUser, waktuKicauan);
  TreeKicauan nodeKicauan = newNodeKicauan(kicauanBaru);
  insertLast(&listKicauan, nodeKicauan);

  // Cetak pesan
  printf("Selamat! kicauan telah diterbitkan!\n");
  printf("Detil kicauan:\n");
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
void TampilkanKicauan()
/* I.S. Sembarang */
/* F.S. Menampilkan seluruh kicauan buatan diri sendiri dan orang2 yang berada di list teman terurut berdasarkan waktu */
{
  // Validasi sudah masuk atau belum
  // TODO: CONNECT WITH GLOBAL VAR CURRENT USER
  boolean isUserLoggedIn = true;
  if (!isUserLoggedIn)
  {
    printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    return;
  }

  // Buat list baru yang telah di sortir berdasarkan date time.
  ListDinKicauan sortedKicauan = sortKicauanByDateTime(listKicauan, true);

  // TO DO: SAMBUNGKAN DENGAN LOGIC CURRENT USER & TEMAN USER
  // Cari kicauan yang dibuat oleh current user atau teman current user
  IdxType i;
  for (i = getFirstIdx(sortedKicauan); i <= getLastIdx(sortedKicauan); i++)
  {
    boolean isCurrentUserOrFriend = true;
    if (isCurrentUserOrFriend)
    {
      printDetailKicauan(InfoKicauan(ELMT(sortedKicauan, i)));
    }
  }
}

/* Prosedur like kicauan */
void SukaKicauan(int idKicau)
/* I.S. Sembarang */
/* F.S. Bila idKicau valid, maka jumlah like kicauan dengan id idKicau bertambah satu (update global var list kicauan)
  Bila idKicau tidak valid, maka keluarkan pesan kicauan tidak ditemukan */
{
  // Validasi sudah masuk atau belum
  // TODO: CONNECT WITH GLOBAL VAR CURRENT USER
  boolean isUserLoggedIn = true;
  if (!isUserLoggedIn)
  {
    printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    return;
  }

  // Kasus idKicau tidak valid
  // Kicauan tidak bisa di delete sehingga idKicau yang valid adalah >= 1 <= listLength(listKicauan)
  if (!isKicauanExist(listKicauan, idKicau))
  {
    printf("Tidak ditemukan kicauan dengan ID = %d!\n", idKicau);
    return;
  }

  // Kasus kicauan dimiliki akun privat dan user belum berteman
  // TODO: CONNECT DENGAN LOGIC CURRENT USE & APAKAH USER SUDAH BERTEMAN
  boolean isCurrentUserCanSee = true;
  if (!isCurrentUserCanSee)
  {
    printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n");
    return;
  }

  // Kasus idKicauValid dan kicauan dapat dilihat
  TreeKicauan nodeKicauan = ELMT(listKicauan, idKicau);
  LIKE(InfoKicauan(nodeKicauan)) += 1;

  // Cetak pesan
  printf("Selamat! kicauan telah disukai!\n");
  printf("Detil kicauan:\n");
  printDetailKicauan(InfoKicauan(nodeKicauan));
}

/* Prosedur Ubah Kicauan */
/* I.S. Sembarang */
void UbahKicauan(int idKicau)
/* F.S. Bila idKicau valid, maka kicauan dengan suatu id idKicau diperbarui (update global var list kicauan)
  Bila idKicau tidak valid, maka keluarkan pesan kicauan tidak ditemukan */
{
  // Validasi sudah masuk atau belum
  // TODO: CONNECT WITH GLOBAL VAR CURRENT USER
  boolean isUserLoggedIn = true;
  if (!isUserLoggedIn)
  {
    printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    return;
  }

  // Bila idKicau tidak valid
  // Kicauan tidak bisa di delete sehingga idKicau yang valid adalah >= 1 <= listLength(listKicauan)
  if (!isKicauanExist(listKicauan, idKicau))
  {
    printf("Tidak ditemukan kicauan dengan ID = %d!\n", idKicau);
    return;
  }

  // Kasus kicauan bukan milik pengguna
  // TODO: CONNECT DENGAN LOGIC CURRENT USER
  boolean isKicauanMilikPengguna = true;
  if (!isKicauanMilikPengguna)
  {
    printf("Kicauan dengan ID = %d bukan milikmu!\n", idKicau);
    return;
  }

  // Kasus idKicau valid dan kicauan milik pengguna
  // Masukan pesan kicauan
  printf("Masukkan kicauan:\n");
  MASUKAN pesanKicauan;
  baca(&pesanKicauan);
  printf("\n");

  // Validasi masukan kicauan
  if (isAllSpace(pesanKicauan))
  {
    printf("Kicauan tidak boleh hanya berisi spasi!\n");
    return;
  }

  // Masukan valid, update kicauan
  TreeKicauan nodeKicauan = ELMT(listKicauan, idKicau);

  // Update text
  int i;
  for (i = 0; i < 280; i++)
  {
    TEXT(InfoKicauan(nodeKicauan))
    [i] = pesanKicauan.TabMASUKAN[i];
  }

  // Tampilkan pesan
  printf("Selamat! kicauan telah diterbitkan!\n");
  printf("Detil kicauan:\n");
  printDetailKicauan(InfoKicauan(nodeKicauan));
}