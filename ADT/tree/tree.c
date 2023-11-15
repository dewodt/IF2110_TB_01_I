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

/* Prosedur untuk mengecek apakah ada balasan */
boolean isBalasanExist(TreeKicauan nodeKicauan)
/* Mengembalikan true bila ada balasan, mengembalikan false bila tidak ada balasan */
{
  return (FirstLeftChildBalasan(nodeKicauan) != NULL);
}

/* Dapatkan node balasan dengan id terbesar (latest balasan) */
/* Menghasilkan node balasan dengan id terbesar */
/* Menghasilkan null bila tidak ada */
AddressBalasan getLatestBalasan(TreeKicauan nodeKicauan)
{
  // Kasus tidak ada balasan
  if (!isBalasanExist(nodeKicauan))
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

  // Kasus tidak ada left child dan right sibling
  if (leftChild == NULL && rightSibling == NULL)
  {
    return nodeBalasan;
  }

  // Kasus ada left child tidak ada right sibling
  if (leftChild != NULL && rightSibling == NULL)
  {
    AddressBalasan maxLeftChild = getLatestBalasanRecursive(leftChild);
    if (ID(InfoBalasan(maxLeftChild)) > ID(InfoBalasan(nodeBalasan)))
    {
      return maxLeftChild;
    }
    else
    {
      return nodeBalasan;
    }
  }

  // Kasus tidak ada left child ada right sibling
  if (leftChild == NULL && rightSibling != NULL)
  {
    AddressBalasan maxRightSibling = getLatestBalasanRecursive(rightSibling);
    if (ID(InfoBalasan(maxRightSibling)) > ID(InfoBalasan(nodeBalasan)))
    {
      return maxRightSibling;
    }
    else
    {
      return nodeBalasan;
    }
  }

  // Kasus ada left child dan right sibling
  if (leftChild != NULL && rightSibling != NULL)
  {
    AddressBalasan maxLeftChild = getLatestBalasanRecursive(leftChild);
    AddressBalasan maxRightSibling = getLatestBalasanRecursive(rightSibling);

    if (ID(InfoBalasan(maxLeftChild)) > ID(InfoBalasan(maxRightSibling)))
    {
      if (ID(InfoBalasan(maxLeftChild)) > ID(InfoBalasan(nodeBalasan)))
      {
        return maxLeftChild;
      }
      else
      {
        return nodeBalasan;
      }
    }
    else
    {
      if (ID(InfoBalasan(maxRightSibling)) > ID(InfoBalasan(nodeBalasan)))
      {
        return maxRightSibling;
      }
      else
      {
        return nodeBalasan;
      }
    }
  }
}

/* Dapatkan node balasan pada kicauan dengan id tertentu */
/* Mengembalikan node bila ketemu, mengembalika NULL bisa tidak ketemu */
/* Untuk mengecek seluruh node, input: firstLeftChild dari kicauan */
AddressBalasan getBalasan(TreeKicauan nodeKicauan, int idBalasan)
{
  // Kasus tidak ada balasan
  if (!isBalasanExist(nodeKicauan))
  {
    return NULL;
  }

  // Kasus idBalasan tidak valid
  if (idBalasan < 1)
  {
    return NULL;
  }

  // Kasus ada balasan
  AddressBalasan nodeBalasan = FirstLeftChildBalasan(nodeKicauan);
  return getBalasanRecursive(nodeBalasan, idBalasan);
}
AddressBalasan getBalasanRecursive(AddressBalasan nodeBalasan, int idBalasan)
{
  // Kasus nodeBalasan merupakan node yang dicari
  if (ID(InfoBalasan(nodeBalasan)) == idBalasan)
  {
    return nodeBalasan;
  }

  // Kasus nodeBalasan bukan merupakan node yang dicari, cek left child & right sibling
  AddressBalasan leftChild = LeftChildBalasan(nodeBalasan);
  AddressBalasan rightSibling = RightSiblingBalasan(nodeBalasan);

  // Kasus currentNode bukan value yang dicair,
  // dan tidak ada left child dan right sibling
  if (leftChild == NULL && rightSibling == NULL)
  {
    return NULL;
  }

  AddressBalasan nodeBalasanLeftChild = getBalasanRecursive(leftChild, idBalasan);
  AddressBalasan nodeBalasanRightSibling = getBalasanRecursive(rightSibling, idBalasan);

  // Ketemu di left child
  if (nodeBalasanLeftChild != NULL)
  {
    return nodeBalasanLeftChild;
  }

  // Ketemu di right
  if (nodeBalasanRightSibling != NULL)
  {
    return nodeBalasanRightSibling;
  }

  // Tidak ketemu
  return NULL;
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
void hapusBalasan(TreeKicauan nodeKicauan, AddressBalasan nodeBalasanDelete)
/* I.S. Address balasan terdefinisi & valid */
/* F.S. Address balasan dan semua anak-anaknya (jika ada) terbebaskan */
{
  AddressBalasan firstLeftChild = FirstLeftChildBalasan(nodeKicauan);
  if (firstLeftChild == nodeBalasanDelete)
  {
    // Kasus balasan yang ingin dihapus merupakan first child dari root
    // Ganti firstLeftChild right siblingnya
    firstLeftChild = RightSiblingBalasan(nodeBalasanDelete);
    freeNodeAndChilds(nodeBalasanDelete);
    return;
  }

  // Kasus balasan yang ingin dihapus bukan merupakan first child dari root
  hapusBalasanRekursif(firstLeftChild, nodeBalasanDelete);
}
void hapusBalasanRekursif(AddressBalasan currentNode, AddressBalasan nodeBalasanDelete)
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
    RightSiblingBalasan(currentNode) = RightSiblingBalasan(nodeBalasanDelete);
    freeNodeAndChilds(nodeBalasanDelete);
    return;
  }

  // Kasus leftChild dari current node merupakan node yang ingin dihapus
  if (leftChild == nodeBalasanDelete)
  {
    LeftChildBalasan(currentNode) = RightSiblingBalasan(nodeBalasanDelete);
    freeNodeAndChilds(nodeBalasanDelete);
    return;
  }

  // Kasus rightSibling dari current node bukan merupakan node yang ingin dihapus
  hapusBalasanRekursif(rightSibling, nodeBalasanDelete);

  // Kasus leftChild dari current node bukan merupakan node yang ingin dihapus
  hapusBalasanRekursif(leftChild, nodeBalasanDelete);
}
void freeNodeAndChilds(AddressBalasan nodeBalasan)
{
  // Kasus nodeBalasan kosong
  if (nodeBalasan == NULL)
  {
    return;
  }

  // Kasus nodeBalasan memiliki left
  if (LeftChildBalasan(nodeBalasan) != NULL)
  {
    freeNodeAndChilds(LeftChildBalasan(nodeBalasan));
  }

  // Kasus nodeBalasan memiliki right
  if (RightSiblingBalasan(nodeBalasan) != NULL)
  {
    freeNodeAndChilds(RightSiblingBalasan(nodeBalasan));
  }

  // Bebaskan current Node
  free(nodeBalasan);
}