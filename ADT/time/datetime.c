/* File: datetime.h */
/* Tanggal: 30 Agustus 2023 */
/* Definisi ADT DATETIME */

#ifndef DATETIME_H
#define DATETIME_H

#include "boolean.h"
#include "time.h"
#include <stdio.h>

/* *** Definisi TYPE DATETIME <DD/MM/YY HH:MM:SS> *** */
typedef struct
{
    int DD;   /* integer [1..31] */
    int MM;   /* integer [1..12] */
    int YYYY; /* integer [1900..2030] */
    TIME T;
} DATETIME;

/* *** Notasi Akses: selektor DATETIME *** */
#define Day(D) (D).DD
#define Month(D) (D).MM
#define Year(D) (D).YYYY
#define Time(D) (D).T

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */

int GetMaxDay(int M, int Y)
{
    if ((M == 1) || (M == 3) || (M == 5) || (M == 7) || (M == 8) || (M == 10) || (M == 12))
    {
        return 31;
    }
    else if ((M == 4) || (M == 6) || (M == 9) || (M == 11))
    {
        return 30;
    }
    else if (M == 2)
    {
        if (((Y % 4 == 0) && (Y % 100 != 0)) || (Y % 400 == 0))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    else
    {
        return 0;
    }
}
/* Mengirimkan jumlah hari maksimum pada bulan M dan tahun Y */
/* Prekondisi: 1 <= M <= 12*/
/* Hint: Perhatikan Leap Year. Leap Year adalah tahun dengan 29 hari pada bulan Februari */
/* Aturan Leap Year: */
/* 1. Jika angka tahun itu habis dibagi 400, maka tahun itu sudah pasti tahun kabisat. */
/* 2. Jika angka tahun itu tidak habis dibagi 400 tetapi habis dibagi 100, maka tahun itu sudah pasti bukan merupakan tahun kabisat. */
/* 3. Jika angka tahun itu tidak habis dibagi 400, tidak habis dibagi 100 akan tetapi habis dibagi 4, maka tahun itu merupakan tahun kabisat. */
/* 4. Jika angka tahun tidak habis dibagi 400, tidak habis dibagi 100, dan tidak habis dibagi 4, maka tahun tersebut bukan merupakan tahun kabisat. */

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s)
{
    return (((D > 0) && (D <= GetMaxDay(M, Y))) && ((M > 0) && (M <= 12)) && ((Y >= 1900) && (Y <= 2030)) && ((h >= 0) && (h <= 23)) && ((m >= 0) && (m <= 59)) && ((s >= 0) && (s <= 59)));
}
/* Mengirim true jika D,M,Y,h,m,s dapat membentuk D yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah DATETIME */

/* *** Konstruktor: Membentuk sebuah DATETIME dari komponen-komponennya *** */
void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss)
{
    TIME T;
    Day(*D) = DD;
    Month(*D) = MM;
    Year(*D) = YYYY;
    CreateTime(&T, hh, mm, ss);
    Time(*D) = T;
}
/* Membentuk sebuah DATETIME dari komponen-komponennya yang valid */
/* Prekondisi : DD, MM, YYYY, h, m, s valid untuk membentuk DATETIME */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaDATETIME(DATETIME *D)
{
    int DD, MM, YYYY, hh, mm, ss;
    scanf("%d %d %d %d %d %d", &DD, &MM, &YYYY, &hh, &mm, &ss);
    while (!(IsDATETIMEValid(DD, MM, YYYY, hh, mm, ss)))
    {
        printf("DATETIME tidak valid\n");
        scanf("%d %d %d %d %d %d", &DD, &MM, &YYYY, &hh, &mm, &ss);
    }
    CreateDATETIME(D, DD, MM, YYYY, hh, mm, ss);
}
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

void TulisDATETIME(DATETIME D)
{
    printf("%d/%d/%d %02d:%02d:%02d", Day(D), Month(D), Year(D), Hour(Time(D)), Minute(Time(D)), Second(Time(D)));
}
/* I.S. : D sembarang */
/* F.S. : Nilai D ditulis dg format DD/MM/YYYY HH:MM:SS */
/* Proses : menulis nilai setiap komponen D ke layar dalam format DD/MM/YYYY HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok operasi relasional terhadap DATETIME *** */
boolean DEQ(DATETIME D1, DATETIME D2)
{
    return (Day(D1) == Day(D2) &&
            Month(D1) == Month(D2) &&
            Year(D1) == Year(D2) &&
            TEQ(Time(D1), Time(D2)));
}
/* Mengirimkan true jika D1=D2, false jika tidak */

boolean DNEQ(DATETIME D1, DATETIME D2)
{
    return (!(DEQ(D1, D2)));
}
/* Mengirimkan true jika D1 tidak sama dengan D2 */

boolean DLT(DATETIME D1, DATETIME D2)
{
    if (DEQ(D1, D2))
    {
        return false;
    }
    if (Year(D1) < Year(D2))
    {
        return true;
    }
    else if (Year(D1) > Year(D2))
    {
        return false;
    }
    else
    {
        // kalo tahun sama, mo ngecek bulan
        if (Month(D1) < Month(D2))
        {
            return true;
        }
        else if (Month(D1) > Month(D2))
        {
            return false;
        }
        else
        {
            // tahun dan bulan sama
            if (Day(D1) < Day(D2))
            {
                return true;
            }
            else if (Day(D1) > Day(D2))
            {
                return false;
            }
            else
            {
                // tahun, bulan, hari sama, skrg cek jam
                if (TLT(Time(D1), Time(D2)))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
}
/* Mengirimkan true jika D1<D2, false jika tidak */

boolean DGT(DATETIME D1, DATETIME D2)
{
    if (DLT(D1, D2))
    {
        return false;
    }
    else if (DEQ(D1, D2))
    {
        return false;
    }
    else
    {
        return true;
    }
}
/* Mengirimkan true jika D1>D2, false jika tidak */

DATETIME DATETIMENextNDetik(DATETIME D, int N)
{
    Second(Time(D)) += N;

    // kalo detik jadi > 60
    if (Second(Time(D)) > 60)
    {
        Minute(Time(D)) += (Second(Time(D)) / 60);
        Second(Time(D)) %= 60;
    }
    if (Minute(Time(D)) > 60)
    {
        Hour(Time(D)) += (Minute(Time(D)) / 60);
        Minute(Time(D)) %= 60;
    }
    if (Hour(Time(D)) > 23)
    {
        Day(D) += (Hour(Time(D)) / 24);
        Hour(Time(D)) %= 24;
    }
    if (Day(D) > GetMaxDay(Month(D), Year(D)))
    {
        int temp = Month(D);
        Month(D) += Day(D) / GetMaxDay(Month(D), Year(D));
        Day(D) %= GetMaxDay(temp, Year(D));
    }
    if (Month(D) > 12)
    {
        Year(D) += Month(D) / 12;
        Month(D) %= 12;
    }

    return D;
}

/* Mengirim salinan D dengan detik ditambah N */

DATETIME DATETIMEPrevNDetik(DATETIME D, int N)
{
    long sisa;
    sisa = (TIMEToDetik(Time(D)) - N);
    // waktu skrg - N (conv ke dtk), kalo dia kurang dr 0, harus modif tgl.
    while (sisa < 0)
    {
        if (Day(D) > 1)
        {
            Day(D)--;
            sisa += 86400;
        }
        else if (Month(D) > 1)
        {
            Day(D) = GetMaxDay(Month(D) - 1, Year(D));
            Month(D) -= 1;
            sisa += 86400;
        }
        else
        {
            Month(D) = 12;
            Day(D) = 31;
            Year(D) -= 1;
            sisa += 86400;
        }
    }
    TIME T;
    DATETIME DBaru;
    T = DetikToTIME(sisa);
    CreateDATETIME(&DBaru, Day(D), Month(D), Year(D), Hour(T), Minute(T), Second(T));
    return (DBaru);
}

/* Mengirim salinan D dengan detik dikurang N */
/* *** Kelompok Operator Aritmetika terhadap DATETIME *** */

const int hariperbulan[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int CountLeapYears(DATETIME D)
{
    int i;
    int jumlah = 0;
    int tahun = Year(D);
    // cek apkh tahun skrg harus masuk perhitungan leap year ato ga
    if ((Month(D)) <= 2)
    {
        tahun--;
    }

    for (i = 0; i < Year(D); i++)
    {
        if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
        {
            jumlah++;
        }
    }
    return (jumlah);
}

long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh)
{
    long int i, hari1, hari2, selisihhari, detikhari1, detikhari2;

    // jumlah hari DAw
    hari1 = (Year(DAw) - 1) * 365 + Day(DAw);

    for (i = 0; i < (Month(DAw) - 1); i++)
    {
        hari1 += hariperbulan[i];
    }

    hari1 += CountLeapYears(DAw);

    // jumlah hari DAkh
    hari2 = (Year(DAkh) - 1) * 365 + Day(DAkh);

    for (i = 0; i < (Month(DAkh) - 1); i++)
    {
        hari2 += hariperbulan[i];
    }

    hari2 += CountLeapYears(DAkh);

    detikhari1 = hari1 * 86400 + TIMEToDetik(Time(DAw));
    detikhari2 = hari2 * 86400 + TIMEToDetik(Time(DAkh));

    return (detikhari2 - detikhari1);
}
/* Mengirim DAkh-DAw dlm Detik, dengan kalkulasi */
/* Prekondisi: DAkh > DAw */

#endif

// TES

// int main() {
//     DATETIME D1,D2;
//     BacaDATETIME(&D1);
//     TulisDATETIME(D1);
//     printf("\n");
//     BacaDATETIME(&D2);
//     TulisDATETIME(D2);
//     printf("\n");

//     if (DEQ(D1,D2)) {
//         printf("datetime sama\n");
//     }
//     else {
//         printf("datetime tidak sama\n");
//     }

//     if (DNEQ(D1,D2)) {
//         printf("datetime tidak sama\n");
//     }
//     else {
//         printf("datetime sama\n");
//     }

//     if (DLT(D1,D2)) {
//         printf("D1 < D2\n");
//     }
//     else {
//         printf("D2 < D1\n");
//     }

//     if (DGT(D1,D2)) {
//         printf("D1 > D2\n");
//     }
//     else {
//         printf("D2 > D1\n");
//     }

// TulisDATETIME(DATETIMENextNDetik(D1, 4023900));
// printf("\n");
//     TulisDATETIME(DATETIMEPrevNDetik(D1, 3600));

//     printf("\n");
//     printf("%ld", DATETIMEDurasi(D1, D2));
// //     printf("\n");
//     return 0;
// }