#include <stdlib.h>
#include "matrix_free.h"

void freeMatrix(Matrix *mat)
{
    if (mat != NULL)
    {
        if (mat->data != NULL)
        {
            free(mat->data);
            mat->data = NULL;
        }
        free(mat);
    }
}
