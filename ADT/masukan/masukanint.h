/* File: MASUKANmachine.h */
/* Definisi Mesin MASUKAN: Model Akuisisi Versi I */

#ifndef __MASUKANINT_H__
#define __MASUKANINT_H__

#include "../boolean.h"
#include "../charmachine/charmachine.h"

#define NMax 281
#define BLANK ' '

typedef int MASUKANint;

/* State Mesin MASUKAN */
extern boolean EndMASUKANint;
extern MASUKANint currentMASUKANint;


void STARTMASUKANint();
/* I.S. : currentChar sembarang
   F.S. : EndMASUKAN = true, dan currentChar = MARK;
          atau EndMASUKAN = false, currentMASUKAN adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void CopyMASUKANint();
/* Mengakuisisi kata, menyimpan dalam currentMASUKAN
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentMASUKAN berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void bacaInt(int* angka);


#endif