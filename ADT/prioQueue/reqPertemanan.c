
#include "reqPertemanan.h"
#include "../modifiedliststatik/modifiedliststatik.h"

void searchID_Pengguna(MASUKAN Pengguna, int* id)
{
    int hasil;
    hasil = -1;
    int i;
    i = 0;
    while (i < listLength(listUser) && hasil == -1)
    {
        if(isMASUKANEqual(strToMASUKAN(USERNAME(listUser,i),stringLength(USERNAME(listUser,i))),Pengguna)){
            hasil = i;
        }else{
            i++;
        }
    }
    (*id) = hasil;
}
// void SETUJUI_PERTEMANAN(PrioQueueint* listReqPertemanan, MatrixTeman RelasiPertemanan, int ID_Pengguna, ListStatik listPengguna, int jumlahPengguna){
//     int id;
//     id = searchID_Pengguna(listPengguna, USERNAME(*currentUser));
//     int i;
//     int hasil;
//     hasil = 0;
//     for ( i = 0; i < 20; i++)
//     {
//         if(ELMT_MTXTEMAN(RelasiPertemanan,id,i) == 1 && ELMT_MTXTEMAN(RelasiPertemanan,i,id) == 1){
//             hasil += 1;
//         }
//     }
//     return hasil;
// }



// char* searchNamaPengguna(ListStatik listPengguna, int ID_Pengguna, int jumlahPengguna){
//     return USERNAME(listPengguna,ID_Pengguna);
// }

void isiReqPertemanan(int jumlahPengguna, int ID_Pengguna){
    int i, countSameFriend;
    for ( i = 0; i < jumlahPengguna; i++)
    {
        countSameFriend = 0;
        if((ELMT_MTXTEMAN(RelasiPertemanan, ID_Pengguna, i) == 0) && (ELMT_MTXTEMAN(RelasiPertemanan, i, ID_Pengguna) == 1)){
            int j;
            for ( j = 0; j < jumlahPengguna; j++)
            {
                if((ELMT_MTXTEMAN(RelasiPertemanan, ID_Pengguna, j) == 1) && (ELMT_MTXTEMAN(RelasiPertemanan, j, ID_Pengguna) == 1)){
                    countSameFriend += 1;
                }
            }
            infotypeQ reqFriend;
            reqFriend.info = i;
            reqFriend.prio = countSameFriend;
            printf("%d\n", reqFriend.prio);
            Enqueue(&prioQ, reqFriend);
        }
    }
    
 }

void TAMBAH_TEMAN(int ID_Pengguna, ListStatik listPengguna){
    if(!IsEmptyQ(prioQ)){
        printf("Terdapat permintaan pertemanan yang belum Anda setujui.\n");
        printf("Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
    }else{
        MASUKAN namaTeman;
        baca(&namaTeman);
        int idx;
        searchID_Pengguna( namaTeman,&idx);
        if(idx == -1){
            printf("Pengguna bernama namaTeman tidak ditemukan.\n"); 
        }
        else if(ELMT_MTXTEMAN(RelasiPertemanan, ID_Pengguna, idx) == 1 && ELMT_MTXTEMAN(RelasiPertemanan, idx, ID_Pengguna) == 0){
            printf("Anda sudah mengirimkan permintaan pertemanan kepada namaTeman. Silakan tunggu hingga permintaan Anda disetujui.\n");
        }
        else if(ELMT_MTXTEMAN(RelasiPertemanan, ID_Pengguna, idx) == 0 && ELMT_MTXTEMAN(RelasiPertemanan, idx, ID_Pengguna) == 0){
            ELMT_MTXTEMAN(RelasiPertemanan, ID_Pengguna, idx) = 1;
            printf("Anda sudah mengirimkan permintaan pertemanan kepada namaTeman. Silakan tunggu hingga permintaan Anda disetujui.\n");
        }
        else if(ELMT_MTXTEMAN(RelasiPertemanan, ID_Pengguna, idx) == 1 && ELMT_MTXTEMAN(RelasiPertemanan, idx, ID_Pengguna) == 1){
            printf("Anda sudah berteman.\n");
        }
    }
}
// update Spesifikasi fitur ini ditiadakan
// void BATAL_TAMBAH_TEMAN(MatrixTeman RelasiPertemanan, int ID_Pengguna, MASUKAN namaTeman, ListStatik listPengguna){
//     if(ELMT_MTXTEMAN(RelasiPertemanan, ID_Pengguna, searchID_Pengguna(listPengguna, namaTeman)) == 1 && ELMT_MTXTEMAN(RelasiPertemanan, searchID_Pengguna(listPengguna, namaTeman), ID_Pengguna) == 0){
//         printf("Permintaan pertemanan kepada Bob telah dibatalkan.\n");
//         ELMT_MTXTEMAN(RelasiPertemanan, ID_Pengguna, searchID_Pengguna(listPengguna, namaTeman)) = 0;
//     }else{
//         printf("Anda belum mengirimkan permintaan pertemanan kepada Bob.\n");
//     }
// }

void DAFTAR_PERMINTAAN_PERTEMANAN(int jumlahPengguna){
    if(NBElmt(prioQ) == 0){
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
    }else{
        printf("Terdapat %d permintaan pertemanan untuk Anda.\n", NBElmt(prioQ));
        int i;
        for ( i = 0; i < NBElmt(prioQ); i++)
        {
            infotypeQ reqFriend;
            Dequeue(&prioQ,&reqFriend);
            printf(" | %s\n", USERNAME(listUser,reqFriend.info));
            printf(" | Jumlah teman: %d\n", reqFriend.prio);
            Enqueue(&prioQ,reqFriend);
        }
        
    }
}



// DONE
void SETUJUI_PERTEMANAN(int ID_Pengguna,int jumlahPengguna){
    infotypeQ reqFriend;
    printf("sebelum dq");
    Dequeue(&prioQ, &reqFriend);
    //MASUKAN namaPengguna;
    //namaPengguna = searchNamaPengguna(listPengguna,(reqFriend.info), jumlahPengguna);
    printf("Permintaan pertemanan teratas dari %s\n", USERNAME(listUser,reqFriend.info));
    printf(" | %s\n", USERNAME(listUser,reqFriend.info));
    printf(" | Jumlah teman: %d\n", reqFriend.prio);
    printf("Apakah Anda ingin menyetujui permintaan pertemanan ini?");
    printf("(YA/TIDAK)");
    MASUKAN valid;
    baca(&valid);
    while(!(isSame(valid, "YA") || isSame(valid, "TIDAK"))){
        baca(&valid);
    }
    if(isSame(valid, "YA")){
        ELMT_MTXTEMAN(RelasiPertemanan, ID_Pengguna, reqFriend.info) = 1;
        printf("Permintaan pertemanan dari %s telah disetujui. Selamat! Anda telah berteman dengan %s.\n", USERNAME(listUser,reqFriend.info), USERNAME(listUser,reqFriend.info));
    }else if(isSame(valid,"YA")){
        printf("Permintaan pertemanan dari %s telah ditolak.\n", USERNAME(listUser,reqFriend.info));
        ELMT_MTXTEMAN(RelasiPertemanan, reqFriend.info, ID_Pengguna) = 0;
    }
}