#include <stdio.h>
#include <math.h>
int main() {
    double matrix[5][5];
    double sumMain = 0.0;
    double sumSide = 0.0;
    int i, j;
    printf("Enter 9 elements for 5x5 matrix:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == j) {
                sumMain += matrix[i][j];
            }
            if (i + j == 4) {
                sumSide += matrix[i][j];
            }
        }
    }
    printf("\nResults:\n");
    printf("Sum of main diagonal: %.2lf\n", sumMain);
    printf("Sum of side diagonal: %.2lf\n", sumSide);

    return 0;
}
