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

int main() {
    // Coefficients of the two lines representing the diameters
    float a1 = 2, b1 = -3, c1 = -5;   // Line 1: 2x - 3y = 5
    float a2 = 3, b2 = -4, c2 = -7;   // Line 2: 3x - 4y = 7
    float area = 154.0;               // Area of the circle

    // Variables to hold the center and radius
    float centerX, centerY, radius;

    // Call the function to find the center
    findCenter(a1, b1, c1, a2, b2, c2, &centerX, &centerY);

    // Call the function to calculate the radius
    radius = calculateRadius(area);

    // Print the center and radius
    printf("Center of the circle: (%.2f, %.2f)\n", centerX, centerY);
    printf("Radius of the circle: %.2f\n", radius);

    // Equation of the circle: (x - centerX)^2 + (y - centerY)^2 = radius^2
    printf("Equation of the circle: (x - %.2f)^2 + (y - %.2f)^2 = %.2f\n", centerX, centerY, radius * radius);

    // Open the file to write coordinates
    //FILE *file = fopen("coordinates.txt", "w");
    //if (file == NULL) {
      //  printf("Error opening file!\n");
        //return 1;
    //}

    // Writing 3 random points on the circle (theta = 0, 120, 240 degrees)
   // float theta[] = {0, 120 * M_PI / 180, 240 * M_PI / 180}; // Angles in radians
    //float coordinates[3][2]; // 3x2 array to store the coordinates
    //for (int i = 0; i < 3; i++) {
      //  float x = centerX + radius * cos(theta[i]);
        //float y = centerY + radius * sin(theta[i]);
        //coordinates[i][0] = x;
        //coordinates[i][1] = y;
        //fprintf(file, "(%.2f, %.2f)\n", x, y);
    //}

    // Close the file
    //fclose(file);


    //printf("Points on the circle are written to coordinates.txt\n");

    return 0;
}

