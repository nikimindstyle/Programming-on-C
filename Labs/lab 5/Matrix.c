#include "matrix.h"
#include <stdlib.h>

double** create_matrix(int n) {
    int i;
    double** M = (double**)malloc(n * sizeof(double*));
    if (M == 0) return 0;
    
    for (i = 0; i < n; i++) {
        M[i] = (double*)malloc(n * sizeof(double));
        if (M[i] == 0) return 0;
    }
    return M;
}

double** matrix_add(double** A, double** B, int n) {
    int i, j;
    double** C = create_matrix(n);
    if (C == 0) return 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

double** matrix_sub(double** A, double** B, int n) {
    int i, j;
    double** C = create_matrix(n);
    if (C == 0) return 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

double** matrix_mul(double** A, double** B, int n) {
    int i, j, k;
    double** C = create_matrix(n);
    if (C == 0) return 0;

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

double** calc_matrix(double** A, double** B, int n, char op) {
    if (op == '+') {
        return matrix_add(A, B, n);
    } 
    else if (op == '-') {
        return matrix_sub(A, B, n);
    } 
    else if (op == '*') {
        return matrix_mul(A, B, n);
    }
    
    return 0;
}
