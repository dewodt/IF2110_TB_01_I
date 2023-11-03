/* File: MASUKANmachine.h */
/* Definisi Mesin MASUKAN: Model Akuisisi Versi I */

#ifndef __MASUKAN_H__
#define __MASUKAN_H__

#include "boolean.h"
#include "../charmachine/charmachine.h"

#define NMax 281
#define BLANK ' '

typedef struct
{
   char TabMASUKAN[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} MASUKAN;

/* State Mesin MASUKAN */
extern boolean EndMASUKAN;
extern MASUKAN currentMASUKAN;


void STARTMASUKAN();
/* I.S. : currentChar sembarang
   F.S. : EndMASUKAN = true, dan currentChar = MARK;
          atau EndMASUKAN = false, currentMASUKAN adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void CopyMASUKAN();
/* Mengakuisisi kata, menyimpan dalam currentMASUKAN
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentMASUKAN berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void baca(MASUKAN* masukan);
// Menerima input untuk nama, sandi, bio, dll

void perintah(MASUKAN* perintah, MASUKAN* argumen1, MASUKAN* argumen2);
// menerima input perintah beserta dengan argumen-argumennya

boolean isSame(MASUKAN masuk, char string[]);
// membandingkan masuk dengan string

void displayMASUKAN(MASUKAN masuk);
// menampilkan isi dari array masuk

#endif