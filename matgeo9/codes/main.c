#include <stdio.h>

// Function to find direction and normal vectors for the line
void find_direction_and_normal_vector(double *direction, double *normal) {
    // Line: 2 + 3y = 7x can be rearranged to 7x - 3y = -2
    // General form: Ax + By + C = 0 -> A=7, B=-3
    double A = 7;
    double B = -3;
    
    // Direction vector (dx, dy) is perpendicular to the normal vector (A, B)
    direction[0] = B;    // dx = -B
    direction[1] = -A;   // dy = A
    
    // Normal vector (nx, ny) is (A, B)
    normal[0] = A;
    normal[1] = B;
}

int main() {
    double direction[2], normal[2];
    double points[3][2];
    
    // Rearranging the line equation to slope-intercept form: y = (7/3)x - (2/3)
    double slope = 7.0 / 3.0;
    double intercept = -2.0 / 3.0;
    
    // Find direction and normal vectors
    find_direction_and_normal_vector(direction, normal);
    
    // Print the direction and normal vectors
    printf("Direction Vector: (%.2f, %.2f)\n", direction[0], direction[1]);
    printf("Normal Vector: (%.2f, %.2f)\n", normal[0], normal[1]);
    
    // Generate 3 points using x values (-1, 0, 1) and y = slope * x + intercept
    for (int i = 0; i < 3; i++) {
        points[i][0] = i - 1;  // x values: -1, 0, 1
        points[i][1] = slope * points[i][0] + intercept;  // y = mx + b
    }
    
    // Save the points to coordinates.txt
    FILE *file = fopen("coordinates.txt", "w");
    
    // Check if the file is opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    } else {
        printf("File 'coordinates.txt' opened successfully.\n");
    }
    
    // Print and write the points to the file
    for (int i = 0; i < 3; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i + 1, points[i][0], points[i][1]);
        fprintf(file, "Point %d: (%.2f, %.2f)\n", i + 1, points[i][0], points[i][1]);
    }

    fclose(file);
    printf("Points saved to 'coordinates.txt' successfully.\n");

    return 0;
}

