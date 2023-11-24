#include <stdio.h>
#include <stdlib.h>
#include "ADT/masukan/masukan.h"
#include "ADT/datetime/datetime.h"
#include "ADT/simpan/simpan.h"
#include "ADT/tree/tree.h"
#include "ADT/kicauan/kicauan.h"
#include "ADT/balasan/balasan.h"
#include "ADT/listdinkicauan/listdinkicauan.h" // global variable listKicauan
#include "ADT/pengguna/pengguna.h"             // global variable currentUser
#include "ADT/teman/teman.h"
#include "ADT/matrixteman/matrixteman.h" // global variable matrixTeman
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
  CreateEmptyStack(&user1.draf);
  listUser.contents[0] = user1;

  user2.username[0] = 'A';
  user2.username[1] = 'B';
  user2.username[2] = 'C';
  user2.isPrivate = true; // Privat
  CreateEmptyStack(&user2.draf);
  listUser.contents[1] = user2;

  // Matriks pertemanan
  RelasiPertemanan.mem[0][0] = 1;
  RelasiPertemanan.mem[1][1] = 1;
  RelasiPertemanan.mem[0][1] = 0;
  RelasiPertemanan.mem[1][0] = 0;

  // Tanpa login
  BuatDraf();
  LihatDraf();

  // Login pertama
  currentUser = &user1;
  printf("Current user: %s\n", currentUser->username);

  // Buat draf
  BuatDraf();
  BuatDraf();
  BuatDraf();

  // Lihat draf
  LihatDraf();
  LihatDraf();
  LihatDraf();
  LihatDraf();
}