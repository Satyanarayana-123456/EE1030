#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define MAX_ITER 1000

void mat_mul(double complex *A,double complex *B,double complex *C,int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            C[i*n + j] = 0;
            for (int k=0;k<n;k++){
                C[i*n + j] += A[i*n + k]*B[k*n + j];
            }
        }
    }
}

void qr_decomposition(double complex *A,double complex *Q,double complex *R,int n){
    for (int k=0;k<n;k++){
       for (int i=0;i<n;i++){
            Q[i*n + k] = A[i*n + k];
        }
         for (int j=0;j<k;j++){
            double complex dot=0;
            for (int i=0;i<n;i++){
                dot += conj(Q[i*n + j])*A[i*n + k];
            }
            for (int i=0;i<n;i++){
                Q[i*n + k] -= dot*Q[i*n + j];
            }
        }

        double complex norm=0;
        for (int i=0;i<n;i++){
            norm += conj(Q[i*n + k])*Q[i*n + k];
        }
        norm=sqrt(norm);
        for (int i=0;i<n;i++){
            Q[i*n + k] /= norm;
        }

        for (int j=k;j<n;j++){
            double complex dot=0;
            for (int i=0;i<n;i++){
                dot += conj(Q[i*n + k])*A[i*n + j];
            }
            R[k*n + j] = dot;
        }
    }
}

void qr_algorithm(double complex *A,double complex *eigenvalues,int n){
    double complex *Q = (double complex *)malloc((n*n)*sizeof(double complex));
    double complex *R = (double complex *)malloc((n*n)*sizeof(double complex));

    for (int iter=0;iter<MAX_ITER;iter++){
        qr_decomposition(A, Q, R, n);

        mat_mul(R, Q, A, n);
     
        int converged=1;
        for (int i=0;i<n;i++){
            for (int j=0;j<i;j++){
                if(cabs(A[i*n + j]) > 1e-9){
                    converged = 0;
                    break;
                }
            }
        }
        if(converged){
        break;}
    }
    for (int i=0;i<n;i++){
        eigenvalues[i] = A[i*n + i];
    }
    free(Q);
    free(R);
  }

int main(void){
    int n;
    printf("Enter the dimension(n) for the square matrix: ");
    scanf("%d", &n);
    if(n<=0){
    printf("Matrix dimension should be positive integer\n");
    return 1;
    }

    double complex *A = (double complex *)malloc((n*n)*sizeof(double complex));
    double complex *eigenvalues = (double complex *)malloc(n*sizeof(double complex));
    if (A == NULL || eigenvalues == NULL){
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements of the %dx%d matrix row-wise(real and imaginary part separated by space):\n",n,n);
    for (int i=0;i<n*n;i++){
        double real, imag;
        scanf("%lf %lf", &real, &imag);
        A[i] = real + imag*I;
    }

    qr_algorithm(A, eigenvalues, n);
    printf("Eigenvalues:\n");
    for (int i=0;i<n;i++){
        printf("%f + %fi\n",creal(eigenvalues[i]),cimag(eigenvalues[i]));
    }
    free(A);
    free(eigenvalues);

    return 0;
}

