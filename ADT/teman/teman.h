// import
#include <stdlib.h>
#include <stdio.h>
#include "./../boolean.h"
#include "./matrix/matrix.c"
#include "./../modifiedliststatik/modifiedliststatik.c" // Untuk akses struct User
#include "./../masukan/masukan.c" // Untuk membandingkan MASUKAN atau string char[]

// variabel global
extern Matrix RelasiPertemanan;

void createFriendMatrix(Matrix* RelasiPertemanan);
/**
 * I.s. Matriks pertemanan belum terdefinisi
 * F.S. Matriks pertemanan terdefinisi dengan ukuran tetap 20 x 20
 * Prosedur membuat adjMatrix untuk representasi graf relasi pertemanan
 * Hanya untuk matrix global Relasi Pertemanan 
 * 20 simpul untuk total pengguna yang saling berteman 
 * Definisi sesuai spek dan ada req friend jika tidak refleksif pada index yang bersesuaian
*/

IdxType searchIndexPengguna(ListStatik ListPengguna, User Pengguna);
/**
 * Fungsi untuk mengembalikan index Pengguna pada ListPengguna
 * return -1 jika tidak ditemukan
*/
IdxType searchIndexPenggunaByName(ListStatik ListPengguna, char *Username);
/**
 * Fungsi untuk mengembalikan index Username/Author pada ListPengguna
*/


boolean areFriendsEachOthers(Matrix RelasiPertemanan, ListStatik ListPengguna, User Pengguna1, User Pengguna2)
/**
 * Fungsi untuk cek apakah Pengguna1 berteman dengan Pengguna2
 * Mengembalikan true jika saling berteman, false jika tidak
*/
boolean areFriendsByName(ListStatik ListPengguna, ListStatik ListPengguna, char *Username1, char *Username2);
/**
 * Fungsi untuk cek apakah Username/Author 1 berteman dengan Username/Author 2
 * Mengembalikan true jika saling berteman, false jika tidak
*/

/** DONE???
 * BUTUH NGEPRINT PROFIL2 PENGGUNA
 * BUTUH NGEBANDINGIN PROFIL2 PENGGUNA JUGA
*/

void listFriend(ListStatik DaftarTeman);
/**
 * Prosedur mencetak DaftarTeman oleh showFriendList() jika punya teman
*/

void showFriendList(Matrix RelasiPertemanan, ListStatik ListPengguna, User CurrentPengguna);
/**
 * Prosedur perintah MASUKAN DAFTAR_TEMAN
 * User import global variable CurrentUser
*/

void deleteFriend(Matrix *RelasiPertemanan, User CurrentUser);
/**
 * Prosedur perintah MASUKAN HAPUS_TEMAN
 * User import global variable CurrentUser
*/
