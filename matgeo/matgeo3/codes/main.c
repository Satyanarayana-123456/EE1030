#include <stdio.h>

// Function to calculate the coefficients of the equation m*x + n*y = p
void calculate_relation(float x1, float y1, float x2, float y2, float *m, float *n, float *p) {
    *m = 2 * (x2 - x1);
    *n = 2 * (y2 - y1);
    *p = (x2 * x2 + y2 * y2) - (x1 * x1 + y1 * y1);
}

// Function to write coordinates to a file
void write_coordinates(const char *filename, float m, float n, float p) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Generate and write three coordinates
    for (int i = 0; i < 3; i++) {
        float x = i + 1;
        float y = (p - m * x) / n;  // Solving for y in m*x + n*y = p
        fprintf(file, "%.2f, %.2f\n", x, y);
    }

    fclose(file);
    printf("Coordinates saved to %s\n", filename);
}

int main() {
    float x1 = 7.0, y1 = 1.0;
    float x2 = 3.0, y2 = 5.0;
    float m, n, p;

    // Calculate the relation coefficients
    calculate_relation(x1, y1, x2, y2, &m, &n, &p);

    // Write coordinates that satisfy the relation to coordinates.txt
    write_coordinates("coordinates.txt", m, n, p);

    return 0;
}

