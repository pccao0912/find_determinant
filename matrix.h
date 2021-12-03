#ifndef MATRIX_H
	#define MATRIX_H
		typedef struct matrix_struct {
			int numRows, numCols;
			double** matrix;
		}Matrix;
		int getMatrixInfo (FILE* fp);
		double** createEmptyMatrix(Matrix matrix);
		double** getMatrixValues(Matrix matrix, FILE* fp);
		double DETcalculation(Matrix m, double detValue);
		// void free_matrix(Matrix* m);
#endif

