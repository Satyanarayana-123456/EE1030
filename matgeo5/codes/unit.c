#include <math.h>

void find_unit_vector(double P[3], double Q[3], double unit_vector[3]) {
    double PQ[3];  // Vector PQ
    double magnitude = 0.0;

    // Calculate PQ = Q - P
    for (int i = 0; i < 3; i++) {
        PQ[i] = Q[i] - P[i];
        magnitude += PQ[i] * PQ[i];
    }

    // Calculate the magnitude of vector PQ
    magnitude = sqrt(magnitude);

    // Calculate the unit vector components
    for (int i = 0; i < 3; i++) {
        unit_vector[i] = PQ[i] / magnitude;
    }
}

