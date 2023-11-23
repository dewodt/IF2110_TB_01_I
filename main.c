#include <stdio.h>
#include "ADT/masukan/masukan.h"
#include "ADT/listdinkicauan/listdinkicauan.h"
#include "ADT/modifiedliststatik/modifiedliststatik.h"
#include "ADT/listdinUtas/listdinForUtas.h"
#include "ADT/masukan/masukanFile.h"
#include "ADT/matrixteman/matrixteman.h"
#include "ADT/prioQueue/prioQueueint.h"
#include "ADT/pengguna/pengguna.h"
#include "ADT/teman/teman.h"
#include "ADT/Utas/utas.h"

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
    createMatrixTeman(20, 20, &RelasiPertemanan);
    currentUser = NULL;
    MakeEmpty(&Q, 100);
    
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
    perintah(&kata, &arg1, &arg2);
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
            MASUK(&listUser, &currentUser);;
        }
        else if (isSame(kata, "KELUAR;"))
        {
            KELUAR(&currentUser);
        }
        else if (isSame(kata, "GANTI_PROFIL;"))
        {
            GANTI_PROFIL(&listUser, currentUser);
        }
        else if (isSame(kata, "LIHAT_PROFIL"))
        {
            LIHAT_PROFIL(&listUser, arg1);
        }
        else if (isSame(kata, "UBAH_FOTO_PROFIL;"))
        {
            UBAH_FOTO_PROFIL(&listUser, currentUser);
        }
        else if (isSame(kata, "ATUR_JENIS_AKUN;"))
        {
            ATUR_JENIS_AKUN(&listUser, currentUser);
        }
        else if (isSame(kata, "DAFTAR_TEMAN;"))
        {
            showFriendList();
        }
        else if (isSame(kata, "HAPUS_TEMAN;"))
        {
            deleteFriend();
        }
        else if (isSame(kata, "TAMBAH_TEMAN;"))
        {
            TAMBAH_TEMAN(Q, searchID_Pengguna(strToMASUKAN(currentUser->username, stringLength(currentUser->username))), listUser);
            displayMatrixTeman(RelasiPertemanan);
        }
        else if (isSame(kata, "DAFTAR_PERMINTAAN_PERTEMANAN;"))
        {
            DAFTAR_PERMINTAAN_PERTEMANAN(Q, listUser, listLength(listUser));
        }
        else if (isSame(kata, "SETUJUI_PERTEMANAN;"))
        {
            SETUJUI_PERTEMANAN(&Q, searchID_Pengguna(strToMASUKAN(currentUser->username, stringLength(currentUser->username))), listUser, listLength(listUser));
        }
        else if (isSame(kata, "KICAU;"))
        {
            BuatKicauan(&listKicauan, currentUser);
        }
        else if (isSame(kata, "KICAUAN;"))
        {
            TampilkanKicauan(listKicauan, currentUser);
        }
        else if (isSame(kata, "SUKA_KICAUAN"))
        {
            int IDKicau;
            IDKicau = masukanToInt(arg1);
            SukaKicauan(IDKicau);
        }
        else if (isSame(kata, "UBAH_KICAUAN"))
        {
            int IDKicau;
            IDKicau = masukanToInt(arg1);
            UbahKicauan(IDKicau);
        }
        else if (isSame(kata, "BALAS"))
        {
            BuatBalasan(masukanToInt(arg1), masukanToInt(arg2));
        }
        else if (isSame(kata, "BALASAN;"))
        {
            TampilkanBalasan(masukanToInt(arg1));
        }
        else if (isSame(kata, "HAPUS_BALASAN;"))
        {
            HapusBalasan(masukanToInt(arg1), masukanToInt(arg2));
        }
        else if (isSame(kata, "BUAT_DRAF;"))
        {
            BuatDraf();
        }
        else if (isSame(kata, "LIHAT_DRAF;"))
        {
            LihatDraf();
        }
        else if (isSame(kata, "UTAS;"))
        {
            BUAT_UTAS(listKicauan, listUtas, *currentUser, masukanToInt(arg1));
        }
        else if (isSame(kata, "SAMBUNG_UTAS;"))
        {
            SAMBUNG_UTAS(masukanToInt(arg1), masukanToInt(arg2), &listUtas, *currentUser);
        }
        else if (isSame(kata, "HAPUS_UTAS;"))
        {
            HAPUS_UTAS(&listUtas, masukanToInt(arg1), masukanToInt(arg2), *currentUser);
        }
        else if (isSame(kata, "CETAK_UTAS;"))
        {
            printf("ini CETAK_UTAS");
        }
        else if (isSame(kata, "SIMPAN;"))
        {
            printf("ini SIMPAN");
        }
        else if (isSame(kata, "MUAT;"))
        {
            printf("ini MUAT");
        }
        printf(">> ");
        perintah(&kata, &arg1, &arg2);
    }

    if (isSame(kata, "\nTUTUP_PROGRAM;"))
    {
        printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
    }

    printf("###################Akhir#######################\n ");
    return 0;
}