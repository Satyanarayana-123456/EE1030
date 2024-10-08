#include <stdio.h>
#include <math.h>

// Function to calculate the upper half of the parabola: y^2 = 4px
double parabola_upper(double x, double p) {
    return sqrt(4 * p * x);  // Upper part of the parabola
}

// Function to calculate the lower half of the parabola: y^2 = 4px
double parabola_lower(double x, double p) {
    return -sqrt(4 * p * x);  // Lower part of the parabola
}

// Function to calculate the upper half of the circle: (x - h)^2 + (y - k)^2 = r^2
double circle_upper(double x, double h, double k, double r) {
    return k + sqrt(r * r - (x - h) * (x - h));  // Upper part of the circle
}

// Function to calculate the lower half of the circle: (x - h)^2 + (y - k)^2 = r^2
double circle_lower(double x, double h, double k, double r) {
    return k - sqrt(r * r - (x - h) * (x - h));  // Lower part of the circle
}

// Riemann sum to compute the area between the parabola and x-axis for 0 <= x <= 0.5
double riemann_sum_parabola(double a, double b, int n, double p) {
    double dx = (b - a) / n;
    double area = 0.0;
    for (int i = 0; i < n; i++) {
        double x = a + i * dx;
        double y_parabola_upper = parabola_upper(x, p);  // Upper part of the parabola
        area += fabs(y_parabola_upper) * dx;  // Area under the parabola
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
        area += fabs(y_circle_upper) * dx;  // Area under the circle
    }
    return area;
}

// Function to save parabola points and circle points to coordinates.txt separately
void save_points(double x_start, double x_mid, double x_end, double p, double h, double k, double r) {
    FILE *file = fopen("coordinates.txt", "w");
      fprintf(file, "(%.4lf, %.4lf)\n", x_mid, parabola_upper(x_mid, p));
fprintf(file, "(%.4lf, %.4lf)\n", x_mid, parabola_lower(x_mid, p));
fprintf(file, "\n");
     // Save 250 points on the parabola for positive x (0 to 0.5)
    int num_points_parabola = 250;
    double dx_parabola = (x_mid - x_start) / num_points_parabola;

    for (int i = 0; i <= num_points_parabola; i++) {
        double x = x_start + i * dx_parabola;
        double y_parabola_upper = parabola_upper(x, p);  // Upper parabola
        double y_parabola_lower = parabola_lower(x, p);  // Lower parabola
        fprintf(file, "%.4lf, %.4lf\n", x, y_parabola_upper);  // Upper points
        fprintf(file, "%.4lf, %.4lf\n", x, y_parabola_lower);  // Lower points
    }

    

    // Save 250 points on the circle for positive x (0.5 to 1)
    int num_points_circle = 250;
    double dx_circle = (1.5 - 0) / num_points_circle;
    
    for (int i = 0; i <= num_points_circle; i++) {
        double x = 0 + i * dx_circle;
        double y_circle_upper = circle_upper(x, h, k, r);  // Upper circle
        double y_circle_lower = circle_lower(x, h, k, r);  // Lower circle
fprintf(file, "%.4lf, %.4lf\n", x, y_circle_upper);  // Upper points
        fprintf(file, "%.4lf, %.4lf\n", x, y_circle_lower);  // Lower points
    }

    // Save 250 points on the circle for negative x (-1 to -0.5)
    for (int i = 0; i <= num_points_circle; i++) {
        double x = h - (0 + i * dx_circle);  // Reflect x to negative
        double y_circle_upper = circle_upper(x, h, k, r);
        double y_circle_lower = circle_lower(x, h, k, r);
        fprintf(file, "%.4lf, %.4lf\n", x, y_circle_upper);  // Upper points
        fprintf(file, "%.4lf, %.4lf\n", x, y_circle_lower);  // Lower points
    }

    fclose(file);
}
int main() {
    // Parameters for parabola and circle
    double p = 1.0;  // Parabola: y^2 = 4px, so p=1
    double h = 0.0, k = 0.0, r = 1.5;  // Circle: (x - h)^2 + (y - k)^2 = r^2

    // Define the interval of interest
    double x_start = 0.0;  // Start of parabola
    double x_mid = 0.5;    // Intersection point
    double x_end = 1.0;    // End of circle

    // Number of sub-intervals for the Riemann sum
    int n = 1000;

    // Calculate the area of the parabola from 0 to 0.5
    double area_parabola = riemann_sum_parabola(x_start, x_mid, n, p);
    // Calculate the area of the circle from 0.5 to 1
    double area_circle = riemann_sum_circle(x_mid, x_end, n, h, k, r);

    // Total area is the sum of both areas
    double total_area = 2*(area_parabola + area_circle);
    printf("The total area of the region is: %.4lf\n", total_area);

    // Save parabola points first and circle points after that to coordinates.txt
    save_points(x_start, x_mid, x_end, p, h, k, r);

    return 0;
}

