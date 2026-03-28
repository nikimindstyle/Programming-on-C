#include "matrix.h"
#include <stdlib.h>

double* calculate_matrices(double* A, double* B, int n, char op) {
    int size;
    double* C;
    int i, j, k; 
    int idx;
    double valA, valB;

    size = n * n;
    C = (double*)malloc(size * sizeof(double));
    
    if (C == NULL) {
        return NULL; 
    }


    for (i = 0; i < n; i++) {       
        for (j = 0; j < n; j++) {   
            
            idx = i * n + j; 

            if (op == '+') {
                C[idx] = A[idx] + B[idx];
            } 
            else if (op == '-') {
                C[idx] = A[idx] - B[idx];
            } 
            else if (op == '*') {
                C[idx] = 0.0;
                for (k = 0; k < n; k++) {
                    valA = A[i * n + k];
                    valB = B[k * n + j];
                    C[idx] += valA * valB;
                }
            }
        }
    }

    return C; 
}
