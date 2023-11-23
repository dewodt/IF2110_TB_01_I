#ifndef PENGGUNA_H
#define PENGGUNA_H

#include "../boolean.h"
#include "../masukan/masukan.h"
#include "../modifiedliststatik/modifiedliststatik.h"
#include "../modifiedmatrix/modifiedmatrix.h"

/* Global variable menyimpan state user yang sedang masuk */
/* Saat program jalan, bernilai null */
/* Saat user login, bernilai pointer ke user yang sedang login */
extern User *currentUser;

// Mengembalikan true bila user sudah login dan mengembalikan false bila user belum login
boolean isUserLoggedIn();
// Jika global variable currentUser NULL maka belum login
// Jika global variable currentUser tidak NULL maka sudah login (pointer ke user yang sedang login)

// mendaftarkan pengguna
void DAFTAR(ListStatik *pengguna);
// I.S.
// F.S.

// masuk sebagai pengguna
void MASUK(ListStatik *pengguna, User **currentUser);
// I.S.
// F.S.

// keluar dari akun pengguna
void KELUAR(User **currentUser);
// I.S.
// F.S.

// ganti profil (nama, bio akun, no HP, weton)
void GANTI_PROFIL(ListStatik *pengguna, User *currentUser);
// I.S.
// F.S.

// lihat profil pengguna
void LIHAT_PROFIL(ListStatik *pengguna, MASUKAN namapengguna);
// I.S.
// F.S.

// ganti profile
void UBAH_FOTO_PROFIL(ListStatik *pengguna, User *currentUser);
// I.S.
// F.S.

// atur jenis akun
void ATUR_JENIS_AKUN(ListStatik *pengguna, User *currentUser);
// I.S.
// F.S.

#endif