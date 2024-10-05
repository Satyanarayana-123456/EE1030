#include <stdio.h>
#include <math.h>

// Function to calculate y-value for the line y = mx + c
double line(double m, double c, double x) {
    return m * x + c;
}

// Function to calculate y-value for the parabola y = ax^2 + bx + c
double parabola(double a, double b, double c, double x) {
    return a * x * x + b * x + c;
}

// Function to calculate the area using the Riemann sum method
double riemannSum(double a, double b, double c1, double m, double c2, double x1, double x2, int n) {
    double delta_x = (x2 - x1) / n;  // Width of each small rectangle
    double sum = 0.0;
    
    for (int i = 0; i < n; i++) {
        double x = x1 + i * delta_x;  // Current x position
        double y_line = line(m, c2, x);  // y value of the line at x
        double y_parabola = parabola(a, b, c1, x);  // y value of the parabola at x
        double height = fabs(y_line - y_parabola);  // Height difference between line and parabola
        sum += height * delta_x;  // Add the area of the small rectangle
    }

    return sum;
}

