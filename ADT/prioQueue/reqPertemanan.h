#ifndef __REQPERTEMANAN_H__
#define __REQPERTEMANAN_H__

#include <stdio.h>
#include "../modifiedliststatik/modifiedliststatik.h"
#include "../matrixteman/matrixteman.h"
#include "../masukan/masukan.h"
#include "prioQueueint.h"

void searchID_Pengguna(MASUKAN Pengguna, int* id);

// char* searchNamaPengguna(ListStatik listPengguna, int ID_Pengguna, int jumlahPengguna);

void isiReqPertemanan(PrioQueueint* listReqPertemanan, MatrixTeman relasiPertemanan, int jumlahPengguna, int ID_Pengguna);

void TAMBAH_TEMAN(PrioQueueint listReqPertemanan, MatrixTeman relasiPertemanan, int ID_Pengguna, ListStatik listPengguna);

void DAFTAR_PERMINTAAN_PERTEMANAN(PrioQueueint listReqPertemanan, ListStatik listPengguna, int jumlahPengguna);

void SETUJUI_PERTEMANAN(PrioQueueint* listReqPertemanan, MatrixTeman relasiPertemanan, int ID_Pengguna, ListStatik listPengguna, int jumlahPengguna);

#endif