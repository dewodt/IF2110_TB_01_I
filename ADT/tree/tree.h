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

/* Prosedur untuk mengecek apakah ada balasan */
boolean isBalasanExist(TreeKicauan nodeKicauan);
/* Mengembalikan true bila ada balasan, mengembalikan false bila tidak ada balasan */

/* Dapatkan node balasan dengan id terbesar (latest balasan) */
AddressBalasan getLatestBalasan(TreeKicauan nodeKicauan);
AddressBalasan getLatestBalasanRecursive(AddressBalasan nodeBalasan);
/* Menghasilkan node balasan dengan id terbesar */
/* Menghasilkan null bila tidak ada */

/* Dapatkan node balasan pada kicauan dengan id tertentu */
AddressBalasan getBalasan(TreeKicauan nodeKicauan, int idBalasan);
AddressBalasan getBalasanRecursive(AddressBalasan nodeBalasan, int idBalasan);
/* Mengembalikan node bila ketemu, mengembalika NULL bisa tidak ketemu */
/* Untuk mengecek seluruh node, input: firstLeftChild dari kicauan */

#endif