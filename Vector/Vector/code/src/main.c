#include "matrix_pro.h"
#include <stdlib.h>
#include <stdio.h>
int main(){
    printf("Matrix of size 100\n");
    INTEGER rows_1 = 100;
    INTEGER cols_1 = 100;
    for (INTEGER i = 0;i < 10; i++){
        printf("test %d \n", i);
        REAL alpha = i;
        Matrix* A = createMatrix(rows_1, cols_1);
        Matrix *B = createMatrix(rows_1, cols_1);
        Matrix *add = addMatrix(A, B);
        freeMatrix(add);
        Matrix *scal = scalaire_multiplyMatrix(alpha, A);
        freeMatrix(scal);
        Matrix *trans = transposeMatrix(A);
        freeMatrix(trans);
        Matrix *mult = multiplyMatrix(A, B);
        freeMatrix(mult);
        freeMatrix(A);
        freeMatrix(B);
    }
    printf("Matrix of size 1000\n");
    INTEGER rows_2 = 1000;
    INTEGER cols_2 = 1000;
    for (INTEGER i = 0; i < 10; i++){
        printf("test %d \n", i);
        REAL alpha = i;
        Matrix* A = createMatrix(rows_2, cols_2);
        Matrix *B = createMatrix(rows_2, cols_2);
        Matrix *add = addMatrix(A, B);
        freeMatrix(add);
        Matrix *scal = scalaire_multiplyMatrix(alpha, A);
        freeMatrix(scal);
        Matrix *trans = transposeMatrix(A);
        freeMatrix(trans);
        Matrix *mult = multiplyMatrix(A, B);
        freeMatrix(mult);
        freeMatrix(A);
        freeMatrix(B);
    }
    printf("Matrix of size 10000\n");
    INTEGER rows_3 = 10000;
    INTEGER cols_3 = 10000;
    for (INTEGER i = 0; i < 10; i++){
        printf("第 %d 次\n", i);
        REAL alpha = i;
        Matrix* A = createMatrix(rows_3, cols_3);
        Matrix *B = createMatrix(rows_3, cols_3);
        Matrix *add = addMatrix(A, B);
        freeMatrix(add);
        Matrix *scal = scalaire_multiplyMatrix(alpha, A);
        freeMatrix(scal);
        Matrix *trans = transposeMatrix(A);
        freeMatrix(trans);
        Matrix *mult = multiplyMatrix(A, B);
        freeMatrix(mult);
        freeMatrix(A);
        freeMatrix(B);  
    }


    return 0;

}

