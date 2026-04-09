#include "../includes/ml.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
	size_t rows;
	size_t cols;
	MyFloat *data;
} Matrix;

typedef struct {
	Matrix weights;
	Matrix bias;
	Matrix aux;
} Layer;

struct _Model {
	size_t length;
	Layer *layers;
};

static inline MyFloat* mat_at(Matrix m, size_t row, size_t col)
{
	return &m.data[col + row * m.cols];
}

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

void mat_dot(Matrix dst, Matrix a, Matrix b)
{
	assert(dst.data != NULL);
	assert(a.data != NULL);
	assert(b.data != NULL);

	assert(a.cols == b.rows);
	assert(dst.rows == a.rows);
	assert(dst.cols == b.cols);

	size_t inner = a.cols;

	for (size_t r = 0; r < dst.rows; r++) {
		for (size_t c = 0; c < dst.cols; c++) {
			*mat_at(dst, r, c) = 0;
			for (size_t k = 0; k < inner; k++) {
				*mat_at(dst, r, c) += *mat_at(a, r, k) * *mat_at(b, k, c);
			}
		}	
	}
}

void mat_sum(Matrix dst, Matrix a)
{
	assert(dst.data != NULL);
	assert(a.data != NULL);

	assert(dst.rows == a.rows);
	assert(dst.cols == a.cols);

	for (size_t r = 0; r < dst.rows; r++) {
		for (size_t c = 0; c < dst.cols; c++) {
			*mat_at(dst, r, c) += *mat_at(a, r, c);
		}	
	}
}

void mat_print(Matrix m)
{
	printf("[\n");
	for (size_t r = 0; r < m.rows; r++) {
		printf("\t");
		for (size_t c = 0; c < m.cols; c++) {
			printf("%f ", (float) *mat_at(m, r, c));
		}
		printf("\n");
	}
	printf("]\n");
}

Model* generate_model(size_t len, size_t layers[len])
{
	(void) len;
	(void) layers;
	assert(0 && "TODO: Implement generate_model");
}
