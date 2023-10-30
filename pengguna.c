#include <stdio.h>
#include <string.h>
#include "modifiedliststatik.h"
#include "modifiedmatrix.h"
#include "boolean.h"
#include "pcolor.h"

boolean isLoggedin = false;

// mendaftarkan pengguna
ListStatik DAFTAR(ListStatik pengguna) {
    if (isLoggedin) {
        printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
    } else {
        if (listLength(pengguna) == 20) {
            printf("Maaf, kapasitas pengguna sudah penuh. Tidak dapat mendaftar lebih banyak pengguna.\n");
            return pengguna;
        }

        int idx = listLength(pengguna);
        char username_temp[MAX_USERNAME_LENGTH];
        printf("Masukkan nama: ");
        fgets(username_temp, MAX_USERNAME_LENGTH, stdin);
        username_temp[strcspn(username_temp, "\n")] = '\0';

        // cek apakah nama pengguna udah ada
        for (int i = 0; i < listLength(pengguna); i++) {
            if (strcmp(ELMT(pengguna, i).username, username_temp) == 0) {
                printf("Wah, sayang sekali nama tersebut telah diambil.\n");
                return pengguna;
            }
        }

        strcpy(ELMT(pengguna, idx).username, username_temp);

        printf("Masukkan kata sandi: ");
        char password_temp[MAX_PASSWORD_LENGTH];
        fgets(password_temp, MAX_PASSWORD_LENGTH, stdin);
        password_temp[strcspn(password_temp, "\n")] = '\0';

        strcpy(ELMT(pengguna, idx).password, password_temp);
        printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
        // printList(pengguna);
    }
    return pengguna;
}

// masuk sebagai pengguna
void MASUK(ListStatik pengguna) {
    char username[MAX_USERNAME_LENGTH];

    printf("Masukkan nama: ");
    fgets(username, MAX_USERNAME_LENGTH, stdin);
    username[strcspn(username, "\n")] = '\0';

    // cari pengguna dengan nama yang cocok
    int userIndex = -1;
    boolean found = false;
    int i = 0;

    while (i < listLength(pengguna) && (!found)) {
        if (strcmp(ELMT(pengguna, i).username, username) == 0) {
            found = true;
            userIndex = i;
        } else {
            i++;
        }

    }

    if (userIndex == -1) {
        printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
        return;
    } else {
        char password[MAX_PASSWORD_LENGTH];
        
        printf("Masukkan kata sandi: ");
        fgets(password, MAX_PASSWORD_LENGTH, stdin);
        password[strcspn(password, "\n")] = '\0';

        if (strcmp(ELMT(pengguna, i).password, password) == 0) {
                isLoggedin = true;
                printf("Anda telah berhasil masuk dengan nama pengguna %s. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n", username);
            } else {
                printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
            }
        }
    }

// keluar dari akun pengguna
void KELUAR() {
    if (!isLoggedin) {
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    } else {
        isLoggedin = false;
        printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n");
    }
}

int main() {
    char command[20];
    ListStatik pengguna;
    CreateListStatik(&pengguna);

    while (1) {
        printf(">> ");
        fgets(command, 20, stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "DAFTAR") == 0) {
            pengguna = DAFTAR(pengguna);
        } else if (strcmp(command, "MASUK") == 0) {
            MASUK(pengguna);
        } else if (strcmp(command, "KELUAR") == 0) {
            KELUAR();
        }
        
        printList(pengguna);
        printf("\n");
    }

    return 0;
}
