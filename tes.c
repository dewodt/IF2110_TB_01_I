#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "modifiedliststatik.h"
#include "modifiedmatrix.h"
#include "./ADT/wordmachine/wordmachine.h"
#include "boolean.h"
#include "./ADT/pcolor/pcolor.h"
#include "./ADT/Baca/baca.c"

Word strToWord(char str[], int len) {
    int i;
    Word kata;
    kata.Length = len;
    for (i = 0; i < len; i++)
    {
        kata.TabWord[i] = str[i];
    }
    return kata;
}

void wordToStr(Word word, char *str) {
    int len = word.Length;
    strncpy(str, word.TabWord, len); // Use strncpy to ensure null-termination
    str[len] = '\0'; // Null-terminate the destination string
}

int stringLength(const char *str) {
    return strlen(str);
}

boolean isWordEqual(Word word1, Word word2) {
    int i;
    if (word1.Length != word2.Length) {
        return false;
    }
    for (i = 0; i < word1.Length; i++)
    {
        if (word1.TabWord[i] != word2.TabWord[i]) {
            return false;
        }
    }
    return true;
}

// mendaftarkan pengguna
ListStatik DAFTAR(ListStatik pengguna, boolean isLoggedin) {
    if (isLoggedin) {
        printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
    } else {
        if (listLength(pengguna) >= MAX_USERS) {
            printf("Maaf, kapasitas pengguna sudah penuh. Tidak dapat mendaftar lebih banyak pengguna.\n");
            return pengguna;
        }

        int idx = listLength(pengguna);
        printList(pengguna);
        printf("\n");
        printf("listlength: %d\n", idx);

        Word username_temp;
        printf("Masukkan nama: ");
        baca(&username_temp);

        // cek apakah nama pengguna udah ada
        for (int i = 0; i < listLength(pengguna); i++) {
            if (isWordEqual(strToWord(ELMT(pengguna, i).username, stringLength(ELMT(pengguna, i).username)), username_temp)) {
                printf("Wah, sayang sekali nama tersebut telah diambil.\n");
                return pengguna;
            }
        }

        char username[MAX_USERNAME_LENGTH];
        wordToStr(username_temp, username);
        strncpy(ELMT(pengguna, idx).username, username, MAX_USERNAME_LENGTH);

        printf("username: %s\n", ELMT(pengguna, idx).username);

        Word password_temp;
        printf("Masukkan kata sandi: ");
        baca(&password_temp);

        char password[MAX_PASSWORD_LENGTH];
        wordToStr(password_temp, password);
        strncpy(ELMT(pengguna, idx).password, password, MAX_PASSWORD_LENGTH);
        printf("password: %s\n", ELMT(pengguna, idx).password);

        printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
    }

    return pengguna;
}

// masuk sebagai pengguna
boolean MASUK(ListStatik pengguna, boolean isLoggedin) {
    if (isLoggedin) {
        printf("Wah Anda sudah masuk. Keluar dulu yuk!\n");
        return isLoggedin;
    }

    Word username;
    printf("Masukkan nama: ");
    baca(&username);

    // cari pengguna dengan nama yang cocok
    int userIndex = -1;
    boolean found = false;
    int i = 0;

    while (i < listLength(pengguna) && (!found)) {
        if (isWordEqual(strToWord(ELMT(pengguna, i).username, stringLength(ELMT(pengguna, i).username)), username)) {
            found = true;
            userIndex = i;
        } else {
            i++;
        }

    }

    if (userIndex == -1) {
        printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
        return isLoggedin;
    } else {
        Word password;
        printf("Masukkan kata sandi: ");
        baca(&password);

        if (isWordEqual(strToWord(ELMT(pengguna, i).password, stringLength(ELMT(pengguna, i).password)), password)) {
                isLoggedin = true;
                char username_str[MAX_USERNAME_LENGTH];
                wordToStr(username, username_str);
                printf("Anda telah berhasil masuk dengan nama pengguna %s. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n", username_str);
            } else {
                printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
            }
        }

        return isLoggedin;
}

// keluar dari akun pengguna
boolean KELUAR(boolean isLoggedin) {
    if (!isLoggedin) {
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    } else {
        isLoggedin = false;
        printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n");
    }
    return isLoggedin;
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
            if (isLoggedin) {
                printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
                isLoggedin = true;
                printf(">> ");
                baca(&command);
            } else {
                if (listLength(pengguna) >= MAX_USERS) {
                    printf("Maaf, kapasitas pengguna sudah penuh. Tidak dapat mendaftar lebih banyak pengguna.\n");
                    continue;
                }

                int idx = listLength(pengguna);
                printList(pengguna);
                printf("\n");
                printf("listlength: %d\n", idx);
                
                Word username_temp;
                printf("Masukkan nama: ");
                baca(&username_temp);

                // cek apakah nama pengguna udah ada
                for (int i = 0; i < listLength(pengguna); i++) {
                    if (isWordEqual(strToWord(ELMT(pengguna, i).username, stringLength(ELMT(pengguna, i).username)), username_temp)) {
                        printf("Wah, sayang sekali nama tersebut telah diambil.\n");
                        continue;
                    }
                }

                char username[MAX_USERNAME_LENGTH];
                wordToStr(username_temp, username);
                strcpy(ELMT(pengguna, idx).username, username);
                printf("username: %s\n", ELMT(pengguna, idx).username);

                Word password_temp;
                printf("Masukkan kata sandi: ");
                baca(&password_temp);

                char password[MAX_PASSWORD_LENGTH];
                wordToStr(password_temp, password);
                strcpy(ELMT(pengguna, idx).password, password);
                printf("password: %s\n", ELMT(pengguna, idx).password);
                
                printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
            }
        } else if(isSame(command, "\nMASUK;")){
            if (isLoggedin) {
                printf("Wah Anda sudah masuk. Keluar dulu yuk!\n");
                isLoggedin = true;
                printf(">> ");
                baca(&command);
            }

            Word username;
            printf("Masukkan nama: ");
            baca(&username);

            // cari pengguna dengan nama yang cocok
            int userIndex = -1;
            boolean found = false;
            int i = 0;

            while (i < listLength(pengguna) && (!found)) {
                if (isWordEqual(strToWord(ELMT(pengguna, i).username, stringLength(ELMT(pengguna, i).username)), username)) {
                    found = true;
                    userIndex = i;
                } else {
                    i++;
                }

            }

            if (userIndex == -1) {
                printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
                continue;
            } else {
                Word password;
                printf("Masukkan kata sandi: ");
                baca(&password);

                if (isWordEqual(strToWord(ELMT(pengguna, i).password, stringLength(ELMT(pengguna, i).password)), password)) {
                        isLoggedin = true;
                        char username_str[MAX_USERNAME_LENGTH];
                        wordToStr(username, username_str);
                        printf("Anda telah berhasil masuk dengan nama pengguna %s. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n", username_str + 1);
                    } else {
                        printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
                        printf("Masukkan kata sandi: ");
                        baca(&password);
                    }
                }
        } else if (isSame(command, "\nKELUAR;")){
            if (!isLoggedin) {
                printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            } else {
                isLoggedin = false;
                printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n");
            }
        }
        printList(pengguna);
        printf("\n");

        printf(">> ");
        baca(&command);
    }

    return 0;
}