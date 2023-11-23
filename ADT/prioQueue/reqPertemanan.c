#include <stdio.h>
#include "../masukan/masukan.h"
#include "../modifiedliststatik/modifiedliststatik.h"
//#include "../matrixteman/matrixteman.h"
#include "prioQueueint.h"
#include "../pengguna/pengguna.h"
int searchID_Pengguna(ListStatik listPengguna, MASUKAN Pengguna)
{
    int hasil;
    hasil = -1;
    int i;
    i = 0;
    while (i < listLength(listPengguna) && hasil != -1)
    {
        if(USERNAME(listPengguna,i) == MASUKANToStr(Pengguna)){
            hasil = i;
        }else{
            i++;
        }
    }
    return hasil;
}
// void SETUJUI_PERTEMANAN(PrioQueueint* listReqPertemanan, Matrix relasiPertemanan, int ID_Pengguna, ListStatik listPengguna, int jumlahPengguna){
//     int id;
//     id = searchID_Pengguna(listPengguna, USERNAME(*currentUser));
//     int i;
//     int hasil;
//     hasil = 0;
//     for ( i = 0; i < 20; i++)
//     {
//         if(ELMT_MTX(relasiPertemanan,id,i) == 1 && ELMT_MTX(relasiPertemanan,i,id) == 1){
//             hasil += 1;
//         }
//     }
//     return hasil;
// }



// char* searchNamaPengguna(ListStatik listPengguna, int ID_Pengguna, int jumlahPengguna){
//     return USERNAME(listPengguna,ID_Pengguna);
// }

void isiReqPertemanan(PrioQueueint* listReqPertemanan, Matrix relasiPertemanan, int jumlahPengguna, int ID_Pengguna){
    int i, countSameFriend;
    for ( i = 0; i < jumlahPengguna; i++)
    {
        countSameFriend = 0;
        if((ELMT_MTX(relasiPertemanan, ID_Pengguna, i) == 0) && (ELMT_MTX(relasiPertemanan, i, ID_Pengguna) == 1)){
            int j;
            for ( j = 0; j < jumlahPengguna; j++)
            {
                if((ELMT_MTX(relasiPertemanan, ID_Pengguna, i) == 1) && (ELMT_MTX(relasiPertemanan, i, ID_Pengguna) == 1)){
                    countSameFriend ++;
                }
            }
            infotypeQ reqFriend;
            reqFriend.info = i;
            reqFriend.prio = countSameFriend;
            Enqueue(listReqPertemanan, reqFriend);
        }
    }
    
 }

void TAMBAH_TEMAN(PrioQueueint listReqPertemanan, Matrix relasiPertemanan, int ID_Pengguna, ListStatik listPengguna){
    if(!IsEmptyQ(listReqPertemanan)){
        printf("Terdapat permintaan pertemanan yang belum Anda setujui.\n");
        printf("Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
    }else{
        MASUKAN namaTeman;
        baca(&namaTeman);
        if(searchID_Pengguna(listPengguna, namaTeman) == -1){
            printf("Pengguna bernama namaTeman tidak ditemukan.\n"); 
        }
        else if(ELMT_MTX(relasiPertemanan, ID_Pengguna, searchID_Pengguna(listPengguna, namaTeman)) == 1 && ELMT_MTX(relasiPertemanan, searchID_Pengguna(listPengguna, namaTeman), ID_Pengguna) == 0){
            printf("Anda sudah mengirimkan permintaan pertemanan kepada namaTeman. Silakan tunggu hingga permintaan Anda disetujui.\n");
        }
        else if(ELMT_MTX(relasiPertemanan, ID_Pengguna, searchID_Pengguna(listPengguna, namaTeman)) == 0 && ELMT_MTX(relasiPertemanan, searchID_Pengguna(listPengguna, namaTeman), ID_Pengguna) == 0){
            ELMT_MTX(relasiPertemanan, ID_Pengguna, searchID_Pengguna(listPengguna, namaTeman)) = 1;
            printf("Anda sudah mengirimkan permintaan pertemanan kepada namaTeman. Silakan tunggu hingga permintaan Anda disetujui.\n");
        }
        else if(ELMT_MTX(relasiPertemanan, ID_Pengguna, searchID_Pengguna(listPengguna, namaTeman)) == 1 && ELMT_MTX(relasiPertemanan, searchID_Pengguna(listPengguna, namaTeman), ID_Pengguna) == 1){
            printf("Anda sudah berteman.\n");
        }
    }
}
// update Spesifikasi fitur ini ditiadakan
// void BATAL_TAMBAH_TEMAN(Matrix relasiPertemanan, int ID_Pengguna, MASUKAN namaTeman, ListStatik listPengguna){
//     if(ELMT_MTX(relasiPertemanan, ID_Pengguna, searchID_Pengguna(listPengguna, namaTeman)) == 1 && ELMT_MTX(relasiPertemanan, searchID_Pengguna(listPengguna, namaTeman), ID_Pengguna) == 0){
//         printf("Permintaan pertemanan kepada Bob telah dibatalkan.\n");
//         ELMT_MTX(relasiPertemanan, ID_Pengguna, searchID_Pengguna(listPengguna, namaTeman)) = 0;
//     }else{
//         printf("Anda belum mengirimkan permintaan pertemanan kepada Bob.\n");
//     }
// }

void DAFTAR_PERMINTAAN_PERTEMANAN(PrioQueueint listReqPertemanan, ListStatik listPengguna, int jumlahPengguna){
    if(NBElmt(listReqPertemanan) == 0){
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
    }else{
        printf("Terdapat %d permintaan pertemanan untuk Anda.\n", NBElmt(listReqPertemanan));
        int i;
        for ( i = 0; i < NBElmt(listReqPertemanan); i++)
        {
            infotypeQ reqFriend;
            Dequeue(&listReqPertemanan,&reqFriend);
            printf(" | %s\n", USERNAME(listPengguna,reqFriend.info));
            printf(" | Jumlah teman: %d\n", reqFriend.prio);
        }
        
    }
}



// DONE
void SETUJUI_PERTEMANAN(PrioQueueint* listReqPertemanan, Matrix relasiPertemanan, int ID_Pengguna, ListStatik listPengguna, int jumlahPengguna){
    infotypeQ reqFriend;
    Dequeue(listReqPertemanan, &reqFriend);
    //MASUKAN namaPengguna;
    //namaPengguna = searchNamaPengguna(listPengguna,(reqFriend.info), jumlahPengguna);
    printf("Permintaan pertemanan teratas dari %s\n", USERNAME(listPengguna,reqFriend.info));
    printf(" | %s\n", USERNAME(listPengguna,reqFriend.info));
    printf(" | Jumlah teman: %d\n", reqFriend.prio);
    printf("Apakah Anda ingin menyetujui permintaan pertemanan ini?");
    printf("(YA/TIDAK)");
    MASUKAN valid;
    baca(&valid);
    while(!(isSame(valid, "YA") || isSame(valid, "TIDAK"))){
        baca(&valid);
    }
    if(isSame(valid, "YA")){
        ELMT_MTX(relasiPertemanan, ID_Pengguna, reqFriend.info) = 1;
        printf("Permintaan pertemanan dari %s telah disetujui. Selamat! Anda telah berteman dengan %s.\n", USERNAME(listPengguna,reqFriend.info), USERNAME(listPengguna,reqFriend.info));
    }else if(isSame(valid,"YA")){
        printf("Permintaan pertemanan dari %s telah ditolak.\n", USERNAME(listPengguna,reqFriend.info));
        ELMT_MTX(relasiPertemanan, reqFriend.info, ID_Pengguna) = 0;
    }
}