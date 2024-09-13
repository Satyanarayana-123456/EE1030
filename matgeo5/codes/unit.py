from ctypes import*
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Load the shared object file
unit = CDLL('./unit.so')

# Define the C function signature
# void find_unit_vector(double x1, double y1, double z1, double x2, double y2, double z2, double *ux, double *uy, double *uz)
unit.find_unit_vector.argtypes = [c_double, c_double, c_double, 
                                  c_double, c_double, c_double,
                                  POINTER(c_double), POINTER(c_double), POINTER(c_double)]

# Points P and Q
x1, y1, z1 = 2, 1, -1  # P(2, 1, -1)
x2, y2, z2 = 4, 4, -7  # Q(4, 4, -7)

# Prepare variables for unit vector output
ux, uy, uz = c_double(), c_double(), c_double()

# Call the function from the shared object
unit.find_unit_vector(x1, y1, z1, x2, y2, z2, byref(ux), byref(uy), byref(uz))

# Get the unit vector components
ux, uy, uz = ux.value, uy.value, uz.value

# Create a figure for plotting
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plot the vector PQ
ax.quiver(x1, y1, z1, ux, uy, uz, length=1, color='blue', label='Unit Vector PQ', arrow_length_ratio=0.1)

# Mark points P and Q
ax.scatter(x1, y1, z1, color='red', s=100, label='Point P(2, 1, -1)')
ax.scatter(x2, y2, z2, color='green', s=100, label='Point Q(4, 4, -7)')

# Set labels
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')

# Title and legend
ax.set_title('Unit Vector PQ')
ax.legend()

# Show the plot
plt.show()

