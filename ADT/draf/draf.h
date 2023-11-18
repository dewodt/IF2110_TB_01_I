/* File: charmachine.h */
/* Definisi Mesin Karakter */

#include "./stack/stack.h"
#include "./../masukan/masukan.h"

#ifndef __DRAF_H__
#define __DRAF_H__

void prosesDraf(Stack* DrafStack, Draf DrafInfo);

void infoDraf(Draf DrafInfo);

void buatDraf(Stack* DrafStack);
/**
 * Prosedur untuk MASUKAN BUAT_DRAF
*/

void lihatDraf(Stack DrafStack);
/**
 * Prosedur untuk MASUKAN LIHAT_DRAF
*/

#endif