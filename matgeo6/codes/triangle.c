#include <math.h>

#define PI 3.14159265358979323846

// Function to calculate coordinates of A, B, C
void findCoordinates(double AB, double BC, double angleB, double *Ax, double *Ay, double *Bx, double *By, double *Cx, double *Cy) {
    // Coordinates of point B
    *Bx = 0;
    *By = 0;
    
    // Coordinates of point C (C lies on the positive x-axis)
    *Cx = BC;
    *Cy = 0;
    
    // Convert angleB to radians
    double angleB_rad = (angleB * PI) / 180.0;
    
    // Coordinates of point A using trigonometry
    *Ax = AB * cos(angleB_rad);
    *Ay = AB * sin(angleB_rad);
}

