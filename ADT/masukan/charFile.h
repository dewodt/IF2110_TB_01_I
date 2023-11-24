/* File: charmachine.h */
/* Definisi Mesin Karakter */

#ifndef __CHAR_FILE_H__
#define __CHAR_FILE_H__

#include "../boolean.h"

#define MARK '.'
/* State Mesin */
extern char currentCharFILE;
extern boolean EOP;

void STARTFILE(char* nameFile);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADVFILE();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

#endif