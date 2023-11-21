/* Implementasi ADT MatrixTeman */

#include "matrixteman.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MatrixTeman *** */
void createMatrixTeman(int nRows, int nCols, MatrixTeman *m)
/* Membentuk sebuah MatrixTeman "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
{
  // Inisialisasi neff
  ROW_EFF_MTXTEMAN(*m) = nRows;
  COL_EFF_MTXTEMAN(*m) = nCols;
}

/* *** Selektor "Dunia MatrixTeman" *** */
boolean isMatrixTemanIdxValid(int i, int j)
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
{
  return (i >= 0) && (i < ROW_CAP_MTXTEMAN) && (j >= 0) && (j < COL_CAP_MTXTEMAN);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxTypeMTXTeman getLastIdxRowMatrixTeman(MatrixTeman m)
/* Mengirimkan Index baris terbesar m */
{
  return ROW_EFF_MTXTEMAN(m) - 1;
}
IdxTypeMTXTeman getLastIdxColMatrixTeman(MatrixTeman m)
/* Mengirimkan Index kolom terbesar m */
{
  return COL_EFF_MTXTEMAN(m) - 1;
}
boolean isIdxEffMatrixTeman(MatrixTeman m, IdxTypeMTXTeman i, IdxTypeMTXTeman j)
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
{
  return (i >= 0) && (i <= getLastIdxRow(m)) && (j >= 0) && (j <= getLastIdxCol(m));
}
ElTypeMTXTeman getElmtDiagonalMatrixTeman(MatrixTeman m, IdxTypeMTXTeman i)
/* Mengirimkan elemen m(i,i) */
{
  return ELMT_MTXTEMAN(m, i, i);
}

/* ********** Assignment  MatrixTeman ********** */
void copyMatrixTeman(MatrixTeman mIn, MatrixTeman *mOut)
/* Melakukan assignment mOut <- mIn */
{
  int i, j;
  createMatrix(ROW_EFF_MTXTEMAN(mIn), COL_EFF_MTXTEMAN(mIn), mOut);
  for (i = 0; i < ROW_EFF_MTXTEMAN(mIn); i++)
  {
    for (j = 0; j < COL_EFF_MTXTEMAN(mIn); j++)
    {
      ELMT_MTXTEMAN(*mOut, i, j) = ELMT_MTXTEMAN(mIn, i, j);
    }
  }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrixTeman(MatrixTeman *m, int nRow, int nCol)
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
  int i, j;
  createMatrix(nRow, nCol, m);
  for (i = 0; i < nRow; i++)
  {
    for (j = 0; j < nCol; j++)
    {
      scanf("%d", &ELMT_MTXTEMAN(*m, i, j));
    }
  }
}

void displayMatrixTeman(MatrixTeman m)
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
  int i, j;
  for (i = 0; i < ROW_EFF_MTXTEMAN(m); i++)
  {
    for (j = 0; j < COL_EFF_MTXTEMAN(m); j++)
    {
      printf("%d", ELMT_MTXTEMAN(m, i, j));
      if (j != COL_EFF_MTXTEMAN(m) - 1)
      {
        printf(" ");
      }
    }
    printf("\n");
  }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MatrixTeman ********** */
boolean isMatrixTemanEqual(MatrixTeman m1, MatrixTeman m2)
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
{
  int i, j;
  boolean equal;
  // Jmlh elemen beda
  if (countElmt(m1) != countElmt(m2))
  {
    return false;
  }

  // Jmlh elemen sama
  equal = true;
  for (i = 0; i < ROW_EFF_MTXTEMAN(m1); i++)
  {
    for (j = 0; j < COL_EFF_MTXTEMAN(m1); j++)
    {
      if (ELMT_MTXTEMAN(m1, i, j) != ELMT_MTXTEMAN(m2, i, j))
      {
        equal = false;
      }
    }
  }
  return equal;
}
boolean isMatrixTemanNotEqual(MatrixTeman m1, MatrixTeman m2)
/* Mengirimkan true jika m1 tidak sama dengan m2 */
{
  return !isMatrixEqual(m1, m2);
}
boolean isMatrixTemanSizeEqual(MatrixTeman m1, MatrixTeman m2)
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */
{
  return ROW_EFF_MTXTEMAN(m1) == ROW_EFF_MTXTEMAN(m2) && COL_EFF_MTXTEMAN(m1) == COL_EFF_MTXTEMAN(m2);
}

/* ********** Operasi lain ********** */
int countElmtMatrixTeman(MatrixTeman m)
/* Mengirimkan banyaknya elemen m */
{
  return ROW_EFF_MTXTEMAN(m) * COL_EFF_MTXTEMAN(m);
}

/* ********** KELOMPOK TEST TERHADAP MatrixTeman ********** */
boolean isSquareMatrixTeman(MatrixTeman m)
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
{
  return ROW_EFF_MTXTEMAN(m) == COL_EFF_MTXTEMAN(m);
}
boolean isSymmetricMatrixTeman(MatrixTeman m)
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) dan untuk setiap elemen m, m(i,j)=m(j,i) */
{
  int i, j;
  boolean symmetric;
  if (!isSquare(m))
  {
    return false;
  }

  symmetric = true;
  for (i = 0; i < ROW_EFF_MTXTEMAN(m); i++)
  {
    for (j = 0; j < i; j++)
    {
      if (ELMT_MTXTEMAN(m, i, j) != ELMT_MTXTEMAN(m, j, i))
      {
        symmetric = false;
      }
    }
  }

  return symmetric;
}
boolean isIdentityMatrixTeman(MatrixTeman m)
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
  int i, j;
  boolean identity;

  if (!isSquare(m))
  {
    return false;
  }

  identity = true;
  for (i = 0; i < ROW_EFF_MTXTEMAN(m); i++)
  {
    for (j = 0; j < COL_EFF_MTXTEMAN(m); j++)
    {
      if ((i == j && ELMT_MTXTEMAN(m, i, j) != 1) || (i != j && ELMT_MTXTEMAN(m, i, j) != 0))
      {
        identity = false;
      }
    }
  }

  return identity;
}
boolean isSparseMatrixTeman(MatrixTeman m)
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
  int i, j, countNonZero;

  for (i = 0; i < ROW_EFF_MTXTEMAN(m); i++)
  {
    for (j = 0; j < COL_EFF_MTXTEMAN(m); j++)
    {
      if (ELMT_MTXTEMAN(m, i, j) != 0)
      {
        countNonZero += 1;
      }
    }
  }

  return 100 * countNonZero <= 5 * countElmt(m);
}
