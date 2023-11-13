#ifndef TREE_H
#define TREE_H

#include "../kicauan/kicauan.h"
#include "../balasan/balasan.h"

/* ADT Tree digunakan untuk mendeskripsikan kicauan & balasan */
/* Definisi struktur tree */
/* Menggunakan left-child/right sibling representation
Left-child artinya reply pertama sebuah balasan atau kicauan
Right sibling merupakan reply-reply lainnya dari parent */

/* Definisi balasan (disimpan dalam node) */
typedef struct balasan *AddressBalasan;
typedef struct balasan
{
  InfoBalasan infoBalasan;
  AddressBalasan nextBalasanRightSibling;
  AddressBalasan nextBalasanLeftChild;
} Balasan;

/* Definisi kicauan (disimpan di dalam list dinamis) */
typedef struct kicauan
{
  InfoKicauan infoKicauan;
  AddressBalasan firstLeftChildBalasan;
} Kicauan;

/* Selektor Balasan */
#define INFOBALASAN(b) (b)->infoBalasan
#define RIGHTSIBLING(b) (b)->nextBalasanRightSibling
#define LEFTCHILD(b) (b)->nextBalasanLeftChild

/* Selektor Kicauan */
#define INFOKICAUAN(k) (k).infoKicauan
#define FIRSTLEFTCHILD(k) (k).firstLeftChildBalasan

/* Prosedur membuat kicauan baru */
void createKicauan(Kicauan *k, int id, char text[], int like, char author, DATETIME datetime);
/* I.S. Sembarang, data id, text, like, author, datetime valid */
/* F.S. Terbentuk kicauan dengan id, teks, like, author, datetime sesuai input */

/* Prosedur membuat balasan baru */
AddressBalasan newNodeBalasan(Balasan balasan);
/* I.S. Sembarang */
/* F.S. Bila alokasi berhasil, terbentuk alokasi node balasan baru
  Bila alokasi gagal, F.S.=I.S. */

#endif