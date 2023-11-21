#include <stdio.h>
#include <stdlib.h>
#include "ADT/pengguna/pengguna.h"

int main()
{
    MASUKAN command;
    boolean isLoggedin = false;
    ListStatik pengguna;
    CreateListStatik(&pengguna);
    User currentUser;
    char commandStr[50];
    char commandAwal[50];
    MASUKAN namapengguna;

    printf(">> ");
    baca(&command);

    while (!isSame(command, "TUTUP_PROGRAM;"))
    {
        if (isSame(command, "DAFTAR;"))
        {
            DAFTAR(&pengguna, &isLoggedin);
        }
        else if (isSame(command, "MASUK;"))
        {
            isLoggedin = MASUK(&pengguna, &isLoggedin, &currentUser);
        }
        else if (isSame(command, "KELUAR;"))
        {
            isLoggedin = KELUAR(&isLoggedin);
        }
        else if (isSame(command, "GANTI_PROFIL;"))
        {
            GANTI_PROFIL(&pengguna, &isLoggedin, &currentUser);
        }
        else if (compareString(command.TabMASUKAN, "LIHAT_PROFIL", 12) == 0)
        {
            int len = command.Length;
            int idx = 0;

            // mencari indeks awal nama pengguna
            while (idx < len && command.TabMASUKAN[idx] != ' ')
            {
                idx++;
            }

            if (idx < len)
            {
                // copy perintah awal (tanpa spasi akhir) dan nama pengguna
                for (int i = 0; i < idx; i++)
                {
                    commandAwal[i] = command.TabMASUKAN[i];
                }
                commandAwal[idx] = '\0'; // null-terminator

                int j = 0;
                for (int i = idx + 1; i < len; i++)
                {
                    namapengguna.TabMASUKAN[j] = command.TabMASUKAN[i];
                    j++;
                }
                namapengguna.Length = j;
                namapengguna.TabMASUKAN[j] = '\0'; // null-terminator

                // printf("Perintah Awal: %s\n", commandAwal);
                // printf("Nama Pengguna: %s\n", namapengguna.TabMASUKAN);

                // baru call fungsi LIHAT_PROFIL dengan namapengguna
                LIHAT_PROFIL(&pengguna, namapengguna);
            }
        }
        else if (isSame(command, "UBAH_FOTO_PROFIL;"))
        {
            UBAH_FOTO_PROFIL(&pengguna, &isLoggedin, &currentUser);
        }
        else if (isSame(command, "ATUR_JENIS_AKUN;"))
        {
            ATUR_JENIS_AKUN(&pengguna, &isLoggedin, &currentUser);
        }

        printList(&pengguna);
        printf("\n");
        printf("%d\n", listLength(pengguna));

        printf(">> ");
        baca(&command);
    }

    if (isSame(command, "\nTUTUP_PROGRAM;"))
    {
        printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
    }

    return 0;
}

// gcc ADT/pengguna/pengguna.c ADT/modifiedliststatik/modifiedliststatik.c  ADT/modifiedmatrix/modifiedmatrix.c ADT/masukan/masukan.c ADT/charmachine/charmachine.c ADT/pcolor/pcolor.c