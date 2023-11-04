#include "ADTUsed/time/time.h"
#include "ADTUsed/datetime/datetime.h"
#include "ADTUsed/listlinier/listlinierForUtas.h"
#include "ADTUsed/kicauan/kicauan.h"

#ifndef UTAS_H
#define UTAS_H

// Bentukan Utas
typedef struct
{
    Kicauan *tweet;   // Pointer menuju kicauan yang berkaitan (Menggunakan pointer supaya dinamis jika kicauan di modified)
    int IDUtas;       // ID Utas
    Address threads;  // Alamat mennuju kicauan sambungan pertama
} UTAS;

#define Threads(u) (u)->threads
#define IDUtas(u) (u).IDUtas

// Membuat sebuah Utas baru dari kicauan yang sudah ada, Akan di-set ID Utas dan pointer kicauan
void CreateUtas(UTAS *u, Kicauan *tweet);

// Menyambung Utas
void SAMBUNG_UTAS(UTAS *u, char text[MAX_CHAR], int index);

// Mencetak Utas
void CETAK_UTAS(UTAS u);

// Menghapus kicauan sambungan pada ID Utas tertentu, dan index kicauan sambungan tertentu
void HAPUS_UTAS(UTAS *u);


#endif