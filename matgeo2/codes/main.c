#include <stdio.h>

// Function to find the slope (m) and intercept (c) of the line
void find_relation(double x1, double y1, double x2, double y2, double* m, double* c) {
    *m = (y2 - y1) / (x2 - x1);
    *c = y1 - (*m) * x1;
}

int main() {
    double x1 = -4, y1 = 6; // Coordinates of point B
    double x2 = -2, y2 = 3; // Coordinates of point C
    double m, c;

    // Calculate the slope and intercept
    find_relation(x1, y1, x2, y2, &m, &c);

    // Print the relation between x and y
    printf("The relation between x and y is: y = %.2lf * x + %.2lf\n", m, c);

    // Open the file coordinates.txt for writing
    FILE *file = fopen("coordinates.txt", "w");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write some coordinates that satisfy the relation y = m * x + c
    for (double x = -10; x <= 10; x += 1.0) {
        double y = m * x + c;
        fprintf(file, "x = %.2lf, y = %.2lf\n", x, y);
    }

    // Close the file
    fclose(file);

    return 0;
}

