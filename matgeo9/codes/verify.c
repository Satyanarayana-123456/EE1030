#include <stdio.h>

int verify_perpendicular(double direction[2], double normal[2]) {
    // Dot product of two vectors: direction • normal = dx * nx + dy * ny
    double dot_product = direction[0] * normal[0] + direction[1] * normal[1];
    
    // If the dot product is zero, the vectors are perpendicular
    if (dot_product == 0) {
        return 1;  // Perpendicular
    } else {
        return 0;  // Not perpendicular
    }
}

