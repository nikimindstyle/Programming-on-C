#include "matrix.h"
#include <stdlib.h>

double** calculate_matrices(double** A, double** B, int n, char op) {
    int i, j, k;

    double** C = (double**)malloc(n * sizeof(double*));
    if (C == NULL) return NULL;

    for (i = 0; i < n; i++) {
        C[i] = (double*)malloc(n * sizeof(double));
        if (C[i] == NULL) return NULL;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            
            if (op == '+') {
                C[i][j] = A[i][j] + B[i][j];
            } 
            else if (op == '-') {
                C[i][j] = A[i][j] - B[i][j];
            } 
            else if (op == '*') {
                C[i][j] = 0.0;
                for (k = 0; k < n; k++) {

                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }

    return C;
}
