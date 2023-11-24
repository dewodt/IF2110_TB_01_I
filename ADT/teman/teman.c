#include <stdio.h>
#include "../masukan/masukan.h"
#include "teman.h"
#include "../matrixteman/matrixteman.h"               // Global variable Matrix RelasiPertemanan
#include "../modifiedliststatik/modifiedliststatik.h" // Global variable ListStatik listPengguna
#include "../pengguna/pengguna.h"                     // Global variable User currentUser

IdxType searchIndexPengguna(User Pengguna)
/**
 * Fungsi untuk mengembalikan index Pengguna pada ListPengguna
 * return -1 jika tidak ditemukan
 */
{
  return searchIndexPenggunaByName(Pengguna.username);
}

IdxType searchIndexPenggunaByName(char *Username)
/**
 * Fungsi untuk mengembalikan index Username/Author pada ListPengguna
 */
{
  IdxType IdxPengguna = -1, i = 0;
  boolean found = false;
  // Harusnya compare string aman dari '\0', semoga ga ngebug TT
  while (i < listLength(listUser) && !found)
  {
    if (compareString(Username, USERNAME(listUser, i), stringLength(Username)) == 0)
    {
      found = true;
      IdxPengguna = i;
    }
    else
    {
      i++;
    }
  }
  return IdxPengguna;
}

boolean areFriendsEachOthers(User Pengguna1, User Pengguna2)
/**
 * Fungsi untuk cek apakah Pengguna1 berteman dengan Pengguna2
 * Mengembalikan true jika saling berteman, false jika tidak
 */
{
  return areFriendsByName(Pengguna1.username, Pengguna2.username);
}

boolean areFriendsByName(char *Username1, char *Username2)
/**
 * Fungsi untuk cek apakah Username/Author 1 berteman dengan Username/Author 2
 * Mengembalikan true jika saling berteman, false jika tidak
 */
{
  IdxType IdxPengguna1 = searchIndexPenggunaByName(Username1);
  IdxType IdxPengguna2 = searchIndexPenggunaByName(Username2);
  IdxType i = IdxPengguna1, j = IdxPengguna2;
  return (ELMT_MTXTEMAN(RelasiPertemanan, i, j) == 1 && ELMT_MTXTEMAN(RelasiPertemanan, j, i) == 1 && IdxPengguna1 != IdxPengguna2);
}

int getCountFriend(User user)
/* Menghitung jumlah teman yang dimiliki user */
/* Prekondisi: User valid */
{
  int count = 0;
  printf("%d\n", listLength(listUser));
  int i;
  for (i = 0; i < listLength(listUser); i++)
  {
    User tempUser = ELMT(listUser, i);
    if (areFriendsEachOthers(user, tempUser))
    {
      count++;
    }
  }

  return count;
}

void showFriendList()
/**
 * Prosedur perintah MASUKAN DAFTAR_TEMAN
 * User import global variable CurrentUser
 */
{
  // track semua dulu, kompleksitasnya tetep T(20) = O(1)
  // Kasus jika belum ada User login
  if (!isUserLoggedIn())
  { // import global variable || !*isLoggedIn
    printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    return;
  }

  // Kasus jika sudah login namun belum punya teman
  printf("belum cnt\n");
  printf("%p\n", currentUser);
  
  int countFriend = getCountFriend(*currentUser);
  printf("sudah cnt\n");
  if (countFriend == 0)
  {
    printf("%s belum mempunyai teman\n", currentUser->username);
    return;
  }

  // Kasus jika sudah login dan punya teman, print list teman

  printf("%s memiliki %d teman\n", currentUser->username, countFriend);
  printf("Daftar teman %s", currentUser->username);
  int i;
  for (i = 0; i < listLength(listUser); i++)
  {
    User tempUser = ELMT(listUser, i);
    if (areFriendsEachOthers(*currentUser, tempUser))
    {
      printf("| %s\n", tempUser.username);
    }
  }
}

void deleteFriend()
/**
 * Prosedur perintah MASUKAN HAPUS_TEMAN
 * User import global variable CurrentUser
 */

{
  // track semua dulu, kompleksitasnya tetep T(20) = O(1)
  // Kasus jika belum ada User login
  if (!isUserLoggedIn())
  { // import global variable || !*isLoggedIn
    printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    return;
  }

  MASUKAN usernameMasukan;
  printf("Masukkan nama pengguna:\n");
  baca(&usernameMasukan);

  char *usernameStr = MASUKANToStr(usernameMasukan);
  IdxType idxDelUser = searchIndexPenggunaByName(usernameStr);

  // Kasus user tidak ditemukan
  if (idxDelUser == -1)
  {
    // Kasus tidak ditemukan
    printf("Tidak ditemukan pengguna bernama %s.\n", usernameStr);
    return;
  }

  // Kasus user ditemukan
  // Cek apakah sudah berteman atau belum
  User delUser = ELMT(listUser, idxDelUser);
  if (!areFriendsEachOthers(*currentUser, delUser))
  {
    // Kasus belum berteman
    printf("%s bukan teman Anda.\n", usernameStr);
    return;
  }

  // Jika sudah berteman, hapus
  MASUKAN Yakin;
  printf("Apakah anda yakin ingin menghapus Bob dari daftar teman anda?(YA/TIDAK) ");
  baca(&Yakin);

  // Jika tidak mengetik "YA;" diasumsikan tidak ingin menghapus
  if (isSame(Yakin, "YA"))
  {
    int idxCurrentUser = searchIndexPengguna(*currentUser);
    ELMT_MTXTEMAN(RelasiPertemanan, idxCurrentUser, idxDelUser) = 0;
    ELMT_MTXTEMAN(RelasiPertemanan, idxDelUser, idxCurrentUser) = 0;
    printf("%s berhasil dihapus dari daftar teman Anda.\n", usernameStr);
  }
  else
  {
    printf("Penghapusan teman dibatalkan.\n");
  }
}
