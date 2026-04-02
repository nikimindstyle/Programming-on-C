#include "matrix.h"
#include <stdlib.h>

double** create_matrix(int n) {
    int i;
    double** M = (double**)malloc(n * sizeof(double*));
    if (M == NULL) return NULL;
    
    for (i = 0; i < n; i++) {
        M[i] = (double*)malloc(n * sizeof(double));
        if (M[i] == NULL) return NULL;
    }
    return M;
}

double** matrix_plus(double** A, double** B, int n) {
    int i, j;
    double** C = create_matrix(n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

double** matrix_minus(double** A, double** B, int n) {
    int i, j;
    double** C = create_matrix(n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

double** matrix_multi(double** A, double** B, int n) {
    int i, j, k;
    double** C = create_matrix(n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = 0.0;
            for (k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

double** calculate_matrices(double** A, double** B, int n, char op) {
    if (op == '+') {
        return matrix_plus(A, B, n);
    } 
    else if (op == '-') {
        return matrix_minus(A, B, n);
    } 
    else if (op == '*') {
        return matrix_multi(A, B, n);
    }
    
    return 0;
}
