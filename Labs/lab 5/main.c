#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

double* A;
double* B;
double* Result;

int main() {
    int n, size;
    char op;
    
    int i, j;
    printf("Enter matrix size N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error: Size must be positive.\n");
        return 1;
    }

    size = n * n;
    A = (double*)malloc(size * sizeof(double));
    B = (double*)malloc(size * sizeof(double));

    if (A == NULL || B == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }
    printf("Enter elements for Matrix A (%d numbers):\n", size);
    for (i = 0; i < size; i++) { 
        scanf("%lf", &A[i]);
    }
    printf("Enter elements for Matrix B (%d numbers):\n", size);
    for (i = 0; i < size; i++) { 
        scanf("%lf", &B[i]);
    }

    printf("Enter operation (+, -, *): ");
    scanf(" %c", &op); 
    Result = calculate_matrices(A, B, n, op);

    if (Result == NULL) {
        printf("Error: Calculation failed or invalid operation.\n");
        free(A);
        free(B);
        return 1;
    }
    printf("\nResult Matrix (%c):\n", op);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2lf\t", Result[i * n + j]);
        }
        printf("\n");
    }

    free(A);
    free(B);
    free(Result);

    printf("Memory free.\n");

    return 0;
}
