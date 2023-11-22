/* File: charmachine.h */
/* Definisi Mesin Karakter */

#ifndef __DRAF_H__
#define __DRAF_H__

#include "../stackdraf/stackdraf.h"

// Pointer to draf of CurrentUser, all parameter in Stack* Draf = &(currentUser->draf)

void CreateDraf(Draf *Draf, char *text, DATETIME datetime);
/* I.S. Draf sembarang, id, text, author, datetime terdefinisi */
/* Draf terdefinisi */
/* F.S. Draf terdefinisi sesuai parameter */

void BuatDraf();
/**
 * Prosedur untuk MASUKAN BUAT_DRAF
 */

void LihatDraf();
/**
 * Prosedur untuk MASUKAN LIHAT_DRAF
 */

void DisplayDetailDraf(Draf DrafInfo);
/**
 * Prosedur untuk menampilkan informasi sebuah draf
 */

void HapusDraf(Stack *stackDraf);
/* I.S. stackDraf terdefinisi dan tidak kosong */
/* F.S. elemen stackDraf berkurang satu, yaitu elemen paling atasnya */

void SimpanDraf(Stack *stackDraf, Draf newDraf);
/* I.S. stackDraf terdefinisi dan newDraf terdefinisi */
/* F.S. stack stackDraf bertambah newDraf pada posisi paling atasnya */

void TerbitDraf(Stack *stackDraf);
/* I.S. stackDraf terdefinisi dan tidak kosong */
/* F.S. stackDraf berkurang satu elemennya (paling atas), dan terbentuk elemen baru pada listDinKicauan */

void UbahDraf(Stack *stackDraf);
/*
 * Prosedur untuk mengubah draf
 * I.S. stackDraf terdefinisi dan tidak kosong
 * F.S. 3 kemungkinan:
 *  1. Draf dihapus
 *  2. Draf disimpan
 *  3. Draf diterbitkan
 */

#endif