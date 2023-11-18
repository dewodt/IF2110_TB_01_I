#ifndef TREE_H
#define TREE_H

#include "../boolean.h"
#include "../datetime/datetime.h"
#include "../modifiedliststatik/modifiedliststatik.h"

/* Struktur Kicauan */
/* Kicauan memiliki id, teks, like, author, datetime */
/* Kicauan juga bisa menjadi sebuah utas */
typedef struct kicauan
{
  int id;
  char text[280];
  int like;
  User *author;
  DATETIME datetime;
} Kicauan;

/* Struktur Info Balasan */
/* Balasan memiliki id, teks, author, datetime */
typedef struct balasan
{
  int id;
  char text[280];
  User *author;
  DATETIME datetime;
} Balasan;

/* Selektor Kicauan & Balasan */
#define ID(k) (k).id
#define TEXT(k) (k).text
#define LIKE(k) (k).like
#define AUTHOR(k) (k).author
#define DATETIME(k) (k).datetime

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
boolean isKicauanHasBalasan(TreeKicauan nodeKicauan);
/* Mengembalikan true bila ada balasan, mengembalikan false bila tidak ada balasan */

/* Prosedur untuk mengecek apakah balasan exists (valid) */
boolean isBalasanExist(TreeKicauan nodeKicauan, int idBalasan);
/* Mengembalikan true bila balasan dengan idBalasan ada pada kicauan dengan idKicauan, mengembalikan false bila sebaliknya */

/* Dapatkan id baru untuk membuat balasan baru */
int getNewBalasanId(TreeKicauan nodeKicauan);
/* Menghasilkan 1 bila tidak ada balasan pada suatu kicauan */
/* Menghasilkan idxLatest + 1 dengan idxLatest adalah balasan paling baru */

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

/* Prosedur untuk append balasan pada sebuah kicauan */
void balasKicauan(TreeKicauan nodeKicauan, Balasan balasan);
/* I.S. nodeKicauan terdefinisi dan balasan terdefinisi */
/* F.S. bila gagal, I.S. = F.S.
        bila berhasil, balasan ditambahkan pada kicauan */

/* Prosedur untuk membalas balasan */
void balasBalasan(AddressBalasan nodeBalasan, Balasan balasan);
/* I.S. nodeBalasan terdefinisi, dan balasan terdefinisi */
/* F.S. bila gagal, I.S. = F.S.
        bila berhasil, balasan ditambahkan pada balasan */

/* Prosedur untuk menghapus balasan */
void hapusNodeBalasan(TreeKicauan nodeKicauan, AddressBalasan nodeBalasanDelete);
void hapusNodeBalasanRekursif(AddressBalasan currentNode, AddressBalasan nodeBalasanDelete);
/* I.S. Address balasan terdefinisi */
/* F.S. Address balasan dan semua anak-anaknya terbebaskan */

/* Menghapus dan mendealokasi node dan semua node leftChild dan rightSiblingnya */
void freeNodes(AddressBalasan nodeBalasan);
/* I.S. node balasan terdefinisi */
/* F.S. node balasan dan seluruh childnya dihapus dari node */

#endif