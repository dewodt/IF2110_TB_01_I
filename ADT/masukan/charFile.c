/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include <stdio.h>
#include "charFile.h"

char currentCharFILE;
//boolean EOP;

static FILE *pita;
static int retval;

void STARTFILE(char* nameFile)
{
  /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
     Karakter pertama yang ada pada pita posisinya adalah pada jendela.
     I.S. : sembarang
     F.S. : currentChar adalah karakter pertama pada pita. Jika currentChar != MARK maka EOP akan padam (false).
            Jika currentChar = MARK maka EOP akan menyala (true) */

  /* Algoritma */
  // FILE* output;
  // printf("%s", nameFile);
  // output = fopen("config/config-1/pengguna.config", "r");
  // if(!output){
  //     printf("error\n");
  // }else{
  //     printf("berhasil\n");
  // }
  pita = fopen(nameFile, "r");
  if (!pita) {
    printf("ERRPOR");
  }
  ADVFILE();
}

void ADVFILE()
{
  /* Pita dimajukan satu karakter.
     I.S. : Karakter pada jendela =
            currentChar, currentChar != MARK
     F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
            currentChar mungkin = MARK.
                  Jika  currentChar = MARK maka EOP akan menyala (true) */

  /* Algoritma */
  retval = fscanf(pita, "%c", &currentCharFILE);
  EOP = (currentCharFILE == MARK);
  if (EOP)
  {
    // fclose(pita);
  }
}