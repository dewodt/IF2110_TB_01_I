#include <stdio.h>
#include "ADT/masukan/masukan.h"
#include "ADT/listdinkicauan/listdinkicauan.h"
#include "ADT/modifiedliststatik/modifiedliststatik.h"
#include "ADT/listdinUtas/listdinForUtas.h"
#include "ADT/masukan/masukanFile.h"
#include "ADT/matrixteman/matrixteman.h"
#include "ADT/prioQueue/prioQueueint.h"
#include "ADT/pengguna/pengguna.h"

/* GLOBAL VARIABLES:
currentUser
listKicauan
listUser
continue
*/

/* GLOBAL VARIABLES */
ListDinKicauan listKicauan;
ListStatik listUser;
ListUtas listUtas;
User *currentUser;
int jumlahPengguna;
MatrixTeman RelasiPertemanan;
PrioQueueint Q;

char commandStr[50];
char commandAwal[50];
MASUKAN namapengguna;

int main()
{
    // Inisialisasi global variable
    CreateListDinKicauan(&listKicauan, 100);
    CreateListUtas(&listUtas, 100);
    CreateListStatik(&listUser);
    currentUser = NULL;

    // Tampilan awal
    printf(".______    __    __  .______      .______    __  .______ \n");
    printf("|   _  \\  |  |  |  | |   _  \\     |   _  \\  |  | |   _  \\\n");
    printf("|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |\n");
    printf("|   _  <  |  |  |  | |      /     |   _  <  |  | |      /     \n");
    printf("|  |_)  | |  `--'  | |  |\\  \\----.|  |_)  | |  | |  |\\  \\----.\n");
    printf("|______/   \\______/  | _| `._____||______/  |__| | _| `._____|\n");
    printf("Selamat datang di BurBir.\n");
    printf("Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan \n");
    printf("metode (pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n");
    // printf("Silahkan masukan folder konfigurasi untuk dimuat: \n");
    // printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");

    // Baca config
    MASUKAN kata, arg1, arg2;
    printf(">> ");
    baca(&kata);
    // Proses salin konfig ke dalam variabel program
    // bacaPengguna(&listUser,kata);
    // bacaKicauan(&listKicauan,kata,listUser);
    // bacaBalasan(&listKicauan,kata,listUser);
    // bacaUtas(listKicauan,kata,listUser,&listUtas);
    // bacaDraf(listKicauan,kata,listUser);
    // printf(">> ");

    while (!isSame(kata, "TUTUP_PROGRAM;"))
    {
        if (isSame(kata, "DAFTAR;"))
        {
            DAFTAR(&listUser);
        }
        else if (isSame(kata, "MASUK;"))
        {
            MASUK(&listUser, &currentUser);
        }
        else if (isSame(kata, "KELUAR;"))
        {
            KELUAR(&currentUser);
        }
        else if (isSame(kata, "GANTI_PROFIL;"))
        {
            GANTI_PROFIL(&listUser, currentUser);
        }
        else if (compareString(kata.TabMASUKAN, "LIHAT_PROFIL", 12) == 0)
        {
            int len = kata.Length;
            int idx = 0;

            // mencari indeks awal nama pengguna
            while (idx < len && kata.TabMASUKAN[idx] != ' ')
            {
                idx++;
            }

            if (idx < len)
            {
                // copy perintah awal (tanpa spasi akhir) dan nama pengguna
                for (int i = 0; i < idx; i++)
                {
                    commandAwal[i] = kata.TabMASUKAN[i];
                }
                commandAwal[idx] = '\0'; // null-terminator

                int j = 0;
                for (int i = idx + 1; i < len; i++)
                {
                    namapengguna.TabMASUKAN[j] = kata.TabMASUKAN[i];
                    j++;
                }
                namapengguna.Length = j;
                namapengguna.TabMASUKAN[j] = '\0'; // null-terminator

                // printf("Perintah Awal: %s\n", commandAwal);
                // printf("Nama Pengguna: %s\n", namapengguna.TabMASUKAN);

                // baru call fungsi LIHAT_PROFIL dengan namapengguna
                LIHAT_PROFIL(&listUser, namapengguna);
            }
        }
        else if (isSame(kata, "UBAH_FOTO_PROFIL;"))
        {
            UBAH_FOTO_PROFIL(&listUser, currentUser);
        }
        else if (isSame(kata, "ATUR_JENIS_AKUN;"))
        {
            ATUR_JENIS_AKUN(&listUser, currentUser);
        }
        else if (isSame(kata, "\nDAFTAR_TEMAN;"))
        {
            printf("ini DAFTAR_TEMAN");
        }
        else if (isSame(kata, "\nHAPUS_TEMAN;"))
        {
            printf("ini HAPUS_TEMAN");
        }
        else if (isSame(kata, "\nTAMBAH_TEMAN;"))
        {
            printf("ini TAMBAH_TEMAN");
        }
        else if (isSame(kata, "\nBATAL_TAMBAH_TEMAN;"))
        {
            printf("ini BATAL_TAMBAH_TEMAN");
        }
        else if (isSame(kata, "\nDAFTAR_PERMINTAAN_PERTEMANAN;"))
        {
            printf("ini DAFTAR_PERMINTAAN_PERTEMANAN");
        }
        else if (isSame(kata, "\nSETUJUI_PERTEMANAN;"))
        {
            printf("ini SETUJUI_PERTEMANAN");
        }
        else if (isSame(kata, "\nKICAU"))
        {
            BuatKicauan(&listKicauan, currentUser);
        }
        else if (isSame(kata, "\nKICAUAN"))
        {
            TampilkanKicauan(listKicauan, currentUser);
        }
        else if (isSame(kata, "\nSUKA_KICAUAN"))
        {
            printf("ini SUKA_KICAUAN");
        }
        else if (isSame(kata, "\nUBAH_KICAUAN;"))
        {
            printf("ini UBAH_KICAUAN");
        }
        else if (isSame(kata, "\nBALAS;"))
        {
            printf("ini BALAS");
        }
        else if (isSame(kata, "\nBALASAN;"))
        {
            printf("ini BALASAN");
        }
        else if (isSame(kata, "\nHAPUS_BALASAN;"))
        {
            printf("ini HAPUS_BALASAN");
        }
        else if (isSame(kata, "\nBUAT_DRAF;"))
        {
            printf("ini BUAT_DRAF");
        }
        else if (isSame(kata, "\nLIHAT_DRAF;"))
        {
            printf("ini LIHAT_DRAF");
        }
        else if (isSame(kata, "\nUTAS;"))
        {
            printf("ini UTAS");
        }
        else if (isSame(kata, "\nSAMBUNG_UTAS;"))
        {
            printf("ini SAMBUNG_UTAS");
        }
        else if (isSame(kata, "\nHAPUS_UTAS;"))
        {
            printf("ini HAPUS_UTAS");
        }
        else if (isSame(kata, "\nCETAK_UTAS;"))
        {
            printf("ini CETAK_UTAS");
        }
        else if (isSame(kata, "\nSIMPAN;"))
        {
            printf("ini SIMPAN");
        }
        else if (isSame(kata, "\nMUAT;"))
        {
            printf("ini MUAT");
        }
        printf(">> ");
        baca(&kata);
    }

    if (isSame(kata, "\nTUTUP_PROGRAM;"))
    {
        printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
    }

    printf("###################Akhir#######################\n ");
    return 0;
}