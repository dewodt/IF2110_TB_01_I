#include <stdio.h>
#include "wordmachine.h"
#include "liststatik.h"

int searchID_Pengguna(ListStatik listPengguna, MASUKAN Pengguna) // mungkin penggunanya char
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

// Word searchNamaPengguna(ListStatik listPengguna, int ID_Pengguna);

// void isiReqPertemanan(Queue* listReqPertemanan, Matrix relasiPertemanan, int jumlahPengguna, int ID_Pengguna){
//     int i, countSameFriend;
//     for ( i = 0; i < jumlahPengguna; i++)
//     {
//         countSameFriend = 0;
//         if((ELMT(relasiPertemanan, ID_Pengguna, i) == 0) && (ELMT(relasiPertemanan, i, ID_Pengguna) == 1)){
//             int j;
//             for ( j = 0; j < jumlahPengguna; j++)
//             {
//                 if((ELMT(relasiPertemanan, ID_Pengguna, i) == 1) && (ELMT(relasiPertemanan, i, ID_Pengguna) == 1)){
//                     countSameFriend ++;
//                 }
//             }
//             ElType reqFriend;
//             reqFiend.ID = i;
//             reqFiend.prio = countSameFriend;
//             enqueue(*countSameFriend, reqFriend);
//         }
//     }
    
// }

// void TAMBAH_TEMAN(Queue listReqPertemanan, Matrix relasiPertemanan, int ID_Pengguna, Word namaTeman){
//     if(isEmpty(listReqPertemanan)){
//         printf("Terdapat permintaan pertemanan yang belum Anda setujui.\n");
//         printf("Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
//     }else{
//         if(searchID_Pengguna(listPengguna, namaTeman) == -1){
//             printf("Pengguna bernama namaTeman tidak ditemukan.\n"); 
//         }
//         else if(ELMT(relasiPertemanan, ID_Pengguna, searchID_Pengguna(listPengguna, namaTeman)) == 1 && ELMT(relasiPertemanan, searchID_Pengguna(listPengguna, namaTeman), ID_Pengguna) == 0){
//             printf("Anda sudah mengirimkan permintaan pertemanan kepada namaTeman. Silakan tunggu hingga permintaan Anda disetujui.\n");
//         }
//         else if(ELMT(relasiPertemanan, ID_Pengguna, searchID_Pengguna(listPengguna, namaTeman)) == 0 && ELMT(relasiPertemanan, searchID_Pengguna(listPengguna, namaTeman), ID_Pengguna) == 0){
//             ELMT(relasiPertemanan, ID_Pengguna, searchID_Pengguna(listPengguna, namaTeman)) = 1;
//             printf("Anda sudah mengirimkan permintaan pertemanan kepada namaTeman. Silakan tunggu hingga permintaan Anda disetujui.\n");
//         }
//         else if(ELMT(relasiPertemanan, ID_Pengguna, searchID_Pengguna(listPengguna, namaTeman)) == 1 && ELMT(relasiPertemanan, searchID_Pengguna(listPengguna, namaTeman), ID_Pengguna) == 1){
//             printf("Anda sudah berteman.\n");
//         }
//     }
// }

// void BATAL_TAMBAH_TEMAN(Matrix relasiPertemanan, int ID_Pengguna, Word namaTeman){
//     if(ELMT(relasiPertemanan, ID_Pengguna, searchID_Pengguna(listPengguna, namaTeman)) == 1 && ELMT(relasiPertemanan, searchID_Pengguna(listPengguna, namaTeman), ID_Pengguna) == 0){
//         printf("Permintaan pertemanan kepada Bob telah dibatalkan.\n");
//         ELMT(relasiPertemanan, ID_Pengguna, searchID_Pengguna(listPengguna, namaTeman)) = 0;
//     }else{
//         printf("Anda belum mengirimkan permintaan pertemanan kepada Bob.\n");
//     }
// }

// void SETUJUI_PERTEMANAN(Queue* listReqPertemanan, Matrix relasiPertemanan, int ID_Pengguna){
//     Word valid;
//     STARTWORD(&valid);
//     if(isSame(valid, "YA")){
//         ElType reqFriend;
//         dequeue(*listReqPertemanan, *reqFriend);
//         ELMT(relasiPertemanan, ID_Pengguna, reqFriend.ID) = 1;
//         printf("Permintaan pertemanan dari Bob telah disetujui. Selamat! Anda telah berteman dengan Bob.\n");
//     }else{
//         printf("Permintaan pertemanan dari Bob telah ditolak.\n");
//         ElType reqFriend;
//         dequeue(*listReqPertemanan, *reqFriend);
//         ELMT(relasiPertemanan, reqFriend.ID, ID_Pengguna) = 0;
//     }
// }