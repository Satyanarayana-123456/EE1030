#include <math.h>

void findCircleProperties(float a1, float b1, float c1, float a2, float b2, float c2, float area, float *centerX, float *centerY, float *radius) {
    float pi = 22.0 / 7.0;

    // Finding the center of the circle (intersection of two lines)
    float determinant = a1 * b2 - a2 * b1;

    if (determinant != 0) {
        *centerX = (b1 * c2 - b2 * c1) / determinant;
        *centerY = (a2 * c1 - a1 * c2) / determinant;

        // Calculate radius from the area
        *radius = sqrt(area / pi);
    } else {
        // Handle the case when the lines are parallel (no intersection)
        *centerX = *centerY = *radius = 0;
    }
}

