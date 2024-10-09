#include <stdio.h>

// Function to generate three points on the line using parametric form
void generate_points(float start_point[], float direction_vector[], int dimension, FILE *file) {
    float k_values[3] = {0, 1, 2}; // Values for parameter k to generate points
    float point[2]; // Array to store the generated points (x, y)

    // Generate points using parametric form
    for (int i = 0; i < 3; i++) {
        // x = x0 + k * 1, y = y0 + k * slope
        for (int j = 0; j < 2; j++) {
            point[j] = start_point[j] + k_values[i] * direction_vector[j];
        }
        // Write the generated points to the file
        fprintf(file, "%.2f, %.2f\n", point[0], point[1]);
    }
}

int main() {
	int n; //dimension of vector is n
  // float start_point[n];
//	float direction_vector[n];
//	float normal_vector[n];
    // The given equation is 2 + 3y = 7x
    // Rearrange the equation to match the form Ax + By = C
    // 7x - 3y = -2

    // Coefficients A, B, and C for the line 7x - 3y = -2
    float A = 7.0;
    float B = -3.0;
    float C = -2.0;
    //It is a 2D vector
    n=2;

    // Calculate slope and y-intercept based on A, B, C
    float slope = -A / B;        // Slope is -A/B
    float intercept = C / B;     // Y-intercept is C/B
    
    // Parametric form: (x // y) = (0 // intercept) + k(1 // slope)
    // Using arrays to represent start point and direction vector
float start_point[2] = {0.0, intercept};      // (x0, y0) = (0, intercept)
float direction_vector[2] = {1.0, slope};     // (1, slope)
float normal_vector[2] = {-slope, 1};

    // Display the start point and direction vector
    printf("Point on the line (x0, y0): (%.2f, %.2f)\n", start_point[0], start_point[1]);
    printf("Direction Vector: (%.2f, %.2f)\n", direction_vector[0], direction_vector[1]);
    printf("Normal Vector: (%.2f, %.2f)\n",normal_vector[0], normal_vector[1]);

    // Open the file to save coordinates
    FILE *file = fopen("coordinates.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Generate and save three points on the line using parametric form and arrays
    generate_points(start_point, direction_vector, n, file);

    // Close the file
    fclose(file);

    printf("Coordinates saved to coordinates.txt\n");

    return 0;
}

