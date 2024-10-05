#include <stdio.h>
#include <math.h>

// Function to find points of intersection between line and parabola
void find_intersection(float m, float c, float a, float b, float c_p) {
    float A, B, C;
    float discriminant, x1, x2, y1, y2;

    // Form the quadratic equation A*x^2 + B*x + C = 0
    A = a;
    B = (b - m);
    C = (c_p - c);

    // Calculate the discriminant
    discriminant = B * B - 4 * A * C;

    if (discriminant < 0) {
        printf("The line and parabola do not intersect.\n");
    } else if (discriminant == 0) {
        // One intersection point (tangent)
        x1 = -B / (2 * A);
        y1 = m * x1 + c;
        printf("Tangent at point: (%.2f, %.2f)\n", x1, y1);
    } else {
        // Two intersection points
        x1 = (-B + sqrt(discriminant)) / (2 * A);
        x2 = (-B - sqrt(discriminant)) / (2 * A);

        // Calculate y-coordinates for the two x-values
        y1 = m * x1 + c;
        y2 = m * x2 + c;

        printf("Intersection points: (%.2f, %.2f) and (%.2f, %.2f)\n", x1, y1, x2, y2);
    }
}

