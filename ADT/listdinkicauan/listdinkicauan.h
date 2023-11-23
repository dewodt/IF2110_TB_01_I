/* MODUL KICAUAN DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list dinamis kicauan menyimpan root tree kicauan */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#ifndef LISTDINKICAUAN_H
#define LISTDINKICAUAN_H

#include "../boolean.h"
#include "../tree/tree.h"

/*  Kamus Umum */
#define IDX_MIN_LDK 0
/* Indeks minimum list */
#define IDX_UNDEF_LDK -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
// LDK: List Dinamis Kicauan
typedef TreeKicauan ElTypeListDinKicauan;
typedef int IdxType;
typedef struct listDinKicauan
{
  ElTypeListDinKicauan *buffer; /* memori tempat penyimpan elemen (container) */
  int nEff;                     /* >=0, banyaknya elemen efektif */
  int capacity;                 /* ukuran elemen */
} ListDinKicauan;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListDinKicauan, cara deklarasi dan akses: */
/* Deklarasi : l : ListDinKicauan */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

// Global Variable List Kicauan
extern ListDinKicauan listKicauan;

/* ********** SELEKTOR ********** */
#define NEFF_LDK(l) (l).nEff
#define BUFFER_LDK(l) (l).buffer
#define ELMT_LDK(l, i) (l).buffer[i]
#define CAPACITY_LDK(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDinKicauan(ListDinKicauan *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateListDinKicauan(ListDinKicauan *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY_LD(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listDinKicauanLength(ListDinKicauan l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* Prosedur Menghitung banyaknya kicauan yang memiliki balasan */
int countKicauanWithBalasan(ListDinKicauan l);
/* Mengembalikan banyaknya kicauan yg memiliki balasan */

/* *** Selektor INDEKS *** */
IdxType getFirstIdxListDinKicauan(ListDinKicauan l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdxListDinKicauan(ListDinKicauan l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidListDinKicauan(ListDinKicauan l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEffListDinKicauan(ListDinKicauan l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
/* Prosedur mengecek apakah ada kicauan dengan idKicauan */
boolean isKicauanExist(int idKicauan);
/* Mengembalikan true bila kicauan ada, mengembalikan false bila tidak. */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyListDinKicauan(ListDinKicauan l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFullListDinKicauan(ListDinKicauan l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** OPERASI LAIN ********** */
/* Sortir kicauan berdasarkan datetime */
ListDinKicauan sortKicauanByDateTime(ListDinKicauan l, boolean asc);
/* Menghasilkan list baru list dinamis kicauan yang sudah disortir berdasarkan tanggalnya */

void copyListDinKicauan(ListDinKicauan lIn, ListDinKicauan *lOut);
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListDinKicauan(ListDinKicauan *l, ElTypeListDinKicauan val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListDinKicauan(ListDinKicauan *l, ElTypeListDinKicauan *val);
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListDinKicauan(ListDinKicauan *l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkListDinKicauan(ListDinKicauan *l, int num);
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressListDinKicauan(ListDinKicauan *l);
/* Proses : Mengubah capacity sehingga capacity = nEff */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = nEff */

#endif