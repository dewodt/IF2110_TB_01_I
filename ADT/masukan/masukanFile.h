/* File: masukanFile.h */
/* Definisi Mesin MASUKANFILE: Model Akuisisi Versi I */

#ifndef __MASUKANFILE_H__
#define __MASUKANFILE_H__

#include "../boolean.h"
#include "charFile.h"
#include "../masukan/masukanint.h"
#include "masukan.h"
#include "../modifiedliststatik/modifiedliststatik.h"
#include "../listdinkicauan/listdinkicauan.h"
//#include "../prioQueue/reqPertemanan.c"
#include "../kicauan/kicauan.h"
#include "../balasan/balasan.h"
#include "../listdinUtas/listdinForUtas.h"

#define NMax 281
#define BLANK ' '

typedef struct
{
   char TabMASUKANFILE[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} MASUKANFILE;

/* State Mesin MASUKANFILE */
extern boolean EndMASUKANFILE;
extern MASUKANFILE currentMASUKANFILE;

void STARTMASUKANFILE(char nameFile[]);
/* I.S. : currentChar sembarang
   F.S. : EndMASUKANFILE = true, dan currentChar = MARK;
          atau EndMASUKANFILE = false, currentMASUKANFILE adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void CopyMASUKANFILE();
/* Mengakuisisi kata, menyimpan dalam currentMASUKANFILE
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentMASUKANFILE berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

int masukanFileToInt(MASUKANFILE masukanFile);

int charToInt(char sebenarnyaInt);

void ADVMASUKANFILE();

void bacaAwalFile(MASUKANFILE *MASUKANFILE, MASUKAN namaFile);

void bacaLanjutFile(MASUKANFILE *MASUKANFILE);

boolean isSameFile(MASUKANFILE masuk, char string[]);
// membandingkan masuk dengan string

void displayMASUKANFILE(MASUKANFILE masuk);
// menampilkan isi dari array masuk

MASUKAN masukanFileToMasukan(MASUKANFILE MASUKANFILE);

void bacaPengguna(ListStatik* listPengguna, MASUKAN namaFile);

void bacaKicauan(ListDinKicauan* listKicauan, MASUKAN namaFile, ListStatik listPengguna);

void splitMasukanFileJadi2(MASUKANFILE masukanFile, MASUKANFILE* hasil1, MASUKANFILE* hasil2);

void bacaBalasan(ListDinKicauan* listKicauan, MASUKAN namaFile, ListStatik listPengguna);

void bacaUtas(ListDinKicauan* listKicauan, MASUKAN namaFile, ListStatik listPengguna);
// void MASUKANFILEToStr(MASUKANFILE masukanFile, char *str[]);

#endif