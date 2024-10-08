import numpy as np
import matplotlib.pyplot as plt
from ctypes import *

# Load the shared library
area = CDLL('./area.so')

# Define the parameter and return types for the functions
area.riemann_sum_parabola.argtypes = [c_double, c_double, c_int, c_double]
area.riemann_sum_parabola.restype = c_double

area.riemann_sum_circle.argtypes = [c_double, c_double, c_int, c_double, c_double, c_double]
area.riemann_sum_circle.restype = c_double

# Define the parameters for the parabola and the circle
p = 1.0  # Parameter for the parabola y^2 = 4px
h = 0.0  # x-coordinate of the circle center
k = 0.0  # y-coordinate of the circle center
r = 1.5  # Radius of the circle
x_start = 0.0
x_mid = 0.5
x_end = 1.5
# Number of rectangles for the Riemann sum
n = 1000

# Calculate areas using the shared library functions
area_parabola = area.riemann_sum_parabola(c_double(x_start), c_double(x_mid), c_int(n), c_double(p))
area_circle = area.riemann_sum_circle(c_double(x_mid), c_double(x_end), c_int(n), c_double(h), c_double(k), c_double(r))

# Calculate and print the total area
total_area = 2 * (area_parabola + area_circle)
print(f"Total area: {round(total_area, 4):.4f}")

# Read intersection points
with open("coordinates.txt", "r") as file:
    intersections = [next(file) for _ in range(2)]
    x1_intersection, y1_intersection = map(float, intersections[0].strip().strip("()").split(","))
    x2_intersection, y2_intersection = map(float, intersections[1].strip().strip("()").split(","))

# Read points from coordinates.txt
data = np.loadtxt("coordinates.txt", delimiter=',', skiprows=3, usecols=(0, 1))

# Extract points: first 502 for parabola, next 502 for circle
x_parabola = data[:502, 0]
y_parabola = data[:502, 1]
x_circle = data[502:1506, 0]
y_circle = data[502:1506, 1]

# Create a single plot
plt.figure(figsize=(10, 8))

# Plot parabola points
plt.scatter(x_parabola, y_parabola, label='Parabola', color='blue', s=1)  # s=1 for small points
# Plot circle points
plt.scatter(x_circle, y_circle, label='Circle', color='green', s=1)  # s=1 for small points

# Define the range for shading the area above the parabola
x_parabola_fill = np.linspace(0, 0.5, 1000)
y_parabola_fill = np.sqrt(4 * p * x_parabola_fill)

# Shade the area above the parabola from x=0 to x=0.5
plt.fill_between(x_parabola_fill, y_parabola_fill, color='blue', alpha=0.3)
plt.fill_between(x_parabola_fill, -y_parabola_fill, color='blue', alpha=0.3)

# Define the range for shading the area below the circle
x_circle_fill = np.linspace(0.5, 1.5, 1000)
y_circle_fill_upper = k + np.sqrt(r**2 - (x_circle_fill - h)**2)
y_circle_fill_lower = k - np.sqrt(r**2 - (x_circle_fill - h)**2)

# Shade the area above the circle from x=0.5 to x=1.5
plt.fill_between(x_circle_fill, y_circle_fill_upper, color='blue', alpha=0.3)
plt.fill_between(x_circle_fill, y_circle_fill_lower, color='blue', alpha=0.3)

# Plot intersection points
plt.scatter([x1_intersection, x2_intersection], [y1_intersection, y2_intersection],
            label='Intersection Points', color='red', zorder=5)
plt.text(x1_intersection, y1_intersection, f'({x1_intersection:.2f}, {y1_intersection:.2f})', fontsize=10, color='red', ha='right')
plt.text(x2_intersection, y2_intersection, f'({x2_intersection:.2f}, {y2_intersection:.2f})', fontsize=10, color='red', ha='left')

# Labels and legend
plt.xlabel('x')
plt.ylabel('y')
plt.title('Area between Parabola and Circle')
plt.legend()

# Ensure equal aspect ratio for accurate representation
plt.axis('equal')
plt.grid(True)

# Show the plot
plt.tight_layout()
plt.show()

