from ctypes import*
import numpy as np
import matplotlib.pyplot as plt

# Load the shared object file
circle_lib = CDLL('./circle.so')

# Define the function signatures
# findCenter(a1, b1, c1, a2, b2, c2, centerX, centerY)
circle_lib.findCenter.argtypes = [c_float, c_float, c_float,
                                  c_float, c_float, c_float,
                                  POINTER(c_float), POINTER(c_float)]

# calculateRadius(area) -> radius
circle_lib.calculateRadius.argtypes = [c_float]
circle_lib.calculateRadius.restype = c_float

# Input values for the equations and area
a1, b1, c1 = 2.0, -3.0, -5.0  # Line 1: 2x - 3y = 5
a2, b2, c2 = 3.0, -4.0, -7.0  # Line 2: 3x - 4y = 7
area = 154.0  # Area of the circle

# Variables to store center coordinates
centerX = c_float(0)
centerY = c_float(0)

# Calculate center of the circle
circle_lib.findCenter(a1, b1, c1, a2, b2, c2, byref(centerX), byref(centerY))
centerX = centerX.value
centerY = centerY.value

# Calculate the radius of the circle
radius = circle_lib.calculateRadius(area)

# Read points from coordinates.txt
#with open("coordinates.txt", "r") as file:
 #   points = np.array([list(map(float, line.strip().replace("(", "").replace(")", #"").split(", "))) for line in file])

# Plot the circle
theta = np.linspace(0, 2 * np.pi, 300)
x_circle = centerX + radius * np.cos(theta)
y_circle = centerY + radius * np.sin(theta)

plt.figure()
plt.plot(x_circle, y_circle, label=f" Center({centerX:.2f}, {centerY:.2f}), Radius = {radius:.2f}")
#plt.scatter(points[:, 0], points[:, 1], color='red', label="Points on Circle")
plt.scatter(centerX, centerY, color='blue', s=100, label="Center", edgecolor='black')  # Mark the center

#for point in points:
 #   plt.text(point[0], point[1], f"({point[0]:.2f}, {point[1]:.2f})", fontsize=10, ha='right', color='black')

plt.text(centerX, centerY, f"({centerX:.2f}, {centerY:.2f})", fontsize=10, ha='right', color='black')

plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.title("Circle")
plt.legend(loc='upper right')
plt.gca().set_aspect('equal', adjustable='box')
plt.grid(True)
plt.show()

