#include <stdio.h>
// #include "../listlinierForUtas.h"
// #include "../../tree/tree.h"
// #include "../../masukan/masukan.h"
// #include "../../masukan/masukanint.h"
// #include "../../charmachine/charmachine.h"
// #include "../../kicauan/kicauan.h"
#include "../listlinierForUtas.c"
#include "../../tree/tree.c"
#include "../../masukan/masukan.c"
#include "../../masukan/masukanint.c"
#include "../../charmachine/charmachine.c"
#include "../../kicauan/kicauan.h"

int main()
{

    MASUKAN teks;
    MASUKANint type, teksint;

    char auth[20];
    bacaInt(&type);

    DATETIME time1;
    Month(time1) = 11;
    Year(time1) = 2023;
    Day(time1) = 23;
    Hour(Time(time1)) = 9;
    Minute(Time(time1)) = 23;
    Second(Time(time1)) = 26;

    DATETIME time2;
    Month(time2) = 11;
    Year(time2) = 2023;
    Day(time2) = 15;
    Hour(Time(time2)) = 9;
    Minute(Time(time2)) = 23;
    Second(Time(time2)) = 26;

    DATETIME time3;
    Month(time3) = 10;
    Year(time3) = 2023;
    Day(time3) = 19;
    Hour(Time(time3)) = 19;
    Minute(Time(time3)) = 23;
    Second(Time(time3)) = 26;

    threads linier;
    CreateThreads(&linier);

    User joseph, ucup;
    strcpy(ucup.username, "Yusuf");
    strcpy(joseph.username, "Joseph");

    // Buat Kicauan
    Kicauan kicau1, kicau2;

    // ID
    ID(kicau1) = 1;
    // Like
    LIKE(kicau1) = 77;
    // Author
    AUTHOR(kicau1) = &joseph;
    // Datetime
    DATETIME(kicau1) = time1;
    // Text
    strcpy(TEXT(kicau1), "AKU JOSEPH");

    // ID
    ID(kicau2) = 2;
    // Like
    LIKE(kicau2) = 70;
    // Author
    AUTHOR(kicau2) = &ucup;
    // Datetime
    DATETIME(kicau2) = time1;
    // Text
    strcpy(TEXT(kicau2), "AKU YUDUF");

    UTAS utas;

    switch (type)
    {
    case 1:

        // Testing membuat kicauan sambungan baru

        strcpy(auth, "Messi");
        baca(&teks);

        CreateThreads(&linier);

        insertLastThreads(&linier, MASUKANToStr(teks), time1);

        displayThreads(linier, auth);
        break;

    case 2:
        // Testing Menghapus kicauan sambungan pada index tertentu
        strcpy(auth, "Stark");

        // Input 3 Kicauan Sambungan
        baca(&teks);
        insertLastThreads(&linier, MASUKANToStr(teks), time2);

        baca(&teks);
        insertLastThreads(&linier, MASUKANToStr(teks), time2);

        baca(&teks);
        insertLastThreads(&linier, MASUKANToStr(teks), time2);
        displayThreads(linier, auth);

        // Hapus Kicauan Sambungan Pada Indeks Tertentu
        bacaInt(&teksint);
        deleteAtThreads(&linier, teksint);

        // Menampilkan Utas
        displayThreads(linier, auth);
        break;
    case 3:

        // Menambah Kicauan Sambungan Pada Indeks Tertentu
        bacaInt(&teksint);
        baca(&teks);
        insertAtThreads(&linier, MASUKANToStr(teks), teksint);

        displayThreads(linier, auth);

        printf("%d", lengthThreads(linier));
        break;

    case 4:
        //  Membuat Utas

        CreateUtas(&utas, &kicau1, 1);
        for (int i = 0; i < 3; i++)
        {
            baca(&teks);
            SambungUtasLast(&utas, MASUKANToStr(teks), time3);
        }
        displayUtas(utas);
    default:
        break;
    }
}