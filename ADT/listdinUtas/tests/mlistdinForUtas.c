// #include <stdio.h>
// #include "../../listlinierUtas/listlinierForUtas.c"
// #include "../../tree/tree.c"
// #include "../../masukan/masukan.c"
// #include "../../masukan/masukanint.c"
// #include "../../charmachine/charmachine.c"
// #include "../listdinForUtas.c"
// #include "../../kicauan/kicauan.h"

// int main()
// {
//     MASUKAN teks;

//     // Custom Date time
//     DATETIME time1;
//     Month(time1) = 11;
//     Year(time1) = 2023;
//     Day(time1) = 23;
//     Hour(Time(time1)) = 9;
//     Minute(Time(time1)) = 23;
//     Second(Time(time1)) = 26;

//     DATETIME time2;
//     Month(time2) = 11;
//     Year(time2) = 2023;
//     Day(time2) = 15;
//     Hour(Time(time2)) = 9;
//     Minute(Time(time2)) = 23;
//     Second(Time(time2)) = 26;

//     DATETIME time3;
//     Month(time3) = 10;
//     Year(time3) = 2023;
//     Day(time3) = 19;
//     Hour(Time(time3)) = 19;
//     Minute(Time(time3)) = 23;
//     Second(Time(time3)) = 26;

//     threads linier;
//     CreateThreads(&linier);

//     // BUAT USER
//     User joseph, ucup;
//     strcpy(ucup.username, "Yusuf");
//     strcpy(joseph.username, "Joseph");

//     // Buat Kicauan
//     Kicauan kicau1, kicau2;

//     ID(kicau1) = 1;
//     LIKE(kicau1) = 77;
//     AUTHOR(kicau1) = &joseph;
//     DATETIME(kicau1) = time1;
//     strcpy(TEXT(kicau1), "AKU JOSEPH");

//     ID(kicau2) = 2;
//     LIKE(kicau2) = 70;
//     AUTHOR(kicau2) = &ucup;
//     DATETIME(kicau2) = time1;
//     strcpy(TEXT(kicau2), "AKU YUDUF");

//     // BUAT LIST UTAS
//     ListUtas utases;
//     CreateListUtas(&utases, 3);

//     MASUKANint inputint;
//     bacaInt(&inputint);

//     // BUATUTAS
//     UTAS utas;

//     int ID;
//     switch (inputint)
//     {
//     case 1:
//         // Membuat List Utas dari utas barulalu menampilkan semua utas yang terdaftar

//         for (int i = 0; i < 4; i++)
//         {
//             ID = listUtasLength(utases) + 1;
//             CreateUtas(&utas, &kicau1, ID);
//             insertUtas(&utases, utas);
//             baca(&teks);
//             insertLastThreadForConfig(&BUFFERListDinUtas(utases)[i], MASUKANToStr(teks), time3);
//         }

//         for (int i = 0; i < 4; i++)
//         {
//             displayUtas(BUFFERListDinUtas(utases)[i]);
//         }
//         // Mengecek Apakah list dinamis di expand saat sudah full capacity
//         printf("%d", CAPACITYListDinUtas(utases));
//     default:
//         break;
//     }
// }