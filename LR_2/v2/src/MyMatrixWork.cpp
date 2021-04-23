#include "../inc/MyMatrixWork.h"

vector_t make_vector(qreal x, qreal y)
{
	vector_t result = {x, y, 1};
	return result;
}

vector_t multiplicateVectorAndMatrix(matrix_t matrix, vector_t vector)
{
	vector_t result = {0, 0, 0};
	for (int i = 0; i < (int) matrix.size(); i++)
	{
		for (int j = 0; j < (int) matrix.size(); j++)
		{
			result[i] += matrix[j][i] * vector[j];
			//std::cout << result[i] << " " << matrix[j][i] << " " << vector[j] << std::endl;
			//std::cout << i << " " << j << std::endl;
		}
	}
	//std::cout << std::endl;
	return result;
}

matrix_t makeMatrix(qreal x, qreal y, int operation)
{
	matrix_t matrix = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	if (operation == TRANSFER)
	{
		for (int i = 0; i < (int) matrix.size(); i++)
			matrix[i][i] = 1;

		matrix[2][0] = x;
		matrix[2][1] = y;
	}
	else if (operation == ROTATE)
	{
		matrix[0][0] = cos(x * M_PI / 180);
		matrix[1][1] = cos(x * M_PI / 180);
		matrix[0][1] = -sin(x * M_PI / 180);
		matrix[1][0] = sin(x * M_PI / 180);

		//matrix[2][0] = 0;
		//matrix[2][1] = 0;
		//matrix[0][2] = 0;
		//matrix[1][2] = 0;
		matrix[2][2] = 1;
	}
	else if (operation == SCALE)
	{
		//for (int i = 0; i < (int) matrix.size(); i++)
		//	matrix[i][i] = 1;

		matrix[0][0] = x;
		matrix[1][1] = y;
		matrix[2][2] = 1;
	}
	return matrix;
}

matrix_t multiplicateMatrixes(matrix_t a, matrix_t b)
{
	matrix_t matrix = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	for (int i = 0; i < (int) matrix.size(); i++)
	{	
		for (int j = 0; j < (int) matrix.size(); j++)
		{
			for (int k = 0; k < (int) matrix.size(); k++)
			{
				matrix[j][k] += a[j][i] * b[i][k];
			}
		}
	}
	return matrix;
}
