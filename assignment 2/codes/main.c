// main.c

#include <stdio.h>

struct Point {
    float x;
    float y;
};

// Declare the function prototype for the shared library
extern struct Point findVertexC(float x1, float y1, float x2, float y2, float x4, float y4);

int main() {
    struct Point A, B, D, C;
float x1 = 3,y1 = 1,x2 = 5,y2 = 1,x4 = 4,y4 = 3;

    // Call the function from the shared library to calculate vertex C
    C = findVertexC(x1, y1, x2, y2, x4, y4);
    
    // Output the coordinates of vertex C
    printf("The coordinates of vertex C are: (%.2f, %.2f)\n", C.x, C.y);
    
    return 0;
}

