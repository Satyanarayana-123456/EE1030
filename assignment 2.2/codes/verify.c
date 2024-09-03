#define MAX_COORDINATES 3

// Tolerance for floating-point comparison
#define TOLERANCE 0.00001

// Function to verify if a single coordinate satisfies the relation
int verify_coordinate(float m, float n, float p, float x, float y) {
    float result = m * x + n * y - p;
    return (result < TOLERANCE && result > -TOLERANCE);
}

// Function to verify three coordinates against the relation
void verify_coordinates(float m, float n, float p, float coords[MAX_COORDINATES][2], int results[MAX_COORDINATES]) {
    results[0] = verify_coordinate(m, n, p, coords[0][0], coords[0][1]);
    results[1] = verify_coordinate(m, n, p, coords[1][0], coords[1][1]);
    results[2] = verify_coordinate(m, n, p, coords[2][0], coords[2][1]);
}

