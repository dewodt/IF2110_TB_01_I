/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#ifndef LISTSTATIK_H
#define LISTSTATIK_H

#include <stdio.h>
#include "boolean.h"
#include "modifiedliststatik.h"
#include "modifiedmatrix.h"
#include "./ADT/charmachine/charmachine.h"
#include "./ADT/pcolor/pcolor.h"
#include "functions.c"

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
typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char bio[MAX_BIO_LENGTH];
    MASUKAN phone_num;
    char weton[MAX_WETON_LENGTH];
    char acc_type[MAX_ACC_TYPE_LENGTH];
    Matrix profile;
    char jenis_akun[6];
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
void CreateListStatik(ListStatik *l) {
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        strcpy(ELMT(*l, i).username, "");
        strcpy(ELMT(*l, i).password, "");
        strcpy(ELMT(*l, i).bio, "");
        strcpy(ELMT(*l, i).weton, "");
        strcpy(ELMT(*l, i).acc_type, "");
        createMatrix(5, 10, &(ELMT(*l, i).profile));
        strcpy(ELMT(*l, i).jenis_akun, "1");
    }
}

int listLength(ListStatik l) {
    int i;
    int count = 0;
    for (i = 0; i < MAX_USERS; i++) {
        if (ELMT(l, i).username[0] != '\0') {
            count += 1;
        }
    }
    return count;
} 

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l) {
    /* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    if (listLength(l) == 0) {
        return true;
    }
    else {
        return false;
    }
}

/* *** Test List penuh *** */
boolean isFull(ListStatik l) {
    /* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    if (listLength(l) == CAPACITY) {
        return true;
    }
    else {
        return false;
    }
}

void printList(ListStatik *pengguna) {
    int i;
    printf("[");
    for (i = 0; i < listLength(*pengguna); i++) {
        printf("%s", ELMT(*pengguna, i).username);
        if (i < listLength(*pengguna) - 1) {
            printf(",");
        }
    }
    printf("]");
}

void SetPhoneNum(ListStatik *l, int userIndex, MASUKAN nohp) {
    if (userIndex >= 0 && userIndex < MAX_USERS) {
        ELMT(*l, userIndex).phone_num = nohp;
    }
}

void SetBio(ListStatik *l, int userIndex, const char *bio) {
    if (userIndex >= 0 && userIndex < MAX_USERS) {
        strcpy(ELMT(*l, userIndex).bio, bio);
    }
}

void SetWeton(ListStatik *l, int userIndex, const char *weton) {
    if (userIndex >= 0 && userIndex < MAX_USERS) {
        strcpy(ELMT(*l, userIndex).weton, weton);
    }
}

void SetProfile(ListStatik *l, int userIndex, Matrix *profile) {
    if (userIndex >= 0 && userIndex < MAX_USERS) {
        ELMT(*l, userIndex).profile = *profile;
    }
}



#endif

// TES

// int main() {
//     ListStatik l;
//     CreateListStatik(&l);
//     printf("list length: %d\n", listLength(l));

//     char username_temp[MAX_USERNAME_LENGTH];
//     printf("Masukkan nama: ");
//     fgets(username_temp, MAX_USERNAME_LENGTH, stdin);
//     username_temp[strcspn(username_temp, "\n")] = '\0';
//     strcpy(ELMT(l, 0).username, username_temp);
//     printList(l);
//     printf("list length: %d\n", listLength(l));
// }