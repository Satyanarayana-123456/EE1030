#include <stdio.h>
#include <math.h>

#define NUM_POINTS 500

// Function to calculate the y-value of the line y = mx
double line(double m, double x) {
    return m * x;
}

// Function to calculate the y-value of the parabola x^2 = y (which implies y = x^2)
double parabola(double x) {
    return x * x;
}

// Function to calculate the area using definite integration
double area(double m) {
    double integral_line = (m * m * m) / 2.0;  // Integral of mx from 0 to m
    double integral_parabola = (m * m * m) / 3.0;  // Integral of x^2 from 0 to m
    return integral_line - integral_parabola;
}

// Function to solve for m using numerical approximation
double find_m(double target_area, double precision) {
    double low = 0.0, high = 10.0;  // Reasonable initial guesses for m
    double mid;

    while (high - low > precision) {
        mid = (low + high) / 2.0;
        double current_area = area(mid);

        if (current_area < target_area) {
            low = mid;
        } else {
            high = mid;
        }
    }

    return (low + high) / 2.0;
}

// Function to save intersection points and 500 points on the parabola to coordinates.txt
void save_points(double m, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Find points of intersection
    // Intersection occurs when mx = x^2, i.e., x(m - x) = 0
    // So, the intersection points are at x = 0 and x = m
    double x1 = 0.0, y1 = line(m, x1);  // First intersection point (0, 0)
    double x2 = m, y2 = line(m, x2);  // Second intersection point (m, m^2)

    // Save the intersection points
    fprintf(file, "(%.4lf, %.4lf)\n", x1, y1);
    fprintf(file, "(%.4lf, %.4lf)\n", x2, y2);
    fprintf(file, "\n");


    // We'll generate points over the range [-2m, 2m]
    double step = (2 * m) / (NUM_POINTS - 1);  // Divide the interval [-2m, 2m] into 500 steps

    for (int i = 0; i < NUM_POINTS; i++) {
        double x = -m + i * step;  // Range from -m to +m
        double y = parabola(x);
        fprintf(file, "%.4lf, %.4lf\n", x, y);
    }

    fclose(file);
    printf("Points saved to %s.\n", filename);
}

int main() {
    double target_area = 32.0 / 3.0;  // Given area
    double precision = 0.00001;  // Precision for finding m

    // Find the positive value of m
    double m_value = find_m(target_area, precision);
    printf("The positive value of m is approximately: %.4lf\n", m_value);

    // Save intersection points and 500 points on the parabola to coordinates.txt
    save_points(m_value, "coordinates.txt");

    return 0;
}

