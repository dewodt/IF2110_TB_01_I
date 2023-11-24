#ifndef __REQPERTEMANAN_H__
#define __REQPERTEMANAN_H__

#include <stdio.h>
#include "../modifiedliststatik/modifiedliststatik.h"
#include "../matrixteman/matrixteman.h"
#include "../masukan/masukan.h"
#include "prioQueueint.h"


void searchID_Pengguna(MASUKAN Pengguna, int* id);

// char* searchNamaPengguna(ListStatik listPengguna, int ID_Pengguna, int jumlahPengguna);

void isiReqPertemanan(int jumlahPengguna, int ID_Pengguna);

void TAMBAH_TEMAN(int ID_Pengguna, ListStatik listPengguna);

void DAFTAR_PERMINTAAN_PERTEMANAN(int jumlahPengguna);

void SETUJUI_PERTEMANAN(int ID_Pengguna, int jumlahPengguna);

#endif