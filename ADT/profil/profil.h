#ifndef PROFIL_H
#define PROFIL_H

#include "../boolean.h"
#include "../masukan/masukan.h"
#include "../modifiedliststatik/modifiedliststatik.h"
#include "../modifiedmatrix/modifiedmatrix.h"

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
