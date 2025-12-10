#ifndef MATRIX_STORE_H
#define MATRIX_STORE_H

#include "basic_data_structure.h"
#include "basic_error_id.h"
#include "basic_data_type.h"

// 创建矩阵
// 返回一个新分配的矩阵，包含指定的行和列数
// 如果分配失败，返回NULL
Matrix *createMatrix(INTEGER rows, INTEGER cols);

#endif