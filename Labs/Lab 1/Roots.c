#include <stdio.h>
#include <math.h>

int main() {
    int continue_calculating = 1;
        double a, b, c, D, x1, x2;
    while (continue_calculating == 1) {
        printf("Enter coof a, b, c: ");
        scanf("%lf %lf %lf", &a, &b, &c);

        D = pow(b, 2) - 4 * a * c;

        printf("Discriminant = %2lf\n", D);
        printf("Square of discriminant = %2lf\n", pow(D, 0.5));

        if (D > 0) {
            x1 = (-b + pow(D, 0.5)) / (2 * a);
            x2 = (-b - pow(D, 0.5)) / (2 * a);
            printf("Have two roots\n");
            printf("roots x1 = %2lf\n", x1);
            printf("roots x2 = %2lf\n", x2);
        }
        else if (D == 0) {
            x1 = -b / (2 * a);
            printf("Have one root\n");
            printf("x = %2lf\n", x1);
        }
        else {
            printf("Not have roots :(\n");
        }
    printf("Do you want to continue? (1 for yes, 0 for no): ");
    scanf("%d", &continue_calculating);
       if (continue_calculating ==0) {
            printf("Goodbye!\n");
        }
    }
}