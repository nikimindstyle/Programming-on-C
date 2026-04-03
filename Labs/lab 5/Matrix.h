#ifndef MATRIX_H
#define MATRIX_H

double** matrix_add(double** A, double** B, int n);
double** matrix_sub(double** A, double** B, int n);
double** matrix_mul(double** A, double** B, int n);
double** calc_matrix(double** A, double** B, int n, char op);

#endif
