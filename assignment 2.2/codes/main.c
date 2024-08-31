#include <stdio.h>

// Declare the function from equi.c
void find_relation(double bx, double by, double cx, double cy, double *m, double *c);

int main() {
    // Coordinates of B and C
    double bx = 7.0, by = 1.0;
    double cx = 3.0, cy = 5.0;
    
    // Variables to store the slope and intercept
    double m, c;
    
    // Find the relation between x and y
    find_relation(bx, by, cx, cy, &m, &c);
    
    // Print the relation y = mx + c or x = constant for a vertical line
    if (bx == cx) {
        // Special case for vertical line
        printf("The relation between x and y is: x = %.2f\n", bx);
    } else if (m == 0) {
        // Special case for horizontal line
        printf("The relation between x and y is: y = %.2f\n", c);
    } else {
        printf("The relation between x and y is: y = %.2fx + %.2f\n", m, c);
    }

    // Store some coordinates that satisfy the relation in coordinates.txt
    FILE *file = fopen("coordinates.txt", "w");
    if (file != NULL) {
        if (bx == cx) {
            // For a vertical line, y can take any value; x is constant
            for (int y = -10; y <= 10; y++) {
                fprintf(file, "(%.2f, %d)\n", bx, y);
            }
        } else {
            // For non-vertical lines, generate points along the line
            for (int x = -10; x <= 10; x++) {
                double y = m * x + c;
                fprintf(file, "(%d, %.2f)\n", x, y);
            }
        }
        fclose(file);
    } else {
        printf("Error opening file for writing.\n");
    }
    
    return 0;
}


