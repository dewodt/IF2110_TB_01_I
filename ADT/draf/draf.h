/* File: charmachine.h */
/* Definisi Mesin Karakter */

#include "stack.h"
#include "wordmachine.h"

#ifndef __DRAF_H__
#define __DRAF_H__

// extern Stack DrafStack;
// extern Word Hapus;
// extern Word Simpan;
// extern Word Terbit;
// extern Word Kembali;
// Hapus.Length = 5;
// Simpan.Length = 6;
// Terbit.Length = 6;
// Kembali.Length = 7;

// Datatype Draf = ADT Kicauan
typedef struct {
  int id; // auto-increment mulai 1
  Word text; // max: 280 char
  int like; // draf reload to 0 or sesuai kicauan sebelumnya?
  // Pengguna author;
  // Time datetime;
} Draf;

void buatDraf(Stack* DrafStack);

void lihatDraf(Stack* DrafStack);

#endif