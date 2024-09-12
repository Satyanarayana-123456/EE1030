// Function to calculate the coefficients of the equation m*x + n*y = p
void calculate_relation(float x1, float y1, float x2, float y2, float *m, float *n, float *p) {
    // The relation is derived from the equation of the perpendicular bisector:
    // (x - x1)^2 + (y - y1)^2 = (x - x2)^2 + (y - y2)^2

    // Simplified form: 
    // m * x + n * y = p where
    *m = 2 * (x2 - x1);
    *n = 2 * (y2 - y1);
    *p = (x2 * x2 + y2 * y2) - (x1 * x1 + y1 * y1);
}

