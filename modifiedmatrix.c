/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef MATRIX_H
#define MATRIX_H

#include "boolean.h"
#include "modifiedmatrix.h"
#include <stdio.h>
#include "./ADT/pcolor/pcolor.h"
#include "masukan.h"

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
void createMatrix(int nRows, int nCols, Matrix *m) {
    /* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
    /* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
    /* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
    
    int i, j;
    for (i = 0; i < nRows; i++) {
        for (j = 0; j < nCols; j+=2) {
            ELMT_MTX(*m, i, j) = 'R';
            ELMT_MTX(*m, i, j+1) = '*';
        }
    }
}

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j) {
    /* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
    return ((i >= 0 && i < ROW_CAP) && (j >= 0 && j < COL_CAP));
}


/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m) {
    /* Mengirimkan Index baris terbesar m */
    return (ROW_EFF(m)-1);
}

IdxType getLastIdxCol(Matrix m) {
    /* Mengirimkan Index kolom terbesar m */
    return (COL_EFF(m)-1);
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j) {
    /* Mengirimkan true jika i, j adalah Index efektif bagi m */
    return ((i >= 0 && i <= getLastIdxRow(m)) && (j >= 0 && j <= getLastIdxCol(m)));
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut) {
    /* Melakukan assignment mOut <- mIn */
    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    int i, j;
    for (i = 0; i < ROW_EFF(mIn); i++) {
        for (j = 0; j < COL_EFF(mIn); j++) {
            ELMT_MTX(*mOut, i, j) = ELMT_MTX(mIn, i, j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol) {
    /* I.S. isIdxValid(nRow,nCol) */
    /* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
    /* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
    /* Selanjutnya membaca nilai elemen per baris dan kolom */
    /* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
    1 2 3
    4 5 6
    8 9 10 
    */
    if (isMatrixIdxValid(nRow - 1, nCol - 1)) {
        createMatrix(nRow, nCol, m);
        int i, j;
        for (i = 0; i < nRow; i++) {
            for (j = 0; j < nCol; j++) {
                scanf("%s", &ELMT_MTX(*m, i, j));
            }
        }
    }
}

void readMatrixMasukan(Matrix *m, int nRow, int nCol) {
    if (isMatrixIdxValid(nRow - 1, nCol - 1)) {
        createMatrix(nRow, nCol, m);
        int i, j;
        START();
        EndMASUKAN = false;
        for (i = 0; i < nRow && !EndMASUKAN; i++) {
            for (j = 0; j < nCol && !EndMASUKAN; j++) {
                while (currentChar == '\n' || currentChar == ' ') {
                    ADV();
                }
                ELMT_MTX(*m, i, j) = currentChar;
                ADV();

                if (currentChar == ';') {
                    EndMASUKAN = true;
                }
            }
        }
    }
}

void displayMatrix(Matrix m) {
    /* I.S. m terdefinisi */
    /* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
    dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
    /* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
    /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
    1 2 3
    4 5 6
    8 9 10
    */
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            if (j < COL_EFF(m)-1) {
                print_red(ELMT_MTX(m, i, j));
            }
            else {
                print_red(ELMT_MTX(m, i, j));
                printf("\n");
            }
        }
    }
}

void displayProfile(Matrix m) {
    /* I.S. m terdefinisi */
    /* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
    dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
    /* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
    /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
    1 2 3
    4 5 6
    8 9 10
    */
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j+=2) {
            if (j < COL_EFF(m)-2) {
                if (ELMT_MTX(m, i, j) == 'R') {
                    print_red(ELMT_MTX(m, i, j+1)); 
                } else if (ELMT_MTX(m, i, j) == 'G') {
                    print_green(ELMT_MTX(m, i, j+1));
                } else if (ELMT_MTX(m, i, j) == 'B') {
                    print_blue(ELMT_MTX(m, i, j+1));
                }
            }
            else if (j == COL_EFF(m)-2) {
                if (ELMT_MTX(m, i, j) == 'R') {
                    print_red(ELMT_MTX(m, i, j+1)); 
                    printf("\n");
                } else if (ELMT_MTX(m, i, j) == 'G') {
                    print_green(ELMT_MTX(m, i, j+1));
                    printf("\n");
                } else if (ELMT_MTX(m, i, j) == 'B') {
                    print_blue(ELMT_MTX(m, i, j+1));
                    printf("\n");
                }
            }
            // printf("j: %d\n", j);
        }
    }
}


#endif

// int main() {
//     Matrix m1, m2;
//     createMatrix(5, 10, &m2);
//     displayProfile(m2);
//     readMatrixMasukan(&m1, 5, 10);
//     displayProfile(m1);
// }