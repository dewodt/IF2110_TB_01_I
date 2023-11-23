// #include <stdio.h>
// #include <stdlib.h>
// #include "../masukan/masukan.h"
// #include "pengguna.h"

// User *currentUser = NULL;

// int main()
// {
//     MASUKAN command;
//     ListStatik pengguna;
//     CreateListStatik(&pengguna);
//     char commandStr[50];
//     char commandAwal[50];
//     MASUKAN namapengguna;

//     printf(">> ");
//     baca(&command);

//     while (!isSame(command, "TUTUP_PROGRAM;"))
//     {
//         if (isSame(command, "DAFTAR;"))
//         {
//             DAFTAR(&pengguna);
//         }
//         else if (isSame(command, "MASUK;"))
//         {
//             MASUK(&pengguna, &currentUser);
//         }
//         else if (isSame(command, "KELUAR;"))
//         {
//             KELUAR(&currentUser);
//         }
//         else if (isSame(command, "GANTI_PROFIL;"))
//         {
//             GANTI_PROFIL(&pengguna, currentUser);
//         }
//         else if (compareString(command.TabMASUKAN, "LIHAT_PROFIL", 12) == 0)
//         {
//             int len = command.Length;
//             int idx = 0;

//             // mencari indeks awal nama pengguna
//             while (idx < len && command.TabMASUKAN[idx] != ' ')
//             {
//                 idx++;
//             }

//             if (idx < len)
//             {
//                 // copy perintah awal (tanpa spasi akhir) dan nama pengguna
//                 for (int i = 0; i < idx; i++)
//                 {
//                     commandAwal[i] = command.TabMASUKAN[i];
//                 }
//                 commandAwal[idx] = '\0'; // null-terminator

//                 int j = 0;
//                 for (int i = idx + 1; i < len; i++)
//                 {
//                     namapengguna.TabMASUKAN[j] = command.TabMASUKAN[i];
//                     j++;
//                 }
//                 namapengguna.Length = j;
//                 namapengguna.TabMASUKAN[j] = '\0'; // null-terminator

//                 // printf("Perintah Awal: %s\n", commandAwal);
//                 // printf("Nama Pengguna: %s\n", namapengguna.TabMASUKAN);

//                 // baru call fungsi LIHAT_PROFIL dengan namapengguna
//                 LIHAT_PROFIL(&pengguna, namapengguna);
//             }
//         }
//         else if (isSame(command, "UBAH_FOTO_PROFIL;"))
//         {
//             UBAH_FOTO_PROFIL(&pengguna, currentUser);
//         }
//         else if (isSame(command, "ATUR_JENIS_AKUN;"))
//         {
//             ATUR_JENIS_AKUN(&pengguna, currentUser);
//         }

//         // printList(&pengguna);
//         // printf("\n");
//         // printf("%d\n", listLength(pengguna));

//         printf(">> ");
//         baca(&command);
//     }

//     if (isSame(command, "\nTUTUP_PROGRAM;"))
//     {
//         printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
//     }

//     return 0;
// }

// // RUN DALAM FOLDER PENGGUNA
// // gcc driverpengguna.c pengguna.c ../modifiedliststatik/modifiedliststatik.c  ../modifiedmatrix/modifiedmatrix.c ../masukan/masukan.c ../charmachine/charmachine.c ../pcolor/pcolor.c