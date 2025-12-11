#include "matrix_pro.h"
#include <stdlib.h>
#include <stdio.h>
int main()
{
    printf("Matrix of size 100\n");
    INTEGER rows_1 = 100;
    INTEGER cols_1 = 100;
    for (INTEGER i = 0; i < 10; i++)
    {
        printf("100第 %d 次\n", i);
        REAL alpha = i;
        Matrix *A = createMatrix(rows_1, cols_1);
        Matrix *B = createMatrix(rows_1, cols_1);
        Matrix *add = addMatrix(A, B);
        Matrix *scal = scalaire_multiplyMatrix(alpha, A);
        Matrix *trans = transposeMatrix(A);
        Matrix *mult = multiplyMatrix(A, B);

        freeMatrix(A);
        freeMatrix(B);
        freeMatrix(add);
        freeMatrix(scal);
        freeMatrix(trans);
        freeMatrix(mult);
    }

    printf("维度为1000的矩阵\n");
    INTEGER rows_2 = 1000;
    INTEGER cols_2 = 1000;
    for (INTEGER i = 0; i < 10; i++)
    {
        printf("1000第 %d 次\n", i);
        REAL alpha = i;
        Matrix *A = createMatrix(rows_2, cols_2);
        Matrix *B = createMatrix(rows_2, cols_2);
        Matrix *add = addMatrix(A, B);
        Matrix *scal = scalaire_multiplyMatrix(alpha, A);
        Matrix *trans = transposeMatrix(A);
        Matrix *mult = multiplyMatrix(A, B);

        freeMatrix(A);
        freeMatrix(B);
        freeMatrix(add);
        freeMatrix(scal);
        freeMatrix(trans);
        freeMatrix(mult);
    }


    printf("维度为10000的矩阵\n");
    INTEGER rows_3 = 10000;
    INTEGER cols_3 = 10000;
    for (INTEGER i = 0; i < 10; i++)
    {
        printf("10000第 %d 次\n", i);
        REAL alpha = i;
        Matrix *A = createMatrix(rows_3, cols_3);
        Matrix *B = createMatrix(rows_3, cols_3);
        Matrix *add = addMatrix(A, B);
        Matrix *scal = scalaire_multiplyMatrix(alpha, A);
        Matrix *trans = transposeMatrix(A);
        Matrix *mult = multiplyMatrix(A, B);

        freeMatrix(A);
        freeMatrix(B);
        freeMatrix(add);
        freeMatrix(scal);
        freeMatrix(trans);
        freeMatrix(mult);
    }


    return 0;
}
