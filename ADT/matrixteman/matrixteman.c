// import
#include "./matrixteman.h"

void createFriendMatrix(Matrix* RelasiPertemanan){
  createMatrix(20, 20, RelasiPertemanan);
}

IdxType searchIndexPengguna(ListStatik ListPengguna, User Pengguna){
  return searchIndexPenggunaByName(ListPengguna, Pengguna.username);
}

IdxType searchIndexPenggunaByName(ListStatik ListPengguna, char *Username){
  IdxType IdxPengguna = -1, i = 0;
  boolean found = false;
  // Harusnya compare string aman dari '\0', semoga ga ngebug TT
  while (i < listLength(ListPengguna) && !found) {
    if (compareString(Username, USERNAME(ListPengguna, i), stringLength(Username)) == 0) {
      found = true;
      IdxPengguna = i;
    } else {
      i++;
    }
  }
  return IdxPengguna;
}

boolean areFriendsEachOthers(Matrix RelasiPertemanan, ListStatik ListPengguna, User Pengguna1, User Pengguna2){
  return areFriendsByName(RelasiPertemanan, ListPengguna, Pengguna1.username, Pengguna2.username);
}

boolean areFriendsByName(Matrix RelasiPertemanan, ListStatik ListPengguna, char *Username1, char *Username2){
  IdxType IdxPengguna1 = searchIndexPenggunaByName(ListPengguna, Username1);
  IdxType IdxPengguna2 = searchIndexPenggunaByName(ListPengguna, Username2);
  IdxType i = IdxPengguna1, j = IdxPengguna2;
  return (ELMT(RelasiPertemanan, i, j) == 1 && ELMT(RelasiPertemanan, j, i) == 1);
}

void displayListFriend(ListStatik DaftarTeman, User CurrentPengguna){
  IdxType i;
  printf("Daftar teman %s\n", CurrentPenguna.username);
  for (i = 0; i < listLength(DaftarTeman); i++){
    printf("| %s\n", USERNAME(DaftarTeman, i));
  }
}

void showFriendList(Matrix RelasiPertemanan, ListStatik ListPengguna, User CurrentPengguna){
  // track semua dulu, kompleksitasnya tetep T(20) = O(1)
  // Kasus jika belum ada User login
  if (CurrentPengguna = NULL) { // import global variable || !*isLoggedIn
      printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
      return;
  } else {
    IdxType IdxCurrentPengguna = searchIndexPengguna(ListPengguna, CurrentPengguna);

    // Buat list temannya CurrentPengguna
    ListStatik DaftarTeman;
    CreateListStatik(&DaftarTeman);
    for (i = 0; i < listLength(ListPengguna); i++){
      if (ELMT(RelasiPertemanan, IdxCurrentPengguna, i) == 1){
        insertLast(&DaftarTeman, ELMT(RelasiPertemanan, IdxCurrentPengguna, i));
      }
    }

    if (listLength(DaftarTeman) == 0){
      printf("%s belum mempunyai teman\n", CurrentPengguna.username);
    } else {
      printf("%s memiliki %d teman\n", CurrentPengguna.username, listLength(DaftarTeman));
      displayListFriend(DaftarTeman, CurrentPengguna);
    }
  }
}

void deleteFriend(Matrix *RelasiPertemanan, ListStatik ListPengguna, User CurrentUser) {
  MASUKAN UsernameMasukan;
  printf("Masukkan nama pengguna:\n");
  baca(&UsernameMasukan);

  char* UsernameStr;
  MASUKANToStr(UsernameMasukan, UsernameStr);

  IdxType IndexCurrentUser = searchIndexPengguna(ListPengguna, CurrentUser);
  IdxType IndexUsername = searchIndexPenggunaByName(ListPengguna, UsernameStr);

  if (IndexUsername == -1) {
    // Kasus tidak ditemukan
    printf("Tidak ditemukan pengguna bernama %s.\n", UsernameStr);
  } else if (!areFriendsByName(*RelasiPertemanan, ListPengguna, CurrentUser.username, UsernameStr)) {
    // Kasus belum berteman
    printf("%s bukan teman Anda.\n", UsernameStr);
  } else {
    // Kasus lain, jika sudah berteman ataupun sudah mengirim req teman
    MASUKAN Yakin;
    printf("Apakah anda yakin ingin menghapus Bob dari daftar teman anda?(YA/TIDAK) ");
    baca(&Yakin);
    // Jika tidak mengetik "YA;" diasumsikan tidak ingin menghapus
    if (isSame(Yakin, "YA;")){
      IdxType i = IndexCurrentUser, j = IndexUsername;
      ELMT(*RelasiPertemanan, i, j) == 0;
      ELMT(*RelasiPertemanan, j, i) == 0;
      printf("%s berhasil dihapus dari daftar teman Anda.\n", UsernameStr);
    } else {
      printf("Penghapusan teman dibatalkan.\n");
    }
  }
}

// unit test driver
int main() {
  Matrix RelasiPertemanan;
  createRelasiPertemanan(20, 20, &RelasiPertemanan);
}