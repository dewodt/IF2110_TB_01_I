#ifndef UTAS_H
#define UTAS_H

#include "../listdinkicauan/listdinkicauan.h"
#include "../masukan/masukan.h"
#include "../listlinierUtas/listlinierForUtas.h"
#include "../listdinUtas/listdinForUtas.h"
#include "../listdinkicauan/listdinkicauan.h"
#include "../boolean.h"
#include "../tree/tree.h"
#include "../matrixteman/matrixteman.h"

#include <stdio.h>

boolean isKicauExistinUtas(Kicauan kicau, ListUtas lu);

int isIdUtasValid(ListUtas li, int idx);

boolean isIndexSambunganValid(threads u, int index);

boolean isUtasUser(UTAS u, User userloggedin);

boolean isKicauanUser(Kicauan k, User userloggedin);

void BUAT_UTAS(ListDinKicauan lk, ListUtas lu, User userloggedIn, int idk);

void SAMBUNG_UTAS(int idU, int index, ListUtas *lu, User userloggedin);

void HAPUS_UTAS(ListUtas *li, int idU, int index, User userloggedin);

void CETAK_UTAS(int idU, ListUtas li, Matrix friendship, ListStatik ListPengguna, User user1, User user2);

#endif