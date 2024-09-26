// Function to calculate the dot product of two vectors
float dot_product(float vec1[], float vec2[], int n) {
    float dot = 0.0;
    for (int i = 0; i < n; i++) {
        dot += vec1[i] * vec2[i];
    }
    return dot;
}

// Function to verify if two vectors are perpendicular
int are_perpendicular(float vec1[], float vec2[], int n) {
    float dot = dot_product(vec1, vec2, n);
    
    // If dot product is approximately zero, the vectors are perpendicular
    if (dot == 0.0) {
        return 1; // Vectors are perpendicular
    } else {
        return 0; // Vectors are not perpendicular
    }
}

