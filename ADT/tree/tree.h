#ifndef TREE_H
#define TREE_H

#include "../kicauan/kicauan.h"
#include "../balasan/balasan.h"

/* ADT Tree digunakan untuk mendeskripsikan kicauan & balasan */
/* Definisi struktur tree */
/* Menggunakan left-child/right sibling representation
Left-child artinya reply pertama sebuah balasan atau kicauan
Right sibling merupakan reply-reply lainnya dari parent */

/* Definisi node balasan */
typedef struct nodeBalasan *AddressBalasan;
typedef struct nodeBalasan
{
  Balasan InfoBalasan;
  AddressBalasan nextBalasanRightSibling;
  AddressBalasan nextBalasanLeftChild;
} NodeBalasan;

/* Definisi node kicauan */
typedef struct nodeKicauan *AddressKicauan;
typedef struct nodeKicauan
{
  Kicauan InfoKicauan;
  AddressBalasan firstLeftChildBalasan;
} NodeKicauan;

/* Tipe buatan Tree */
typedef AddressKicauan TreeKicauan;

/* Prosedur membuat node kicauan baru */
/* I.S. Sembarang */
/* F.S. Bila alokasi berhasil, terbentuk alokasi node kicauan baru
  Bila alokasi gagal, F.S.=I.S. */
AddressKicauan newNodeKicauan(Kicauan kicauan);

/* Prosedur membuat node balasan baru */
/* I.S. Sembarang */
/* F.S. Bila alokasi berhasil, terbentuk alokasi node balasan baru
  Bila alokasi gagal, F.S.=I.S. */
AddressBalasan newNodeBalasan(Balasan balasan);

#endif