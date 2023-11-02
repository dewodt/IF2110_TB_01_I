/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#ifndef LISTSTATIK_H
#define LISTSTATIK_H

#include "boolean.h"
#include "modifiedmatrix.h"

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
#define MAX_PHONE_NUM_LENGTH 9999 // unlimited, hrs pikir caranya dulu  (long long int)
#define MAX_WETON_LENGTH 10
#define MAX_ACC_TYPE_LENGTH 10


/* Definisi elemen dan koleksi objek */
typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char bio[MAX_BIO_LENGTH];
    char phone_num[MAX_PHONE_NUM_LENGTH];
    char weton[MAX_WETON_LENGTH];
    char acc_type[MAX_ACC_TYPE_LENGTH];
    Matrix profile;
} User; /* type elemen List */
typedef int IdxType;
typedef struct {
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

/* ********** SELEKTOR ********** */
#define ELMT(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l);

int listLength(ListStatik l);

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l);

/* *** Test List penuh *** */
boolean isFull(ListStatik l);


void printList(ListStatik l);

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, User user);

#endif
