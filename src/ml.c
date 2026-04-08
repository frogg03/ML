#include "../includes/ml.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

Matrix mat_alloc(size_t rows, size_t cols)
{
	assert(rows != 0);
	assert(cols != 0);

	Matrix m;
	m.rows = rows;
	m.cols = cols;
	m.data = malloc(sizeof(*m.data)*rows*cols);
	assert(m.data != NULL);
	return m;
}

void mat_dot(Matrix dat, Matrix a, Matrix b);
void mat_sum(Matrix dst, Matrix a);
void mat_print(Matrix m);

