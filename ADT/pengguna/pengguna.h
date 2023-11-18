#ifndef PENGGUNA_H
#define PENGGUNA_H

#include "../boolean.h"
#include "../masukan/masukan.h"
#include "../modifiedliststatik/modifiedliststatik.h"
#include "../modifiedmatrix/modifiedmatrix.h"

// Mengembalikan true bila user sudah login dan mengembalikan false bila user belum login
boolean isUserLoggedIn();
// Jika global variable currentUser NULL maka belum login
// Jika global variable currentUser tidak NULL maka sudah login (pointer ke user yang sedang login)

// mendaftarkan pengguna
void DAFTAR(ListStatik *pengguna, boolean *isLoggedin);
// I.S.
// F.S.

// masuk sebagai pengguna
boolean MASUK(ListStatik *pengguna, boolean *isLoggedin, User *currentUser);
// I.S.
// F.S.

// keluar dari akun pengguna
boolean KELUAR(boolean *isLoggedin);
// I.S.
// F.S.

// ganti profil (nama, bio akun, no HP, weton)
void GANTI_PROFIL(ListStatik *pengguna, boolean *isLoggedIn, User *currentUser);
// I.S.
// F.S.

// lihat profil pengguna
void LIHAT_PROFIL(ListStatik *pengguna, MASUKAN namapengguna);
// I.S.
// F.S.

// ganti profile
void UBAH_FOTO_PROFIL(ListStatik *pengguna, boolean *isLoggedIn, User *currentUser);
// I.S.
// F.S.

// atur jenis akun
void ATUR_JENIS_AKUN(ListStatik *pengguna, boolean *isLoggedIn, User *currentUser);
// I.S.
// F.S.

#endif