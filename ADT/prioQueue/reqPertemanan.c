#include <stdio.h>
#include "MASUKAN.h"
#include "liststatik.h"
#include "matrix.h"
#include "prioQueueint.h"

int jumlahTeman(ListStatik listPengguna, MASUKAN user, Matrix relasiPertemanan){
    int id;
    id = searchID_Pengguna(listPengguna, user);
    int i;
    int hasil;
    hasil = 0;
    for ( i = 0; i < 20; i++)
    {
        if(ELMT(relasiPertemanan,id,i) == 1 && ELMT(relasiPertemanan,i,id) == 1){
            hasil += 1;
        }
    }
    return hasil;
}


int searchID_Pengguna(ListStatik listPengguna, MASUKAN Pengguna)
{
    int hasil;
    hasil = -1;
    int i;
    i = 0;
    while (i < listLength(listPengguna) && hasil != -1)
    {
        if(listStatik[i].username == Pengguna){
            hasil = i;
        }else{
            i++;
        }
    }
    return hasil;
}

MASUKAN searchNamaPengguna(ListStatik listPengguna, int ID_Pengguna, int jumlahPengguna){
    MASUKAN hasil;
    if(ID_Pengguna < jumlahPengguna){
        return listPengguna[ID_Pengguna].username;
    }else{
        return hasil; //harusnya gak ke sini
    }
}

void isiReqPertemanan(PrioQueueint* listReqPertemanan, Matrix relasiPertemanan, int jumlahPengguna, int ID_Pengguna){
    int i, countSameFriend;
    for ( i = 0; i < jumlahPengguna; i++)
    {
        countSameFriend = 0;
        if((ELMT(relasiPertemanan, ID_Pengguna, i) == 0) && (ELMT(relasiPertemanan, i, ID_Pengguna) == 1)){
            int j;
            for ( j = 0; j < jumlahPengguna; j++)
            {
                if((ELMT(relasiPertemanan, ID_Pengguna, i) == 1) && (ELMT(relasiPertemanan, i, ID_Pengguna) == 1)){
                    countSameFriend ++;
                }
            }
            infotype reqFriend;
            reqFiend.ID = i;
            reqFiend.prio = countSameFriend;
            enqueue(*listReqPertemanan, reqFriend);
        }
    }
    
}

void TAMBAH_TEMAN(PrioQueueint listReqPertemanan, Matrix relasiPertemanan, int ID_Pengguna, ListStatik listPengguna){
    if(!isEmpty(listReqPertemanan)){
        printf("Terdapat permintaan pertemanan yang belum Anda setujui.\n");
        printf("Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
    }else{
        MASUKAN namaTeman;
        baca(&namaTeman);
        if(searchID_Pengguna(listPengguna, namaTeman) == -1){
            printf("Pengguna bernama namaTeman tidak ditemukan.\n"); 
        }
        else if(ELMT(relasiPertemanan, ID_Pengguna, searchID_Pengguna(listPengguna, namaTeman)) == 1 && ELMT(relasiPertemanan, searchID_Pengguna(listPengguna, namaTeman), ID_Pengguna) == 0){
            printf("Anda sudah mengirimkan permintaan pertemanan kepada namaTeman. Silakan tunggu hingga permintaan Anda disetujui.\n");
        }
        else if(ELMT(relasiPertemanan, ID_Pengguna, searchID_Pengguna(listPengguna, namaTeman)) == 0 && ELMT(relasiPertemanan, searchID_Pengguna(listPengguna, namaTeman), ID_Pengguna) == 0){
            ELMT(relasiPertemanan, ID_Pengguna, searchID_Pengguna(listPengguna, namaTeman)) = 1;
            printf("Anda sudah mengirimkan permintaan pertemanan kepada namaTeman. Silakan tunggu hingga permintaan Anda disetujui.\n");
        }
        else if(ELMT(relasiPertemanan, ID_Pengguna, searchID_Pengguna(listPengguna, namaTeman)) == 1 && ELMT(relasiPertemanan, searchID_Pengguna(listPengguna, namaTeman), ID_Pengguna) == 1){
            printf("Anda sudah berteman.\n");
        }
    }
}
// update Spesifikasi fitur ini ditiadakan
// void BATAL_TAMBAH_TEMAN(Matrix relasiPertemanan, int ID_Pengguna, MASUKAN namaTeman, ListStatik listPengguna){
//     if(ELMT(relasiPertemanan, ID_Pengguna, searchID_Pengguna(listPengguna, namaTeman)) == 1 && ELMT(relasiPertemanan, searchID_Pengguna(listPengguna, namaTeman), ID_Pengguna) == 0){
//         printf("Permintaan pertemanan kepada Bob telah dibatalkan.\n");
//         ELMT(relasiPertemanan, ID_Pengguna, searchID_Pengguna(listPengguna, namaTeman)) = 0;
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
            infotype reqFriend;
            Dequeue(&listReqPertemanan,&reqFriend);
            printf(" | %s\n", searchNamaPengguna(listPengguna,(reqFriend.info), jumlahPengguna).TabMASUKAN[]);
            printf(" | Jumlah teman: %d\n", reqFriend.prio);
        }
        
    }
}



// DONE
void SETUJUI_PERTEMANAN(PrioQueueint* listReqPertemanan, Matrix relasiPertemanan, int ID_Pengguna, ListStatik listPengguna, int jumlahPengguna){
    infotype reqFriend;
    dequeue(listReqPertemanan, &reqFriend);
    MASUKAN namaPengguna;
    namaPengguna = searchNamaPengguna(listPengguna,(reqFriend.info), jumlahPengguna);
    printf("Permintaan pertemanan teratas dari %s\n", namaPengguna.TabMASUKAN[]);
    printf(" | %s\n", namaPengguna.TabMASUKAN[]);
    printf(" | Jumlah teman: %d\n", jumlahTeman(listPengguna,namaPengguna,relasiPertemanan));
    printf("Apakah Anda ingin menyetujui permintaan pertemanan ini?");
    printf("(YA/TIDAK)");
    MASUKAN valid;
    baca(&valid);
    while(!(isSame(valid, "YA") || isSame(valid, "TIDAK"))){
        baca(&valid);
    }
    if(isSame(valid, "YA")){
        ELMT(relasiPertemanan, ID_Pengguna, reqFriend.ID) = 1;
        printf("Permintaan pertemanan dari %s telah disetujui. Selamat! Anda telah berteman dengan %s.\n", namaPengguna.TabMASUKAN[]);
    }else if{
        printf("Permintaan pertemanan dari %s telah ditolak.\n", namaPengguna.TabMASUKAN[]);
        ELMT(relasiPertemanan, reqFriend.ID, ID_Pengguna) = 0;
    }
}