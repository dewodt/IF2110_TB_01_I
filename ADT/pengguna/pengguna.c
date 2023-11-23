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
        // displayMASUKAN(bio_temp);

        boolean validbio = false;

        do
        {
            validbio = false;
            if (bio_temp.Length > 135) {
                validbio = false;
            }
            else {
                validbio = true;
            }

            if (!validbio)
            {
                printf("Bio anda > 135 karakter. Masukkan lagi: ");
                baca(&bio_temp);
            }
        } while (!validbio);

        if (validbio) {
            char *bio = MASUKANToStr(bio_temp);
            SetBio(pengguna, userIndex, bio);
        }

        MASUKAN nohp;
        int z;
        printf("Masukkan No HP: ");
        baca(&nohp);
        boolean validnumber = false;

        do
        {
            validnumber = true;
            if (nohp.Length > 15) {
                validnumber = false;
            }
            else if (isMasukanEmpty(nohp)) {
                validnumber = true;
            }
            else {
                for (z = 0; z < nohp.Length; z++)
                {
                    if (nohp.TabMASUKAN[z] < '0' || nohp.TabMASUKAN[z] > '9')
                    {
                        validnumber = false;
                        break;
                    }
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
        char *weton;
        printf("Masukkan Weton: ");
        baca(&weton_temp);
        boolean validweton = false;

        do
        {
            weton = MASUKANToStr(weton_temp);
            // printf("%s\n", weton);
            // printf("char[0]: %c\n", weton[0]);
            if (isMasukanEmpty(weton_temp))
            {
                validweton = true;
            }
            else
            {
                toLowerCase(weton);
                if ((compareString(weton, ";", 1) == 0)|| (compareString(weton, "pahing", 6) == 0 && weton_temp.Length == 6) || (compareString(weton, "kliwon", 6) == 0 && weton_temp.Length == 6) || (compareString(weton, "wage", 4) == 0 && weton_temp.Length == 4) || (compareString(weton, "pon", 3) == 0 && weton_temp.Length == 3) || (compareString(weton, "legi", 4) == 0 && weton_temp.Length == 4))
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
        if (ELMT(*pengguna, userIndex).isPrivate == false)
        {
            printf("| Nama: %s\n", ELMT(*pengguna, userIndex).username);
            printf("| Bio Akun: %s\n", ELMT(*pengguna, userIndex).bio);
            char *phonenum = MASUKANToStr(ELMT(*pengguna, userIndex).phone_num);
            printf("| No HP: %s\n", phonenum);
            printf("| Weton: %s\n", ELMT(*pengguna, userIndex).weton);
            printf("Foto profil akun %s \n", MASUKANToStr(namapengguna));
            displayProfile(ELMT(*pengguna, userIndex).profile);
        }
        else if (ELMT(*pengguna, userIndex).isPrivate == true)
        {
            printf("Wah, akun %s diprivat nih. Ikuti dulu yuk untuk bisa melihat profil %s!\n", MASUKANToStr(namapengguna), MASUKANToStr(namapengguna));
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
        boolean status = false;
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

        if (ELMT(*pengguna, userIndex).isPrivate == false)
        {
            printf("Saat ini, akun Anda adalah akun Publik.\n");
            printf("Ingin mengubah ke akun Privat? (YA/TIDAK) ");

            MASUKAN acctype;
            baca(&acctype);

            if (isSame(acctype, "YA;"))
            {
                status = true;
                SetIsPrivate(pengguna, userIndex, &status);
                printf("Akun anda sudah diubah menjadi akun Privat.\n");
            }
            else if (isSame(acctype, "TIDAK;"))
            {
                printf("Akun anda tidak jadi diubah menjadi akun Privat.\n");
            }
        }
        else if (ELMT(*pengguna, userIndex).isPrivate == true)
        {
            printf("Saat ini, akun Anda adalah akun Privat.\n");
            printf("Ingin mengubah ke akun Publik? (YA/TIDAK) ");

            MASUKAN acctype;
            baca(&acctype);

            if (isSame(acctype, "YA;"))
            {
                SetIsPrivate(pengguna, userIndex, &status);
                printf("Akun anda sudah diubah menjadi akun Publik.\n");
            }
            else if (isSame(acctype, "TIDAK;"))
            {
                printf("Akun anda tidak jadi diubah menjadi akun Publik.\n");
            }
        }
    }
}
