#include <stdlib.h>
#include "matrix_store.h"

Matrix *createMatrix(INTEGER rows, INTEGER cols)
{
    Matrix *m = (Matrix *)malloc(sizeof(Matrix));
    if (m == NULL)
    {
        return NULL;
    }
    m->rows = rows;
    m->cols = cols;
    m->data = (REAL *)malloc(sizeof(REAL) * rows * cols);
    if (m->data == NULL)
    {
        free(m);
        return NULL;
    }
    return m;
}
