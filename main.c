#include <stdio.h>
#include "ADT/masukan/masukan.h"
#include "ADT/listdinkicauan/listdinkicauan.h"
#include "ADT/modifiedliststatik/modifiedliststatik.h"
#include "ADT/listdinUtas/listdinForUtas.h"
#include "ADT/masukan/masukanFile.h"
#include "ADT/matrixteman/matrixteman.h"
#include "ADT/prioQueue/prioQueueint.h"
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
PrioQueueint Q;

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
    printf("Silahkan masukan folder konfigurasi untuk dimuat: \n");
    printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");

    // Buat user
    User user1, user2;
    strcpy(user1.username, "Budi");
    user1.isPrivate = false; // Public
    // CreateEmptyStack(&user1.draf);
    listUser.contents[0] = user1;

    strcpy(user2.username, "Hadi");
    user2.isPrivate = true; // Privat
    listUser.contents[1] = user2;

    // Buat Kicauans
    Kicauan k1, k2, k3, k4, k5;
    DATETIME datetime;
    GetCurrentLocalDATETIME(&datetime);
    CreateKicauan(&k1, 1, "tes1", 10, &listUser.contents[1], datetime);
    TreeKicauan tk1 = newNodeKicauan(k1);

    CreateKicauan(&k2, 2, "tes2", 0, &listUser.contents[0], datetime);
    TreeKicauan tk2 = newNodeKicauan(k2);

    CreateKicauan(&k3, 3, "tes3", 90, &listUser.contents[0], datetime);
    TreeKicauan tk3 = newNodeKicauan(k3);

    CreateKicauan(&k4, 4, "tes4", 0, &listUser.contents[1], datetime);
    TreeKicauan tk4 = newNodeKicauan(k4);

    GetCurrentLocalDATETIME(&datetime);
    CreateKicauan(&k5, 5, "tes5", 0, &user1, datetime);
    TreeKicauan tk5 = newNodeKicauan(k5);

    // Insert List Kicauan
    insertLastListDinKicauan(&listKicauan, tk1);
    insertLastListDinKicauan(&listKicauan, tk2);
    insertLastListDinKicauan(&listKicauan, tk3);
    insertLastListDinKicauan(&listKicauan, tk4);
    insertLastListDinKicauan(&listKicauan, tk5);

    // Baca config
    printf(">>");
    MASUKAN command, arg1, arg2;

    perintah(&command, &arg1, &arg2);
    // Proses salin konfig ke dalam variabel program
    // bacaPengguna(&listUser, kata);
    // bacaKicauan(&listKicauan, kata, listUser);
    // bacaBalasan(&listKicauan, kata, listUser);

    bacaUtas(command);

    currentUser = &user1;
    // DISPLAY SEMUA KICAUAN DALAM LIST KICAUAN

    printf("============================ KICAUAN LOADED IN  ============================\n");
    for (int i = 0; i < listDinKicauanLength(listKicauan); i++)
    {
        printDetailKicauan(InfoKicauan(BUFFER_LDK(listKicauan)[i]));
    }

    // DISPLAY SEMUA UTAS DALAM LIST UTAS
    printf("============================ UTAS LOADED IN  ============================\n");
    for (int i = 0; i < listUtasLength(listUtas); i++)
    {
        displayUtas(BUFFERListDinUtas(listUtas)[i]);
        printf("ID UTAS = %d\n", IDUtas(BUFFERListDinUtas(listUtas)[i]));
    }

    // printf("MASUK WHILE");
    while (!isSame(command, "TUTUP_PROGRAM"))
    {

        if (isSame(command, "DAFTAR;"))
        {
            printf("ini DAFTAR\n");
        }
        // else if (isSame(kata, "\nDAFTAR;"))
        // {
        //     printf("ini DAFTAR");
        // }
        // else if (isSame(kata, "\nMASUK;"))
        // {
        //     printf("ini MASUK");
        // }
        // else if (isSame(kata, "\nMASUK;"))
        // {
        //     printf("ini MASUK");
        // }
        // else if (isSame(kata, "\nKELUAR;"))
        // {
        //     printf("ini KELUAR");
        // }
        // else if (isSame(kata, "\nKELUAR;"))
        // {
        //     printf("ini KELUAR");
        // }
        // else if (isSame(kata, "\nTUTUP_PROGRAM;"))
        // {
        //     printf("ini TUTUP_PROGRAM");
        // }
        // else if (isSame(kata, "\nTUTUP_PROGRAM;"))
        // {
        //     printf("ini TUTUP_PROGRAM");
        // }
        // else if (isSame(kata, "\nGANTI_PROFIL;"))
        // {
        //     printf("ini GANTI_PROFIL");
        // }
        // else if (isSame(kata, "\nGANTI_PROFIL;"))
        // {
        //     printf("ini GANTI_PROFIL");
        // }
        // else if (isSame(kata, "\nLIHAT_PROFIL;"))
        // {
        //     printf("ini LIHAT_PROFIL");
        // }
        // else if (isSame(kata, "\nLIHAT_PROFIL;"))
        // {
        //     printf("ini LIHAT_PROFIL");
        // }
        // else if (isSame(kata, "\nATUR_JENIS_AKUN;"))
        // {
        //     printf("ini ATUR_JENIS_AKUN");
        // }
        // else if (isSame(kata, "\nATUR_JENIS_AKUN;"))
        // {
        //     printf("ini ATUR_JENIS_AKUN");
        // }
        // else if (isSame(kata, "\nUBAH_FOTO_PROFIL;"))
        // {
        //     printf("ini UBAH_FOTO_PROFIL");
        // }
        // else if (isSame(kata, "\nUBAH_FOTO_PROFIL;"))
        // {
        //     printf("ini UBAH_FOTO_PROFIL");
        // }
        // else if (isSame(kata, "\nDAFTAR_TEMAN;"))
        // {
        //     printf("ini DAFTAR_TEMAN");
        // }
        // else if (isSame(kata, "\nDAFTAR_TEMAN;"))
        // {
        //     printf("ini DAFTAR_TEMAN");
        // }
        // else if (isSame(kata, "\nHAPUS_TEMAN;"))
        // {
        //     printf("ini HAPUS_TEMAN");
        // }
        // else if (isSame(kata, "\nHAPUS_TEMAN;"))
        // {
        //     printf("ini HAPUS_TEMAN");
        // }
        // else if (isSame(kata, "\nTAMBAH_TEMAN;"))
        // {
        //     printf("ini TAMBAH_TEMAN");
        // }
        // else if (isSame(kata, "\nTAMBAH_TEMAN;"))
        // {
        //     printf("ini TAMBAH_TEMAN");
        // }
        // else if (isSame(kata, "\nBATAL_TAMBAH_TEMAN;"))
        // {
        //     printf("ini BATAL_TAMBAH_TEMAN");
        // }
        // else if (isSame(kata, "\nBATAL_TAMBAH_TEMAN;"))
        // {
        //     printf("ini BATAL_TAMBAH_TEMAN");
        // }
        // else if (isSame(kata, "\nDAFTAR_PERMINTAAN_PERTEMANAN;"))
        // {
        //     printf("ini DAFTAR_PERMINTAAN_PERTEMANAN");
        // }
        // else if (isSame(kata, "\nDAFTAR_PERMINTAAN_PERTEMANAN;"))
        // {
        //     printf("ini DAFTAR_PERMINTAAN_PERTEMANAN");
        // }
        // else if (isSame(kata, "\nSETUJUI_PERTEMANAN;"))
        // {
        //     printf("ini SETUJUI_PERTEMANAN");
        // }
        // else if (isSame(kata, "\nSETUJUI_PERTEMANAN;"))
        // {
        //     printf("ini SETUJUI_PERTEMANAN");
        // }
        // else if (isSame(kata, "\nKICAU;"))
        // {
        //     printf("ini KICAU");
        // }
        // else if (isSame(kata, "\nKICAU;"))
        // {
        //     printf("ini KICAU");
        // }
        // else if (isSame(kata, "\nSUKA_KICAUAN;"))
        // {
        //     printf("ini SUKA_KICAUAN");
        // }
        // else if (isSame(kata, "\nSUKA_KICAUAN;"))
        // {
        //     printf("ini SUKA_KICAUAN");
        // }
        // else if (isSame(kata, "\nUBAH_KICAUAN;"))
        // {
        //     printf("ini UBAH_KICAUAN");
        // }
        // else if (isSame(kata, "\nUBAH_KICAUAN;"))
        // {
        //     printf("ini UBAH_KICAUAN");
        // }
        // else if (isSame(kata, "\nBALAS;"))
        // {
        //     printf("ini BALAS");
        // }
        // else if (isSame(kata, "\nBALAS;"))
        // {
        //     printf("ini BALAS");
        // }
        // else if (isSame(kata, "\nBALASAN;"))
        // {
        //     printf("ini BALASAN");
        // }
        // else if (isSame(kata, "\nBALASAN;"))
        // {
        //     printf("ini BALASAN");
        // }
        // else if (isSame(kata, "\nHAPUS_BALASAN;"))
        // {
        //     printf("ini HAPUS_BALASAN");
        // }
        // else if (isSame(kata, "\nHAPUS_BALASAN;"))
        // {
        //     printf("ini HAPUS_BALASAN");
        // }
        // else if (isSame(kata, "\nBUAT_DRAF;"))
        // {
        //     printf("ini BUAT_DRAF");
        // }
        // else if (isSame(kata, "\nBUAT_DRAF;"))
        // {
        //     printf("ini BUAT_DRAF");
        // }
        // else if (isSame(kata, "\nLIHAT_DRAF;"))
        // {
        //     printf("ini LIHAT_DRAF");
        // }
        // else if (isSame(kata, "\nLIHAT_DRAF;"))
        // {
        //     printf("ini LIHAT_DRAF");
        // }
        else if (isSame(command, "UTAS"))
        {
            BUAT_UTAS(masukanToInt(arg1));
        }

        else if (isSame(command, "SAMBUNG_UTAS")) // bacaUtas(listKicauan, kata, listUser, &listUtas);
        {
            SAMBUNG_UTAS(masukanToInt(arg1), masukanToInt(arg2));
        }
        else if (isSame(command, "HAPUS_UTAS"))
        {
            HAPUS_UTAS(masukanToInt(arg1), masukanToInt(arg2));
        }
        else if (isSame(command, "CETAK_UTAS"))
        {
            CETAK_UTAS(masukanToInt(arg1));
        }
        // else if (isSame(kata, "\nSIMPAN;"))
        //
        //     printf("ini SIMPAN");
        // }

        // bacaPengguna(&listUser, kata);
        // bacaKicauan(&listKicauan, kata, listUser);
        // bacaBalasan(&listKicauan, kata, listUser);
        // bacaUtas(listKicauan, kata, listUser, &listUtas);
        // bacaDraf(listKicauan, kata, listUser);

        // else if (isSame(kata, "\nSIMPAN;"))
        // {
        //     printf("ini SIMPAN");
        // }
        // else if (isSame(kata, "\nMUAT;"))
        // {
        //     printf("ini MUAT");
        // }
        // else if (isSame(kata, "\nMUAT;"))
        // {
        //     printf("ini MUAT");
        // }
        // else
        // {
        //     printf("lainnya\n");
        // }
        printf(">> ");
        perintah(&command, &arg1, &arg2);
    }
    printf("###################Akhir#######################\n ");
    return 0;
}