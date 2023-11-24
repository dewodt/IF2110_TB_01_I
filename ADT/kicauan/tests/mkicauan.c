#include <stdio.h>
#include <stdlib.h>
#include "ADT/masukan/masukan.h"
#include "ADT/datetime/datetime.h"
#include "ADT/simpan/simpan.h"
#include "ADT/tree/tree.h"
#include "ADT/kicauan/kicauan.h"
#include "ADT/balasan/balasan.h"
#include "ADT/teman/teman.h"
#include "ADT/listdinkicauan/listdinkicauan.h" // global variable listKicauan
#include "ADT/pengguna/pengguna.h"             // global variable currentUser
#include "ADT/matrixteman/matrixteman.h"       // global variable matrixTeman
#include "ADT/draf/draf.h"
#include "ADT/stackdraf/stackdraf.h"
#include "ADT/listdinUtas/listdinForUtas.h"

// REDECLARE GLOBAL VARIABLE
ListDinKicauan listKicauan;
User *currentUser;
MatrixTeman RelasiPertemanan;
ListStatik listUser;
ListUtas listUtas;

int main()
{
  // GLOBAL VAR
  CreateListDinKicauan(&listKicauan, 100);
  CreateListStatik(&listUser);
  createMatrixTeman(100, 100, &RelasiPertemanan);

  // Buat user
  User user1, user2;
  user1.username[0] = 'T';
  user1.username[1] = 'E';
  user1.username[2] = 'S';
  user1.isPrivate = false; // Public
  listUser.contents[0] = user1;

  user2.username[0] = 'A';
  user2.username[1] = 'B';
  user2.username[2] = 'C';
  user2.isPrivate = true; // Privat

  listUser.contents[1] = user2;

  // Matriks pertemanan
  RelasiPertemanan.mem[0][0] = 1;
  RelasiPertemanan.mem[1][1] = 1;
  RelasiPertemanan.mem[0][1] = 0;
  RelasiPertemanan.mem[1][0] = 0;

  // Sebelum login
  BuatKicauan();
  TampilkanKicauan();
  SukaKicauan(1);
  UbahKicauan(1);

  // Login pertama
  currentUser = &user1;
  printf("Current user: %s\n", currentUser->username);

  BuatKicauan();
  BuatKicauan();
  BuatKicauan();
  BuatKicauan();
  BuatKicauan();

  // Login kedua
  currentUser = &user2;
  printf("Current user: %s\n", currentUser->username);

  BuatKicauan();
  BuatKicauan();
  BuatKicauan();
  BuatKicauan();
  BuatKicauan();

  // Test Tampilakn kicauan
  TampilkanKicauan();

  // Test like kicauan
  SukaKicauan(1);
  SukaKicauan(2);
  SukaKicauan(7);
  SukaKicauan(8);

  // Test ubah kicauan
  UbahKicauan(1);
  UbahKicauan(2);
  UbahKicauan(6);
  UbahKicauan(8);
}