#include <stdio.h>
#include <stdlib.h>
#include "modifiedliststatik.c"
#include "modifiedmatrix.h"
#include "boolean.h"
#include "./ADT/charmachine/charmachine.c"
#include "./ADT/pcolor/pcolor.c"

// ganti profil (nama, bio akun, no HP, weton
void GANTI_PROFIL(ListStatik *pengguna, boolean *isLoggedIn, User *currentUser) {
    if (!*isLoggedIn) {
        printf("Anda belum login! Masuk terlebih dahulu untuk mengganti profil!\n");
    } else {
        // cari dulu di list dia idx ke berapa, biar kalo ada perubahan semua berubah
        boolean found = false;
        int i = 0;
        int userIndex;
        MASUKAN username;
        username = strToMASUKAN(currentUser->username, stringLength(currentUser->username));
        while (i < listLength(*pengguna)) {
            if (isMASUKANEqual(strToMASUKAN(ELMT(*pengguna, i).username, stringLength(ELMT(*pengguna, i).username)), username)) {
                userIndex = i;
                break;
            }
            i++;
        }

        printf("| Nama: %s\n", ELMT(*pengguna, userIndex).username);
        printf("| Bio Akun: %s\n", ELMT(*pengguna, userIndex).bio);
        char phonenum[ELMT(*pengguna, userIndex).phone_num.Length];
        MASUKANToStr(ELMT(*pengguna, userIndex).phone_num, phonenum);
        printf("| No HP: %s\n", phonenum);
        printf("| Weton: %s\n", ELMT(*pengguna, userIndex).weton);

        MASUKAN bio_temp;
        char bio;
        printf("Masukkan Bio Akun: ");
        baca(&bio_temp);
        MASUKANToStr(bio_temp, &bio);
        
        SetBio(pengguna, userIndex, &bio);

        MASUKAN nohp;
        int z;
        printf("Masukkan No HP: ");
        baca(&nohp);
        boolean validnumber = false;

        do {
            validnumber = true;
            for (z = 0; z < nohp.Length; z++) {
                if (nohp.TabMASUKAN[z] < '0' || nohp.TabMASUKAN[z] > '9') {
                    validnumber = false;
                    break;
                }
            }

            if (!validnumber) {
                printf("No HP tidak valid. Masukkan lagi: ");
                baca(&nohp);
            }
        } while (!validnumber);

        SetPhoneNum(pengguna, userIndex, nohp);

        MASUKAN weton_temp;
        char weton;
        printf("Masukkan Weton: ");
        baca(&weton_temp);
        boolean validweton = false;

        do {
            if (isSame(weton_temp, ";") || isSame(weton_temp, "Pahing;") || isSame(weton_temp, "Kliwon;") || isSame(weton_temp, "Wage;") || isSame(weton_temp, "Pon;") || isSame(weton_temp, "Legi;")) {
                validweton = true;
            }
            if (!validweton) {
                printf("Weton anda tidak valid.\n");
                printf("Masukkan Weton: ");
                baca(&weton_temp);
            }
        } while (!validweton);

        MASUKANToStr(weton_temp, &weton);
        SetWeton(pengguna, userIndex, &weton);

        printf("Profil Anda sudah berhasil diperbarui!\n");
    }
}

// lihat profil pengguna
void LIHAT_PROFIL(ListStatik *pengguna, MASUKAN namapengguna) {
    // cari dulu di list dia idx ke berapa
    boolean found = false;
    int i = 0;
    int userIndex = -1;
    while (i < listLength(*pengguna)) {
        if (isMASUKANEqual(namapengguna, strToMASUKAN(ELMT(*pengguna, i).username, stringLength(ELMT(*pengguna, i).username)))) {
            userIndex = i;
            break;
        }
        i++;
    }

    if (userIndex != -1) {
        printf("| Nama: %s\n", ELMT(*pengguna, userIndex).username);
        printf("| Bio Akun: %s\n", ELMT(*pengguna, userIndex).bio);
        char phonenum[ELMT(*pengguna, userIndex).phone_num.Length];
        MASUKANToStr(ELMT(*pengguna, userIndex).phone_num, phonenum);
        printf("| No HP: %s\n", phonenum);
        printf("| Weton: %s\n", ELMT(*pengguna, userIndex).weton);
        printf("Foto profil akun %s \n", namapengguna.TabMASUKAN);
        displayProfile(ELMT(*pengguna, userIndex).profile);
    } else {
        printf("Maaf, pengguna dengan nama %s tidak ditemukan.\n", namapengguna.TabMASUKAN);
    }
}

// ganti profile
void UBAH_FOTO_PROFIL(ListStatik *pengguna, boolean *isLoggedIn, User *currentUser) {
    if (!*isLoggedIn) {
        printf("Anda belum login! Masuk terlebih dahulu untuk mengganti profil!\n");
    } else {
        // cari dulu di list dia idx ke berapa, biar kalo ada perubahan semua berubah
        boolean found = false;
        int i = 0;
        int userIndex;
        MASUKAN username;
        username = strToMASUKAN(currentUser->username, stringLength(currentUser->username));
        while (i < listLength(*pengguna)) {
            if (isMASUKANEqual(strToMASUKAN(ELMT(*pengguna, i).username, stringLength(ELMT(*pengguna, i).username)), username)) {
                userIndex = i;
                break;
            }
            i++;
        }

        Matrix baru;
        printf("Foto profil Anda saat ini adalah \n");
        displayProfile(ELMT(*pengguna, userIndex).profile);
        printf("\n");
        printf("Masukkan foto profil yang baru \n");
        readMatrix(&baru, 5, 10);
        SetProfile(pengguna, userIndex, &baru);
        printf("\n");
        printf("Foto profil anda sudah berhasil diganti!\n");
    }

}