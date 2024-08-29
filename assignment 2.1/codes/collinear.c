// collinear.c
float find_relation(float x1, float y1, float x2, float y2, float x, float y) {
    // Relation equation: x(y1 - y2) + y(x2 - x1) = x1*y2 - x2*y1
    return x * (y1 - y2) + y * (x2 - x1) - (x1 * y2 - x2 * y1);
}

