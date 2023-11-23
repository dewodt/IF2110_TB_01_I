#include <stdio.h>
#include "ADT/masukan/masukan.h"
#include "ADT/listdinkicauan/listdinkicauan.h"
#include "ADT/modifiedliststatik/modifiedliststatik.h"
#include "ADT/listdinUtas/listdinForUtas.h"
#include "ADT/masukan/masukanFile.h"
#include "ADT/matrixteman/matrixteman.h"
#include "ADT/prioQueue/prioQueueint.h"
#include "ADT/simpan/simpan.h"

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
    createMatrixTeman(20, 20, &RelasiPertemanan);
    currentUser = NULL;
    Stack s;
    CreateEmptyStack(&s);
    DRAF(listUser,0) = s;
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

    // Baca config
    MASUKAN kata;
    printf(">>");
    baca(&kata);

    // Proses salin konfig ke dalam variabel program
    // FILE* output;
    // output = fopen("config/config-1/pengguna.config", "r");
    // if(!output){
    //     printf("error\n");
    // }else{
    //     printf("berhasil\n");
    // }

    // Load User
    printf("\n\n\n\n");
    bacaPengguna(&listUser, kata);
    printf("sampe bacaPengguna\n");
    printf("%s\n", USERNAME(listUser, 0));
    printf("%s\n", PASSWORD(listUser, 0));
    printf("%s\n", MASUKANToStr(PHONE_NUM(listUser, 0)));
    printf("%s\n", WETON(listUser, 0));
    displayProfile(PROFILE(listUser, 0));
    printf("%s\n", USERNAME(listUser, 1));
    printf("%s\n", BIO(listUser, 1));
    printf("%s\n", USERNAME(listUser, 2));
    printf("%s\n", WETON(listUser, 2));
    displayMatrixTeman(RelasiPertemanan);

    // Simpan
    Simpan();

    // // DUMMY CURRENT USER
    // currentUser = &listUser.contents[0];
    // // currentUser = NULL;
    // printf("%p\n", currentUser);

    // printf("\n\n\n\n");
    // bacaKicauan(&listKicauan, kata, listUser);
    // printf("sampe bacaKicauan\n");
    // printDetailKicauan(ELMT_LDK(listKicauan, 0)->infoKicauan);
    // printf("\n");
    // printDetailKicauan(ELMT_LDK(listKicauan, 1)->infoKicauan);
    // TampilkanKicauan();
    // bacaDraf(kata);

    printf("%s\n", InfoTop(DRAF(listUser,0)).text);
    displayTime( InfoTop(DRAF(listUser,0)).datetime);
    printf("%s\n", InfoTop(DRAF(listUser,1)).text);
    displayTime( InfoTop(DRAF(listUser,1)).datetime);
    printf("sampe bacaDraf\n");

    Simpan();

    // printf("==================\n");
    // printf("==================\n");
    // printDetailKicauan(ELMT_LDK(listKicauan,0)->infoKicauan);
    // printf("==================\n");
    // printf("==================\n");
    // bacaBalasan(&listKicauan,kata,listUser);
    // TreeKicauan tk = ELMT_LDK(listKicauan,0);
    // // AddressBalasan ab = FirstLeftChildBalasan(tk);
    // // TampilkanBalasanRekursif(ab, 0);


    // printf("\n\n\n\n");
    // bacaUtas(listKicauan, kata, listUser, &listUtas);
    // printf("sampe bacaUtas\n");
    // printf(">>");

    while (!isSame(kata, "\nTUTUP_PROGRAM;"))
    {
        if (isSame(kata, "\nDAFTAR;"))
        {
            printf("ini DAFTAR");
        }
        else if (isSame(kata, "\nDAFTAR;"))
        {
            printf("ini DAFTAR");
        }
        else if (isSame(kata, "\nMASUK;"))
        {
            printf("ini MASUK");
        }
        else if (isSame(kata, "\nMASUK;"))
        {
            printf("ini MASUK");
        }
        else if (isSame(kata, "\nKELUAR;"))
        {
            printf("ini KELUAR");
        }
        else if (isSame(kata, "\nKELUAR;"))
        {
            printf("ini KELUAR");
        }
        else if (isSame(kata, "\nTUTUP_PROGRAM;"))
        {
            printf("ini TUTUP_PROGRAM");
        }
        else if (isSame(kata, "\nTUTUP_PROGRAM;"))
        {
            printf("ini TUTUP_PROGRAM");
        }
        else if (isSame(kata, "\nGANTI_PROFIL;"))
        {
            printf("ini GANTI_PROFIL");
        }
        else if (isSame(kata, "\nGANTI_PROFIL;"))
        {
            printf("ini GANTI_PROFIL");
        }
        else if (isSame(kata, "\nLIHAT_PROFIL;"))
        {
            printf("ini LIHAT_PROFIL");
        }
        else if (isSame(kata, "\nLIHAT_PROFIL;"))
        {
            printf("ini LIHAT_PROFIL");
        }
        else if (isSame(kata, "\nATUR_JENIS_AKUN;"))
        {
            printf("ini ATUR_JENIS_AKUN");
        }
        else if (isSame(kata, "\nATUR_JENIS_AKUN;"))
        {
            printf("ini ATUR_JENIS_AKUN");
        }
        else if (isSame(kata, "\nUBAH_FOTO_PROFIL;"))
        {
            printf("ini UBAH_FOTO_PROFIL");
        }
        else if (isSame(kata, "\nUBAH_FOTO_PROFIL;"))
        {
            printf("ini UBAH_FOTO_PROFIL");
        }
        else if (isSame(kata, "\nDAFTAR_TEMAN;"))
        {
            printf("ini DAFTAR_TEMAN");
        }
        else if (isSame(kata, "\nDAFTAR_TEMAN;"))
        {
            printf("ini DAFTAR_TEMAN");
        }
        else if (isSame(kata, "\nHAPUS_TEMAN;"))
        {
            printf("ini HAPUS_TEMAN");
        }
        else if (isSame(kata, "\nHAPUS_TEMAN;"))
        {
            printf("ini HAPUS_TEMAN");
        }
        else if (isSame(kata, "\nTAMBAH_TEMAN;"))
        {
            printf("ini TAMBAH_TEMAN");
        }
        else if (isSame(kata, "\nTAMBAH_TEMAN;"))
        {
            printf("ini TAMBAH_TEMAN");
        }
        else if (isSame(kata, "\nBATAL_TAMBAH_TEMAN;"))
        {
            printf("ini BATAL_TAMBAH_TEMAN");
        }
        else if (isSame(kata, "\nBATAL_TAMBAH_TEMAN;"))
        {
            printf("ini BATAL_TAMBAH_TEMAN");
        }
        else if (isSame(kata, "\nDAFTAR_PERMINTAAN_PERTEMANAN;"))
        {
            printf("ini DAFTAR_PERMINTAAN_PERTEMANAN");
        }
        else if (isSame(kata, "\nDAFTAR_PERMINTAAN_PERTEMANAN;"))
        {
            printf("ini DAFTAR_PERMINTAAN_PERTEMANAN");
        }
        else if (isSame(kata, "\nSETUJUI_PERTEMANAN;"))
        {
            printf("ini SETUJUI_PERTEMANAN");
        }
        else if (isSame(kata, "\nSETUJUI_PERTEMANAN;"))
        {
            printf("ini SETUJUI_PERTEMANAN");
        }
        else if (isSame(kata, "\nKICAU;"))
        {
            printf("ini KICAU");
        }
        else if (isSame(kata, "\nKICAU;"))
        {
            printf("ini KICAU");
        }
        else if (isSame(kata, "\nSUKA_KICAUAN;"))
        {
            printf("ini SUKA_KICAUAN");
        }
        else if (isSame(kata, "\nSUKA_KICAUAN;"))
        {
            printf("ini SUKA_KICAUAN");
        }
        else if (isSame(kata, "\nUBAH_KICAUAN;"))
        {
            printf("ini UBAH_KICAUAN");
        }
        else if (isSame(kata, "\nUBAH_KICAUAN;"))
        {
            printf("ini UBAH_KICAUAN");
        }
        else if (isSame(kata, "\nBALAS;"))
        {
            printf("ini BALAS");
        }
        else if (isSame(kata, "\nBALAS;"))
        {
            printf("ini BALAS");
        }
        else if (isSame(kata, "\nBALASAN;"))
        {
            printf("ini BALASAN");
        }
        else if (isSame(kata, "\nBALASAN;"))
        {
            printf("ini BALASAN");
        }
        else if (isSame(kata, "\nHAPUS_BALASAN;"))
        {
            printf("ini HAPUS_BALASAN");
        }
        else if (isSame(kata, "\nHAPUS_BALASAN;"))
        {
            printf("ini HAPUS_BALASAN");
        }
        else if (isSame(kata, "\nBUAT_DRAF;"))
        {
            printf("ini BUAT_DRAF");
        }
        else if (isSame(kata, "\nBUAT_DRAF;"))
        {
            printf("ini BUAT_DRAF");
        }
        else if (isSame(kata, "\nLIHAT_DRAF;"))
        {
            printf("ini LIHAT_DRAF");
        }
        else if (isSame(kata, "\nLIHAT_DRAF;"))
        {
            printf("ini LIHAT_DRAF");
        }
        else if (isSame(kata, "\nUTAS;"))
        {
            printf("ini UTAS");
        }
        else if (isSame(kata, "\nUTAS;"))
        {
            printf("ini UTAS");
        }
        else if (isSame(kata, "\nSAMBUNG_UTAS;"))
        {
            printf("ini SAMBUNG_UTAS");
        }
        else if (isSame(kata, "\nSAMBUNG_UTAS;"))
        {
            printf("ini SAMBUNG_UTAS");
        }
        else if (isSame(kata, "\nHAPUS_UTAS;"))
        {
            printf("ini HAPUS_UTAS");
        }
        else if (isSame(kata, "\nHAPUS_UTAS;"))
        {
            printf("ini HAPUS_UTAS");
        }
        else if (isSame(kata, "\nCETAK_UTAS;"))
        {
            printf("ini CETAK_UTAS");
        }
        else if (isSame(kata, "\nCETAK_UTAS;"))
        {
            printf("ini CETAK_UTAS");
        }
        else if (isSame(kata, "\nSIMPAN;"))
        {
            printf("ini SIMPAN");
        }
        else if (isSame(kata, "\nSIMPAN;"))
        {
            printf("ini SIMPAN");
        }
        else if (isSame(kata, "\nMUAT;"))
        {
            printf("ini MUAT");
        }
        else if (isSame(kata, "\nMUAT;"))
        {
            printf("ini MUAT");
        }
        else
        {
            printf("lainnya\n");
        }
        printf(">>");
        baca(&kata);
    }
    printf("###################Akhir#######################\n ");
    return 0;
}