/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef MATRIX_TEMAN
#define MATRIX_TEMAN

#include "../boolean.h"

/* Ukuran maksimum baris dan kolom */
#define ROW_CAP_MTXTEMAN 20
#define COL_CAP_MTXTEMAN 20

typedef int IdxTypeMTXTeman; /* Index baris, kolom */
typedef int ElTypeMTXTeman;
typedef struct
{
   ElTypeMTXTeman mem[ROW_CAP_MTXTEMAN][COL_CAP_MTXTEMAN];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MatrixTeman;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP_MTXTEMAN-1][0..COL_CAP_MTXTEMAN-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

// variabel global
extern MatrixTeman RelasiPertemanan;

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MatrixTeman *** */
void createMatrixTeman(int nRows, int nCols, MatrixTeman *m);
/* Membentuk sebuah MatrixTeman "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define ROW_EFF_MTXTEMAN(M) (M).rowEff
#define COL_EFF_MTXTEMAN(M) (M).colEff
#define ELMT_MTXTEMAN(M, i, j) (M).mem[(i)][(j)]

/* *** Selektor "Dunia MatrixTeman" *** */
boolean isMatrixTemanIdxValid(int i, int j);
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxTypeMTXTeman getLastIdxRowMatrixTeman(MatrixTeman m);
/* Mengirimkan Index baris terbesar m */
IdxTypeMTXTeman getLastIdxColMatrixTeman(MatrixTeman m);
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEffMatrixTeman(MatrixTeman m, IdxTypeMTXTeman i, IdxTypeMTXTeman j);
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElTypeMTXTeman getElmtDiagonalMatrixTeman(MatrixTeman m, IdxTypeMTXTeman i);
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  MatrixTeman ********** */
void copyMatrixTeman(MatrixTeman mIn, MatrixTeman *mOut);
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void displayMatrixTeman(MatrixTeman m);
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MatrixTeman ********** */
boolean isMatrixTemanEqual(MatrixTeman m1, MatrixTeman m2);
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isMatrixTemanNotEqual(MatrixTeman m1, MatrixTeman m2);
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isMatrixTemanSizeEqual(MatrixTeman m1, MatrixTeman m2);
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

/* ********** Operasi lain ********** */
int countElmtMatrixTeman(MatrixTeman m);
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP MatrixTeman ********** */
boolean isSquareMatrixTeman(MatrixTeman m);
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
boolean isSymmetricMatrixTeman(MatrixTeman m);
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m)
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
boolean isIdentityMatrixTeman(MatrixTeman m);
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean isSparseMatrixTeman(MatrixTeman m);
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */

#endif