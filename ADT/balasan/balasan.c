#include <stdio.h>
#include "../masukan/masukan.h"
#include "../balasan/balasan.h"
#include "../listdinkicauan/listdinkicauan.h"
#include "../modifiedliststatik/modifiedliststatik.h"

/* Buat balasan baru */
void CreateBalasan(Balasan *b, int id, char *text, User *author, DATETIME datetime)
/* I.S. balasan sembarang, id, text, author, datetime terdefinisi */
/* F.S. terbentuk balasan dengan sesuai parameter input */
{
  // Update ID
  ID(*b) = id;

  // Update author (use pointer)
  AUTHOR(*b) = author;

  // Update date time
  DATETIME(*b) = datetime;

  // Update text
  strcpy(TEXT(*b), text);
}

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
  TreeKicauan kicauan = ELMT_LDK(listKicauan, idKicau);
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
      MASUKAN balasanMasukan;
      baca(&balasanMasukan);
      char *balasanStr = "";
      MASUKANToStr(balasanMasukan, balasanStr);
      printf("\n");

      // Dapatkan node balasan paling terakhir
      AddressBalasan latestBalasan = getLatestBalasan(kicauan);
      int nextId = ID(InfoBalasan(latestBalasan)) + 1;

      // Dapatkan waktu sekarang
      DATETIME datetime;
      GetCurrentLocalDATETIME(&datetime);

      // Buat balasan baru
      Balasan balasan;
      CreateBalasan(&balasan, nextId, balasanStr, currentUser, datetime);

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
  MASUKAN balasanMasukan;
  baca(&balasanMasukan);

  char *balasanStr = "";
  MASUKANToStr(balasanMasukan, balasanStr);
  printf("\n");

  // Dapatkan node balasan paling terakhir
  AddressBalasan latestBalasan = getLatestBalasan(kicauan);
  int nextId = ID(InfoBalasan(latestBalasan)) + 1;

  // Dapatkan waktu sekarang
  DATETIME datetime;
  GetCurrentLocalDATETIME(&datetime);

  // Buat balasan baru
  Balasan infoBalasan;
  CreateBalasan(&infoBalasan, nextId, balasanStr, currentUser, datetime);

  // Balas
  balasBalasan(balasan, infoBalasan);
}

// Mencetak kedalaman suatu baris dalam balasan
void CetakKedalaman(int depth)
/* I.S. depth valid */
/* F.S. tercetak spasi kedalaman depth */
{
  int i;
  for (i = 0; i < depth; i++)
  {
    printf("   ");
  }
}

/* Prosedur mencetak satu detail balasan */
void CetakDetailBalasan(Balasan b, boolean isPrivat, int depth)
/* I.S. Sembarang */
/* F.S. bila privat, akan tercetak privat beserta kedalamannya
        bila bisa dilihat, akan tercetak detail balasan (nama, text, dll tercetak) beserta dengan spasi kedalaman */
{
  if (!isPrivat)
  {
    CetakKedalaman(depth);
    printf("| ID = %d\n", ID(b));
    printf("\n");
    CetakKedalaman(depth);
    printf("| Author = %s\n", AUTHOR(b)->username);
    printf("\n");
    CetakKedalaman(depth);
    TulisDATETIME(DATETIME(b));
    printf("\n");
    CetakKedalaman(depth);
    printf("| Text = %s\n", TEXT(b));
    printf("\n");
  }
  else
  {
    CetakKedalaman(depth);
    printf("| PRIVAT\n");
    printf("\n");
    CetakKedalaman(depth);
    printf("| PRIVAT\n");
    printf("\n");
    CetakKedalaman(depth);
    printf("| PRIVAT\n");
    printf("\n");
    CetakKedalaman(depth);
    printf("| PRIVAT\n");
    printf("\n");
  }
}

/* Prosedur Mencetak Balasan */
void TampilkanBalasan(int idKicau)
/* I.S. Sembarang */
/* F.S. Menampilkan seluruh tree balasan dari sebuah idKicau dengan ketentuan
  Bila idKicau tidak valid, output pesan kicauan tidak ada
  Bila Akun yang membuat kicauan privat dan user belum berteman, output pesan kicauan privat
  Bila belum terdapat balasan pada kicauan, output pesan belum terdapat balasan
  Bila pada balasan ada balasan yang privat dan belum berteman, tampilkan balasan PRIVAT */
{
  // Validasi sudah masuk atau belum
  // TODO: CONNECT WITH GLOBAL VAR CURRENT USER
  boolean isUserLoggedIn = true;
  if (!isUserLoggedIn)
  {
    printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    return;
  }

  // Kasus kicauan tidak ada
  if (!isKicauanExist(listKicauan, idKicau))
  {
    printf("Tidak terdapat kicauan dengan id tersebut!\n");
    return;
  }

  // Get kicauan
  TreeKicauan kicauan = ELMT_LDK(listKicauan, idKicau);

  // Kasus kicauan ada namun tidak ada balasan
  if (!isBalasanExist(kicauan))
  {
    printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!\n");
  }

  // Kasus pemilik kicauan akun privat
  // TODO: CONNECT WITH GLOBAL VAR CURRENT USER
  boolean isCurrentUserCanSee = true;
  if (!isCurrentUserCanSee)
  {
    printf("Wah, kicauan tersebut dibuat oleh pengguna dengan akun privat!\n");
    return;
  }

  // Cetak balasan-balasan dalam kicauan
  AddressBalasan firstChildBalasan = FirstLeftChildBalasan(kicauan);
  TampilkanBalasanRekursif(firstChildBalasan, 0);
}
void TampilkanBalasanRekursif(AddressBalasan nodeBalasan, int depth)
{
  // Kasus kosong
  if (nodeBalasan == NULL)
  {
    return;
  }

  // Kasus tidak kosong
  // Cetak node sekarang
  boolean isBalasanBisaDilihatCurrentUser = true;
  CetakDetailBalasan(InfoBalasan(nodeBalasan), isBalasanBisaDilihatCurrentUser, depth);

  // Selesaikan leftchild dulu, baru right child
  AddressBalasan leftChild = LeftChildBalasan(nodeBalasan);
  AddressBalasan rightSibling = RightSiblingBalasan(nodeBalasan);

  // Cetak left child
  TampilkanBalasanRekursif(leftChild, depth + 1);

  // Cetak right sibling
  TampilkanBalasanRekursif(rightSibling, depth);
}

/* Prosedur Menghapus Balasan */
void HapusBalasan(int idKicau, int idBalasan)
/* I.S. Sembarang */
/* F.S. Bila ditemukan balasan dengan idBalasan pada kicauan dengan idKicau maka balasan terhapus
  Bila tidak ditemukan, output pesan balasan tidak ditemukan
  Bila ditemukan dan bukan miliknya output pesan error */
{
  // Validasi sudah masuk atau belum
  // TODO: CONNECT WITH GLOBAL VAR CURRENT USER
  boolean isUserLoggedIn = true;
  if (!isUserLoggedIn)
  {
    printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    return;
  }

  // Kicauan tidak ditemukan
  if (!isKicauanExist(listKicauan, idKicau))
  {
    printf("Balasan tidak ditemukan!\n");
    return;
  }

  // Kicauan ditemukan namun balasan tidak ditemukan
  TreeKicauan kicauan = ELMT_LDK(listKicauan, idKicau);
  AddressBalasan balasan = getBalasan(kicauan, idBalasan);
  if (balasan == NULL)
  {
    printf("Balasan tidak ditemukan!\n");
    return;
  }

  // Kasus balasan ditemukan namun bukan punyanya
  // TO DO: CONNECT DGN ADT CEK PENGGUNA
  boolean isPunyaUser = true;
  if (!isPunyaUser)
  {
    printf("Hei, ini balasan punya siapa? Jangan dihapus ya!\n");
    return;
  }

  // Kasus balasan ditemukan dan punyanya
  hapusBalasan(kicauan, balasan);
}