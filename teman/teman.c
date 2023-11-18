// style ngodingnya maaf ga sesuai standar, ntar dibeautify aja
// ga sempet kalo harus merhatiin detil, yg penting beres jadi bisa dirun

// import
// perlu perbaiki path untuk import export char & word machine, atau satukan saja jdi 1 dir
#include "../ADT/charmachine/charmachine.h"
#include "../ADT/wordmachine/wordmachine.h"
#include "../ADT/boolean.h"
#include "../ADT/matrix/matrix.h"
#include "../ADT/liststatik/liststatik.h"

typedef struct {
  Word nama;
  Word sandi; // kata sandi
  Profil profil;
} Pengguna;

typedef struct {
  // default awal 3 Word di bawah ini = kosong;
  Word bio;   // bio akun, max char = 135
  Word nomor; // no HP
  Word weton; // hanya ada 5 case insensitive
  boolean akun; // privacy: true berarti privat, false berarti publik
  Matrix fotoProfil; // bikin tiap ElType nya tuple (warna, simbol)
} Profil;

//  bikin tipe adjMatrix untuk representasi graf teman;
void createFriendMatrix(Matrix* FriendMatrix){
  // only used whenever configurations loaded
  createMatrix(20, 20, FriendMatrix); // statik, karena maksimal 20 pengguna
  // tiap ada pengguna baru dalam list, tambah 1 di sisi diagonalnya.
  // ngedit detil kek gini bakalan agak ribet krn ga to de poin di spek
  // semoga kita diberi petunjuk dan kemudahan :D
}

/**
 * BUTUH NGEPRINT PROFIL2 PENGGUNA
 * BUTUH NGEBANDINGIN PROFIL2 PENGGUNA JUGA
*/

void listFriend(ListStatik DaftarTeman){
  IdxType i;
  printf("Daftar teman <CurrentPenguna.nama>\n");
  for (int i; i < listLength(DaftarTeman); i++){
    printf("| <DaftarTeman[i].nama>\n ");
  }
}

void showFriendList(Matrix FriendMatrix, ListStatik ListPengguna, ElType CurrentPengguna){
  // ElType nanti ganti pengguna
  // track semua dulu, kompleksitasnya tetep T(20) = O(1)
  IdxType IdxCurrentPengguna = 0, i;

  ListStatik DaftarTeman;
  CreateListStatik(&DaftarTeman);

  while (ELMT(ListPengguna, i) != CurrentPengguna){
    i++;
  }

  for (i = 0; i < listLength(ListPengguna); i++){
    if (ELMT(FriendMatrix, IdxCurrentPengguna, i) == 1){
      insertLast(&DaftarTeman, ELMT(FriendMatrix, IdxCurrentPengguna, i));
    }
  }

  if (listLength(DaftarTeman) == 0){
    printf("<CurrentPengguna.nama> belum mempunyai teman\n");
  } else {
    printf("<CurrentPengguna.nama> memiliki %d teman\n", listLength(DaftarTeman));
  }
}

// unit test driver
int main {
  Matrix FriendMatrix;
  createFriendMatrix(20, 20, &FriendMatrix);
}