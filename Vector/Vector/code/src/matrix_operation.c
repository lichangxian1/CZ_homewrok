#include <stdlib.h>
#include "matrix_operation.h" 

Matrix* addMatrix(const Matrix *A, const Matrix *B){
    if (A -> rows != B -> rows || A -> cols != B -> cols){
        return NULL;
    }
    Matrix * C = (Matrix *)malloc(sizeof(Matrix));
    if (C == NULL) {
        return NULL;
    }
    C->rows = A->rows;
    C->cols = A->cols;
    C->data = (REAL*)malloc(C->rows * C->cols * sizeof(REAL));
    if (C->data == NULL) {
        free(C);
        return NULL;
    }
    for (int i = 0; i < C->rows; i++) {
        for (int j = 0; j < C->cols; j++) {
            C->data[i * C->cols + j] = A->data[i * A->cols + j] + B->data[i * B->cols + j];
        }
    }
    return C;
}

Matrix* scalaire_multiplyMatrix(const REAL Alpha, const Matrix *A){
    if (A == NULL) {
        return NULL;
    }
    Matrix *C = (Matrix *)malloc(sizeof(Matrix));
    if (C == NULL) {
        return NULL;
    }
    C->rows = A->rows;
    C->cols = A->cols;
    C->data = (REAL*)malloc(C->rows * C->cols * sizeof(REAL));
    if (C->data == NULL) {
        free(C);
        return NULL;
    }
    for (int i = 0; i < C->rows; i++) {
        for (int j = 0; j < C->cols; j++) {
            C->data[i * C->cols + j] = Alpha * A->data[i * A->cols + j];
        }
    }
    return C;

}
Matrix *transposeMatrix(const Matrix *A){
    if (A == NULL){
        return _ERROR_NULL_MATRIX;   
    }
    if (A->data == NULL) {
        return _ERROR_NULL_POINTER;
    }
    Matrix *C = (Matrix *)malloc(sizeof(Matrix));
    if (C == NULL) {
        return NULL;
    }
    C->rows = A->cols;
    C->cols = A->rows;
    C->data = (REAL*)malloc(C->rows * C->cols * sizeof(REAL));
    if (C->data == NULL) {
        free(C);
        return NULL;
    }
    for (int i = 0; i < C->rows; i++) {
        for (int j = 0; j < C->cols; j++) {
            C -> data [i * C->cols + j] = A -> data [j * A -> cols + i];
        }
    }
    return C;
}

Matrix *multiplyMatrix(const Matrix *A, const Matrix *B){
    if (A == NULL || B == NULL) {
        return _ERROR_NULL_MATRIX;            
    }
    if (A -> cols != B -> rows){
        return _ERROR_DIMENSION_NOT_MATCH;
    }
    if (A->data == NULL || B->data == NULL) {
        return _ERROR_NULL_POINTER;
    }
    Matrix *C = (Matrix *)malloc(sizeof(Matrix));
    if (C == NULL) {
        return _ERROR_MEMORY_ALLOC_FAILED;
    }
    C -> rows = A -> rows;
    C -> cols = B -> cols;
    INTEGER n = A -> cols;
    C -> data = (REAL*)malloc(C->rows * C->cols * sizeof(REAL));
    if (C->data == NULL) {
        free(C);
        return NULL;
    }
    for (int i = 0; i < C->rows; i++) {
        for (int j = 0; j < C->cols; j++) {
            C->data[i * C->cols + j] = 0;
            for (INTEGER k = 0; k < n; k++) {
                C->data[i * C->cols + j] += A->data[i * A->cols + k] * B->data[k * B->cols + j];
            }
        }
    }
    return C;
}

void printMatrix(const Matrix *A){
    if (A == NULL){
        return _ERROR_NULL_MATRIX;   
    }
    if (A->data == NULL) {
        return _ERROR_NULL_POINTER;
    }
    for (INTEGER i = 0; i < A->rows; i++) {
        for (INTEGER j = 0; j < A->cols; j++) {
            printf("%f ", A->data[i * A->cols + j]);
        }
        printf("\n");
    }
}
