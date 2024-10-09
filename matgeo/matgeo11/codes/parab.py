import numpy as np
import matplotlib.pyplot as plt
from ctypes import *

# Load the shared object file
parab = CDLL('./parab.so')

# Set argument and return types for the functions in parab.so
parab.riemannSum.argtypes = [c_double, c_double, c_double, c_double, c_double, c_double, c_double, c_int]
parab.riemannSum.restype = c_double

# Parameters for the line y = 4x and the parabola y = x^2
a = 1.0  # Coefficient of x^2 in the parabola
b = 0.0  # Coefficient of x in the parabola
c1 = 0.0  # Constant term in the parabola
m_value = 4.0  # Slope of the line y = 4x
c2 = 0.0  # Constant term in the line y = 4x
x1 = 0.0  # Start x-coordinate (lower limit of integration)
x2 = 4.0  # End x-coordinate (upper limit of integration, approx intersection)
n = 1000  # Number of rectangles for Riemann sum (increase for accuracy)

# Call the function to compute the area using Riemann sum method
area = parab.riemannSum(c_double(a), c_double(b), c_double(c1), c_double(m_value), c_double(c2), c_double(x1), c_double(x2), c_int(n))

# Verify the area and print result
target_area = 32.0 / 3.0  # Expected area
if np.isclose(area, target_area, rtol=1e-5):
    print(f"The value of m is verified. Area is approximately: {area}")
else:
    print(f"Area mismatch! Calculated area: {area}")

# Load points from coordinates.txt using loadtxt (skip the first 2 lines for intersections)
points = np.loadtxt("coordinates.txt", delimiter=',', skiprows=3, usecols=(0, 1))

x_parabola = points[:, 0]
y_parabola = points[:, 1]

# Extract intersection points from the first two lines
with open("coordinates.txt", "r") as file:
    intersections = [next(file) for _ in range(2)]
    x1_intersection, y1_intersection = map(float, intersections[0].strip().strip("()").split(","))
    x2_intersection, y2_intersection = map(float, intersections[1].strip().strip("()").split(","))

# Plotting the parabola and intersection points
plt.figure(figsize=(8, 6))

# Plot 500 points of the parabola
plt.plot(x_parabola, y_parabola, label=r'$y = x^2$', color='blue')

# Plot the line y = 4x
#x_line = np.linspace(min(x_parabola), max(x_parabola), 500)
#y_line = m_value * x_line
#plt.plot(x_line, y_line, label=r'$y = 4x$', color='green')

# Highlight the points of intersection
plt.scatter([x1_intersection, x2_intersection], [y1_intersection, y2_intersection], color='red', zorder=5, label='Intersection Points')

# Mark coordinates of the intersection points in brackets
plt.text(x1_intersection, y1_intersection, f'({x1_intersection:.2f}, {y1_intersection:.2f})', fontsize=10, color='red', ha='right')
plt.text(x2_intersection, y2_intersection, f'({x2_intersection:.2f}, {y2_intersection:.2f})', fontsize=10, color='red', ha='left')

# Draw a line between points of intersection
plt.plot([x1_intersection, x2_intersection], [y1_intersection, y2_intersection], color='red', linestyle='--', label='y =4x')

# Labels and legend
plt.xlabel('x')
plt.ylabel('y')
plt.title('Area between y = 4x and y = x^2')
plt.legend()

# Show the plot
plt.grid(True)
plt.show()

