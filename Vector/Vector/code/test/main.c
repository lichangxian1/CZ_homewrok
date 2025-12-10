#include "matrix_pro.h"
#include <stdlib.h>

int main(){
    INTEGER rows = 3;
    INTEGER cols = 3;

    Matrix* A = createMatrix(rows, cols);
    printMatrix(A);

    Matrix *B = createMatrix(rows, cols);
    printMatrix(B);

    Matrix *C = createMatrix(rows, cols);
    printMatrix(C);

    Matrix *D = addMatrix(A, B);
    printMatrix(D);

    Matrix *E = scalaire_multiplyMatrix(2.0, A );
    printMatrix(E);

    Matrix *F = multiplyMatrix(A, B);
    printMatrix(F);
    
    Matrix *G = transposeMatrix(A);
    printMatrix(G);
    return 0;

    freeMatrix(C);
    printMatrix(C);
}

