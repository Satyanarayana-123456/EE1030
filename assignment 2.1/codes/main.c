#include <stdio.h>
#include <dlfcn.h>

int main() {
    // Load the shared library
    void *handle;
    float (*find_relation)(float, float, float, float, float, float);
    char *error;

    handle = dlopen("./collinear.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    // Get the function from the shared library
    find_relation = dlsym(handle, "find_relation");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        return 1;
    }

    // Define the coordinates of points B(x1, y1) and C(x2, y2)
    float x1 = -4.0, y1 = 6.0;
    float x2 = -2.0, y2 = 3.0;

    // The coefficients of x and y are A = (y1 - y2) and B = (x2 - x1)
    float A = y1 - y2;
    float B = x2 - x1;
    float C = x1 * y2 - x2 * y1;

    // Print the relation as: Ax + By = C
    printf("The relation between x and y is: %.2fx + %.2fy = %.2f\n", A, B, C);

    // Close the shared library
    dlclose(handle);

    return 0;
}

