#include <stdio.h>
#include <time.h>
#include "datetime.h"

int GetMaxDay(int M, int Y)
/* Mengirimkan jumlah hari maksimum pada bulan M dan tahun Y */
/* Prekondisi: 1 <= M <= 12*/
/* Hint: Perhatikan Leap Year. Leap Year adalah tahun dengan 29 hari pada bulan Februari */
/* Aturan Leap Year: */
/* 1. Jika angka tahun itu habis dibagi 400, maka tahun itu sudah pasti tahun kabisat. 8*/
/* 2. Jika angka tahun itu tidak habis dibagi 400 tetapi habis dibagi 100, maka tahun itu sudah pasti bukan merupakan tahun kabisat. */
/* 3. Jika angka tahun itu tidak habis dibagi 400, tidak habis dibagi 100 akan tetapi habis dibagi 4, maka tahun itu merupakan tahun kabisat. */
/* 4. Jika angka tahun tidak habis dibagi 400, tidak habis dibagi 100, dan tidak habis dibagi 4, maka tahun tersebut bukan merupakan tahun kabisat. */

{
  if (M == 2)
  {
    // Century leap year
    if (Y % 400 == 0)
      return 29;

    // Century Non leap year
    if (Y % 100 == 0)
      return 28;

    // Non century
    if (Y % 4 == 0)
    {
      return 29;
    }
    else
    {
      return 28;
    }
  }
  else if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12)
  {
    return 31;
  }
  else
  {
    return 30;
  }
}

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s)
/* Mengirim true jika D,M,Y,h,m,s dapat membentuk D yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah DATETIME */
{
  boolean isTimeValid, isDayValid, isMonthValid, isYearValid;

  isTimeValid = IsTIMEValid(h, m, s);

  isMonthValid = M >= 1 && M <= 12;

  isDayValid = D >= 1 && D <= GetMaxDay(M, Y);

  isYearValid = Y >= 1900 && Y <= 2030;

  return isTimeValid && isDayValid && isMonthValid && isYearValid;
}

void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss)
/* Membentuk sebuah DATETIME dari komponen-komponennya yang valid */
/* Prekondisi : DD, MM, YYYY, h, m, s valid untuk membentuk DATETIME */
{
  Year(*D) = YYYY;
  Month(*D) = MM;
  Day(*D) = DD;
  CreateTime(&Time(*D), hh, mm, ss);
}

/* Dapatkan Date Time Local (Sekarang) */
void GetCurrentLocalDATETIME(DATETIME *D)
/* I.S. DateTime sembarang */
/* F.S. DateTime merupakan DateTime local sekarang */
{
  // Dapatkan waktu dari library time.h
  time_t rawtime;
  struct tm *timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  int DD = timeinfo->tm_mday;
  int MM = timeinfo->tm_mon + 1;
  int YYYY = timeinfo->tm_year + 1900;
  int hh = timeinfo->tm_hour;
  int mm = timeinfo->tm_min;
  int ss = timeinfo->tm_sec;

  // Dapatkan waktu kicauan
  CreateDATETIME(D, DD, MM, YYYY, hh, mm, ss);
}

void BacaDATETIME(DATETIME *D)
/* I.S. : D tidak terdefinisi */
/* F.S. : D terdefinisi dan merupakan DATETIME yang valid */
/* Proses : mengulangi membaca komponen DD, MM, YY, h, m, s sehingga membentuk D */
/* yang valid. Tidak mungkin menghasilkan D yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen DD, MM, YY, h, m, s
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika DATETIME tidak valid maka diberikan pesan: "DATETIME tidak valid", dan pembacaan
    diulangi hingga didapatkan DATETIME yang valid. */
/* Contoh:
    32 13 2023 12 34 56
    DATETIME tidak valid
    31 12 2023 12 34 56
    --> akan terbentuk DATETIME <31,12,2023,12,34,56> */
{
  int dd, mm, yy, h, m, s;

  scanf("%d %d %d %d %d %d", &dd, &mm, &yy, &h, &m, &s);
  while (!IsDATETIMEValid(dd, mm, yy, h, m, s))
  {
    printf("DATETIME tidak valid\n");
    scanf("%d %d %d %d %d %d", &dd, &mm, &yy, &h, &m, &s);
  }

  CreateDATETIME(D, dd, mm, yy, h, m, s);
}

void TulisDATETIME(DATETIME D)
/* I.S. : D sembarang */
/* F.S. : Nilai D ditulis dg format DD/MM/YYYY HH:MM:SS */
/* Proses : menulis nilai setiap komponen D ke layar dalam format DD/MM/YYYY HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
{
  printf("%d/%d/%d %02d:%02d:%02d", Day(D), Month(D), Year(D), Hour(Time(D)), Minute(Time(D)), Second(Time(D)));
}

boolean DEQ(DATETIME D1, DATETIME D2)
/* Mengirimkan true jika D1=D2, false jika tidak */
{
  return Day(D1) == Day(D2) && Month(D1) == Month(D2) && Year(D1) == Year(D2) && TEQ(Time(D1), Time(D2));
}

boolean DNEQ(DATETIME D1, DATETIME D2)
/* Mengirimkan true jika D1 tidak sama dengan D2 */
{
  return !DEQ(D1, D2);
}

// Get isKabisat
boolean IsKabisat(int Y)
{
  if (Y % 400 == 0)
    return true;

  if (Y % 100 == 0)
    return false;

  return Y % 4 == 0;
}

// Datetime to detik
// Date time yang diukur dari 1/1/1900 00:00:00
long long int DATETIMEToDetik(DATETIME D)
{
  long long int total = 0;

  // Time
  total += TIMEToDetik(Time(D));

  // Day
  total += (Day(D) - 1) * 24 * 3600;

  // Month
  int i;
  for (i = 1; i < Month(D); i++)
  {
    total += GetMaxDay(i, Year(D)) * 24 * 3600;
  }

  // Year
  int j;
  for (j = 1900; j < Year(D); j++)
  {
    total += (IsKabisat(j) ? 366 : 365) * 24 * 3600;
  }

  return total;
}

// Get detik to datetime
// Detik dari 1/1/1900 ke datetime
DATETIME DetikToDATETIME(long long int N)
{
  // Get year
  int year = 1900;
  while (N >= (IsKabisat(year) ? 366 : 365) * 24 * 3600)
  {
    N -= (IsKabisat(year) ? 366 : 365) * 24 * 3600;
    year++;
  }

  // Get month
  int month = 1;
  while (N >= GetMaxDay(month, year) * 24 * 3600)
  {
    N -= GetMaxDay(month, year) * 24 * 3600;
    month++;
  }

  // Get day
  int day = 1;
  while (N >= 24 * 3600)
  {
    N -= 24 * 3600;
    day++;
  }

  // Get time
  TIME time = DetikToTIME(N);

  // Create datetime
  DATETIME datetime;
  CreateDATETIME(&datetime, day, month, year, Hour(time), Minute(time), Second(time));

  return datetime;
}

boolean DLT(DATETIME D1, DATETIME D2)
/* Mengirimkan true jika D1<D2, false jika tidak */
{
  return DATETIMEToDetik(D1) < DATETIMEToDetik(D2);
}

boolean DGT(DATETIME D1, DATETIME D2)
/* Mengirimkan true jika D1>D2, false jika tidak */
{
  return DATETIMEToDetik(D1) > DATETIMEToDetik(D2);
}

DATETIME DATETIMENextNDetik(DATETIME D, int N)
/* Mengirim salinan D dengan detik ditambah N */
{
  // Hitung banyaknya tahun terlewat
  long long int total = DATETIMEToDetik(D) + (long long int)N;
  return DetikToDATETIME(total);
}

DATETIME DATETIMEPrevNDetik(DATETIME D, int N)
/* Mengirim salinan D dengan detik dikurang N */
/* *** Kelompok Operator Aritmetika terhadap DATETIME *** */
{
  // Hitung banyaknya tahun terlewat
  long long int total = DATETIMEToDetik(D) - (long long int)N;
  return DetikToDATETIME(total);
}

long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh)
/* Mengirim DAkh-DAw dlm Detik, dengan kalkulasi */
/* Prekondisi: DAkh > DAw */
{
  return (long int)(DATETIMEToDetik(DAkh) - DATETIMEToDetik(DAw));
}