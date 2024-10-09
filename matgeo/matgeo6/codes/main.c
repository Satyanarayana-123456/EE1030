#include <stdio.h>
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

int main() {
    // Given values
    double AB = 5;
    double BC = 6;
    double angleB = 60;
    
    // Variables to store the coordinates of A, B, and C
    double Ax, Ay, Bx, By, Cx, Cy;
    
    // Call the function to find the coordinates
    findCoordinates(AB, BC, angleB, &Ax, &Ay, &Bx, &By, &Cx, &Cy);
    
    // Print the coordinates
    printf("Coordinates of A: (%.2f, %.2f)\n", Ax, Ay);
    printf("Coordinates of B: (%.2f, %.2f)\n", Bx, By);
    printf("Coordinates of C: (%.2f, %.2f)\n", Cx, Cy);
    
    return 0;
}

