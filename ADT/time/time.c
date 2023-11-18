#include <stdio.h>
#include "time.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid(int H, int M, int S)
{
  boolean isHourValid, isMinuteValid, isSecondValid;
  isHourValid = H >= 0 && H <= 23;
  isMinuteValid = M >= 0 && M <= 59;
  isSecondValid = S >= 0 && S <= 59;
  return isHourValid && isMinuteValid && isSecondValid;
}

void CreateTime(TIME *T, int HH, int MM, int SS)
{
  (*T).HH = HH;
  (*T).MM = MM;
  (*T).SS = SS;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME(TIME *T)
{
  int HH, MM, SS;
  scanf("%d %d %d", &HH, &MM, &SS);
  while (!IsTIMEValid(HH, MM, SS))
  {
    // Print message if not valid
    printf("Jam tidak valid\n");
    scanf("%d %d %d", &HH, &MM, &SS);
  }

  // Time is valid
  CreateTime(T, HH, MM, SS);
}

void TulisTIME(TIME T)
{
  int HH, MM, SS;
  HH = Hour(T);
  MM = Minute(T);
  SS = Second(T);

  printf("%d:%d:%d", HH, MM, SS);
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToDetik(TIME T)
{
  int HH, MM, SS;
  HH = Hour(T);
  MM = Minute(T);
  SS = Second(T);

  return HH * 3600 + MM * 60 + SS;
}

TIME DetikToTIME(long N)
{
  TIME time;
  int HH, MM, SS, remainderTime;

  remainderTime = N % 86400;                       // For N < -86400, reduce it to N > -86400
  remainderTime = (remainderTime + 86400) % 86400; // Get remainder positive values from N

  HH = remainderTime / 3600;
  MM = (remainderTime % 3600) / 60;
  SS = (remainderTime % 3600) % 60;

  CreateTime(&time, HH, MM, SS);

  return time;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
boolean TEQ(TIME T1, TIME T2)
{
  int s1, s2;

  s1 = TIMEToDetik(T1);
  s2 = TIMEToDetik(T2);

  return s1 == s2;
}

boolean TNEQ(TIME T1, TIME T2)
{
  return !TEQ(T1, T2);
}

boolean TLT(TIME T1, TIME T2)
{
  int s1, s2;

  s1 = TIMEToDetik(T1);
  s2 = TIMEToDetik(T2);

  return s1 < s2;
}

boolean TGT(TIME T1, TIME T2)
{
  int s1, s2;

  s1 = TIMEToDetik(T1);
  s2 = TIMEToDetik(T2);

  return s1 > s2;
}

TIME NextDetik(TIME T)
{
  int s;

  s = TIMEToDetik(T);
  s += 1;

  return DetikToTIME(s);
}

TIME NextNDetik(TIME T, int N)
{
  int s;

  s = TIMEToDetik(T);
  s += N;

  return DetikToTIME(s);
}

TIME PrevDetik(TIME T)
{
  int s;

  s = TIMEToDetik(T);
  s -= 1;

  return DetikToTIME(s);
}

TIME PrevNDetik(TIME T, int N)
{
  int s;

  s = TIMEToDetik(T);
  s -= N;

  return DetikToTIME(s);
}

long Durasi(TIME TAw, TIME TAkh)
{
  int sAw, sAkh;
  sAw = TIMEToDetik(TAw);
  sAkh = TIMEToDetik(TAkh);

  return (sAkh - sAw + 86400) % 86400;
}