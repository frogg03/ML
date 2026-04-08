#ifndef ML_H_
#define ML_H_

#include <stddef.h>

typedef float MyFloat;

typedef struct {
	size_t rows;
	size_t cols;
	MyFloat *data;
} Matrix;

static inline MyFloat* mat_at(Matrix m, size_t row, size_t col)
{
	return &m.data[col + row * m.cols];
}

Matrix mat_alloc(size_t rows, size_t cols);
void mat_dot(Matrix dat, Matrix a, Matrix b);
void mat_sum(Matrix dst, Matrix a);
void mat_print(Matrix m);

#endif // ML_H_
