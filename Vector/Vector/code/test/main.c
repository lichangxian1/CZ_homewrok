#include "matrix_pro.h"
#include <stdlib.h>

int main(){
    INTEGER rows = 3;
    INTEGER cols = 3;
    Matrix* mat_test = createMatrix(rows, cols);
    if (mat_test == NULL){
        return _ERROR_MEMORY_ALLOC_FAILED;
    }
    INTEGER count = 1;
    for(INTEGER i = 0; i < mat_test -> rows; i++){
        for (INTEGER j = 0; j < mat_test -> cols; j++){
            INDEX index = i * mat_test -> cols + j;
            mat_test -> data [index] = count;
            count++;
        }
    }
    printMatrix(mat_test);
    return 0;
}

