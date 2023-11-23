#ifndef REQPERTEMANAN_H
#define REQPERTEMANAN_H

#include "prioQueueint.h"

void SETUJUI_PERTEMANAN(PrioQueueint* listReqPertemanan, Matrix relasiPertemanan, int ID_Pengguna, ListStatik listPengguna, int jumlahPengguna);

int searchID_Pengguna(ListStatik listPengguna, MASUKAN Pengguna);

// char* searchNamaPengguna(ListStatik listPengguna, int ID_Pengguna, int jumlahPengguna);

void isiReqPertemanan(PrioQueueint* listReqPertemanan, Matrix relasiPertemanan, int jumlahPengguna, int ID_Pengguna);

void TAMBAH_TEMAN(PrioQueueint listReqPertemanan, Matrix relasiPertemanan, int ID_Pengguna, ListStatik listPengguna);

void DAFTAR_PERMINTAAN_PERTEMANAN(PrioQueueint listReqPertemanan, ListStatik listPengguna, int jumlahPengguna);

void SETUJUI_PERTEMANAN(PrioQueueint* listReqPertemanan, Matrix relasiPertemanan, int ID_Pengguna, ListStatik listPengguna, int jumlahPengguna);

#endif