#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {
    int n, i, j;
    char op;
    double **A, **B, **Result;



    printf("Enter matrix size N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error: Size must be positive.\n");
        return 1; 
    }



    A = (double**)malloc(n * sizeof(double*));
    for (i = 0; i < n; i++) {
        A[i] = (double*)malloc(n * sizeof(double));
    }

    B = (double**)malloc(n * sizeof(double*));
    for (i = 0; i < n; i++) {
        B[i] = (double*)malloc(n * sizeof(double));
    }



    if (A == NULL || B == 0) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }




    printf("Enter elements for Matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }




    printf("Enter elements for Matrix B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%lf", &B[i][j]);
        }
    }

    printf("Enter operation (+, -, *): ");
    scanf(" %c", &op);

    Result = calc_matrix(A, B, n, op);



    if (Result == 0) {
        printf("Error: Calculation failed or invalid operation.\n");
        for (i = 0; i < n; i++) free(A[i]);
        free(A);
        for (i = 0; i < n; i++) free(B[i]);
        free(B);
        return 1;
    }



    printf("\nResult Matrix (%c):\n", op);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2lf\t", Result[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++) free(A[i]);
    free(A);
    for (i = 0; i < n; i++) free(B[i]);
    free(B);
    for (i = 0; i < n; i++) free(Result[i]);
    free(Result);
    printf("\nMemory free!.\n");

    return 0;
}
