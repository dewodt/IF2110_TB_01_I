#include <stdio.h>
#include "./ADT/wordmachine/wordmachine.h"
#include "./ADT/Baca/baca.c"
int main() {
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
    Word kata;
    printf(">>");
    STARTWORD();
    kata = currentWord;
    // Proses salin konfig ke dalam variabel program
    // Perlu dipastikan tiap data disimpan dalam bentuk apa di dalam program

    printf("\n");
    baca(&kata);
    while (isSame(kata, "TUTUP_PROGRAM;"))
    {   
        if(isSame(kata, "DAFTAR")){
            printf("ini DAFTAR");
        }else if(isSame(kata, "DAFTAR;")){
            printf("ini DAFTAR");
        }else if(isSame(kata, "MASUK")){
            printf("ini MASUK");
        }else if(isSame(kata, "MASUK;")){
            printf("ini MASUK");
        }else if(isSame(kata, "KELUAR")){
            printf("ini KELUAR");
        }else if(isSame(kata, "KELUAR;")){
            printf("ini KELUAR");
        }else if(isSame(kata, "TUTUP_PROGRAM")){
            printf("ini TUTUP_PROGRAM");
        }else if(isSame(kata, "TUTUP_PROGRAM;")){
            printf("ini TUTUP_PROGRAM");
        }else if(isSame(kata, "GANTI_PROFIL")){
            printf("ini GANTI_PROFIL");
        }else if(isSame(kata, "GANTI_PROFIL;")){
            printf("ini GANTI_PROFIL");
        }else if(isSame(kata, "LIHAT_PROFIL")){
            printf("ini LIHAT_PROFIL");
        }else if(isSame(kata, "LIHAT_PROFIL;")){
            printf("ini LIHAT_PROFIL");
        }else if(isSame(kata, "ATUR_JENIS_AKUN")){
            printf("ini ATUR_JENIS_AKUN");
        }else if(isSame(kata, "ATUR_JENIS_AKUN;")){
            printf("ini ATUR_JENIS_AKUN");
        }else if(isSame(kata, "UBAH_FOTO_PROFIL")){
            printf("ini UBAH_FOTO_PROFIL");
        }else if(isSame(kata, "UBAH_FOTO_PROFIL;")){
            printf("ini UBAH_FOTO_PROFIL");
        }else if(isSame(kata, "DAFTAR_TEMAN")){
            printf("ini DAFTAR_TEMAN");
        }else if(isSame(kata, "DAFTAR_TEMAN;")){
            printf("ini DAFTAR_TEMAN");
        }else if(isSame(kata, "HAPUS_TEMAN")){
            printf("ini HAPUS_TEMAN");
        }else if(isSame(kata, "HAPUS_TEMAN;")){
            printf("ini HAPUS_TEMAN");
        }else if(isSame(kata, "TAMBAH_TEMAN")){
            printf("ini TAMBAH_TEMAN");
        }else if(isSame(kata, "TAMBAH_TEMAN;")){
            printf("ini TAMBAH_TEMAN");
        }else if(isSame(kata, "BATAL_TAMBAH_TEMAN")){
            printf("ini BATAL_TAMBAH_TEMAN");
        }else if(isSame(kata, "BATAL_TAMBAH_TEMAN;")){
            printf("ini BATAL_TAMBAH_TEMAN");
        }else if(isSame(kata, "DAFTAR_PERMINTAAN_PERTEMANAN")){
            printf("ini DAFTAR_PERMINTAAN_PERTEMANAN");
        }else if(isSame(kata, "DAFTAR_PERMINTAAN_PERTEMANAN;")){
            printf("ini DAFTAR_PERMINTAAN_PERTEMANAN");
        }else if(isSame(kata, "SETUJUI_PERTEMANAN")){
            printf("ini SETUJUI_PERTEMANAN");
        }else if(isSame(kata, "SETUJUI_PERTEMANAN;")){
            printf("ini SETUJUI_PERTEMANAN");
        }else if(isSame(kata, "KICAU")){
            printf("ini KICAU");
        }else if(isSame(kata, "KICAU;")){
            printf("ini KICAU");
        }else if(isSame(kata, "SUKA_KICAUAN")){
            printf("ini SUKA_KICAUAN");
        }else if(isSame(kata, "SUKA_KICAUAN;")){
            printf("ini SUKA_KICAUAN");
        }else if(isSame(kata, "UBAH_KICAUAN")){
            printf("ini UBAH_KICAUAN");
        }else if(isSame(kata, "UBAH_KICAUAN;")){
            printf("ini UBAH_KICAUAN");
        }else if(isSame(kata, "BALAS")){
            printf("ini BALAS");
        }else if(isSame(kata, "BALAS;")){
            printf("ini BALAS");
        }else if(isSame(kata, "BALASAN")){
            printf("ini BALASAN");
        }else if(isSame(kata, "BALASAN;")){
            printf("ini BALASAN");
        }else if(isSame(kata, "HAPUS_BALASAN")){
            printf("ini HAPUS_BALASAN");
        }else if(isSame(kata, "HAPUS_BALASAN;")){
            printf("ini HAPUS_BALASAN");
        }else if(isSame(kata, "BUAT_DRAF")){
            printf("ini BUAT_DRAF");
        }else if(isSame(kata, "BUAT_DRAF;")){
            printf("ini BUAT_DRAF");
        }else if(isSame(kata, "LIHAT_DRAF")){
            printf("ini LIHAT_DRAF");
        }else if(isSame(kata, "LIHAT_DRAF;")){
            printf("ini LIHAT_DRAF");
        }else if(isSame(kata, "UTAS")){
            printf("ini UTAS");
        }else if(isSame(kata, "UTAS;")){
            printf("ini UTAS");
        }else if(isSame(kata, "SAMBUNG_UTAS")){
            printf("ini SAMBUNG_UTAS");
        }else if(isSame(kata, "SAMBUNG_UTAS;")){
            printf("ini SAMBUNG_UTAS");
        }else if(isSame(kata, "HAPUS_UTAS")){
            printf("ini HAPUS_UTAS");
        }else if(isSame(kata, "HAPUS_UTAS;")){
            printf("ini HAPUS_UTAS");
        }else if(isSame(kata, "CETAK_UTAS")){
            printf("ini CETAK_UTAS");
        }else if(isSame(kata, "CETAK_UTAS;")){
            printf("ini CETAK_UTAS");
        }else if(isSame(kata, "SIMPAN")){
            printf("ini SIMPAN");
        }else if(isSame(kata, "SIMPAN;")){
            printf("ini SIMPAN");
        }else if(isSame(kata, "MUAT")){
            printf("ini MUAT");
        }else if(isSame(kata, "MUAT;")){
            printf("ini MUAT");
        }else{
            printf("lainnya\n");
        }
        printf(">>");
        baca(&kata);
    }
    printf("Akhir");
    return 0;
}