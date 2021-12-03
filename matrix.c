#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include <math.h>
#include <stdbool.h>

int getMatrixInfo (FILE* fp) {

	Matrix matrix;
	fscanf(fp, "%d %d", &matrix.numRows, &matrix.numCols);
	matrix.matrix = createEmptyMatrix(matrix);
	matrix.matrix = getMatrixValues(matrix, fp);

	double detValue = 0;
	detValue = DETcalculation(matrix, detValue);
	printf("The determinant is %.2lf.\n", detValue);
	free(*matrix.matrix);
	free(matrix.matrix);
	// free_matrix(matrix);
	return 0;
}

double** createEmptyMatrix(Matrix matrix) {
	// creating matrix space, initializing to 0
	matrix.matrix = (double**) malloc(matrix.numRows * sizeof(double*));
	for (int curRow = 0; curRow < matrix.numRows; ++curRow) {
		matrix.matrix[curRow] = (double*) malloc(matrix.numCols * sizeof(double));
		for (int curCol = 0; curCol < matrix.numCols; ++curCol) {
			matrix.matrix[curRow][curCol] = 0;
		}
	}
	return matrix.matrix;
}

double** getMatrixValues(Matrix matrix, FILE* fp) {
	// getting values from .txt files and storing them in the files
	double tempValue;
	for (int curRow = 0; curRow < matrix.numRows; ++curRow) {
		for(int curCol = 0; curCol < matrix.numCols; ++curCol) {
			fscanf(fp, "%lf", &tempValue);
			(matrix.matrix)[curRow][curCol] = tempValue;
		}
	}
	return matrix.matrix;
}

double DETcalculation(Matrix m, double detValue) {
	detValue = 0;
	if (m.numRows == 2 && m.numCols == 2) {
		// base case: 2x2 det calculation
		detValue = (m.matrix[0][0] * m.matrix[1][1]) - (m.matrix[0][1] * m.matrix[1][0]);

	}  else {
		for(int j = 0; j < m.numCols; ++j) {
			Matrix smallerMatrix;
			smallerMatrix.numRows = (m.numRows - 1);
			smallerMatrix.numCols = (m.numCols - 1);
			smallerMatrix.matrix = createEmptyMatrix(smallerMatrix);
			for(int i = 1; i < m.numRows; ++i) {
				for (int k = 0; k < m.numCols; ++k) {
					if (k == j) {
						continue;
					} else if (k > j) {
						smallerMatrix.matrix[i-1][k-1] = m.matrix[i][k];
					} else {
						smallerMatrix.matrix[i-1][k] = m.matrix[i][k];
					}
					// printf("smaller matrix: %lf\n", m.matrix[i][k]);
				}
			}
			detValue += pow(-1, j) * m.matrix[0][j] * DETcalculation(smallerMatrix, detValue);
			free(*smallerMatrix.matrix);
			free(smallerMatrix.matrix);
				// -1 or 1 * cofactor * det (smaller matrix)
			// deleteMatrix(smallerMatrix);
		}
	}

	// 3x3 -> three 2x2 matrices
	// 1 + 1 + 1
	// printf("Curr det: %.2lf.\n", detValue);
	return detValue;
}

// void free_matrix(Matrix* m) {
// 	for (int row = 0; row < m->numRows; ++row) {
// 		free((*m->matrix)[row]);
// 	}
// 	free(*m->matrix);
// 	*m.matrix = NULL;

// }
