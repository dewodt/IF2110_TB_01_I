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
#include "../teman/teman.h"
#include "../pengguna/pengguna.h"

#include <stdio.h>

boolean isKicauExistinUtas(AddressKicauan kicau);

int isIdUtasValid(int idx);

boolean isIndexSambunganValid(threads u, int index);

boolean isUtasUser(UTAS u);

boolean isKicauanUser(AddressKicauan k);

void BUAT_UTAS(int idk);

void SAMBUNG_UTAS(int idU, int index);

void HAPUS_UTAS(int idU, int index);

void CETAK_UTAS(int idU);

#endif