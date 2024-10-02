#include <stdio.h>
#include <math.h>

// Function to find the intersection point (center) of two lines
void findCenter(float a1, float b1, float c1, float a2, float b2, float c2, float* centerX, float* centerY) {
    float determinant = a1 * b2 - a2 * b1;

    if (determinant != 0) {
        *centerX = (b1 * c2 - b2 * c1) / determinant;
        *centerY = (a2 * c1 - a1 * c2) / determinant;
    } else {
        printf("The lines are parallel, no intersection found.\n");
    }
}

// Function to calculate radius given the area
float calculateRadius(float area) {
    float pi = 22.0 / 7.0;
    return sqrt(area / pi);
}

