#include <stdio.h>
#include <math.h>

// Function to calculate the unit vector PQ
void find_unit_vector(double x1, double y1, double z1, double x2, double y2, double z2, double *ux, double *uy, double *uz) {
    double PQx = x2 - x1;
    double PQy = y2 - y1;
    double PQz = z2 - z1;

    // Calculate the magnitude of vector PQ
    double magnitude = sqrt(PQx * PQx + PQy * PQy + PQz * PQz);

    // Calculate the unit vector components
    *ux = PQx / magnitude;
    *uy = PQy / magnitude;
    *uz = PQz / magnitude;
}

int main() {
    // Coordinates of P(2, 1, -1) and Q(4, 4, -7)
    double x1 = 2, y1 = 1, z1 = -1;
    double x2 = 4, y2 = 4, z2 = -7;
    double ux, uy, uz;

    // Find the unit vector of PQ
    find_unit_vector(x1, y1, z1, x2, y2, z2, &ux, &uy, &uz);

    // Output the unit vector PQ
    printf("The unit vector PQ is: (%.2lf, %.2lf, %.2lf)\n", ux, uy, uz);

    return 0;
}

