/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef MATRIX_H
#define MATRIX_H

#include "boolean.h"
#include "modifiedmatrix.h"
#include <stdio.h>
#include "pcolor.h"

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
        for (j = 0; j < nCols; j++) {
            ELMT_MTX(*m, i, j) = '*';
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

ElType getELMT_MTXDiagonal(Matrix m, IdxType i) {
    /* Mengirimkan elemen m(i,i) */
    return (ELMT_MTX(m, i, i));
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

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2) {
    /* Prekondisi : m1 berukuran sama dengan m2 */
    /* Mengirim hasil penjumlahan matriks: m1 + m2 */
    Matrix m3;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            ELMT_MTX(m3, i, j) = ELMT_MTX(m1, i, j) + ELMT_MTX(m2, i, j);
        }
    }
    return m3;
}

Matrix subtractMatrix(Matrix m1, Matrix m2) {
    /* Prekondisi : m1 berukuran sama dengan m2 */
    /* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
    Matrix m3;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            ELMT_MTX(m3, i, j) = ELMT_MTX(m1, i, j) - ELMT_MTX(m2, i, j);
        }
    }
    return m3;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2) {
    /* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
    /* Mengirim hasil perkalian matriks: salinan m1 * m2 */
    Matrix m3;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);
    int i, j, k;
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m2); j++) {
            for (k = 0; k < COL_EFF(m1); k++) {
                ELMT_MTX(m3, i, j) += ELMT_MTX(m1, i, k) * ELMT_MTX(m2, k, j);
            }
        }
    }
    return m3;
}

Matrix multiplyMatrixWithMod(Matrix m1, Matrix m2, int mod) {
    /* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
    /* Mengirim hasil perkalian matriks: salinan (m1 * m2)%mod, artinya 
    setiap elemen matrix hasil perkalian m1 * m2 dilakukan modulo terhadap mod */
    Matrix m3;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);
    int i, j, k;
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m2); j++) {
            for (k = 0; k < COL_EFF(m1); k++) {
                ELMT_MTX(m3, i, j) += (ELMT_MTX(m1, i, k) * ELMT_MTX(m2, k, j));
            }
        }
    }

    int a, b;
    for (a = 0; a < ROW_EFF(m3); a++) {
        for (b = 0; b < COL_EFF(m3); b++) {
            ELMT_MTX(m3, a, b) = (ELMT_MTX(m3, a, b) % mod);
        }
    }
    return m3;

}

Matrix multiplyByConst(Matrix m, ElType x) {
    /* Mengirim hasil perkalian setiap elemen m dengan x */
    Matrix m2;
    createMatrix(ROW_EFF(m), COL_EFF(m), &m2);
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            ELMT_MTX(m2, i, j) = x * ELMT_MTX(m, i, j);
        }
    }
    return m2;
}

void pMultiplyByConst(Matrix *m, ElType k) {
    /* I.S. m terdefinisi, k terdefinisi */
    /* F.S. Mengalikan setiap elemen m dengan k */
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++) {
        for (j = 0; j < COL_EFF(*m); j++) {
            ELMT_MTX(*m, i, j) *= k;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2) {
    /* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
    /* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
    /* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
    if (ROW_EFF(m1) != ROW_EFF(m2) || COL_EFF(m1) != COL_EFF(m2)) {
        return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            if (ELMT_MTX(m1, i, j) != ELMT_MTX(m2, i, j)) {
                return false;
            }
        }
    }
    return true;

}

boolean isMatrixNotEqual(Matrix m1, Matrix m2) {
    /* Mengirimkan true jika m1 tidak sama dengan m2 */
    return (!(isMatrixEqual(m1, m2)));
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2) {
    /* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
    /* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */
    return ((ROW_EFF(m1) == ROW_EFF(m2)) && (COL_EFF(m1) == COL_EFF(m2)));
}

/* ********** Operasi lain ********** */
int countELMT_MTX(Matrix m) {
    /* Mengirimkan banyaknya elemen m */
    return (ROW_EFF(m) * COL_EFF(m));
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m) {
    /* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
    return (ROW_EFF(m) == COL_EFF(m));
}

boolean isSymmetric(Matrix m) {
    /* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
    dan untuk setiap elemen m, m(i,j)=m(j,i) */
    if (!(isSquare(m))) {
        return false;
    }
    
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            if (ELMT_MTX(m, i, j) != ELMT_MTX(m, j, i)) {
                return false;
            }
        }
    }
    
    return true;
}

boolean isIdentity(Matrix m) {
    /* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
    setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
    if (!(isSquare(m))) {
        return false;
    }
    
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            if (i == j) {
                if (ELMT_MTX(m, i, j) != 1) {
                return false;
                }
            }
            else {
                if (ELMT_MTX(m, i, j) != 0) {
                return false;
                }
            }
        }
    }
    return true;
}

boolean isSparse(Matrix m) {
    /* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
    hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
    float count = 0;
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
            for (j = 0; j < COL_EFF(m); j++) {
                if (ELMT_MTX(m, i, j) != 0) {
                    count++;
                }
            }
        }
    return (count <= (countELMT_MTX(m) * 5 / 100));
}

Matrix negation(Matrix m) {
    /* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
    Matrix m1;
    createMatrix(ROW_EFF(m), COL_EFF(m), &m1);
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            ELMT_MTX(m1, i, j) = ELMT_MTX(m, i, j) * -1;
        }
    }
    return m1;
}

void pNegation(Matrix *m) {
    /* I.S. m terdefinisi */
    /* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++) {
        for (j = 0; j < COL_EFF(*m); j++) {
            ELMT_MTX(*m, i, j) *= -1;
        }
    }
}

float determinant(Matrix m) {
    /* Prekondisi: isSquare(m) */
    /* Menghitung nilai determinan m */
    if (!isSquare(m)){
      return 0;
    }
    int n = getLastIdxRow(m) + 1;
    int tmpRow[11];
    int i, j, k, idx, temp1, temp2;
    int det = 1;
    int co = 1;
    for (i = 0; i < n; i++) {
        idx = i;
        while((ELMT_MTX(m, idx, i) == 0) && (idx < n)) {
            idx++;
        }
        if (idx == n) {
            return 0;
        }
        if (i != idx) {
            for (j = 0; j < n; j++) {
                temp1 = ELMT_MTX(m, i, j);
                ELMT_MTX(m, i, j) = ELMT_MTX(m, idx, j);
                ELMT_MTX(m, idx, j) = temp1;
            }
            det *= -1;
        }
        for(j = 0; j < n; j++) {
            tmpRow[j] = ELMT_MTX(m, i, j);
        }
        for (j = i + 1; j < n; j++) {
            temp1 = tmpRow[i];
            temp2 = ELMT_MTX(m,j,i);
            for (k = 0; k < n; k++){
                ELMT_MTX(m, j, k) = ((temp1 * ELMT_MTX(m,j,k)) - (temp2 * tmpRow[k]));
            }
            co *= temp1;
        }
    }
    for (i = 0; i < n; i++){
        det *= ELMT_MTX(m, i, i);
    }
    return (det/co);
}

Matrix transpose(Matrix m) {
    /* I.S. m terdefinisi dan IsSquare(m) */
    /* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    Matrix m1;
    createMatrix(ROW_EFF(m), COL_EFF(m), &m1);
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            ELMT_MTX(m1, i , j) = ELMT_MTX(m, j, i);
        }
    }
    return m1;
}

void pTranspose(Matrix *m) {
    /* I.S. m terdefinisi dan IsSquare(m) */
    /* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++) {
        for (j = i+1; j < COL_EFF(*m); j++) {
            int temp = ELMT_MTX(*m, i, j);
            ELMT_MTX(*m, i, j) = ELMT_MTX(*m, j, i);
            ELMT_MTX(*m, j, i) = temp;
        }
    }
}

#endif

// int main() {
//     Matrix m1, m2;
//     readMatrix(&m1, 3, 3);
//     displayMatrix(m1);
//     copyMatrix(m1, &m2);
//     displayMatrix(m2);
// }