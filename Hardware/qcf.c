#include <stdio.h>
#include <stdlib.h>
#include <math.h> 


#define MAX_POINTS 100 // Maximum number of data points

// Function to read data from file
int readData(const char *filename, double T[], double V[], int *n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    *n = 0;
    while (fscanf(file, "%lf %lf", &T[*n], &V[*n]) == 2) {
        (*n)++;
        if (*n >= MAX_POINTS) break;
    }
      fclose(file);
    return 0;
}

// Function to calculate the coefficients a, b, and c for quadratic regression
void calculateQuadraticCoefficients(double T[], double V[], int n, double *a, double *b, double *c) {
    double sumT = 0, sumT2 = 0, sumT3 = 0, sumT4 = 0;
    double sumV = 0, sumTV = 0, sumT2V = 0;

    // Calculate the required sums
    for (int i = 0; i < n; i++) {
        sumT += T[i];
        sumT2 += T[i] * T[i];
        sumT3 += T[i] * T[i] * T[i];
        sumT4 += T[i] * T[i] * T[i] * T[i];

        sumV += V[i];
        sumTV += T[i] * V[i];
        sumT2V += T[i] * T[i] * V[i];
    }
       double D = n * (sumT2 * sumT4 - sumT3 * sumT3)
             - sumT * (sumT * sumT4 - sumT2 * sumT3)
             + sumT2 * (sumT * sumT3 - sumT2 * sumT2);

    double Da = sumV * (sumT2 * sumT4 - sumT3 * sumT3)
              - sumT * (sumTV * sumT4 - sumT3 * sumT2V)
              + sumT2 * (sumTV * sumT3 - sumT2 * sumT2V);

    double Db = n * (sumTV * sumT4 - sumT2V * sumT3)
              - sumV * (sumT * sumT4 - sumT2 * sumT3)
              + sumT2 * (sumT * sumT2V - sumTV * sumT2);

    double Dc = n * (sumT2 * sumT2V - sumT3 * sumTV)
              - sumT * (sumT * sumT2V - sumT2 * sumTV)
              + sumV * (sumT * sumT3 - sumT2 * sumT2);

    *a = Da / D;
    *b = Db / D;
    *c = Dc / D;
}
void printScientific(double value) {
    if (value == 0.0) {
        printf("0.0e0");
        return;
    }
    
    int exponent = (int) floor(log10(fabs(value)));
    double mantissa = value / pow(10, exponent);

    if (fabs(mantissa) < 1) {
        mantissa *= 10;
        exponent -= 1;
    }

    printf("%.4fe%d", mantissa, exponent);
}

int main() {
    double T[MAX_POINTS], V[MAX_POINTS];
    int n;
    if (readData("training_data.txt", T, V, &n) == -1) {
        return -1;
    }

    // Calculate coefficients
    double a, b, c;
    calculateQuadraticCoefficients(T, V, n, &a, &b, &c);
        
    printScientific(a);
    printf("\n");
    printScientific(b);
    printf("\n");
    printScientific(c);

    // Print the resulting quadratic equation in scientific notation
    printf("\nThe quadratic fit equation is: V = ");
    printScientific(a);
    printf(" + ");
    printScientific(b);
    printf("*T + ");
    printScientific(c);
    printf("*T^2\n");

    return 0;
}

