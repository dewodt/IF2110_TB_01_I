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
  Balasan infoBalasan;
  AddressBalasan rightSiblingBalasan;
  AddressBalasan leftChildBalasan;
} NodeBalasan;

/* Definisi node kicauan */
typedef struct nodeKicauan *AddressKicauan;
typedef struct nodeKicauan
{
  Kicauan infoKicauan;
  AddressBalasan firstLeftChildBalasan;
} NodeKicauan;

/* Definisi Tree */
typedef AddressKicauan TreeKicauan;

/* Selektor Balasan */
#define InfoBalasan(P) (P)->infoBalasan
#define RightSiblingBalasan(P) (P)->rightSiblingBalasan
#define LeftChildBalasan(P) (P)->leftChildBalasan

/* Selektor Kicauan */
#define InfoKicauan(P) (P)->infoKicauan
#define FirstLeftChildBalasan(P) (P)->firstLeftChildBalasan

/* Prosedur membuat kicauan baru */
AddressKicauan newNodeKicauan(Kicauan kicauan);
/* I.S. Sembarang */
/* F.S. Bila alokasi berhasil, terbentuk alokasi node kicauan baru
  Bila alokasi gagal, F.S.=I.S. */

/* Prosedur membuat balasan baru */
AddressBalasan newNodeBalasan(Balasan balasan);
/* I.S. Sembarang */
/* F.S. Bila alokasi berhasil, terbentuk alokasi node balasan baru
  Bila alokasi gagal, F.S.=I.S. */

#endif