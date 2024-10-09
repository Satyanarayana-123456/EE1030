#include <math.h>

double distance(double x1, double y1, double x2, double y2) {
    double dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
return dist;
}

