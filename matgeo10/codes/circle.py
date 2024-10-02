from ctypes import*
import numpy as np
import matplotlib.pyplot as plt
# Load the shared object file
circle_lib = CDLL('./circle.so')

# Define the function from the shared library
circle_lib.findCircleProperties.argtypes = [c_float, c_float, c_float,
                                              c_float, c_float, c_float,
                                              c_float, POINTER(c_float),
                                              POINTER(c_float), POINTER(c_float)]

# Initialize variables for the diameters and area
a1, b1, c1 = 2, -3, -5    # Coefficients for line 1: 2x - 3y = 5
a2, b2, c2 = 3, -4, -7    # Coefficients for line 2: 3x - 4y = 7
area = 154.0              # Area of the circle

# Create variables to hold the center and radius
centerX = c_float()
centerY = c_float()
radius = c_float()

# Call the function from the shared object
circle_lib.findCircleProperties(a1, b1, c1, a2, b2, c2, area, 
                                 byref(centerX), 
                                 byref(centerY), 
                                 byref(radius))

# Print the calculated center and radius
#print(f"Center of the circle: ({centerX.value:.2f}, {centerY.value:.2f})")
#print(f"Radius of the circle: {radius.value:.2f}")

# Read the coordinates from the file
with open('coordinates.txt', 'r') as file:
    lines = file.readlines()
    points = [tuple(map(float, line.strip().split(': ')[1].strip('()').split(', '))) for line in lines if "Point" in line]

# Extract x and y coordinates for plotting
x_coords, y_coords = zip(*points)

# Plot the circle
theta = np.linspace(0, 2 * np.pi, 100)
x_circle = centerX.value + radius.value * np.cos(theta)
y_circle = centerY.value + radius.value * np.sin(theta)

plt.plot(x_circle, y_circle, label='Circle', color='blue')

# Plot the points
plt.plot(x_coords, y_coords, 'ro')  # Red points
plt.text(x_coords[0], y_coords[0], f'({x_coords[0]:.2f}, {y_coords[0]:.2f})', fontsize=8, ha='right')
plt.text(x_coords[1], y_coords[1], f'({x_coords[1]:.2f}, {y_coords[1]:.2f})', fontsize=8, ha='right')
plt.text(x_coords[2], y_coords[2], f'({x_coords[2]:.2f}, {y_coords[2]:.2f})', fontsize=8, ha='right')

# Mark the center
plt.plot(centerX.value, centerY.value, 'go')  # Green point for the center
plt.text(centerX.value, centerY.value, f'Center ({centerX.value:.2f}, {centerY.value:.2f})', fontsize=10, ha='right', color='green')

# Adjust plot settings
plt.gca().set_aspect('equal', adjustable='box')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.title('Circle')
plt.legend()
plt.grid(True)
plt.axhline(0, color='black', linewidth=0.5, ls='--')
plt.axvline(0, color='black', linewidth=0.5, ls='--')

# Show the plot
plt.show()

