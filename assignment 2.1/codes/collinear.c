// collinear.c

// Function to find the relation between x and y
void find_relation(double x1, double y1, double x2, double y2, double* m, double* c) {
    // The slope m = (y2 - y1) / (x2 - x1)
    *m = (y2 - y1) / (x2 - x1);
    // The intercept c = y1 - m * x1
    *c = y1 - (*m) * x1;
}

// To compile as shared object: gcc -shared -o collinear.so -fPIC collinear.c

