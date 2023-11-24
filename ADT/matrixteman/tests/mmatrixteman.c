#include "../../masukan/masukan.h"
#include "../../masukan/masukanint.h"
#include "../matrixteman/matrixteman.h"
#include <stdio.h>

int main()
{
    MatrixTeman matrix1, matrix2;

    createMatrixTeman(3, 3, &matrix1);
    createMatrixTeman(3, 3, &matrix2);

    for (int i = 0; i < ROW_EFF_MTXTEMAN(matrix1); i++)
    {
        for (int j = 0; j < COL_EFF_MTXTEMAN(matrix1); j++)
        {
            ELMT_MTXTEMAN(matrix1, i, j) = i + j;
        }
    }

    copyMatrixTeman(matrix1, &matrix2);

    // Display Matrix
    printf("Matrix 1:\n");
    displayMatrixTeman(matrix1);

    printf("\nMatrix 2 (copied from Matrix 1):\n");
    displayMatrixTeman(matrix2);

    if (isMatrixTemanEqual(matrix1, matrix2))
    {
        printf("\nMatrix 1 setara dengan Matrix 2\n");
    }
    else
    {
        printf("\nMatrix 1 tidak setara dengan Matrix 2\n");
    }

    if (isSymmetricMatrixTeman(matrix1))
    {
        printf("Matrix 1 is simetris\n");
    }
    else
    {
        printf("Matrix 1 is asimetris\n");
    }

    if (isIdentityMatrixTeman(matrix1))
    {
        printf("Matrix 1 adalah matrix identitas\n");
    }
    else
    {
        printf("Matrix 1 bukan matrix identitas\n");
    }

    if (isSparseMatrixTeman(matrix1))
    {
        printf("Matrix 1 adalah matriks Sparse\n");
    }
    else
    {
        printf("Matrix 1 bukan matriks Sparse\n");
    }

    return 0;
}
