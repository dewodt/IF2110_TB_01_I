#include <stdio.h>
#include <stdlib.h>
#include "../tree/tree.h"

/* Prosedur membuat kicauan baru */
AddressKicauan newNodeKicauan(Kicauan kicauan)
/* I.S. Sembarang */
/* F.S. Bila alokasi berhasil, terbentuk alokasi node kicauan baru
  Bila alokasi gagal, F.S.=I.S. */
{
  // Alokasi
  AddressKicauan newNode = (AddressKicauan)malloc(sizeof(NodeKicauan));

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
  AddressBalasan newNode = (AddressBalasan)malloc(sizeof(NodeBalasan));

  // Alokasi berhasil
  if (newNode != NULL)
  {
    InfoBalasan(newNode) = balasan;
    LeftChildBalasan(newNode) = NULL;
    RightSiblingBalasan(newNode) = NULL;
  }

  return newNode;
}

/* Prosedur untuk mengecek apakah ada balasan */
boolean isKicauanHasBalasan(TreeKicauan nodeKicauan)
/* Mengembalikan true bila ada balasan, mengembalikan false bila tidak ada balasan */
{
  return (FirstLeftChildBalasan(nodeKicauan) != NULL);
}

/* Prosedur untuk mengecek apakah balasan exists (valid) */
boolean isBalasanExist(TreeKicauan nodeKicauan, int idBalasan)
/* Mengembalikan true bila balasan dengan idBalasan ada pada kicauan dengan idKicauan, mengembalikan false bila sebaliknya */
{
  AddressBalasan balasan = getBalasan(nodeKicauan, idBalasan);

  return (balasan != NULL);
}

/* Dapatkan id baru untuk membuat balasan baru */
int getNewBalasanId(TreeKicauan nodeKicauan)
/* Menghasilkan 1 bila tidak ada balasan pada suatu kicauan */
/* Menghasilkan idxLatest + 1 dengan idxLatest adalah balasan paling baru */
{
  AddressBalasan latestBalasan = getLatestBalasan(nodeKicauan);

  if (latestBalasan == NULL)
  {
    // Kasus tidak ada balasan
    return 1;
  }
  else
  {
    // Kasus ada balasan
    return ID(InfoBalasan(latestBalasan)) + 1;
  }
}

/* Hitung jumlah balasan yang dimiliki suatu kicauan */
int countBalasan(TreeKicauan nodeKicauan)
/* Menghasilkan jumlah balasan yang dimiliki suatu kicauan yang valid */
{
  // Kasus tidak ada balasan
  if (!isKicauanHasBalasan(nodeKicauan))
  {
    return 0;
  }

  // Kasus ada balasan
  AddressBalasan nodeBalasan = FirstLeftChildBalasan(nodeKicauan);
  return countBalasanRecursive(nodeBalasan);
}
int countBalasanRecursive(AddressBalasan nodeBalasan)
{
  // Kasus nodeBalasan kosong
  if (nodeBalasan == NULL)
  {
    return 0;
  }

  // Kasus nodeBalasan tidak kosong
  AddressBalasan leftChild = LeftChildBalasan(nodeBalasan);
  AddressBalasan rightSibling = RightSiblingBalasan(nodeBalasan);

  // Kasus leftChild dan rightSibling kosong
  if (leftChild == NULL && rightSibling == NULL)
  {
    return 1;
  }

  // Kasus dua dua nya tidak kosong
  if (leftChild != NULL && rightSibling != NULL)
  {
    return 1 + countBalasanRecursive(leftChild) + countBalasanRecursive(rightSibling);
  }

  if (leftChild == NULL)
  {
    // Kasus leftChild kosong
    return 1 + countBalasanRecursive(rightSibling);
  }
  else
  {
    // Kasus rightSibling kosong
    return 1 + countBalasanRecursive(leftChild);
  }
}

/* Dapatkan node balasan dengan id terbesar (latest balasan) */
/* Menghasilkan node balasan dengan id terbesar */
/* Menghasilkan null bila tidak ada */
AddressBalasan getLatestBalasan(TreeKicauan nodeKicauan)
{
  // Kasus tidak ada balasan
  if (!isKicauanHasBalasan(nodeKicauan))
  {
    return NULL;
  }

  // Kasus ada balasan
  AddressBalasan nodeBalasan = FirstLeftChildBalasan(nodeKicauan);
  return getLatestBalasanRecursive(nodeBalasan);
}
AddressBalasan getLatestBalasanRecursive(AddressBalasan nodeBalasan)
{
  AddressBalasan leftChild = LeftChildBalasan(nodeBalasan);
  AddressBalasan rightSibling = RightSiblingBalasan(nodeBalasan);

  // Basis
  // Kasus nodeBalasan merupakan node terakhir
  if (rightSibling == NULL && leftChild == NULL)
  {
    return nodeBalasan;
  }

  // Rekurens
  if (leftChild == NULL)
  {
    AddressBalasan latestRightSibling = getLatestBalasanRecursive(rightSibling);
    if (ID(InfoBalasan(nodeBalasan)) > ID(InfoBalasan(latestRightSibling)))
    {
      return nodeBalasan;
    }
    else
    {
      return latestRightSibling;
    }
  }

  if (rightSibling == NULL)
  {
    AddressBalasan latestLeftChild = getLatestBalasanRecursive(leftChild);
    if (ID(InfoBalasan(nodeBalasan)) > ID(InfoBalasan(latestLeftChild)))
    {
      return nodeBalasan;
    }
    else
    {
      return latestLeftChild;
    }
  }

  AddressBalasan latestLeftChild = getLatestBalasanRecursive(leftChild);
  AddressBalasan latestRightSibling = getLatestBalasanRecursive(rightSibling);
  if (ID(InfoBalasan(nodeBalasan)) > ID(InfoBalasan(latestLeftChild)) && ID(InfoBalasan(nodeBalasan)) > ID(InfoBalasan(latestRightSibling)))
  {
    return nodeBalasan;
  }
  else if (ID(InfoBalasan(latestLeftChild)) > ID(InfoBalasan(latestRightSibling)))
  {
    return latestLeftChild;
  }
  else
  {
    return latestRightSibling;
  }
}

/* Dapatkan node balasan pada kicauan dengan id tertentu */
/* Mengembalikan node bila ketemu, mengembalika NULL bisa tidak ketemu */
/* Untuk mengecek seluruh node, input: firstLeftChild dari kicauan */
AddressBalasan getBalasan(TreeKicauan nodeKicauan, int idBalasan)
{
  // Kasus tidak ada balasan atau idBalasan tidak valid
  if (!isKicauanHasBalasan(nodeKicauan) || idBalasan < 1)
  {
    return NULL;
  }

  // Kasus ada balasan
  AddressBalasan nodeBalasan = FirstLeftChildBalasan(nodeKicauan);
  return getBalasanRecursive(nodeBalasan, idBalasan);
}
AddressBalasan getBalasanRecursive(AddressBalasan nodeBalasan, int idBalasan)
{
  // Basis 1
  // Kasus nodeBalasan merupakan node yang dicari
  if (ID(InfoBalasan(nodeBalasan)) == idBalasan)
  {
    return nodeBalasan;
  }

  // Kasus nodeBalasan bukan merupakan node yang dicari, cek left child & right sibling
  AddressBalasan leftChild = LeftChildBalasan(nodeBalasan);
  AddressBalasan rightSibling = RightSiblingBalasan(nodeBalasan);

  // Basis 2 left & right null tp tidak memenuhi basis 1
  if (leftChild == NULL && rightSibling == NULL)
  {
    return NULL;
  }

  // Rekurens
  // Dua dua nya tidak null
  if (leftChild != NULL && rightSibling != NULL)
  {
    AddressBalasan leftChildResult = getBalasanRecursive(leftChild, idBalasan);
    AddressBalasan rightSiblingResult = getBalasanRecursive(rightSibling, idBalasan);

    if (leftChildResult != NULL)
    {
      // Kasus ada di leftchild
      return leftChildResult;
    }
    else
    {
      // Kasus ada di right sibling atau tidak ketemu (otomatis null)
      return rightSiblingResult;
    }
  }

  if (leftChild != NULL)
  {
    // Hanya left child yang tidak null
    return getBalasanRecursive(leftChild, idBalasan);
  }
  else
  {
    // Hanya right sibling yang tidak null
    return getBalasanRecursive(rightSibling, idBalasan);
  }
}

/* Prosedur untuk append balasan pada sebuah kicauan */
void balasKicauan(TreeKicauan nodeKicauan, Balasan balasan)
/* I.S. nodeKicauan terdefinisi dan balasan terdefinisi */
/* F.S. bila gagal, I.S. = F.S.
        bila berhasil, balasan ditambahkan pada kicauan */
{
  // Buat balasan baru
  AddressBalasan nodeBalasan = newNodeBalasan(balasan);

  // Alokasi gagal
  if (nodeBalasan == NULL)
  {
    return;
  }

  // Alokasi berhasil
  // Dapatkan node terakhir balasan dari kicauan
  AddressBalasan pBalasan = FirstLeftChildBalasan(nodeKicauan);

  if (pBalasan == NULL)
  {
    // Kasus belum ada balasan pada kicauan
    FirstLeftChildBalasan(nodeKicauan) = nodeBalasan;
  }
  else
  {
    // Kasus sudah ada balasan pada kicauan, append ke yang paling terakhir
    while (RightSiblingBalasan(pBalasan) != NULL)
    {
      pBalasan = RightSiblingBalasan(pBalasan);
    }
    RightSiblingBalasan(pBalasan) = nodeBalasan;
  }
}

/* Prosedur untuk membalas balasan */
void balasBalasan(AddressBalasan nodeBalasan, Balasan balasan)
/* I.S. nodeBalasan terdefinisi, dan balasan terdefinisi */
/* F.S. bila gagal, I.S. = F.S.
        bila berhasil, balasan ditambahkan pada balasan */
{
  // Buat balasan baru
  AddressBalasan nodeBalasanBaru = newNodeBalasan(balasan);

  // Alokasi gagal
  if (nodeBalasanBaru == NULL)
  {
    return;
  }

  // Alokasi berhasil
  // Dapatkan node terakhir balasan dari kicauan
  AddressBalasan pBalasan = LeftChildBalasan(nodeBalasan);

  if (pBalasan == NULL)
  {
    // Kasus belum ada balasan pada kicauan
    LeftChildBalasan(nodeBalasan) = nodeBalasanBaru;
  }
  else
  {
    // Kasus sudah ada balasan pada kicauan, append ke yang paling terakhir
    while (RightSiblingBalasan(pBalasan) != NULL)
    {
      pBalasan = RightSiblingBalasan(pBalasan);
    }
    RightSiblingBalasan(pBalasan) = nodeBalasanBaru;
  }
}

/* Prosedur untuk menghapus balasan */
void hapusNodeBalasan(TreeKicauan nodeKicauan, AddressBalasan nodeBalasanDelete)
/* I.S. nodeBalasanDelete dan nodeKicauan terdefinisi & valid*/
/* F.S. nodeBalasanDelete dan semua anak-anaknya (jika ada) terbebaskan */
{
  AddressBalasan firstLeftChild = FirstLeftChildBalasan(nodeKicauan);
  if (firstLeftChild == nodeBalasanDelete)
  {
    // Sambungkan dengan node yang baru
    FirstLeftChildBalasan(nodeKicauan) = RightSiblingBalasan(nodeBalasanDelete);

    // Putuskan node
    RightSiblingBalasan(nodeBalasanDelete) = NULL;

    // Bebaskan node
    freeNodes(nodeBalasanDelete);
    return;
  }

  // Kasus balasan yang ingin dihapus bukan merupakan first child dari root
  hapusNodeBalasanRekursif(firstLeftChild, nodeBalasanDelete);
}
void hapusNodeBalasanRekursif(AddressBalasan currentNode, AddressBalasan nodeBalasanDelete)
{
  // Kasus nodeBalasan kosong
  if (currentNode == NULL)
  {
    return;
  }

  AddressBalasan rightSibling = RightSiblingBalasan(currentNode);
  AddressBalasan leftChild = LeftChildBalasan(currentNode);

  // Kasus rightSibling dari current node merupakan node yang ingin dihapus
  if (rightSibling == nodeBalasanDelete)
  {
    // Sambungkan node dgn yg baru
    RightSiblingBalasan(currentNode) = RightSiblingBalasan(nodeBalasanDelete);

    // Putuskan node
    RightSiblingBalasan(nodeBalasanDelete) = NULL;

    // Bebaskan node
    freeNodes(nodeBalasanDelete);
    return;
  }

  // Kasus leftChild dari current node merupakan node yang ingin dihapus
  if (leftChild == nodeBalasanDelete)
  {
    // Sambungkan node dgn yg baru
    LeftChildBalasan(currentNode) = RightSiblingBalasan(nodeBalasanDelete);

    // Putuskan node
    RightSiblingBalasan(nodeBalasanDelete) = NULL;

    // Bebaskan node
    freeNodes(nodeBalasanDelete);
    return;
  }

  // Kasus rightSibling dari current node bukan merupakan node yang ingin dihapus
  hapusNodeBalasanRekursif(rightSibling, nodeBalasanDelete);

  // Kasus leftChild dari current node bukan merupakan node yang ingin dihapus
  hapusNodeBalasanRekursif(leftChild, nodeBalasanDelete);
}

/* Menghapus dan mendealokasi node dan semua node leftChild dan rightSiblingnya */
void freeNodes(AddressBalasan nodeBalasan)
/* I.S. node balasan terdefinisi */
/* F.S. node balasan dan seluruh leftchild atau right siblingnya dihapus dan didealokasi */
{
  // Kasus nodeBalasan kosong
  if (nodeBalasan == NULL)
  {
    return;
  }

  // Kasus node memiliki left
  if (LeftChildBalasan(nodeBalasan) != NULL)
  {
    freeNodes(LeftChildBalasan(nodeBalasan));
  }

  // Kasus node memiliki right
  if (RightSiblingBalasan(nodeBalasan) != NULL)
  {
    freeNodes(RightSiblingBalasan(nodeBalasan));
  }

  // Bebaskan current Node
  free(nodeBalasan);
}