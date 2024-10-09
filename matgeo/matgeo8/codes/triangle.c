#include <math.h>
#include <stdio.h>

// Function to calculate the square of the distance between two points
double distanceSquared(double x1, double y1, double x2, double y2) {
    return pow(x2 - x1, 2) + pow(y2 - y1, 2);
}

// Function to verify b^2 = a^2 + c^2 for a right-angled triangle
int verifyPythagorasTheorem(double Ax, double Ay, double Bx, double By, double Cx, double Cy) {
    // Calculate the squared lengths of sides a, b, and c
    double a2 = distanceSquared(Bx, By, Cx, Cy);  // Side opposite to point A
    double b2 = distanceSquared(Ax, Ay, Cx, Cy);  // Hypotenuse
    double c2 = distanceSquared(Ax, Ay, Bx, By);  // Side opposite to point C

    // Verify if b^2 == a^2 + c^2
    if (fabs(b2 - (a2 + c2)) < 1e-6) {
       return 1;
    } else {
        return 0;;
    }
}

