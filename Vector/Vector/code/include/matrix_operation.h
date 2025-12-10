#ifndef MATRIX_OPERATION_H
#define MATRIX_OPERATION_H

#include "basic_data_structure.h"
#include "basic_error_id.h"
#include "basic_data_type.h"
// 矩阵加分
Matrix *addMatrix(const Matrix *A, const Matrix *B);
// 矩阵数乘
Matrix *scalaire_multiplyMatrix(const REAL Alpha, const Matrix *A);
// 矩阵乘法
Matrix *multiplyMatrix(const Matrix *A, const Matrix *B);
// 矩阵转置
Matrix *transposeMatrix(const Matrix *A);
// 打印矩阵
void printMatrix(const Matrix *A);

#endif