#include <math.h>

void calculateCoordinates(double BC, double CA_AB, double *Ax, double *Ay, double *Bx, double *By, double *Cx, double *Cy) {
    // B is at the origin
    // B is assumed to be right angle
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

