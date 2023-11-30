#include <stdio.h>
#include "ADT/masukan/masukan.h"
#include "ADT/listdinkicauan/listdinkicauan.h"
#include "ADT/modifiedliststatik/modifiedliststatik.h"
#include "ADT/listdinUtas/listdinForUtas.h"
#include "ADT/masukan/masukanFile.h"
#include "ADT/matrixteman/matrixteman.h"
#include "ADT/prioQueue/prioQueueint.h"
#include "ADT/simpan/simpan.h"
#include "ADT/Utas/utas.h"
#include "ADT/kicauan/kicauan.h"
#include "ADT/datetime/datetime.h"

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
PrioQueueint prioQ;

int main()
{
    // Inisialisasi global variable
    CreateListDinKicauan(&listKicauan, 100);
    CreateListUtas(&listUtas, 100);
    CreateListStatik(&listUser);
    currentUser = NULL;
    createMatrixTeman(20,20,&RelasiPertemanan);
    MakeEmpty(&prioQ, 100);
    char commandStr[50];
    char commandAwal[50];
    MASUKAN namapengguna;
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
    printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
    bacaInisialisasi();


    MASUKAN kata,command, arg1, arg2, arg3;
    printf(">> ");
    baca(&kata);
    splitMasukanJadi2(kata,&command,&arg1);

    while (!isSame(command, "TUTUP_PROGRAM"))
    {

        if (isSame(command, "DAFTAR"))
        {
            DAFTAR(&listUser);
        }
        else if (isSame(command, "MASUK"))
        {
            MASUK(&listUser);
            int nTemp;
            searchID_Pengguna(strToMASUKAN(currentUser->username, stringLength(currentUser->username)),&nTemp);
            MakeEmpty(&prioQ, 100);
            isiReqPertemanan(listLength(listUser),nTemp);
        }
        else if (isSame(command, "KELUAR"))
        {
            KELUAR();
        }
        else if (isSame(command, "LIHAT_PROFIL"))
        {
            LIHAT_PROFIL(&listUser, arg1);
        }
        else if (isSame(command, "GANTI_PROFIL"))
        {
            GANTI_PROFIL(&listUser);
        }
        else if (isSame(command, "ATUR_JENIS_AKUN"))
        {
            ATUR_JENIS_AKUN(&listUser);
        }
        else if (isSame(command, "UBAH_FOTO_PROFIL"))
        {
            UBAH_FOTO_PROFIL(&listUser);
        }
        else if (isSame(command, "DAFTAR_TEMAN"))
        {
            printf("%d\n", listLength(listUser));
            showFriendList();
        }
        else if (isSame(command, "HAPUS_TEMAN"))
        {
            deleteFriend();
        }
        else if (isSame(command, "TAMBAH_TEMAN"))
        {
            int nTemp;
            searchID_Pengguna(strToMASUKAN(currentUser->username, stringLength(currentUser->username)),&nTemp);
            TAMBAH_TEMAN(nTemp, listUser);
            displayMatrixTeman(RelasiPertemanan);
        }
        else if (isSame(command, "DAFTAR_PERMINTAAN_PERTEMANAN"))
        {
            DAFTAR_PERMINTAAN_PERTEMANAN(listLength(listUser));
        }
        else if (isSame(command, "SETUJUI_PERTEMANAN"))
        {
            int nTemp;
            searchID_Pengguna(strToMASUKAN(currentUser->username, stringLength(currentUser->username)),&nTemp);
            printf("sebelum setujui\n");
            SETUJUI_PERTEMANAN(nTemp, listLength(listUser));
        }
        else if (isSame(command, "KICAU"))
        {
            BuatKicauan();
        }
        else if (isSame(command, "KICAUAN"))
        {
            TampilkanKicauan();
        }
        else if (isSame(command, "SUKA_KICAUAN"))
        {
            int IDKicau;
            IDKicau = masukanToInt(arg1);
            SukaKicauan(IDKicau);
        }
        else if (isSame(command, "UBAH_KICAUAN"))
        {
            int IDKicau;
            IDKicau = masukanToInt(arg1);
            UbahKicauan(IDKicau);
        }
        else if (isSame(command, "BALAS"))
        {
            splitMasukanJadi2(arg1,&arg2,&arg3);
            displayMASUKAN(arg2);
            displayMASUKAN(arg3);
            // printf("%d %d", arg2, arg3);
            printf("%d %d", masukanToInt(arg2), masukanToInt(arg3));
            BuatBalasan(masukanToInt(arg2), masukanToInt(arg3));
        }
        else if (isSame(command, "BALASAN"))
        {
            TampilkanBalasan(masukanToInt(arg1));
        }
        else if (isSame(command, "HAPUS_BALASAN"))
        {
            splitMasukanJadi2(arg1,&arg2,&arg3);
            HapusBalasan(masukanToInt(arg2), masukanToInt(arg3));
        }
        else if (isSame(command, "BUAT_DRAF"))
        {
            BuatDraf();
        }
        else if (isSame(command, "LIHAT_DRAF"))
        {
            LihatDraf();
        }
        else if (isSame(command, "UTAS"))
        {
            BUAT_UTAS(masukanToInt(arg1));
        }
        else if (isSame(command, "SAMBUNG_UTAS")) // bacaUtas(listKicauan, kata, listUser, &listUtas);
        {
            splitMasukanJadi2(arg1,&arg2,&arg3);
            SAMBUNG_UTAS(masukanToInt(arg2), masukanToInt(arg3));
        }
        else if (isSame(command, "HAPUS_UTAS"))
        {
            splitMasukanJadi2(arg1,&arg2,&arg3);
            HAPUS_UTAS(masukanToInt(arg2), masukanToInt(arg3));
        }
        else if (isSame(command, "CETAK_UTAS"))
        {
            CETAK_UTAS(masukanToInt(arg1));
        }
        else if (isSame(command, "SIMPAN"))
        {
            Simpan();
        }
        else if (isSame(command, "MUAT"))
        {
            bacaConfig();
        }
        printf(">> ");
        baca(&kata);
        splitMasukanJadi2(kata,&command,&arg1);
        
    }
    if (isSame(command, "TUTUP_PROGRAM"))
    {
        printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
    }
    printf("###################Akhir#######################\n ");
    return 0;
}