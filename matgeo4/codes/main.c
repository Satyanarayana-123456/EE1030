#include <stdio.h>
#include <math.h>

// Function to calculate distance between two points A(x1, y1) and B(x2, y2)
double distance(double x1, double y1, double x2, double y2) {
    double dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return dist;
}

int main() {
    double x1=0, y1=6, x2=0, y2=-2;

    // Calculate distance
    double dist = distance(x1, y1, x2, y2);

    // Output the distance
    printf("Distance between A and B: %lf\n", dist);

    return 0;
}

