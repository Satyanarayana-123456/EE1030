#include <stdio.h>

void findCoordinates(double,double,double*,double*,double*,double*,double*,double*);

int main() {
    double AB = 6, BC = 8;  // Given values for AB and BC
    double Ax, Ay, Bx, By, Cx, Cy;

    // Find coordinates of A, B, C
    findCoordinates(AB, BC, &Ax, &Ay, &Bx, &By, &Cx, &Cy);

    // Print the coordinates
    printf("Coordinates of A: (%.2f, %.2f)\n", Ax, Ay);
    printf("Coordinates of B: (%.2f, %.2f)\n", Bx, By);
    printf("Coordinates of C: (%.2f, %.2f)\n", Cx, Cy);

    return 0;
}

