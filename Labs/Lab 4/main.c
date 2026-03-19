#include <stdio.h>
#include "triangle.h"

int main() {
    double a, b, c;
    printf("Enter side A: ");
    scanf("%lf", &a);
    printf("Enter side B: ");
    scanf("%lf", &b);
    printf("Enter side C: ");
    scanf("%lf", &c);

    if (is_valid_triangle(a, b, c)) {
        double P = get_perimeter(a, b, c);
        double S = get_area(a, b, c);
        printf("Perimeter: %.2lf\n", P);
        printf("Area: %.2lf\n", S);
    } else {
        printf("\nError: Invalid triangle sides.\n");
    }

    return 0;
}
