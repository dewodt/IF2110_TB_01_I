/* File: charmachine.h */
/* Definisi Mesin Karakter */

#include "./stack/stack.h"
#include "./../masukan/masukan.h"

#ifndef __DRAF_H__
#define __DRAF_H__

// Pointer to draf of CurrentUser

void createDraf(Draf *Draf, char *text, DATETIME datetime);
/* I.S. Draf sembarang, id, text, author, datetime terdefinisi */
/* Draf terdefinisi */
/* F.S. Draf terdefinisi sesuai parameter */

void prosesDraf(Stack* DrafStack, Draf DrafInfo);
/**
 * Prosedur untuk 4 perintah MASUKAN yang memproses Draf
*/

void tampilkanDraf(Draf DrafInfo);
/**
 * Prosedur untuk menampilkan informasi draf
*/

void buatDraf(Stack* DrafStack);
/**
 * Prosedur untuk MASUKAN BUAT_DRAF
*/

void lihatDraf(Stack* DrafStack);
/**
 * Prosedur untuk MASUKAN LIHAT_DRAF
*/

#endif