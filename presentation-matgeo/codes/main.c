#include <stdio.h>
#include <math.h>

#define NUM_POINTS 500

void findCenter(float a1, float b1, float c1, float a2, float b2, float c2, float* centerX, float* centerY) {
    float determinant = a1 * b2 - a2 * b1;

    if (determinant != 0) {
        *centerX = (b1 * c2 - b2 * c1) / determinant;
        *centerY = (a2 * c1 - a1 * c2) / determinant;
    } else {
        printf("The lines are parallel, no intersection found.\n");
    }
}

float calculateRadius(float area) {
    float pi = 22.0 / 7.0;
    return sqrt(area / pi);
}

int main() {
     float a1 = 2, b1 = -3, c1 = -5;   
    float a2 = 3, b2 = -4, c2 = -7;   
    float area = 154.0;               

    float centerX, centerY, radius;

    findCenter(a1, b1, c1, a2, b2, c2, &centerX, &centerY);
    radius = calculateRadius(area);

    printf("Center of the circle: (%.2f, %.2f)\n", centerX, centerY);
    printf("Radius of the circle: %.2f\n", radius);

     printf("Equation of the circle: (x - (%.2f))^2 + (y - (%.2f))^2 = %.2f\n", centerX, centerY, radius * radius);

    FILE *file = fopen("coordinates.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    for (int i = 0; i < NUM_POINTS; i++) {
        float theta = (2 * M_PI * i) / NUM_POINTS; // Angle in radians
        float x = centerX + radius * cos(theta);
        float y = centerY + radius * sin(theta);
        fprintf(file, "%.4f, %.4f\n", x, y);
    }

    fclose(file);
    return 0;
}

