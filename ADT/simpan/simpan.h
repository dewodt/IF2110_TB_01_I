#ifndef SIMPAN
#define SIMPAN

#include "../matrixteman/matrixteman.h"
#include "../tree/tree.h"

/* Prosedur untuk menyimpan seluruh data program dalam folder config/foo */
void Simpan();
/* I.S. Sembarang */
/* F.S. Data program tersimpan dalam folder config/foo */

/* Prosedur untuk menyimpan data pengguna dalam folder config/foo */
void SimpanPengguna(char *folderDir);
/* I.S. Sembarang */
/* F.S. Data pengguna tersimpan dalam folder config/foo/pengguna */

/* Prosedur untuk menyimpan data kicauan dalam folder config/foo */
void SimpanKicauan(char *folderDir);
/* I.S. Sembarang */
/* F.S. Data kicauan tersimpan dalam folder config/foo/kicauan */

/* Prosedur untuk menyimpan data balasan dalam folder config/foo */
void SimpanBalasan(char *folderDir);
/* I.S. Sembarang */
/* F.S. Data balasan tersimpan dalam folder config/foo/balasan */

/* Menuliskan balasan pada file ptr secara rekursif */
void writeBalasanDetailFile(FILE *ptr, int parentId, AddressBalasan nodeBalasan);
/* I.S. ptr file terdefinisi */
/* F.S. seluruh balasan tertulis pada file */

/* Prosedur untuk menyimpan data draf dalam folder config/foo */
void saveDraf(char *folderDir);
/* I.S. Sembarang */
/* F.S. Data draf tersimpan dalam folder config/foo/draf */

/* Prosedur untuk menyimpan data utas dalam folder config/foo */
void SimpanUtas(char *folderDir);
/* I.S. Sembarang */
/* F.S. Data utas tersimpan dalam folder config/foo/utas */

#endif