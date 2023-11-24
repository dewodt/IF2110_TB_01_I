#include "stdio.h"
#include "stdlib.h"
#include "../tree.h"
// #include "../../kicauan/kicauan.h"
// #include "../../balasan/balasan.h"

int main()
{
  // Create datetime mock
  DATETIME datetime;
  GetCurrentLocalDATETIME(&datetime);

  // Create user mock
  User u1, u2, u3;
  strcpy(u1.username, "user 1");
  strcpy(u1.username, "user 2");
  strcpy(u1.username, "user 3");

  // Create kicauan mock
  Kicauan kicauan;
  CreateKicauan(&kicauan, 1, "Hello World!", 0, &u2, datetime);
  TreeKicauan addrKicau = newNodeKicauan(kicauan);

  // Create balasan mock
  Balasan b1;
  CreateBalasan(&b1, 1, "Hello World! Balasan 1", &u1, datetime);

  Balasan b2;
  CreateBalasan(&b2, 2, "Hello World! Balasan 2", &u2, datetime);

  Balasan b3;
  CreateBalasan(&b3, 3, "Hello World! Balasan 3", &u3, datetime);

  Balasan b4;
  CreateBalasan(&b4, 4, "Hello World! Balasan 4", &u1, datetime);

  Balasan b5;
  CreateBalasan(&b5, 5, "Hello World! Balasan 5", &u2, datetime);

  Balasan b6;
  CreateBalasan(&b6, 6, "Hello World! Balasan 6", &u3, datetime);

  Balasan b7;
  CreateBalasan(&b7, 7, "Hello World! Balasan 7", &u1, datetime);

  Balasan b8;
  CreateBalasan(&b8, 8, "Hello World! Balasan 8", &u2, datetime);

  Balasan b9;
  CreateBalasan(&b9, 9, "Hello World! Balasan 9", &u3, datetime);

  Balasan b10;
  CreateBalasan(&b10, 10, "Hello World! Balasan 10", &u1, datetime);

  // Initial
  printf("Kicauan has balasan: %d (boolean)\n", isKicauanHasBalasan(addrKicau));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 1));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 2));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 3));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 4));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 5));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 6));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 7));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 8));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 9));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 10));
  printf("Count balasan: %d\n", countBalasan(addrKicau));
  printf("\n");

  // Create tree
  // use balasKicauan
  balasKicauan(addrKicau, b1);
  AddressBalasan addr1 = getBalasan(addrKicau, 1);
  balasKicauan(addrKicau, b2);
  AddressBalasan addr2 = getBalasan(addrKicau, 2);
  balasKicauan(addrKicau, b3);
  AddressBalasan addr3 = getBalasan(addrKicau, 3);

  // use balasBalasan
  balasBalasan(addr2, b4);
  AddressBalasan addr4 = getBalasan(addrKicau, 4);
  balasBalasan(addr3, b5);
  AddressBalasan addr5 = getBalasan(addrKicau, 5);
  balasBalasan(addr2, b6);
  AddressBalasan addr6 = getBalasan(addrKicau, 6);
  balasBalasan(addr4, b7);
  AddressBalasan addr7 = getBalasan(addrKicau, 7);
  balasBalasan(addr5, b8);
  AddressBalasan addr8 = getBalasan(addrKicau, 8);
  balasBalasan(addr6, b9);
  AddressBalasan addr9 = getBalasan(addrKicau, 9);
  balasBalasan(addr7, b10);
  AddressBalasan addr10 = getBalasan(addrKicau, 10);

  // Final
  printf("\n");
  printf("Kicauan has balasan: %d (boolean)\n", isKicauanHasBalasan(addrKicau));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 1));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 2));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 3));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 4));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 5));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 6));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 7));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 8));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 9));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 10));
  printf("Count balasan: %d\n", countBalasan(addrKicau));
  printf("\n");

  // Dapatkan balasan terbaru
  printf("\n");
  AddressBalasan latestBalasan = getLatestBalasan(addrKicau);
  printf("Privat: \n");
  CetakDetailBalasan(InfoBalasan(latestBalasan), true, 0);
  printf("Publik: \n");
  CetakDetailBalasan(InfoBalasan(latestBalasan), false, 0);
  printf("\n");

  // Dapatkan balasan id baru
  int newBalasanId = getNewBalasanId(addrKicau);
  printf("\n");
  printf("New balasan id: %d\n", newBalasanId);
  printf("\n");

  // Hapus suatu balasan
  printf("\n");
  printf("BEFORE:\n");
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 1));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 2));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 3));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 4));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 5));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 6));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 7));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 8));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 9));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 10));
  // HAPUS
  hapusNodeBalasan(addrKicau, addr2);
  printf("AFTER:\n");
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 1));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 2));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 3));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 4));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 5));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 6));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 7));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 8));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 9));
  printf("Balasan exists: %d (boolean)\n", isBalasanExist(addrKicau, 10));
  printf("\n");

  // Print tree
  // Kasus kicauan ada namun tidak ada balasan
  AddressBalasan firstChildBalasan = FirstLeftChildBalasan(addrKicau);
  TampilkanBalasanRekursif(firstChildBalasan, 0);

  // Free mallocs after use
  freeNodes(FirstLeftChildBalasan(addrKicau));
  free(addrKicau);

  return 0;
}