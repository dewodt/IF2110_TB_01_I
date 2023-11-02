#include <stdio.h>
#include <stdlib.h>
#include "modifiedliststatik.c"
#include "modifiedmatrix.h"
#include "./ADT/wordmachine/wordmachine.h"
#include "boolean.h"
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
        
        Word username_temp;
        printf("Masukkan nama: ");
        baca(&username_temp);

        // cek apakah nama pengguna udah ada
        for (int i = 0; i < idx; i++) {
            if (isWordEqual(strToWord(ELMT(*pengguna, i).username, stringLength(ELMT(*pengguna, i).username)), username_temp)) {
                printf("Wah, sayang sekali nama tersebut telah diambil.\n");
                return;
            }
        }

        char username[MAX_USERNAME_LENGTH];
        wordToStr(username_temp, username);
        strcpy(ELMT(*pengguna, idx).username, username);
        printf("username: %s\n", ELMT(*pengguna, idx).username);

        Word password_temp;
        printf("Masukkan kata sandi: ");
        baca(&password_temp);

        char password[MAX_PASSWORD_LENGTH];
        wordToStr(password_temp, password);
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

    Word username;
    printf("Masukkan nama: ");
    baca(&username);

    // cari pengguna dengan nama yang cocok
    int userIndex = -1;
    boolean found = false;
    int i = 0;

    while (i <= listLength(*pengguna) && (!found)) {
        if (isWordEqual(strToWord(ELMT(*pengguna, i).username, stringLength(ELMT(*pengguna, i).username)), username)) {
            found = true;
            userIndex = i;
        } else {
            i++;
        }

    }

    if (userIndex == -1) {
        printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
        return *isLoggedin;
    } else {
        Word password;
        printf("Masukkan kata sandi: ");
        baca(&password);

        if (isWordEqual(strToWord(ELMT(*pengguna, userIndex).password, stringLength(ELMT(*pengguna, userIndex).password)), password)) {
                *isLoggedin = true;
                char username_str[MAX_USERNAME_LENGTH];
                wordToStr(username, username_str);
                printf("Anda telah berhasil masuk dengan nama pengguna %s. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n", username_str + 1);
            } else {
                printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
            }
        }

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
    Word command;
    boolean isLoggedin = false;
    ListStatik pengguna;
    CreateListStatik(&pengguna);

    printf(">> ");
    baca(&command);
    while (!isSame(command, "\nTUTUP_PROGRAM;")) {   
        if (isSame(command, "\nDAFTAR;")) {
            DAFTAR(&pengguna, isLoggedin);
        } else if(isSame(command, "\nMASUK;")){
            isLoggedin = MASUK(&pengguna, &isLoggedin);
        } else if(isSame(command, "\nKELUAR;")){
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