#include <stdio.h>
#include <math.h>

#define NUM_POINTS 3  // Define the number of points

// Function to save 3 points on the parabola x^2 = y using a 3x2 array
void save_points() {
    // Create a 3x2 array to store the points
    double coordinates[NUM_POINTS][2];

    // Define the range of x-values and calculate step size
    double x_start = 0.0, x_end = 4.0;
    double step = (x_end - x_start) / (NUM_POINTS - 1);

    // Loop to generate points and store them in the array
    for (int i = 0; i < NUM_POINTS; i++) {
        double x = x_start + i * step;
        double y = x * x;

        // Store the x and y coordinates in the array
        coordinates[i][0] = x;
        coordinates[i][1] = y;
    }

    // Open the file to save the points
    FILE *file = fopen("coordinates.txt", "w");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Write the points from the array to the file
    for (int i = 0; i < NUM_POINTS; i++) {
        fprintf(file, "%.2f, %.2f\n", coordinates[i][0], coordinates[i][1]);
    }

    fclose(file);
//    printf("Points saved to coordinates.txt using a 3x2 array\n");
}

int main() {
    // Given area to be achieved
    double target_area = 32.0 / 3.0;
    
    // We know from the integral that m^3 / 6 = target_area
    // Therefore, m^3 = 6 * target_area
    double m_cubed = 6 * target_area;
    
    // Take the cube root of m_cubed to find m
    double m = cbrt(m_cubed);
    
    printf("The positive value of m such that the area is 32/3 is: %.4f\n", m);
    
    // Save 3 points on the parabola x^2 = y to coordinates.txt using a 3x2 array
    save_points();

    return 0;
}

