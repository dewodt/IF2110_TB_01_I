#include "stdio.h"
#include "stdlib.h"
#include "../boolean.h"
#include "../charmachine/charmachine.h"
#include "masukan.h"

/* State Mesin MASUKAN */
boolean EndMASUKAN;
MASUKAN currentMASUKAN;
// boolean EOP;
// char currentChar;

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
    currentMASUKAN.Length = 0;
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
  currentMASUKAN.Length = 0;
  while (currentChar != ';') {
    if (i < NMax && currentChar != 10)
    {
      currentMASUKAN.TabMASUKAN[i] = currentChar;
      currentMASUKAN.Length = i + 1;
      i++;
    }
    ADV(); 
  }

  // do
  // {
  //   if (i < NMax && currentChar != 10)
  //   {
  //     currentMASUKAN.TabMASUKAN[i] = currentChar;
  //     currentMASUKAN.Length = i + 1;
  //     i++;
  //   }
  //   ADV();
  // } while (currentChar != ';');
}

void baca(MASUKAN *masukan)
{
  // Menerima input untuk nama, sandi, bio, dll
  STARTMASUKAN();
  *masukan = currentMASUKAN;
}

void perintah(MASUKAN *perintah, MASUKAN *argumen1, MASUKAN *argumen2)
{
  // menerima input perintah beserta dengan argumen-argumennya
  MASUKAN temp;
  STARTMASUKAN();
  temp = currentMASUKAN;
  (*perintah).Length = 0;
  (*argumen1).Length = 0;
  (*argumen2).Length = 0;
  int i, j, k;
  j = 0;
  k = 0;
  for (i = 0; i < temp.Length; i++)
  {
    if ((temp.TabMASUKAN[i] == 32) || (temp.TabMASUKAN[i] == 10))
    {
      if (j != 0)
      {
        k++;
        j = 0;
      }
      else
      {
      }
    }
    else
    {
      if (k == 0)
      {
        (*perintah).TabMASUKAN[j] = temp.TabMASUKAN[i];
        (*perintah).Length++;
        j++;
      }
      else if (k == 1)
      {
        (*argumen1).TabMASUKAN[j] = temp.TabMASUKAN[i];
        (*argumen1).Length++;
        j++;
      }
      else
      {
        (*argumen2).TabMASUKAN[j] = temp.TabMASUKAN[i];
        (*argumen2).Length++;
        j++;
      }
    }
  }
}

boolean isSame(MASUKAN masuk, char string[])
{
  // Membandingkan masuk dengan string
  boolean hasil;
  hasil = true;
  int i;
  i = 0;
  while ((i < masuk.Length) && hasil)
  {
    if (masuk.TabMASUKAN[i] != string[i])
    {
      hasil = false;
    }
    i++;
  }
  return hasil;
}

// Memeriksa apakah masuk hanya berisi spasi
// Mengembalikan true bila semuanya spasi
// Mengembalikan false bila ada yang bukan spasi
boolean isAllSpace(MASUKAN masuk)
{
  boolean allSpace = true;
  int i = 0;
  while ((i < masuk.Length) && allSpace)
  {
    if (masuk.TabMASUKAN[i] != ' ')
    {
      allSpace = false;
    }
    i++;
  }
  return allSpace;
}

void displayMASUKAN(MASUKAN masuk)
{
  // Menampilkan isi masukan
  int i;
  printf("[");
  for (i = 0; i < masuk.Length; i++)
  {
    printf("%c,", masuk.TabMASUKAN[i]);
  }
  printf("]\n");
}

MASUKAN strToMASUKAN(char str[], int len)
{
  int i;
  MASUKAN kata;
  kata.Length = len;
  for (i = 0; i < len; i++)
  {
    kata.TabMASUKAN[i] = str[i];
  }
  return kata;
}

// Mengubah tipe masukan menjadi tipe string
char *MASUKANToStr(MASUKAN masukan)
// Menerima masukan bertipe MASUKAN dan mengembalikan bertipe string (array of char).
{
  char *str = (char *)malloc(sizeof(char) * (masukan.Length + 1));
  int i;
  for (i = 0; i < masukan.Length; i++)
  {
    str[i] = masukan.TabMASUKAN[i];
  }
  str[masukan.Length] = '\0';

  return str;
}

int stringLength(const char *str)
{
  int length = 0;
  while (str[length] != '\0')
  {
    length++;
  }
  return length;
}

boolean isMASUKANEqual(MASUKAN word1, MASUKAN word2)
{
  int i;
  if (word1.Length != word2.Length)
  {
    return false;
  }
  for (i = 0; i < word1.Length; i++)
  {
    if (word1.TabMASUKAN[i] != word2.TabMASUKAN[i])
    {
      return false;
    }
  }
  return true;
}

char *strcpy(char *destination, const char *source)
{
  char *dest_start = destination;
  while (*source != '\0')
  {
    *destination = *source;
    destination++;
    source++;
  }
  *destination = '\0';
  return dest_start;
}

/* Mengembalikan hasil sambungan dari dua string */
char *concatStr(const char *str1, const char *str2)
{
  int len1 = stringLength(str1);
  int len2 = stringLength(str2);
  char *str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
  strcpy(str, str1);
  strcpy(str + len1, str2);
  return str;
}

int compareString(const char *str1, const char *str2, size_t n)
{
  while (n > 0 && *str1 && (*str1 == *str2))
  {
    str1++;
    str2++;
    n--;
  }

  if (n == 0)
  {
    return 0; // string sama hingga n karakter
  }
  else
  {
    return *(unsigned char *)str1 - *(unsigned char *)str2;
  }
}

void toLowerCase(char *str)
{
  while (*str)
  {
    *str = (*str >= 'A' && *str <= 'Z') ? (*str + 32) : *str;
    str++;
  }
}

int masukanToInt(MASUKAN masukan)
{
  int hasil;
  hasil = 0;
  boolean isNeg;
  isNeg = false;
  int i;
  for (i = 0; i < masukan.Length; i++)
  {
    if (i == 0 && i == 45)
    {
      isNeg = true;
    }
    else
    {
      hasil *= 10;
      hasil += masukan.TabMASUKAN[i] - 48;
    }
  }
  if (isNeg)
  {
    hasil *= -1;
  }
  return hasil;
}

boolean isMasukanEmpty(MASUKAN masukan) {
  return masukan.Length == 0;
}