#include <stdio.h>
#include "matrix.h"
#include <stdlib.h>

FILE* validate_input(int argc, char** argv);

int main(int argc, char** argv) {
	FILE* fp = validate_input(argc, argv);
	getMatrixInfo(fp);
	// create free memory function
	fclose(fp);
	return 0;
}

FILE* validate_input(int argc, char** argv) {
	FILE* fp = NULL;

	if (argc != 2) {
		printf("Incorrect number of arguments entered\n");
		exit(0);
	}
	fp = fopen(argv[1], "r");
	if(fp == NULL) {
		printf("Unable to open file.\n");
		exit(0);
	}
	return fp;
}