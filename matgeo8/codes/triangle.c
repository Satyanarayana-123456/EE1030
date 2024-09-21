void findCoordinates(double AB, double BC, double *Ax, double *Ay, double *Bx, double *By, double *Cx, double *Cy) {
    // Assuming B is at the origin (0, 0)
    *Bx = 0;
    *By = 0;   // B is at the origin (0, 0)
    *Ax = 0;
    *Ay = AB;  // A is along the y-axis at (0, AB)
    *Cx = BC;
    *Cy = 0;   // C is along the x-axis at (BC, 0)
}

