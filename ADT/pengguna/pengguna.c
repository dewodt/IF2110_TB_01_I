#include <stdio.h>
#include <stdlib.h>
#include "../masukan/masukan.h"
#include "pengguna.h"

// Mengembalikan true bila user sudah login dan mengembalikan false bila user belum login
boolean isUserLoggedIn()
// Jika global variable currentUser NULL maka belum login
// Jika global variable currentUser tidak NULL maka sudah login (pointer ke user yang sedang login)
{
    return currentUser != NULL;
}

// mendaftarkan pengguna
void DAFTAR(ListStatik *pengguna)
{
    if (isUserLoggedIn())
    {
        printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
    }
    else
    {
        if (listLength(*pengguna) >= MAX_USERS)
        {
            printf("Maaf, kapasitas pengguna sudah penuh. Tidak dapat mendaftar lebih banyak pengguna.\n");
            return;
        }

        int idx = listLength(*pengguna);
        // printf("listlength: %d\n", idx);

        boolean uservalid = false;
        MASUKAN username_temp;
        printf("Masukkan nama: ");
        baca(&username_temp);

        while (!uservalid)
        {
            if (username_temp.Length > 20)
            {
                printf("Nama yang anda masukkan > 20 karakter. Ayo coba lagi.\n");
                printf("Masukkan nama: ");
                baca(&username_temp);
            }
            else
            {
                // cek apakah nama pengguna udah ada
                for (int i = 0; i < idx; i++)
                {
                    if (isMASUKANEqual(strToMASUKAN(ELMT(*pengguna, i).username, stringLength(ELMT(*pengguna, i).username)), username_temp))
                    {
                        printf("Wah, sayang sekali nama tersebut telah diambil.\n");
                        printf("Masukkan nama: ");
                        baca(&username_temp);
                    }
                }
                uservalid = true;
            }
        }

        char *username = MASUKANToStr(username_temp);
        strcpy(ELMT(*pengguna, idx).username, username);
        // printf("username: %s\n", ELMT(*pengguna, idx).username);

        boolean passwordvalid = false;
        MASUKAN password_temp;
        printf("Masukkan kata sandi: ");
        baca(&password_temp);

        while (!passwordvalid)
        {
            if (password_temp.Length > 20)
            {
                printf("Kata sandi yang anda masukkan > 20 karakter. Ayo coba lagi.\n");
                printf("Masukkan kata sandi: ");
                baca(&password_temp);
            }
            else
            {
                passwordvalid = true;
            }
        }

        char *password = MASUKANToStr(password_temp);
        // printf("idx skrg: %d\n", idx);
        strcpy(ELMT(*pengguna, idx).password, password);
        // printf("password: %s\n", ELMT(*pengguna, idx).password);

        printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
    }
}

// masuk sebagai pengguna
void MASUK(ListStatik *pengguna, User **currentUser)
{
    if (isUserLoggedIn())
    {
        printf("Wah Anda sudah masuk. Keluar dulu yuk!\n");
        return;
    }

    MASUKAN username;
    printf("Masukkan nama: ");
    baca(&username);

    // cari pengguna dengan nama yang cocok
    int userIndex = -1;

    do
    {
        int i = 0;
        while (i < listLength(*pengguna))
        {
            if (isMASUKANEqual(strToMASUKAN(ELMT(*pengguna, i).username, stringLength(ELMT(*pengguna, i).username)), username))
            {
                userIndex = i;
                break;
            }
            i++;
        }

        if (userIndex == -1)
        {
            printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
            printf("Masukkan nama: ");
            baca(&username);
        }
    } while (userIndex == -1);

    MASUKAN password;
    printf("Masukkan kata sandi: ");
    baca(&password);
    boolean passwordvalid = false;

    do
    {
        if (isMASUKANEqual(strToMASUKAN(ELMT(*pengguna, userIndex).password, stringLength(ELMT(*pengguna, userIndex).password)), password))
        {
            char *username_str = MASUKANToStr(username);
            printf("Anda telah berhasil masuk dengan nama pengguna %s. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n", username_str);
            passwordvalid = true;
        }
        else
        {
            printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
            printf("Masukkan kata sandi: ");
            baca(&password);
        }
    } while (!passwordvalid);

    if (*currentUser != NULL) 
    {
        **currentUser = ELMT(*pengguna, userIndex);
    } 
    else 
    {
        *currentUser = malloc(sizeof(User));
        **currentUser = ELMT(*pengguna, userIndex);
    }

    return;
}

// keluar dari akun pengguna
void KELUAR(User **currentUser)
{
    if (!isUserLoggedIn())
    {
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }
    else
    {
        free(*currentUser);
        *currentUser = NULL;
        printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n");
    }
    return;
}

// ganti profil (nama, bio akun, no HP, weton)
void GANTI_PROFIL(ListStatik *pengguna, User *currentUser)
{
    if (!isUserLoggedIn())
    {
        printf("Anda belum login! Masuk terlebih dahulu untuk mengganti profil!\n");
    }
    else
    {
        // cari dulu di list dia idx ke berapa, biar kalo ada perubahan semua berubah
        int i = 0;
        int userIndex;
        MASUKAN username;
        username = strToMASUKAN(currentUser->username, stringLength(currentUser->username));
        while (i < listLength(*pengguna))
        {
            if (isMASUKANEqual(strToMASUKAN(ELMT(*pengguna, i).username, stringLength(ELMT(*pengguna, i).username)), username))
            {
                userIndex = i;
                break;
            }
            i++;
        }

        printf("| Nama: %s\n", ELMT(*pengguna, userIndex).username);
        printf("| Bio Akun: %s\n", ELMT(*pengguna, userIndex).bio);
        char *phonenum = MASUKANToStr(ELMT(*pengguna, userIndex).phone_num);
        printf("| No HP: %s\n", phonenum);
        printf("| Weton: %s\n", ELMT(*pengguna, userIndex).weton);

        MASUKAN bio_temp;
        printf("Masukkan Bio Akun: ");
        baca(&bio_temp);
        char *bio = MASUKANToStr(bio_temp);

        SetBio(pengguna, userIndex, bio);

        MASUKAN nohp;
        int z;
        printf("Masukkan No HP: ");
        baca(&nohp);
        boolean validnumber = false;

        do
        {
            validnumber = true;
            for (z = 0; z < nohp.Length; z++)
            {
                if (nohp.TabMASUKAN[z] < '0' || nohp.TabMASUKAN[z] > '9')
                {
                    validnumber = false;
                    break;
                }
            }

            if (!validnumber)
            {
                printf("No HP tidak valid. Masukkan lagi: ");
                baca(&nohp);
            }
        } while (!validnumber);

        SetPhoneNum(pengguna, userIndex, nohp);

        MASUKAN weton_temp;
        char weton[NMax];
        printf("Masukkan Weton: ");
        baca(&weton_temp);
        boolean validweton = false;

        do
        {
            char *weton = MASUKANToStr(weton_temp);
            if (compareString(weton, "\0", 1) == 0)
            {
                validweton = true;
            }
            else
            {
                toLowerCase(weton);
                if (compareString(weton, ";", 1) == 0 || compareString(weton, "pahing", 6) == 0 || compareString(weton, "kliwon", 6) == 0 || compareString(weton, "wage", 4) == 0 || compareString(weton, "pon", 3) == 0 || compareString(weton, "legi", 4) == 0)
                {
                    validweton = true;
                }
            }
            if (!validweton)
            {
                printf("Weton anda tidak valid.\n");
                printf("Masukkan Weton: ");
                baca(&weton_temp);
            }
        } while (!validweton);

        SetWeton(pengguna, userIndex, weton);

        printf("Profil Anda sudah berhasil diperbarui!\n");
    }
}

// lihat profil pengguna
void LIHAT_PROFIL(ListStatik *pengguna, MASUKAN namapengguna)
{
    // cari dulu di list dia idx ke berapa
    int i = 0;
    int userIndex = -1;
    while (i < listLength(*pengguna))
    {
        if (isMASUKANEqual(namapengguna, strToMASUKAN(ELMT(*pengguna, i).username, stringLength(ELMT(*pengguna, i).username))))
        {
            userIndex = i;
            break;
        }
        i++;
    }

    if (userIndex != -1)
    {
        if (ELMT(*pengguna, userIndex).jenis_akun[0] == '1')
        {
            printf("| Nama: %s\n", ELMT(*pengguna, userIndex).username);
            printf("| Bio Akun: %s\n", ELMT(*pengguna, userIndex).bio);
            char *phonenum = MASUKANToStr(ELMT(*pengguna, userIndex).phone_num);
            printf("| No HP: %s\n", phonenum);
            printf("| Weton: %s\n", ELMT(*pengguna, userIndex).weton);
            printf("Foto profil akun %s \n", namapengguna.TabMASUKAN);
            displayProfile(ELMT(*pengguna, userIndex).profile);
        }
        else if (ELMT(*pengguna, userIndex).jenis_akun[0] == '0')
        {
            printf("Wah, akun %s diprivat nih. Ikuti dulu yuk untuk bisa melihat profil %s!\n", namapengguna.TabMASUKAN, namapengguna.TabMASUKAN);
        }
    }
    else
    {
        printf("Maaf, pengguna dengan nama %s tidak ditemukan.\n", namapengguna.TabMASUKAN);
    }
}

// ganti profile
void UBAH_FOTO_PROFIL(ListStatik *pengguna, User *currentUser)
{
    if (!isUserLoggedIn())
    {
        printf("Anda belum login! Masuk terlebih dahulu untuk mengganti profil!\n");
    }
    else
    {
        // cari dulu di list dia idx ke berapa, biar kalo ada perubahan semua berubah
        int i = 0;
        int userIndex;
        MASUKAN username;
        username = strToMASUKAN(currentUser->username, stringLength(currentUser->username));
        while (i < listLength(*pengguna))
        {
            if (isMASUKANEqual(strToMASUKAN(ELMT(*pengguna, i).username, stringLength(ELMT(*pengguna, i).username)), username))
            {
                userIndex = i;
                break;
            }
            i++;
        }

        Matrix baru;
        printf("Foto profil Anda saat ini adalah \n");
        displayProfile(ELMT(*pengguna, userIndex).profile);
        printf("Masukkan foto profil yang baru \n");
        readMatrixMasukan(&baru, 5, 10);
        SetProfile(pengguna, userIndex, &baru);
        printf("Foto profil anda sudah berhasil diganti!\n");
    }
}

// atur jenis akun
void ATUR_JENIS_AKUN(ListStatik *pengguna, User *currentUser)
{
    if (!isUserLoggedIn())
    {
        printf("Anda belum login! Masuk terlebih dahulu untuk mengganti profil!\n");
    }
    else
    {
        // cari dulu di list dia idx ke berapa, biar kalo ada perubahan semua berubah
        int i = 0;
        int userIndex;
        MASUKAN username;
        username = strToMASUKAN(currentUser->username, stringLength(currentUser->username));
        while (i < listLength(*pengguna))
        {
            if (isMASUKANEqual(strToMASUKAN(ELMT(*pengguna, i).username, stringLength(ELMT(*pengguna, i).username)), username))
            {
                userIndex = i;
                break;
            }
            i++;
        }

        if (ELMT(*pengguna, userIndex).jenis_akun[0] == '1')
        {
            printf("Saat ini, akun Anda adalah akun Publik.\n");
            printf("Ingin mengubah ke akun Privat? (YA/TIDAK) ");

            MASUKAN acctype;
            baca(&acctype);

            if (isSame(acctype, "YA;"))
            {
                ELMT(*pengguna, userIndex).jenis_akun[0] = '0';
                ELMT(*pengguna, userIndex).jenis_akun[1] = '\0';
                printf("Akun anda sudah diubah menjadi akun Privat.\n");
            }
            else if (isSame(acctype, "TIDAK;"))
            {
                printf("Akun anda tidak jadi diubah menjadi akun Privat.\n");
            }
        }
        else if (ELMT(*pengguna, userIndex).jenis_akun[0] == '0')
        {
            printf("Saat ini, akun Anda adalah akun Privat.\n");
            printf("Ingin mengubah ke akun Publik? (YA/TIDAK) ");

            MASUKAN acctype;
            baca(&acctype);

            if (isSame(acctype, "YA;"))
            {
                ELMT(*pengguna, userIndex).jenis_akun[0] = '1';
                ELMT(*pengguna, userIndex).jenis_akun[1] = '\0';
                printf("Akun anda sudah diubah menjadi akun Publik.\n");
            }
            else if (isSame(acctype, "TIDAK;"))
            {
                printf("Akun anda tidak jadi diubah menjadi akun Publik.\n");
            }
        }
    }
}

User *currentUser = NULL;

int main()
{
    MASUKAN command;
    ListStatik pengguna;
    CreateListStatik(&pengguna);
    char commandStr[50];
    char commandAwal[50];
    MASUKAN namapengguna;

    printf(">> ");
    baca(&command);

    while (!isSame(command, "TUTUP_PROGRAM;"))
    {
        if (isSame(command, "DAFTAR;"))
        {
            DAFTAR(&pengguna);
        }
        else if (isSame(command, "MASUK;"))
        {
            MASUK(&pengguna, &currentUser);
        }
        else if (isSame(command, "KELUAR;"))
        {
            KELUAR(&currentUser);
        }
        else if (isSame(command, "GANTI_PROFIL;"))
        {
            GANTI_PROFIL(&pengguna, currentUser);
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
            UBAH_FOTO_PROFIL(&pengguna, currentUser);
        }
        else if (isSame(command, "ATUR_JENIS_AKUN;"))
        {
            ATUR_JENIS_AKUN(&pengguna, currentUser);
        }

        // printList(&pengguna);
        // printf("\n");
        // printf("%d\n", listLength(pengguna));

        printf(">> ");
        baca(&command);
    }

    if (isSame(command, "\nTUTUP_PROGRAM;"))
    {
        printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
    }

    return 0;
}

// gcc pengguna.c ../modifiedliststatik/modifiedliststatik.c  ../modifiedmatrix/modifiedmatrix.c ../masukan/masukan.c ../charmachine/charmachine.c ../pcolor/pcolor.c