#include <stdio.h>
#include <math.h>

// Function to find the center and radius of the circle
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

int main() {
    // Coefficients of the two lines representing the diameters
    float a1 = 2, b1 = -3, c1 = -5;   // Line 1: 2x - 3y = 5
    float a2 = 3, b2 = -4, c2 = -7;   // Line 2: 3x - 4y = 7
    float area = 154.0;               // Area of the circle

    // Variables to hold the center and radius
    float centerX, centerY, radius;

    // Call the function to find the center and radius
    findCircleProperties(a1, b1, c1, a2, b2, c2, area, &centerX, &centerY, &radius);

    // Print the center and radius
    printf("Center of the circle: (%.2f, %.2f)\n", centerX, centerY);
    printf("Radius of the circle: %.2f\n", radius);

    // Equation of the circle: (x - centerX)^2 + (y - centerY)^2 = radius^2
    printf("Equation of the circle: (x - %.2f)^2 + (y - %.2f)^2 = %.2f\n", centerX, centerY, radius * radius);

    // Open the file to write coordinates
    FILE *file = fopen("coordinates.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Writing 3 random points on the circle (theta = 0, 120, 240 degrees)
    float theta[] = {0, 120 * M_PI / 180, 240 * M_PI / 180}; // Angles in radians
    for (int i = 0; i < 3; i++) {
        float x = centerX + radius * cos(theta[i]);
        float y = centerY + radius * sin(theta[i]);
        fprintf(file, "Point %d: (%.2f, %.2f)\n", i + 1, x, y);
    }

    fclose(file);

    printf("3 points lying on the circle are written to coordinates.txt\n");

    return 0;
}

