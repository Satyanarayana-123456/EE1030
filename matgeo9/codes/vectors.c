#include <stdio.h>

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


