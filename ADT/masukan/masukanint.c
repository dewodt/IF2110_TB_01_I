#include <stdio.h>
#include "../boolean.h"
#include "../charmachine/charmachine.h"
#include "masukanint.h"

/* State Mesin MASUKAN */
boolean EndMASUKANint;
MASUKANint currentMASUKANint;
// boolean EOP;
// char currentChar;

void STARTMASUKANint()
/* I.S. : currentChar sembarang
   F.S. : EndMASUKAN = true, dan currentChar = MARK;
          atau EndMASUKAN = false, currentMASUKAN adalah MASUKAN yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir MASUKAN */
{
  START();
  if (currentChar == ';')
  {
    EndMASUKANint = true;
  }
  else
  {
    EndMASUKANint = false;
    CopyMASUKANint();
  }
}

void CopyMASUKANint()
/* Mengakuisisi MASUKAN, menyimpan dalam currentMASUKAN
   I.S. : currentChar adalah karakter pertama dari MASUKAN
   F.S. : currentMASUKAN berisi MASUKAN yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang MASUKAN melebihi NMax, maka sisa MASUKAN "dipotong" */
{
  int i = 0;
  boolean masukanBenar;
  masukanBenar = true;
  while (currentChar != ';')
  {
    i = i * 10;
    if ((currentChar < 48) || (currentChar > 57))
    {
      if (currentChar != 10)
      {
        masukanBenar = false;
      }
    }
    else
    {
      // printf("%d\n",i);
      int x;
      x = (int)currentChar - 48;
      // printf("%d\n",x);
      i = i + x;
      // printf("%d\n",i);
    }
    ADV();
  }

  if (masukanBenar)
  {
    currentMASUKANint = i;
  }
  else
  {
    currentMASUKANint = -1 * i;
  }
}

void bacaInt(int *masukanint)
{
  // Menerima input untuk nama, sandi, bio, dll
  STARTMASUKANint();
  // printf("%d\n", currentMASUKANint);
  (*masukanint) = currentMASUKANint;
}
