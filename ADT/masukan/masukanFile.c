#include "stdio.h"
#include "stdlib.h"
#include "../boolean.h"

#include "../modifiedliststatik/modifiedliststatik.h"
#include "masukanFile.h"

/* State Mesin MASUKANFILE */
boolean EndMASUKANFILE;
MASUKANFILE currentMASUKANFILE;
//boolean EOP;
//char currentChar;

void STARTMASUKANFILE(char nameFile[])
/* I.S. : currentChar sembarang
   F.S. : EndMASUKANFILE = true, dan currentChar = MARK;
          atau EndMASUKANFILE = false, currentMASUKANFILE adalah MASUKANFILE yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir MASUKANFILE */
{
  STARTFILE(nameFile);
  if (currentCharFILE == 10)
  {
    EndMASUKANFILE = true;
  }
  else
  {
    EndMASUKANFILE = false;
    CopyMASUKANFILE();
  }
}

void ADVMASUKANFILE()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentMASUKANFILE adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndMASUKANFILE = true.
   Proses : Akuisisi kata menggunakan procedure SalinMASUKANFILE */
{
  if (currentCharFILE == MARK)
  {
    EndMASUKANFILE = true;
  }
  else
  {
    CopyMASUKANFILE();
  }
}

void CopyMASUKANFILE()
/* Mengakuisisi MASUKANFILE, menyimpan dalam currentMASUKANFILE
   I.S. : currentChar adalah karakter pertama dari MASUKANFILE
   F.S. : currentMASUKANFILE berisi MASUKANFILE yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang MASUKANFILE melebihi NMax, maka sisa MASUKANFILE "dipotong" */
{
  int i = 0;
  do
  {
    currentMASUKANFILE.TabMASUKANFILE[i] = currentCharFILE;
    ADVFILE();
    i += 1;
  } while (currentCharFILE != 10 && i < NMax);
  currentMASUKANFILE.Length = i;
}

int masukanFileToInt(MASUKANFILE masukanFile){
  int hasil;
  hasil = 0;
  int i;
  for ( i = 0; i < masukanFile.Length; i++)
  {
    hasil *= 10;
    hasil += masukanFile.TabMASUKANFILE[i] - 48;
  }
  return hasil;
}

void bacaAwalFile(MASUKANFILE *MASUKANFILE)
{
  // Menerima input untuk nama, sandi, bio, dll
  STARTMASUKANFILE("file.txt");
  *MASUKANFILE = currentMASUKANFILE;
  if ((*MASUKANFILE).TabMASUKANFILE[0] == 10)
  {
    int i;
    for (i = 1; i < (*MASUKANFILE).Length; i++)
    {
      (*MASUKANFILE).TabMASUKANFILE[i - 1] = (*MASUKANFILE).TabMASUKANFILE[i];
    }
    (*MASUKANFILE).Length = (*MASUKANFILE).Length - 1;
  }
  else
  {
  }
  
}

void bacaLanjutFile(MASUKANFILE *MASUKANFILE)
{
  // Menerima input untuk nama, sandi, bio, dll
  ADVMASUKANFILE();
  *MASUKANFILE = currentMASUKANFILE;
  if ((*MASUKANFILE).TabMASUKANFILE[0] == 10)
  {
    int i;
    for (i = 1; i < (*MASUKANFILE).Length; i++)
    {
      (*MASUKANFILE).TabMASUKANFILE[i - 1] = (*MASUKANFILE).TabMASUKANFILE[i];
    }
    (*MASUKANFILE).Length = (*MASUKANFILE).Length - 1;
  }
  else
  {
  }
}

boolean isSameFile(MASUKANFILE masuk, char string[])
{
  // Membandingkan masuk dengan string
  boolean hasil;
  hasil = true;
  int i;
  i = 0;
  while ((i < masuk.Length) && hasil)
  {
    if (masuk.TabMASUKANFILE[i] != string[i])
    {
      hasil = false;
    }
    i++;
  }
  return hasil;
}


void displayMASUKANFILE(MASUKANFILE masuk)
{
  // Menampilkan isi MASUKANFILE
  int i;
  printf("[");
  for (i = 0; i < masuk.Length; i++)
  {
    printf("%c,", masuk.TabMASUKANFILE[i]);
  }
  printf("]\n");
}

MASUKAN masukanFileToMasukan(MASUKANFILE masukanFile){
  MASUKAN hasil;
  hasil.Length = masukanFile.Length;
  int i;
  for ( i = 0; i < masukanFile.Length; i++)
  {
    hasil.TabMASUKAN[i] = masukanFile.TabMASUKANFILE[i];
  }
  
  return hasil;
}

// void MASUKANFILEToStr(MASUKANFILE masukanFile, char *str[])
// {
//   int len = masukanFile.Length;
//   int i;

//   for (i = 0; i < len; i++)
//   {
//     // printf("%c\n", masukan.TabMASUKAN[i]);
//     str[i] = masukanFile.TabMASUKANFILE[i];
//   }
//   str[len] = '\0';
// }

void bacaPengguna(ListStatik* listPengguna){
  MASUKANFILE masukanFile;
  bacaAwalFile(&masukanFile);
  int n;
  n = masukanFileToInt(masukanFile);
  int i;
  for ( i = 0; i < n; i++)
  {
    bacaLanjutFile(&masukanFile);
    displayMASUKANFILE(masukanFile);
    int j;
    for ( j = 0; j < masukanFile.Length; j++)
    {
      listPengguna->contents[i].username[j] = masukanFile.TabMASUKANFILE[j];
    }
    
    bacaLanjutFile(&masukanFile);
    displayMASUKANFILE(masukanFile);
    int k;
    for ( k = 0; k < masukanFile.Length; k++)
    {
      listPengguna->contents[i].password[k] = masukanFile.TabMASUKANFILE[k];   
    }


    bacaLanjutFile(&masukanFile);
    displayMASUKANFILE(masukanFile);
    int l;
    for ( l = 0; l < masukanFile.Length; l++)
    {
      listPengguna->contents[i].bio[l] = masukanFile.TabMASUKANFILE[l];
    }
  
    bacaLanjutFile(&masukanFile);
    displayMASUKANFILE(masukanFile);
    listPengguna->contents[i].phone_num = masukanFileToMasukan(masukanFile);

    bacaLanjutFile(&masukanFile);
    displayMASUKANFILE(masukanFile);
    int a;
    for ( a = 0; a < masukanFile.Length; a++)
    {
      listPengguna->contents[i].weton[a] = masukanFile.TabMASUKANFILE[a];
    }
    
    bacaLanjutFile(&masukanFile);
    displayMASUKANFILE(masukanFile);
    int b;
    for ( b = 0; b < masukanFile.Length; b++)
    {
      listPengguna->contents[i].acc_type[b] = masukanFile.TabMASUKANFILE[b];
    }
    int c;
    for ( c = 0; c < 5; c++)
    {
      bacaLanjutFile(&masukanFile);
      displayMASUKANFILE(masukanFile);
      int d;
      for ( d = 0; d < 10; d++)
      {
        ELMT_MTX(listPengguna->contents[i].profile,c,d) = masukanFile.TabMASUKANFILE[2*(d)];
      }
    }
  }
}