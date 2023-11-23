#include <stdio.h>
#include "../masukan/masukan.h"
#include "../kicauan/kicauan.h"
#include "../listdinkicauan/listdinkicauan.h" // Global variable listDinKicauan
#include "../pengguna/pengguna.h"             // Global variable currentUser
#include "../teman/teman.h"

/* Konstruktor kicauan */
void CreateKicauan(Kicauan *k, int id, char *text, int like, User *author, DATETIME datetime)
/* I.S. kicauan sembarang, id, text, author, datetime terdefinisi */
/* Kicauan terdefinisi */
/* F.S. kicauan terdefinisi sesuai parameter */
{
  // ID
  ID(*k) = id;

  // Like
  LIKE(*k) = like;

  // Author
  AUTHOR(*k) = author;

  // Datetime
  DATETIME(*k) = datetime;

  // Text
  strcpy(TEXT(*k), text);
}

/* Prosedur pemanggilan pembuatan Kicau (bersama validasi2nya) */
void BuatKicauan()
/* I.S. User sudah masuk, tidak terbentuk kicauan */
/* F.S. Bila data yang diinput valid, maka akan terbentuk kicauan dengan id, teks, like, author, datetime sesuai input (ditambahkan ke global var list kicauan)
   Bila data yang diinput tidak valid atau melawan constraint tertentu, maka output pesan kesalahan */
{
  // VALIDASI SUDAH MASUK ATAU BELUM
  if (!isUserLoggedIn())
  {
    printf("\n");
    printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    printf("\n");
    return;
  }

  // ID Kicauan paling terakhir
  int idKicauanBaru = listDinKicauanLength(listKicauan) + 1;

  // Pesan kicauan
  printf("\n");
  printf("Masukkan kicauan:\n");
  // Masukan
  MASUKAN kicauanMasukan;
  baca(&kicauanMasukan);
  // String
  char *kicauanStr = MASUKANToStr(kicauanMasukan);

  // VALIDASI MASUKAN USER
  if (isAllSpace(kicauanMasukan))
  {
    printf("\n");
    printf("Kicauan tidak boleh hanya berisi spasi!\n");
    printf("\n");
    return;
  }

  // Dapatkan waktu dari library time.h
  DATETIME waktuKicauan;
  GetCurrentLocalDATETIME(&waktuKicauan);

  // Buat kicauan baru
  Kicauan kicauanBaru;

  // Note: pakai global variable current user untuk author
  CreateKicauan(&kicauanBaru, idKicauanBaru, kicauanStr, 0, currentUser, waktuKicauan);
  TreeKicauan nodeKicauan = newNodeKicauan(kicauanBaru);
  insertLastListDinKicauan(&listKicauan, nodeKicauan);

  // Cetak pesan
  printf("\n");
  printf("Selamat! kicauan telah diterbitkan!\n");
  printf("Detil kicauan:\n");
  printDetailKicauan(kicauanBaru);
  printf("\n");
}

/* Prosedur Menampilkan Detail Kicauan */
void printDetailKicauan(Kicauan k)
/* I.S. Sembarang */
/* F.S. Mencetak detail sebuah kicauan */
{
  // ID
  printf("| ID = %d\n", ID(k));

  // Author
  printf("| %s\n", AUTHOR(k)->username);

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
  // VALIDASI SUDAH MASUK ATAU BELUM
  if (!isUserLoggedIn())
  {
    printf("\n");
    printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    printf("\n");
    return;
  }

  // Buat list baru yang telah di sortir berdasarkan date time.
  ListDinKicauan sortedKicauan = sortKicauanByDateTime(listKicauan, true);

  // Cari kicauan yang dibuat oleh current user atau teman current user
  printf("\n");
  IdxType i;
  for (i = getFirstIdxListDinKicauan(sortedKicauan); i <= getLastIdxListDinKicauan(sortedKicauan); i++)
  {
    // Get kicauan
    TreeKicauan kicauan = ELMT_LDK(sortedKicauan, i);
    User *author = AUTHOR(InfoKicauan(kicauan));
    boolean isFriends = areFriendsEachOthers(*currentUser, *author);
    boolean isCurrentUser = currentUser == author;

    // Jika kicauan dibuat oleh current user atau teman current user, print detail kicauan
    if (isFriends || isCurrentUser)
    {
      printDetailKicauan(InfoKicauan(kicauan));
      printf("\n");
    }
  }
}

/* Prosedur like kicauan */
void SukaKicauan(int idKicau)
/* I.S. Sembarang */
/* F.S. Bila idKicau valid, maka jumlah like kicauan dengan id idKicau bertambah satu (update global var list kicauan)
  Bila idKicau tidak valid, maka keluarkan pesan kicauan tidak ditemukan */
{
  // VALIDASI SUDAH MASUK ATAU BELUM
  if (!isUserLoggedIn())
  {
    printf("\n");
    printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    printf("\n");
    return;
  }

  // KASUS ID KICAU TIDAK VALID (TIDAK ADA)
  // Kicauan tidak bisa di delete sehingga idKicau yang valid adalah >= 1 <= listLength(listKicauan)
  if (!isKicauanExist(idKicau))
  {
    printf("\n");
    printf("Tidak ditemukan kicauan dengan ID = %d!\n", idKicau);
    printf("\n");
    return;
  }

  int idxKicau = idKicau - 1;
  TreeKicauan kicauan = ELMT_LDK(listKicauan, idxKicau);

  // KASUS KICAUAN DIMILIKI AKUN PRIVAT DAN BELUM BERTEMAN
  User *author = AUTHOR(InfoKicauan(kicauan));
  boolean isPrivate = isUserPrivate(*author);
  boolean isFriend = areFriendsEachOthers(*currentUser, *author);

  if (isPrivate && !isFriend)
  {
    printf("\n");
    printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n");
    printf("\n");
    return;
  }

  // KASUS IDKICAU VALID DAN BISA DILIHAT
  LIKE(InfoKicauan(kicauan)) += 1;

  // Cetak pesan
  printf("\n");
  printf("Selamat! kicauan telah disukai!\n");
  printf("Detil kicauan:\n");
  printDetailKicauan(InfoKicauan(kicauan));
  printf("\n");
}

/* Prosedur Ubah Kicauan */
/* I.S. Sembarang */
void UbahKicauan(int idKicau)
/* F.S. Bila idKicau valid, maka kicauan dengan suatu id idKicau diperbarui (update global var list kicauan)
  Bila idKicau tidak valid, maka keluarkan pesan kicauan tidak ditemukan */
{
  // VALIDASI SUDAH MASUK ATAU BELUM
  if (!isUserLoggedIn())
  {
    printf("\n");
    printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    printf("\n");
    return;
  }

  // KASUS ID KICAU TIDAK VALID (TIDAK ADA)
  // Kicauan tidak bisa di delete sehingga idKicau yang valid adalah >= 1 <= listLength(listKicauan)
  if (!isKicauanExist(idKicau))
  {
    printf("\n");
    printf("Tidak ditemukan kicauan dengan ID = %d!\n", idKicau);
    printf("\n");
    return;
  }

  // Dapatkan kicauan
  int idxKicau = idKicau - 1;
  TreeKicauan nodeKicauan = ELMT_LDK(listKicauan, idxKicau);

  // KASUS KICAUAN BUKAN MILIK CURRENT LOGGED IN USER
  if (currentUser != AUTHOR(InfoKicauan(nodeKicauan)))
  {
    printf("\n");
    printf("Kicauan dengan ID = %d bukan milikmu!\n", idKicau);
    printf("\n");
    return;
  }

  // KASUS IDKICAU VALID DAN MILIK CURRENT USER
  // Masukan pesan kicauan
  printf("\n");
  printf("Masukkan kicauan:\n");
  // Masukan
  MASUKAN kicauanMasukan;
  baca(&kicauanMasukan);
  // String
  char *kicauanStr = MASUKANToStr(kicauanMasukan);

  // VALIDASI MASUKAN
  if (isAllSpace(kicauanMasukan))
  {
    printf("\n");
    printf("Kicauan tidak boleh hanya berisi spasi!\n");
    printf("\n");
    return;
  }

  // Masukan valid, update kicauan
  // Update text
  strcpy(TEXT(InfoKicauan(nodeKicauan)), kicauanStr);

  // Tampilkan pesan
  printf("\n");
  printf("Selamat! kicauan telah diterbitkan!\n");
  printf("Detil kicauan:\n");
  printDetailKicauan(InfoKicauan(nodeKicauan));
  printf("\n");
}