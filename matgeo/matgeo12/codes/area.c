#include <math.h>

// Function to calculate the upper half of the parabola: y^2 = 4px
double parabola_upper(double x, double p) {
    return sqrt(4 * p * x);  // Upper part of the parabola
}

// Function to calculate the lower half of the parabola: y^2 = 4px
//double parabola_lower(double x, double p) {
  //  return -sqrt(4 * p * x);  // Lower part of the parabola
//}

// Function to calculate the upper half of the circle: (x - h)^2 + (y - k)^2 = r^2
double circle_upper(double x, double h, double k, double r) {
    return k + sqrt(r * r - (x - h) * (x - h));  // Upper part of the circle
}

// Function to calculate the lower half of the circle: (x - h)^2 + (y - k)^2 = r^2
//double circle_lower(double x, double h, double k, double r) {
  //  return k - sqrt(r * r - (x - h) * (x - h));  // Lower part of the circle
//}

// Riemann sum to compute the area between the parabola and x-axis for 0 <= x <= 0.5
double riemann_sum_parabola(double a, double b, int n, double p) {
    double dx = (b - a) / n;
    double area = 0.0;
    for (int i = 0; i < n; i++) {
        double x = a + i * dx;
        double y_parabola_upper = parabola_upper(x, p);  // Upper part of the parabola
        area += y_parabola_upper * dx;  // Area under the parabola
    }
    return area;
}

// Riemann sum to compute the area between the circle and x-axis for 0.5 <= x <= 1
double riemann_sum_circle(double a, double b, int n, double h, double k, double r) {
    double dx = (b - a) / n;
    double area = 0.0;
    for (int i = 0; i < n; i++) {
        double x = a + i * dx;
        double y_circle_upper = circle_upper(x, h, k, r);  // Upper part of the circle
        area += y_circle_upper * dx;  // Area under the circle
    }
    return area;
}
