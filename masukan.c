#include "masukan.h"
#include "charmachine.h"
#include "boolean.h"
#include <stdio.h>

/* State Mesin MASUKAN */
boolean EndMASUKAN;
MASUKAN currentMASUKAN;
boolean EOP;
char currentChar;


void STARTMASUKAN()
/* I.S. : currentChar sembarang
   F.S. : EndMASUKAN = true, dan currentChar = MARK;
          atau EndMASUKAN = false, currentMASUKAN adalah MASUKAN yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir MASUKAN */
{
  START();
  if (currentChar == ';')
  {
    EndMASUKAN = true;
  }
  else
  {
    EndMASUKAN = false;
    CopyMASUKAN();
  }
}


void CopyMASUKAN()
/* Mengakuisisi MASUKAN, menyimpan dalam currentMASUKAN
   I.S. : currentChar adalah karakter pertama dari MASUKAN
   F.S. : currentMASUKAN berisi MASUKAN yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang MASUKAN melebihi NMax, maka sisa MASUKAN "dipotong" */
{
  int i = 0;
  do
  {
    currentMASUKAN.TabMASUKAN[i] = currentChar;
    ADV();
    i += 1;
  } while (currentChar != ';' && i < NMax); 
  currentMASUKAN.Length = i;
}

void baca(MASUKAN* masukan){
// Menerima input untuk nama, sandi, bio, dll
    STARTMASUKAN();
    *masukan = currentMASUKAN;
    if((*masukan).TabMASUKAN[0] == 10){
        int i;
        for (i = 1; i < (*masukan).Length; i++)
        {
            (*masukan).TabMASUKAN[i-1] = (*masukan).TabMASUKAN[i];
        }
        (*masukan).Length = (*masukan).Length-1;
    }else{

    }
}

void perintah(MASUKAN* perintah, MASUKAN* argumen1, MASUKAN* argumen2){
// menerima input perintah beserta dengan argumen-argumennya
  MASUKAN temp;
  STARTMASUKAN();
  temp = currentMASUKAN;
  int i,j,k;
  j = 0;
  k = 0;
  for ( i = 0; i < temp.Length; i++)
  {
    if((temp.TabMASUKAN[i] == 32) || (temp.TabMASUKAN[i]  == 10)){
      if(j != 0){
        k ++;
        j = 0;
      }else{

      }
    }else{
      if(k == 0){
        (*perintah).TabMASUKAN[j] = temp.TabMASUKAN[i];
        j++;
      }else if(k == 1){
        (*argumen1).TabMASUKAN[j] = temp.TabMASUKAN[i];
        j++;
      }else{
        (*argumen2).TabMASUKAN[j] = temp.TabMASUKAN[i];
        j++;
      }
    }
  }
  
  
}
boolean isSame(MASUKAN masuk, char string[]){
    // Membandingkan masuk dengan string
    boolean hasil;
    hasil = true;
    int i;
    i = 0;
    while ((i < masuk.Length) && hasil)
    {
        if(masuk.TabMASUKAN[i] != string[i]){
            hasil = false;
        }
        i ++;
    }
    return hasil;
}

void displayMASUKAN(MASUKAN masuk){
    // Menampilkan isi masukan
    int i;
    printf("[");
    for ( i = 0; i <  masuk.Length; i++)
    {
        printf("%c,", masuk.TabMASUKAN[i]);
    }
    printf("]\n");
    
}