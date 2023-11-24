#include <stdio.h>
#include "modifiedmatrix.h"

int main()
{
  Matrix m1, m2;
  createMatrix(5, 10, &m2);
  printf("Profil awal: \n");
  displayProfile(m2);
  printf("Masukkan matriks profil: \n");
  readMatrixMasukan(&m1, 5, 10);
  displayProfile(m1);
}

// RUN DALAM FOLDER MODIFIEDMATRIX
// gcc drivermodifiedmatrix.c modifiedmatrix.c ../masukan/masukan.c ../charmachine/charmachine.c ../pcolor/pcolor.c