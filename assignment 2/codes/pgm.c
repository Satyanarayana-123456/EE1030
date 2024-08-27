#include <stdio.h>

int main() {
    // Given points
    int A[2] = {3, 1};
    int B[2] = {5, 1};
    int D[2] = {4, 3};
    
    // Coordinates of point C
    int C[2];
    
    // Using the property of parallelogram: A + C = B + D
    C[0] = B[0] + D[0] - A[0];
    C[1] = B[1] + D[1] - A[1];
    
    // Output the coordinates
    FILE *fptr;
    fptr = fopen("coordinates.txt", "w");
    
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write the coordinates of all points to the file
    fprintf(fptr, "A(%d,%d)\n", A[0], A[1]);
    fprintf(fptr, "B(%d,%d)\n", B[0], B[1]);
    fprintf(fptr, "C(%d,%d)\n", C[0], C[1]);
    fprintf(fptr, "D(%d,%d)\n", D[0], D[1]);

    fclose(fptr);
    
    printf("Coordinates calculated and saved to coordinates.txt\n");
    
    return 0;
}

