#include <stdio.h>
#include "ADT/masukan/masukan.h"
#include "ADT/listdinkicauan/listdinkicauan.h"
#include "ADT/modifiedliststatik/modifiedliststatik.h"

/* GLOBAL VARIABLES:
currentUser
listKicauan
listUser
continue
*/

/* GLOBAL VARIABLES */
ListDinKicauan listKicauan;
ListStatik listUser;
User *currentUser;

int main()
{
    // Inisialisasi global variable
    CreateListDinKicauan(&listKicauan, 100);
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

    // Baca config
    MASUKAN kata;
    printf(">>");
    baca(&kata);
    // Proses salin konfig ke dalam variabel program
    // Perlu dipastikan tiap data disimpan dalam bentuk apa di dalam program
    printf(">>");
    baca(&kata);

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