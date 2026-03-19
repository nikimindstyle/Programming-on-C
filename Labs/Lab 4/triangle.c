#include "triangle.h"
#include <math.h>

int is_valid_triangle(double a, double b, double c) {
    if (a + b > c && a + c > b && b + c > a) {
        return 1;
    }
    return 0;
}

double get_perimeter(double a, double b, double c) {
    return a + b + c;
}

double get_area(double a, double b, double c) {
    double p = get_perimeter(a, b, c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c)); // is a geron teorem
}
