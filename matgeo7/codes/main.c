#include <stdio.h>
#include <math.h>

void calculateCoordinates(double BC, double CA_AB, double *Ax, double *Ay, double *Bx, double *By, double *Cx, double *Cy) {
    // B is at the origin
    *Bx = 0;
    *By = 0;

    // C is along the x-axis, so C = (BC, 0)
    *Cx = BC;
    *Cy = 0;

    // Calculate Ay using the given formula
    *Ay = ((CA_AB * CA_AB) - (BC * BC)) / (2 * CA_AB);

    // A lies on the y-axis at (0, Ay)
    *Ax = 0;
}

int main() {
    double CA_AB = 5.5;  // CA + AB = 5.5 cm
    double BC = 3.5;     // BC = 3.5 cm
    double Ax, Ay, Bx, By, Cx, Cy;

    // Calculate the coordinates of A, B, and C
    calculateCoordinates(BC, CA_AB, &Ax, &Ay, &Bx, &By, &Cx, &Cy);

    // Print the coordinates
    printf("Coordinates of A: (%.2lf, %.2lf)\n", Ax, Ay);
    printf("Coordinates of B: (%.2lf, %.2lf)\n", Bx, By);
    printf("Coordinates of C: (%.2lf, %.2lf)\n", Cx, Cy);

    return 0;
}

