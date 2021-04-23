#ifndef MYMATRIXWORK_H
#define MYMATRIXWORK_H

#include <iostream>
#include <QtGlobal>
#include <vector>

#include <cmath>

#define TRANSFER 1
#define ROTATE 2
#define SCALE 3

typedef std::vector<qreal> vector_t;
typedef std::vector<std::vector<qreal>> matrix_t;

vector_t multiplicateVectorAndMatrix(matrix_t matrix, vector_t vector);
vector_t make_vector(qreal x, qreal y);

matrix_t makeMatrix(qreal x, qreal y, int operation);
matrix_t multiplicateMatrixes(matrix_t a, matrix_t b);

#endif