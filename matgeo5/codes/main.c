#include <stdio.h>
#include <math.h>

// Function to calculate the unit vector PQ
void find_unit_vector(double P[3], double Q[3], double unit_vector[3]) {
    double PQ[3];
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

int main() {
    // Coordinates of P(2, 1, -1) and Q(4, 4, -7)
    double P[3] = {2, 1, -1};
    double Q[3] = {4, 4, -7};
    double unit_vector[3];

    // Find the unit vector of PQ
    find_unit_vector(P, Q, unit_vector);

    // Output the unit vector PQ
    printf("The unit vector PQ is: (%.2lf, %.2lf, %.2lf)\n", unit_vector[0], unit_vector[1], unit_vector[2]);

    return 0;
}

