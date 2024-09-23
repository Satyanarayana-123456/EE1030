#include <stdio.h>
#include <stdlib.h>

// Function to calculate the coordinates
double** calculateCoordinates(double AB, double BC) {
    // Allocate memory for a 3x2 array to hold the coordinates
    double** coordinates = (double**)malloc(3 * sizeof(double*));
    for (int i = 0; i < 3; i++) {
        coordinates[i] = (double*)malloc(2 * sizeof(double));
    }

    // Coordinates of B (0, 0) as the right-angled vertex
    coordinates[1][0] = 0.0; // x-coordinate of B
    coordinates[1][1] = 0.0; // y-coordinate of B

    // Coordinates of A (0, AB)
    coordinates[0][0] = 0.0; // x-coordinate of A
    coordinates[0][1] = AB;  // y-coordinate of A

    // Coordinates of C (BC, 0)
    coordinates[2][0] = BC;  // x-coordinate of C
    coordinates[2][1] = 0.0;  // y-coordinate of C

    return coordinates;
}

// Function to free allocated memory
void freeCoordinates(double** coordinates) {
    for (int i = 0; i < 3; i++) {
        free(coordinates[i]);
    }
    free(coordinates);
}

int main() {
    double AB = 6.0; // Length AB
    double BC = 8.0; // Length BC

    // Get coordinates for triangle ABC
    double** coords = calculateCoordinates(AB, BC);

    // Open file to write coordinates
    FILE *file = fopen("coordinates.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Save coordinates to file
    for (int i = 0; i < 3; i++) {
        fprintf(file, "%.2f, %.2f\n", coords[i][0], coords[i][1]);
    }

    // Close the file
    fclose(file);

    printf("Coordinates saved to coordinates.txt\n");

    // Free allocated memory
    freeCoordinates(coords);

    return 0;
}

