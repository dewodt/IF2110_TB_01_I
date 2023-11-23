/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef MODIFIEDMATRIX_H
#define MODIFIEDMATRIX_H

#include <stdio.h>
#include "../boolean.h"
#include "../masukan/masukan.h"
#include "../pcolor/pcolor.h"

/* Ukuran maksimum baris dan kolom */
#define ROW_CAP 100
#define COL_CAP 100

typedef int IdxType; /* Index baris, kolom */
typedef int ElType;
typedef struct
{
   char mem[ROW_CAP][COL_CAP];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* *** Selektor *** */
#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMT_MTX(M, i, j) (M).mem[(i)][(j)]

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m);
// i.S.
// F.S.

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j);
// FOO

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m);
// FOO

IdxType getLastIdxCol(Matrix m);
// FOO

boolean isIdxEff(Matrix m, IdxType i, IdxType j);
// FOO

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut);
// I.S.
// F.S.

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol);
// I.S.
// F.S.

void readMatrixMasukan(Matrix *m, int nRow, int nCol);
// I.S.
// F.S.

void displayMatrix(Matrix m);
// I.S.
// F.S.

void displayProfile(Matrix m);
// I.S.
// F.S.

#endif
