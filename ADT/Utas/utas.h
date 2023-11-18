#ifndef UTAS_H
#define UTAS_H

#include "../listdinkicauan/listdinkicauan.h"
#include "../../../main.c"
#include "../masukan/masukan.h"
#include "../listlinierUtas/listlinierForUtas.h"
#include "../listdinUtas/listdinForUtas.h"
#include "../boolean.h"

int isIdUtasValid(ListUtas li, int idx);

boolean isIndexSambunganValid(threads u, int index);

boolean isUtasUser(UTAS u);

boolean isKicauanUser(Kicauan k);

void BUAT_UTAS(int idk);

void SAMBUNG_UTAS(int idU, int index, ListUtas *li);

void HAPUS_UTAS(int idU, int index, ListUtas *li);

void CETAK_UTAS(int idU, ListUtas li);

#endif