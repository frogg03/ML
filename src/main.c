#include "../includes/ml.h"

#include <stdio.h>

int main (void)
{
    Matrix a = mat_alloc(2, 3);
    Matrix b = mat_alloc(3, 4);
    Matrix c = mat_alloc(2, 4);

    for (size_t i = 0; i < a.rows * a.cols; i++)
        a.data[i] = i;

    for (size_t i = 0; i < b.rows * b.cols; i++)
        b.data[i] = 3 * i % 10;

    mat_dot(c, a, b);

    mat_print(a);
    mat_print(b);
    mat_print(c);

    return 0;
}
