// Function to find the relation between x and y
void find_relation(double bx, double by, double cx, double cy, double *m, double *c) {
    // Midpoint of B and C
    double mx = (bx + cx) / 2.0;
    double my = (by + cy) / 2.0;

    // Check if the line BC is vertical
    if (cx != bx) {
        // Slope of line BC
        double slope_bc = (cy - by) / (cx - bx);
        
        // Slope of the perpendicular bisector
        *m = -1.0 / slope_bc;
    } else {
        // If the line BC is vertical, the perpendicular bisector is horizontal
        *m = 0;
        *c = my;
        return;
    }
    
    // Calculate the intercept c of the line y = mx + c
    *c = my - (*m * mx);
}


