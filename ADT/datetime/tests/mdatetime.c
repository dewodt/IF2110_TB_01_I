#include "stdio.h"
#include "../datetime.h"
#

int main()
{
  // Create DateTime
  DATETIME InitDT;
  // Input datetime, createDateTimeisDateTimeValid (sudah include)
  BacaDATETIME(&InitDT);
  // Tulis date time
  TulisDATETIME(InitDT);

  // Get max day
  int M, Y;
  printf("Masukkan bulan dan tahun M Y");
  scanf("%d %d", &M, &Y);
  printf("Max day: %d\n", GetMaxDay(M, Y));

  // Get current local date time
  DATETIME CDT;
  GetCurrentLocalDATETIME(&CDT);
  TulisDATETIME(CDT);

  // Comparison Date
  DATETIME D1, D2;
  BacaDATETIME(&D1);
  BacaDATETIME(&D2);
  printf("D1 < D2: %d\n", DLT(D1, D2));
  printf("D1 > D2: %d\n", DGT(D1, D2));
  printf("D1 == D2: %d\n", DLT(D1, D2) == DGT(D1, D2));
  printf("D1 != D2: %d\n", DLT(D1, D2) != DGT(D1, D2));

  // Next N Detik
  int N;
  DATETIME DNDETIK;
  printf("Masukkan N: ");
  scanf("%d", &N);
  DNDETIK = DATETIMENextNDetik(InitDT, N);
  TulisDATETIME(DNDETIK);

  // Prev N Detik
  DATETIME PNDETIK;
  printf("Masukkan N: ");
  scanf("%d", &N);
  PNDETIK = DATETIMEPrevNDetik(InitDT, N);
  TulisDATETIME(PNDETIK);

  return 0;
}