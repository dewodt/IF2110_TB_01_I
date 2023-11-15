#include <stdio.h>
#include <stdlib.h>
#include "modifiedliststatik.c"
#include "modifiedmatrix.h"
#include "boolean.h"
#include "./ADT/charmachine/charmachine.c"
#include "./ADT/pcolor/pcolor.c"

// ganti profil (nama, bio akun, no HP, weton)
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
        char weton[NMax];
        printf("Masukkan Weton: ");
        baca(&weton_temp);
        boolean validweton = false;

        do {
            MASUKANToStr(weton_temp, weton);
            if (compareString(weton, "\0", 1) == 0) {
                validweton = true;
            } else {
                toLowerCase(weton);
                if (compareString(weton, ";", 1) == 0 || compareString(weton, "pahing", 6) == 0 || compareString(weton, "kliwon", 6) == 0 || compareString(weton, "wage", 4) == 0 || compareString(weton, "pon", 3) == 0 || compareString(weton, "legi", 4) == 0) {
                    validweton = true;
                }
            }
            if (!validweton) {
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
        if (ELMT(*pengguna, userIndex).jenis_akun[0] == '1') {
            printf("| Nama: %s\n", ELMT(*pengguna, userIndex).username);
            printf("| Bio Akun: %s\n", ELMT(*pengguna, userIndex).bio);
            char phonenum[ELMT(*pengguna, userIndex).phone_num.Length];
            MASUKANToStr(ELMT(*pengguna, userIndex).phone_num, phonenum);
            printf("| No HP: %s\n", phonenum);
            printf("| Weton: %s\n", ELMT(*pengguna, userIndex).weton);
            printf("Foto profil akun %s \n", namapengguna.TabMASUKAN);
            displayProfile(ELMT(*pengguna, userIndex).profile);
        } else if (ELMT(*pengguna, userIndex).jenis_akun[0] == '0') {
            printf("Wah, akun %s diprivat nih. Ikuti dulu yuk untuk bisa melihat profil %s!\n", namapengguna.TabMASUKAN, namapengguna.TabMASUKAN);
        }
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
        printf("Masukkan foto profil yang baru \n");
        readMatrixMasukan(&baru, 5, 10);
        SetProfile(pengguna, userIndex, &baru);
        printf("Foto profil anda sudah berhasil diganti!\n");
    }
}

// atur jenis akun
void ATUR_JENIS_AKUN(ListStatik *pengguna, boolean *isLoggedIn, User *currentUser) {
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

        if (ELMT(*pengguna, userIndex).jenis_akun[0] == '1') {
            printf("Saat ini, akun Anda adalah akun Publik.\n");
            printf("Ingin mengubah ke akun Privat? (YA/TIDAK) ");

            MASUKAN acctype;
            baca(&acctype);

            if (isSame(acctype, "YA;")) {
                ELMT(*pengguna, userIndex).jenis_akun[0] = '0';
                ELMT(*pengguna, userIndex).jenis_akun[1] = '\0';
                printf("Akun anda sudah diubah menjadi akun Privat.\n");
            } else if (isSame(acctype, "TIDAK;")) {
                printf("Akun anda tidak jadi diubah menjadi akun Privat.\n");
            }
        } else if (ELMT(*pengguna, userIndex).jenis_akun[0] == '0') {
            printf("Saat ini, akun Anda adalah akun Privat.\n");
            printf("Ingin mengubah ke akun Publik? (YA/TIDAK) ");

            MASUKAN acctype;
            baca(&acctype);

            if (isSame(acctype, "YA;")) {
                ELMT(*pengguna, userIndex).jenis_akun[0] = '1';
                ELMT(*pengguna, userIndex).jenis_akun[1] = '\0';
                printf("Akun anda sudah diubah menjadi akun Publik.\n");
            } else if (isSame(acctype, "TIDAK;")) {
                printf("Akun anda tidak jadi diubah menjadi akun Publik.\n");
            }
        }
    }
}