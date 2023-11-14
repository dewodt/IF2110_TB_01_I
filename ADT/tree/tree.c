#include <stdio.h>
#include "../tree/tree.h"

/* Prosedur membuat kicauan baru */
AddressKicauan newNodeKicauan(Kicauan kicauan)
/* I.S. Sembarang */
/* F.S. Bila alokasi berhasil, terbentuk alokasi node kicauan baru
  Bila alokasi gagal, F.S.=I.S. */
{
  // Alokasi
  AddressKicauan newNode = (AddressKicauan)malloc(sizeof(Kicauan));

  // Alokasi berhasil
  if (newNode != NULL)
  {
    InfoKicauan(newNode) = kicauan;
    FirstLeftChildBalasan(newNode) = NULL;
  }

  return newNode;
}

/* Prosedur membuat balasan baru */
AddressBalasan newNodeBalasan(Balasan balasan)
/* I.S. Sembarang */
/* F.S. Bila alokasi berhasil, terbentuk alokasi node balasan baru
  Bila alokasi gagal, F.S.=I.S. */
{
  // Alokasi
  AddressBalasan newNode = (AddressBalasan)malloc(sizeof(Balasan));

  // Alokasi berhasil
  if (newNode != NULL)
  {
    InfoBalasan(newNode) = balasan;
    LeftChildBalasan(newNode) = NULL;
    RightSiblingBalasan(newNode) = NULL;
  }

  return newNode;
}