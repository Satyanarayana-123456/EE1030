from ctypes import *
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Load the shared object file
unit = CDLL('./unit.so')

# Define the C function signature
unit.find_unit_vector.argtypes = [POINTER(c_double), POINTER(c_double), POINTER(c_double)]

# Points P and Q
P = (c_double * 3)(2.0, 1.0, -1.0)  # P(2, 1, -1)
Q = (c_double * 3)(4.0, 4.0, -7.0)  # Q(4, 4, -7)

# Prepare array for unit vector output
unit_vector = (c_double * 3)()

# Call the function from the shared object
unit.find_unit_vector(P, Q, unit_vector)

# Get the unit vector components
ux, uy, uz = unit_vector[0], unit_vector[1], unit_vector[2]

# Create a figure for plotting
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plot the solid unit vector PQ from point P
ax.quiver(P[0], P[1], P[2], ux, uy, uz, length=1, color='blue', label='Unit Vector PQ', arrow_length_ratio=0.1)

# Plot the dotted line joining P and Q
ax.plot([P[0], Q[0]], [P[1], Q[1]], [P[2], Q[2]], 'k--', label='Line PQ')

# Mark points P and Q
ax.scatter(P[0], P[1], P[2], color='red', s=100, label=f'Point P({P[0]}, {P[1]}, {P[2]})')
ax.scatter(Q[0], Q[1], Q[2], color='green', s=100, label=f'Point Q({Q[0]}, {Q[1]}, {Q[2]})')

# Add text annotations to label the coordinates of P and Q
ax.text(P[0], P[1], P[2], f'P({P[0]}, {P[1]}, {P[2]})', color='red', fontsize=12)
ax.text(Q[0], Q[1], Q[2], f'Q({Q[0]}, {Q[1]}, {Q[2]})', color='green', fontsize=12)

# Set labels
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')

# Title and legend
ax.set_title('Unit Vector PQ')
ax.legend()

# Show the plot
plt.show()

