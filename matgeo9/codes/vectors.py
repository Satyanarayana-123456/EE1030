from ctypes import*
import matplotlib.pyplot as plt

# Load the shared object file
verify = CDLL('./verify.so')

# Define argument and return types for the verify_perpendicular function
verify.verify_perpendicular.argtypes = (POINTER(c_double), POINTER(c_double))
verify.verify_perpendicular.restype = c_int

# Load the direction and normal vectors from your C program
direction = (c_double * 2)(-3, -7)  # Example direction vector
normal = (c_double * 2)(7, -3)      # Example normal vector

# Verify if the vectors are perpendicular
result = verify.verify_perpendicular(direction, normal)
if result == 1:
    print("The vectors are perpendicular.")
else:
    print("The vectors are not perpendicular.")

# Read points from coordinates.txt
points = []
with open('coordinates.txt', 'r') as file:
    for line in file:
        parts = line.strip().split(':')[-1].strip().strip('()').split(',')
        x, y = float(parts[0]), float(parts[1])
        points.append((x, y))

# Extract x and y values from points
x_values = [p[0] for p in points]
y_values = [p[1] for p in points]

# Plot the points and the line
plt.plot(x_values, y_values, 'bo-', label="Line")
plt.xlabel('X')
plt.ylabel('Y')

# Highlight the points
for i, point in enumerate(points):
    plt.text(point[0], point[1], f'P{i+1}({point[0]:.2f},{point[1]:.2f})')

# Show the plot
plt.legend()
plt.grid(True)
plt.title('Line 2 + 3y = 7x')
plt.show()

