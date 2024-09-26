#include <stdio.h>

// Function to generate three points lying on the line
void generate_points(float slope, float intercept, FILE *file) {
    float x_values[3] = {0, 1, 2}; // Three arbitrary x-values
    float y_values[3];
    
    for (int i = 0; i < 3; i++) {
        y_values[i] = slope * x_values[i] + intercept; // Calculate corresponding y-values
        fprintf(file, "%.2f, %.2f\n", x_values[i], y_values[i]);
    }
}

int main() {
    // The given equation is 2 + 3y = 7x
    // Rearrange the equation to match the form Ax + By = C

    // Coefficients A, B, and C for the line 7x - 3y = -2
    float A = 7.0;
    float B = -3.0;
    float C = -2.0;

    // Calculate slope and y-intercept based on A, B, C
    float slope = -A / B; // Slope is -A/B
    float intercept = C / B; // Y-intercept is C/B
    
    // Find direction vector (since slope is rise/run, direction vector is (run, rise))
    float direction_vector[2] = {1, slope}; // For slope, direction vector can be (1, slope)
    
    // Find normal vector (perpendicular to the direction vector)
    float normal_vector[2] = {-slope, 1}; // Normal to (1, slope) is (-slope, 1)
    
    // Display the vectors
    printf("Direction Vector: (%.2f, %.2f)\n", direction_vector[0], direction_vector[1]);
    printf("Normal Vector: (%.2f, %.2f)\n", normal_vector[0], normal_vector[1]);

    // Open the file to save coordinates
    FILE *file = fopen("coordinates.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    // Generate and save three points on the line (only points are saved to the file)
    generate_points(slope, intercept, file);
    
    // Close the file
    fclose(file);
    
    printf("Coordinates saved to coordinates.txt\n");
    
    return 0;
}

