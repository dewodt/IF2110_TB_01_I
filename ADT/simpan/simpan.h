#ifndef SIMPAN
#define SIMPAN

/* Prosedur untuk menyimpan seluruh data program dalam folder config/foo */
void Simpan();
/* I.S. Sembarang */
/* F.S. Data program tersimpan dalam folder config/foo */

/* Prosedur untuk menyimpan data pengguna dalam folder config/foo */
void SimpanPengguna();
/* I.S. Sembarang */
/* F.S. Data pengguna tersimpan dalam folder config/foo/pengguna */

/* Prosedur untuk menyimpan data kicauan dalam folder config/foo */
void SimpanKicauan(char *folderDir);
/* I.S. Sembarang */
/* F.S. Data kicauan tersimpan dalam folder config/foo/kicauan */

/* Prosedur untuk menyimpan data balasan dalam folder config/foo */
void SimpanBalasan();
/* I.S. Sembarang */
/* F.S. Data balasan tersimpan dalam folder config/foo/balasan */

/* Prosedur untuk menyimpan data draf dalam folder config/foo */
void SimpanDraf();
/* I.S. Sembarang */
/* F.S. Data draf tersimpan dalam folder config/foo/draf */

/* Prosedur untuk menyimpan data utas dalam folder config/foo */
void SimpanUtas();
/* I.S. Sembarang */
/* F.S. Data utas tersimpan dalam folder config/foo/utas */

#endif