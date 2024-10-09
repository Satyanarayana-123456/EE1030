from ctypes import*
import numpy as np
import matplotlib.pyplot as plt

# Load the shared library
lib = CDLL('./collinear.so')

# Define the function from the shared library
# Function prototype: void find_relation(double x1, double y1, double x2, double y2, double* m, double* c);
lib.find_relation.argtypes = [c_double, c_double, c_double, c_double, POINTER(c_double), POINTER(c_double)]
lib.find_relation.restype = None

# Known points B and C
x1, y1 = -4, 6  # Coordinates of point B
x2, y2 = -2, 3  # Coordinates of point C

# Variables to hold the slope and intercept
m = c_double()
c = c_double()

# Call the function to get the slope and intercept
lib.find_relation(x1, y1, x2, y2, byref(m), byref(c))

# Print the relation
print(f"The relation between x and y is: y = {m.value:.2f} * x + {c.value:.2f}")

# Read coordinates from the file
x_coords = []
y_coords = []

with open('coordinates.txt', 'r') as file:
    for line in file:
        parts = line.split(',')
        x = float(parts[0].split('=')[1].strip())
        y = float(parts[1].split('=')[1].strip())
        x_coords.append(x)
        y_coords.append(y)

# Check collinearity by calculating area of the triangle formed with the points B, C, and (x, y)
def is_collinear(xa, ya, xb, yb, xc, yc):
    # Calculate the area of the triangle using the determinant method
    area = abs(xa*(yb - yc) + xb*(yc - ya) + xc*(ya - yb)) / 2.0
    return area == 0

# Select a point from coordinates.txt to verify
if x_coords and y_coords:
    x, y = x_coords[0], y_coords[0]
    if is_collinear(x1, y1, x2, y2, x, y):
        print(f"The point ({x}, {y}) is collinear with points B and C (area is 0).")
    else:
        print(f"The point ({x}, {y}) is NOT collinear with points B and C (area is not 0).")

# Generate the plot
plt.figure(figsize=(8, 6))

# Plot the line
x_values = np.linspace(min(x_coords)-1, max(x_coords)+1, 400)
y_values = m.value * x_values + c.value
plt.plot(x_values, y_values, label=f'y = {m.value:.2f} * x + {c.value:.2f}', color='blue')

# Plot the coordinates
plt.scatter(x_coords, y_coords, color='red', label='Coordinates from file')

# Highlight points B and C
plt.scatter([x1, x2], [y1, y2], color='green', zorder=5, label='Points B and C')

# Labels and title
plt.xlabel('x')
plt.ylabel('y')
plt.title('Plot of the Line and Coordinates')
plt.legend()
plt.grid(True)

# Show the plot
plt.show()

