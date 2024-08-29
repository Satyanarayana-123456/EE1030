// vertex.c

struct Point {
    float x;
    float y;
};

struct Point findVertexC(float x1, float y1, float x2, float y2, float x4, float y4) {
    struct Point c;
    c.x = x2 + x4 - x1;
    c.y = y2 + y4 - y1;
    return c;
}

