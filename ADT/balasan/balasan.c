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
  // VALIDASI USER SUDAH MASUK ATAU BELUM
  // TODO: CONNECT WITH GLOBAL VAR CURRENT USER
  boolean isUserLoggedIn = true;
  if (!isUserLoggedIn)
  {
    printf("\n");
    printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    printf("\n");
    return;
  }

  // VALIDASI ID KICAUAN ADA ATAU TIDAK
  // Kicauan tidak bisa di delete sehingga idKicau yang valid adalah >= 1 <= listLength(listKicauan)
  if (!isKicauanExist(idKicau))
  {
    printf("\n");
    printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
    printf("\n");
    return;
  }

  // Dapatkan kicauan
  int idxKicauan = idKicau - 1;
  TreeKicauan kicauan = ELMT_LDK(listKicauan, idxKicauan);

  if (idBalasan == -1)
  {
    // KASUS MEMBALAS KICAUAN
    // idKicau valid

    // VALIDASI AKUN PRIVAT DAN BELUM BERTEMAN
    // TO DO: CONNECT DGN ADT CEK TEMAN & CEK PRIVAT PENGGUNA
    boolean isCurrentUserCanSee = true;
    if (!isCurrentUserCanSee)
    {
      // Kasus tidak bisa membalas kicauan
      printf("\n");
      printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!\n");
      printf("\n");
      return;
    }

    // Kasus bisa membalas kicauan
    // Dapatkan input balasan
    printf("\n");
    printf("Masukkan balasan:\n");
    // Masukan
    MASUKAN balasanMasukan;
    baca(&balasanMasukan);
    // String
    char *balasanStr = MASUKANToStr(balasanMasukan);
    printf("\n");

    // Dapatkan id selanjutnya
    int nextId = getNewBalasanId(kicauan);
    // printf("nextId = %d\n", nextId);

    // Dapatkan waktu sekarang
    DATETIME datetime;
    GetCurrentLocalDATETIME(&datetime);

    // Buat balasan baru
    // TO DO: CONNECT KE GLOBAL VARIABLE CURRENT USER
    // ADT MASIH BERMASALAH, SET TO NULL DULU
    Balasan balasan;
    CreateBalasan(&balasan, nextId, balasanStr, NULL, datetime);

    // Balas
    balasKicauan(kicauan, balasan);
  }
  else
  {
    // KASUS MEMBALAS BALASAN
    // idKicau valid
    AddressBalasan balasan = getBalasan(kicauan, idBalasan);

    // VALIDASI ID BALASAN ADA ATAU TIDAK
    if (balasan == NULL)
    {
      printf("\n");
      printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
      printf("\n");
      return;
    }

    // VALIDASI AKUN PRIVAT DAN BELUM BERTEMAN
    boolean isCurrentUserCanSee = true;
    if (!isCurrentUserCanSee)
    {
      printf("\n");
      printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebu!\n");
      printf("\n");
      return;
    }

    // Kasus idKicau valid, idBalasan valid (membalas balasan)
    // Dapatkan input balasan
    printf("\n");
    printf("Masukkan balasan:\n");
    // Masukan
    MASUKAN balasanMasukan;
    baca(&balasanMasukan);
    // String
    char *balasanStr = MASUKANToStr(balasanMasukan);
    printf("\n");

    // Dapatkan node balasan paling terakhir
    int nextId = getNewBalasanId(kicauan);

    // Dapatkan waktu sekarang
    DATETIME datetime;
    GetCurrentLocalDATETIME(&datetime);

    // Buat balasan baru
    // TO DO: CONNECT KE GLOBAL VARIABLE CURRENT USER
    // ADT MASIH BERMASALAH, SET TO NULL DULU
    Balasan infoBalasan;
    CreateBalasan(&infoBalasan, nextId, balasanStr, NULL, datetime);

    // Balas
    balasBalasan(balasan, infoBalasan);
  }
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
    // Kasus bukan privat
    // ID
    CetakKedalaman(depth);
    printf("| ID = %d\n", ID(b));

    // Author
    CetakKedalaman(depth);
    printf("| %s\n", AUTHOR(b)->username);

    // DateTime
    CetakKedalaman(depth);
    printf("| ");
    TulisDATETIME(DATETIME(b));
    printf("\n");

    // Text
    CetakKedalaman(depth);
    printf("| %s\n", TEXT(b));
  }
  else
  {
    // Kasus privat
    // ID
    CetakKedalaman(depth);
    printf("| ID = %d\n", ID(b));

    // Author
    CetakKedalaman(depth);
    printf("| PRIVAT\n");

    // DateTime
    CetakKedalaman(depth);
    printf("| PRIVAT\n");

    // Text
    CetakKedalaman(depth);
    printf("| PRIVAT\n");
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
    printf("\n");
    printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    printf("\n");
    return;
  }

  // Kasus kicauan tidak ada
  if (!isKicauanExist(idKicau))
  {
    printf("\n");
    printf("Tidak terdapat kicauan dengan id tersebut!\n");
    printf("\n");
    return;
  }

  // Get kicauan
  int idxKicauan = idKicau - 1;
  TreeKicauan kicauan = ELMT_LDK(listKicauan, idxKicauan);

  // Kasus kicauan ada namun tidak ada balasan
  if (!isKicauanHasBalasan(kicauan))
  {
    printf("\n");
    printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!\n");
    printf("\n");
  }

  // Kasus pemilik kicauan akun privat
  // TODO: CONNECT WITH GLOBAL VAR CURRENT USER
  boolean isCurrentUserCanSee = true;
  if (!isCurrentUserCanSee)
  {
    printf("\n");
    printf("Wah, kicauan tersebut dibuat oleh pengguna dengan akun privat!\n");
    printf("\n");
    return;
  }

  // Kasus ada balasan (setidaknya satu) dan kicauan tidak privat
  // Cetak balasan-balasan dalam kicauan
  AddressBalasan firstChildBalasan = FirstLeftChildBalasan(kicauan);
  printf("\n");
  TampilkanBalasanRekursif(firstChildBalasan, 0);
}
void TampilkanBalasanRekursif(AddressBalasan nodeBalasan, int depth)
{
  // Kasus tidak kosong
  // Cetak node sekarang
  boolean isPrivat = false;
  CetakDetailBalasan(InfoBalasan(nodeBalasan), isPrivat, depth);
  printf("\n");

  // Selesaikan leftchild dulu, baru right child
  AddressBalasan leftChild = LeftChildBalasan(nodeBalasan);
  AddressBalasan rightSibling = RightSiblingBalasan(nodeBalasan);

  // Cetak left child
  if (leftChild != NULL)
  {
    TampilkanBalasanRekursif(leftChild, depth + 1);
  }

  // Cetak right sibling
  if (rightSibling != NULL)
  {
    TampilkanBalasanRekursif(rightSibling, depth);
  }
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
  if (!isKicauanExist(idKicau))
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