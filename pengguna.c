#include <stdio.h>
#include <stdlib.h>
#include "modifiedliststatik.c"
#include "modifiedmatrix.h"
#include "boolean.h"
#include "./ADT/charmachine/charmachine.c"
#include "./ADT/pcolor/pcolor.c"

// mendaftarkan pengguna
void DAFTAR(ListStatik *pengguna, boolean isLoggedin) {
    if (isLoggedin) {
        printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
    } else {
        if (listLength(*pengguna) >= MAX_USERS) {
            printf("Maaf, kapasitas pengguna sudah penuh. Tidak dapat mendaftar lebih banyak pengguna.\n");
            return;
        }

        int idx = listLength(*pengguna);
        printf("listlength: %d\n", idx);
        
        boolean uservalid = false;
        MASUKAN username_temp;
        printf("Masukkan nama: ");
        baca(&username_temp);

        while (!uservalid) {
            if (username_temp.Length > 20) {
                printf("Nama yang anda masukkan > 20 karakter. Ayo coba lagi.\n");
                    printf("Masukkan nama: ");
                    baca(&username_temp);
            } else {
                // cek apakah nama pengguna udah ada
                for (int i = 0; i < idx; i++) {
                    if (isMASUKANEqual(strToMASUKAN(ELMT(*pengguna, i).username, stringLength(ELMT(*pengguna, i).username)), username_temp)) {
                        printf("Wah, sayang sekali nama tersebut telah diambil.\n");
                        printf("Masukkan nama: ");
                        baca(&username_temp);
                    }
                }
                uservalid = true;
            }
        }

        char username[MAX_USERNAME_LENGTH];
        MASUKANToStr(username_temp, username);
        strcpy(ELMT(*pengguna, idx).username, username);
        printf("username: %s\n", ELMT(*pengguna, idx).username);

        boolean passwordvalid = false;
        MASUKAN password_temp;
        printf("Masukkan kata sandi: ");
        baca(&password_temp);

        while (!passwordvalid) {
            if (password_temp.Length > 20) {
                printf("Kata sandi yang anda masukkan > 20 karakter. Ayo coba lagi.\n");
                    printf("Masukkan kata sandi: ");
                    baca(&password_temp);
            } else {
                passwordvalid = true;
            }
        }

        char password[MAX_PASSWORD_LENGTH];
        MASUKANToStr(password_temp, password);
        printf("idx skrg: %d\n", idx);
        strcpy(ELMT(*pengguna, idx).password, password);
        printf("password: %s\n", ELMT(*pengguna, idx).password);
        
        printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
        
    }
}

// masuk sebagai pengguna
boolean MASUK(ListStatik *pengguna, boolean *isLoggedin) {
    if (*isLoggedin) {
        printf("Wah Anda sudah masuk. Keluar dulu yuk!\n");
        return *isLoggedin;
    }

    MASUKAN username;
    printf("Masukkan nama: ");
    baca(&username);

    // cari pengguna dengan nama yang cocok
    int userIndex = -1;

    do {
        boolean found = false;
        int i = 0;
        while (i < listLength(*pengguna)) {
            if (isMASUKANEqual(strToMASUKAN(ELMT(*pengguna, i).username, stringLength(ELMT(*pengguna, i).username)), username)) {
                userIndex = i;
                found = true;
                break;
            }
            i++;
        }

        if (userIndex == -1) {
            printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
            printf("Masukkan nama: ");
            baca(&username);
        }
    } while (userIndex == -1);

    MASUKAN password;
    printf("Masukkan kata sandi: ");
    baca(&password);
    boolean passwordvalid = false;

    do {
        if (isMASUKANEqual(strToMASUKAN(ELMT(*pengguna, userIndex).password, stringLength(ELMT(*pengguna, userIndex).password)), password)) {
            *isLoggedin = true;
            char username_str[MAX_USERNAME_LENGTH];
            MASUKANToStr(username, username_str);
            printf("Anda telah berhasil masuk dengan nama pengguna %s. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n", username_str);
            passwordvalid = true;
        } else {
            printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
            printf("Masukkan kata sandi: ");
    baca(&password);
        }
    } while (!passwordvalid);

    return *isLoggedin;
}

// keluar dari akun pengguna
boolean KELUAR(boolean *isLoggedin) {
    if (!*isLoggedin) {
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    } else {
        *isLoggedin = false;
        printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n");
    }
    return *isLoggedin;
}

int main() {
    MASUKAN command;
    boolean isLoggedin = false;
    ListStatik pengguna;
    CreateListStatik(&pengguna);

    printf(">> ");
    baca(&command);
    while (!isSame(command, "TUTUP_PROGRAM;")) {   
        if (isSame(command, "DAFTAR;")) {
            DAFTAR(&pengguna, isLoggedin);
        } else if(isSame(command, "MASUK;")){
            isLoggedin = MASUK(&pengguna, &isLoggedin);
        } else if(isSame(command, "KELUAR;")){
            isLoggedin = KELUAR(&isLoggedin);
        }

        printList(&pengguna);
        printf("\n");
        printf("%d\n", listLength(pengguna));

        printf(">> ");
        baca(&command);
    }

    if (isSame(command, "\nTUTUP_PROGRAM;")) {
        printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
    }

    return 0;
}