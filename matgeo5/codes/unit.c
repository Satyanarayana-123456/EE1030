#include <math.h>

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

