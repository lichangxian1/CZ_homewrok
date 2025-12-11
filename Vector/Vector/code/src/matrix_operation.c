#include <stdlib.h>
#include <stdio.h>
#include "matrix_operation.h" 
#include <time.h>

Matrix* addMatrix(const Matrix *A, const Matrix *B){
    clock_t start, end;
    REAL cpu_time_used;
    start = clock();  // 开始计时
    INTEGER error_code = _ERROR_NO_ERROR;
    if (A -> rows != B -> rows || A -> cols != B -> cols){
        error_code = _ERROR_DIMENSION_NOT_MATCH;
        return NULL;
    }
    Matrix * C = (Matrix *)malloc(sizeof(Matrix));
    if (C == NULL) {
        error_code = _ERROR_MEMORY_ALLOC_FAILED;
        return NULL;
    }
    C->rows = A->rows;
    C->cols = A->cols;
    C->data = (REAL*)malloc(C->rows * C->cols * sizeof(REAL));
    if (C->data == NULL) {
        free(C);
        error_code = _ERROR_MEMORY_ALLOC_FAILED;
        return NULL;
    }
    for (int i = 0; i < C->rows; i++) {
        for (int j = 0; j < C->cols; j++) {
            C->data[i * C->cols + j] = A->data[i * A->cols + j] + B->data[i * B->cols + j];
        }
    }
    end = clock();  // 结束计时
    cpu_time_used = ((REAL) (end - start)) / CLOCKS_PER_SEC;  // 计算时间
    printf("矩阵加法执行时间为: %f seconds\n", cpu_time_used);
    printf("错误代码为：%d\n", error_code);
    return C;
}

Matrix* scalaire_multiplyMatrix(const REAL Alpha, const Matrix *A){
    clock_t start, end;
    REAL cpu_time_used;
    start = clock();  // 开始计时
    INTEGER error_code = _ERROR_NO_ERROR;
    if (A == NULL) {
        error_code = _ERROR_NULL_MATRIX;
        return NULL;
    }
    Matrix *C = (Matrix *)malloc(sizeof(Matrix));
    if (C == NULL) {
        error_code = _ERROR_MEMORY_ALLOC_FAILED;
        return NULL;
    }
    C->rows = A->rows;
    C->cols = A->cols;
    C->data = (REAL*)malloc(C->rows * C->cols * sizeof(REAL));
    if (C->data == NULL) {
        free(C);
        error_code = _ERROR_MEMORY_ALLOC_FAILED;
        return NULL;
    }
    for (int i = 0; i < C->rows; i++) {
        for (int j = 0; j < C->cols; j++) {
            C->data[i * C->cols + j] = Alpha * A->data[i * A->cols + j];
        }
    }
    end = clock();  // 结束计时
    cpu_time_used = ((REAL) (end - start)) / CLOCKS_PER_SEC;  // 计算时间
    printf("矩阵标量乘法执行时间为: %f seconds\n", cpu_time_used);
    printf("错误代码为：%d\n", error_code);
    return C;

}
Matrix *transposeMatrix(const Matrix *A){
    clock_t start, end;
    REAL cpu_time_used;
    start = clock();  // 开始计时
    INTEGER error_code = _ERROR_NO_ERROR;
    if (A == NULL){
        error_code = _ERROR_NULL_MATRIX;
        return NULL;
    }
    if (A->data == NULL) {
        error_code = _ERROR_NULL_POINTER;
        return NULL;
    }
    Matrix *C = (Matrix *)malloc(sizeof(Matrix));
    if (C == NULL) {
        error_code = _ERROR_MEMORY_ALLOC_FAILED;
        return NULL;
    }
    C->rows = A->cols;
    C->cols = A->rows;
    C->data = (REAL*)malloc(C->rows * C->cols * sizeof(REAL));
    if (C->data == NULL) {
        free(C);
        error_code = _ERROR_MEMORY_ALLOC_FAILED;
        return NULL;
    }
    for (int i = 0; i < C->rows; i++) {
        for (int j = 0; j < C->cols; j++) {
            C -> data [i * C->cols + j] = A -> data [j * A -> cols + i];
        }
    }
    end = clock();  // 结束计时
    cpu_time_used = ((REAL) (end - start)) / CLOCKS_PER_SEC;  // 计算时间
    printf("矩阵转置执行时间为: %f seconds\n", cpu_time_used);
    printf("错误代码为：%d\n", error_code);
    return C;
}

Matrix *multiplyMatrix(const Matrix *A, const Matrix *B){
    clock_t start, end;
    REAL cpu_time_used;
    start = clock();  // 开始计时
    INTEGER error_code = _ERROR_NO_ERROR;
    if (A == NULL || B == NULL) {
        error_code = _ERROR_NULL_MATRIX;
        return NULL;
    }
    if (A -> cols != B -> rows){
        error_code = _ERROR_DIMENSION_NOT_MATCH;
        return NULL;
    }
    if (A->data == NULL || B->data == NULL) {
        error_code = _ERROR_NULL_POINTER;
        return NULL;
    }
    Matrix *C = (Matrix *)malloc(sizeof(Matrix));
    if (C == NULL) {
        error_code = _ERROR_MEMORY_ALLOC_FAILED;
        return NULL;
    }
    C -> rows = A -> rows;
    C -> cols = B -> cols;
    INTEGER n = A -> cols;
    C -> data = (REAL*)malloc(C->rows * C->cols * sizeof(REAL));
    if (C->data == NULL) {
        free(C);
        error_code = _ERROR_MEMORY_ALLOC_FAILED;
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
    end = clock();  // 结束计时
    cpu_time_used = ((REAL) (end - start)) / CLOCKS_PER_SEC;  // 计算时间
    printf("矩阵乘法执行时间为: %f seconds\n", cpu_time_used);
    printf("错误代码为：%d\n", error_code);
    return C;
}

void printMatrix(const Matrix *A){
    INTEGER error_code = _ERROR_NO_ERROR;
    if (A == NULL){
        error_code = _ERROR_NULL_MATRIX;
        return;
    }
    if (A->data == NULL) {
        error_code = _ERROR_NULL_POINTER;
        return;
    }
    for (INTEGER i = 0; i < A->rows; i++) {
        for (INTEGER j = 0; j < A->cols; j++) {
            printf("%f ", A->data[i * A->cols + j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("错误代码为：%d\n", error_code);
}
