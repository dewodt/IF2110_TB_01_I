#include "stdio.h"
#include "../time.h"

int main()
{
  // Create TIME
  TIME time;
  // Input time, createTimeisTimeValid (sudah include)
  BacaTIME(&time);

  // Tulis time
  TulisTIME(time);

  // Comparison time
  TIME T1, T2;
  BacaTIME(&T1);
  BacaTIME(&T2);
  printf("T1 < T2: %d\n", TLT(T1, T2));
  printf("T1 > T2: %d\n", TGT(T1, T2));
  printf("T1 == T2: %d\n", TLT(T1, T2) == TGT(T1, T2));
  printf("T1 != T2: %d\n", TLT(T1, T2) != TGT(T1, T2));

  // Time to Detik
  TIME T3;
  BacaTIME(&T3);
  printf("Time to detik: %d\n", TIMEToDetik(T3));

  // Detik to time
  int detik;
  printf("Masukkan detik: ");
  scanf("%d", &detik);
  TIME T4;
  T4 = DetikToTIME(detik);
  TulisTIME(T4);

  // Next N Detik
  int N;
  TIME DNDETIK;
  printf("Masukkan N: ");
  scanf("%d", &N);
  DNDETIK = NextNDetik(time, N);
  TulisTIME(DNDETIK);

  // Prev N Detik
  TIME PNDETIK;
  printf("Masukkan N: ");
  scanf("%d", &N);
  PNDETIK = PrevNDetik(time, N);
  TulisTIME(PNDETIK);

  return 0;
}