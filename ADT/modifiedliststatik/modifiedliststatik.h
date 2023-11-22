/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#ifndef MODIFIEDLISTSTATIK_H
#define MODIFIEDLISTSTATIK_H

#include <stdio.h>
#include "../boolean.h"
#include "../modifiedliststatik/modifiedliststatik.h"
#include "../modifiedmatrix/modifiedmatrix.h"
#include "../masukan/masukan.h"
#include "../pcolor/pcolor.h"
// #include "../draf/stack/stack.h"

/*  Kamus Umum */
#define CAPACITY 20
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

#define MAX_USERS 20
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_BIO_LENGTH 135
#define MAX_WETON_LENGTH 10
#define MAX_ACC_TYPE_LENGTH 10

/* Definisi elemen dan koleksi objek */
typedef struct
{
   char username[MAX_USERNAME_LENGTH];
   char password[MAX_PASSWORD_LENGTH];
   char bio[MAX_BIO_LENGTH];
   MASUKAN phone_num;
   char weton[MAX_WETON_LENGTH];
   char acc_type[MAX_ACC_TYPE_LENGTH];
   Matrix profile;
   char jenis_akun[6];
   boolean isPrivate;
   // Stack draf;
} User; /* type elemen List */
typedef int IdxType;
typedef struct
{
   User contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
} ListStatik;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListStatik, cara deklarasi dan akses: */
/* Deklarasi : l : ListStatik */
/* Maka cara akses:
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi :
   List kosong: semua elemen bernilai MARK
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* Global variable menyimpan user dalam list statik */
extern ListStatik listUser;

/* ********** SELEKTOR ********** */
#define ELMT(l, i) (l).contents[(i)]
#define USERNAME(l, i) (l).contents[(i)].username
#define PASSWORD(l, i) (l).contents[(i)].password
#define BIO(l, i) (l).contents[(i)].bio
#define PHONE_NUM(l, i) (l).contents[(i)].phone_num
#define WETON(l, i) (l).contents[(i)].weton
#define ACC_TYPE(l, i) (l).contents[(i)].acc_type
#define PROFILE(l, i) (l).contents[(i)].profile
#define JENIS_AKUN(l, i) (l).contents[(i)].jenis_akun
#define DRAF(l, i) (l).contents[(i)].draf

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l);
// I.S.
// F.S.

int listLength(ListStatik l);
// I.S.
// F.S.

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l);
// I.S.
// F.S.

/* *** Test List penuh *** */
boolean isFull(ListStatik l);
// I.S.
// F.S.

void printList(ListStatik *pengguna);
// I.S.
// F.S.

void SetPhoneNum(ListStatik *l, int userIndex, MASUKAN nohp);
// I.S.
// F.S.

void SetBio(ListStatik *l, int userIndex, const char *bio);
// I.S.
// F.S.

void SetWeton(ListStatik *l, int userIndex, const char *weton);
// I.S.
// F.S.

void SetProfile(ListStatik *l, int userIndex, Matrix *profile);
// I.S.
// F.S.

void SetIsPrivate(ListStatik *l, int userIndex, boolean *status);
// I.S.
// F.S.
#endif