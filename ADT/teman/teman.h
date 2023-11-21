#ifndef TEMAN_H
#define TEMAN_H

#include "../boolean.h"
#include "../matrixteman/matrixteman.h"
#include "../modifiedliststatik/modifiedliststatik.h" // Untuk akses struct User

IdxTypeMTXTeman searchIndexPengguna(User Pengguna);
/**
 * Fungsi untuk mengembalikan index Pengguna pada ListPengguna
 * return -1 jika tidak ditemukan
 */
IdxTypeMTXTeman searchIndexPenggunaByName(char *Username);
/**
 * Fungsi untuk mengembalikan index Username/Author pada ListPengguna
 */

boolean areFriendsEachOthers(User Pengguna1, User Pengguna2);
/**
 * Fungsi untuk cek apakah Pengguna1 berteman dengan Pengguna2
 * Mengembalikan true jika saling berteman, false jika tidak
 */
boolean areFriendsByName(char *Username1, char *Username2);
/**
 * Fungsi untuk cek apakah Username/Author 1 berteman dengan Username/Author 2
 * Mengembalikan true jika saling berteman, false jika tidak
 */

int getCountFriend(User user);
/* Menghitung jumlah teman yang dimiliki user */
/* Prekondisi: User valid */

void showFriendList();
/**
 * Prosedur perintah MASUKAN DAFTAR_TEMAN
 * User import global variable CurrentUser
 */

void deleteFriend();
/**
 * Prosedur perintah MASUKAN HAPUS_TEMAN
 * User import global variable CurrentUser
 */

#endif