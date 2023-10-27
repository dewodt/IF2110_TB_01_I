#include <stdio.h>
#include <string.h>

// struktur data untuk pengguna
struct User {
    char username[20];
    char password[20];
};

// menyimpan pengguna ke file konfigurasi
void saveUsers(struct User users[], int totalUsers) {
    FILE *file = fopen("config-1", "w");
    if (file == NULL) {
        // gagal membuka file untuk penulisan
        return;
    }

    for (int i = 0; i < totalUsers; i++) {
        fprintf(file, "%s %s\n", users[i].username, users[i].password);
    }

    fclose(file);
}

// membaca pengguna dari file konfigurasi
void loadUsers(struct User users[], int *totalUsers) {
    FILE *file = fopen("config-1", "r");
    if (file == NULL) {
        // file konfigurasi tidak ditemukan atau tidak dapat dibaca
        return;
    }

    *totalUsers = 0;
    while (fscanf(file, "%s %s", users[*totalUsers].username, users[*totalUsers].password) == 2) {
        (*totalUsers)++;
    }

    fclose(file);
}

// daftar pengguna (max 20)
struct User users[20];
int totalUsers = 0;

// mendaftarkan pengguna
void DAFTAR() {
    if (totalUsers >= 20) {
        printf("Maaf, kapasitas pengguna sudah penuh. Tidak dapat mendaftar lebih banyak pengguna.\n");
        return;
    }

    struct User newUser;
    printf("Masukkan nama: ");
    scanf("%s", newUser.username);

    // cek apakah nama pengguna udah ada
    for (int i = 0; i < totalUsers; i++) {
        if (strcmp(users[i].username, newUser.username) == 0) {
            printf("Wah, sayang sekali nama tersebut telah diambil.\n");
            return;
        }
    }

    printf("Masukkan kata sandi: ");
    scanf("%s", newUser.password);

    // simpan pengguna baru
    users[totalUsers] = newUser;
    totalUsers++;
    printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");

    // simpan pengguna baru ke file konfigurasi
    saveUsers(users, totalUsers);
}

// masuk sebagai pengguna
void MASUK() {
    char username[20];
    char password[20];
    printf("Masukkan nama: ");
    scanf("%s", username);

    // cari pengguna dengan nama yang cocok
    int userIndex = -1;
    for (int i = 0; i < totalUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            userIndex = i;
            break;
        }
    }

    if (userIndex == -1) {
        printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
        return;
    }

    printf("Masukkan kata sandi: ");
    scanf("%s", password);

    if (strcmp(users[userIndex].password, password) == 0) {
        printf("Anda telah berhasil masuk dengan nama pengguna %s. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n", username);
    } else {
        printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
    }
}

// keluar dari akun pengguna
void KELUAR() {
    printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n");
}

int main() {
    char command[20];
    loadUsers(users, &totalUsers);

    while (1) {
        printf(">> ");
        scanf("%s", command);

        if (strcmp(command, "DAFTAR;") == 0) {
            DAFTAR();
        } else if (strcmp(command, "MASUK;") == 0) {
            MASUK();
        } else if (strcmp(command, "KELUAR;") == 0) {
            KELUAR();
        }
    }
}