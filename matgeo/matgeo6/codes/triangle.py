from ctypes import*
import numpy as np
import matplotlib.pyplot as plt

# Load the shared object file
triangle_lib = CDLL('./triangle.so')

# Define the function signature for `find_coordinates`
triangle_lib.findCoordinates.argtypes = [
    c_double, c_double, c_double,
    POINTER(c_double), POINTER(c_double),
    POINTER(c_double), POINTER(c_double),
    POINTER(c_double), POINTER(c_double)
]

# Given values
AB = 5
BC = 6
angleB = 60

# Create variables to store the coordinates
Ax = c_double()
Ay = c_double()
Bx = c_double()
By = c_double()
Cx = c_double()
Cy = c_double()

# Call the function from the shared object file
triangle_lib.findCoordinates(AB, BC, angleB, byref(Ax), byref(Ay), byref(Bx), byref(By), byref(Cx), byref(Cy))

# Convert coordinates to numpy arrays
A = np.array([Ax.value, Ay.value])
B = np.array([Bx.value, By.value])
C = np.array([Cx.value, Cy.value])

# Plot the triangle
plt.figure()
plt.plot([A[0], B[0]], [A[1], B[1]], 'bo-', label='AB')
plt.plot([B[0], C[0]], [B[1], C[1]], 'go-', label='BC')
plt.plot([C[0], A[0]], [C[1], A[1]], 'ro-', label='CA')
plt.scatter([A[0], B[0], C[0]], [A[1], B[1], C[1]], c='black')

# Annotate the points with their coordinates
plt.text(A[0], A[1], f'A({A[0]:.2f}, {A[1]:.2f})', fontsize=12, ha='right')
plt.text(B[0], B[1], f'B({B[0]:.2f}, {B[1]:.2f})', fontsize=12, ha='right')
plt.text(C[0], C[1], f'C({C[0]:.2f}, {C[1]:.2f})', fontsize=12, ha='right')

plt.xlabel('X')
plt.ylabel('Y')
plt.title('Triangle ABC')
plt.legend()
plt.grid(True)
plt.axis('equal')
plt.show()

