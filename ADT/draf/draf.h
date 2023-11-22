/* File: charmachine.h */
/* Definisi Mesin Karakter */

#ifndef __DRAF_H__
#define __DRAF_H__

#include "../stackdraf/stackdraf.h"

// Pointer to draf of CurrentUser, all parameter in Stack* Draf = &(currentUser->draf)

void createDraf(Draf *Draf, char *text, DATETIME datetime);
/* I.S. Draf sembarang, id, text, author, datetime terdefinisi */
/* Draf terdefinisi */
/* F.S. Draf terdefinisi sesuai parameter */

void prosesDraf(Stack *DrafStack, Draf *DrafInfo);
/**
 * Prosedur untuk 4 perintah MASUKAN yang memproses Draf
 */

void tampilkanDraf(Draf DrafInfo);
/**
 * Prosedur untuk menampilkan informasi draf
 */

void buatDraf(Stack *DrafStack);
/**
 * Prosedur untuk MASUKAN BUAT_DRAF
 */

void lihatDraf(Stack *DrafStack);
/**
 * Prosedur untuk MASUKAN LIHAT_DRAF
 */

void ubahDraf(Stack *DrafStack, Draf *Draft);
/**
 * Prosedur untuk mengubah Draft setelah melihat draf
 */

#endif