from ctypes import*
import numpy as np
import matplotlib.pyplot as plt

# Load the shared library
equi = CDLL('./equi.so')

# Define the function prototype
# Assuming `find_relation` has the following signature:
# void find_relation(double bx, double by, double cx, double cy, double *m, double *c);
equi.find_relation.argtypes = [c_double, c_double, c_double, c_double, POINTER(c_double), POINTER(c_double)]

# Function to calculate the distance between two points
def distance(x1, y1, x2, y2):
    return np.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)

# Function to verify the point is equidistant from B and C
def verify_equidistant(point, B, C):
    dist_B = distance(point[0], point[1], B[0], B[1])
    dist_C = distance(point[0], point[1], C[0], C[1])
    return np.abs(dist_B - dist_C) < 1e-6  # Using a tolerance for floating-point comparison

# Points B and C
B = (7, 1)
C = (3, 5)

# Read points from coordinates.txt without using loops
with open('coordinates.txt', 'r') as file:
    data = file.read().strip().split('\n')
    points = np.array([list(map(float, line.strip('()').split(', '))) for line in data])

# Select a point to verify
test_point = points[0]

# Verify the selected point is equidistant from B and C
is_equidistant = verify_equidistant(test_point, B, C)

if is_equidistant:
    print(f"Point {test_point} is equidistant from B{B} and C{C}.")
else:
    print(f"Point {test_point} is NOT equidistant from B{B} and C{C}.")

# Plotting the relation and points
x_vals = points[:, 0]
y_vals = points[:, 1]

plt.plot(x_vals, y_vals, 'bo-', label='Line Relation')
plt.scatter([B[0], C[0], test_point[0]], [B[1], C[1], test_point[1]], color='red')
plt.text(B[0], B[1], 'B(7,1)', fontsize=12, ha='right')
plt.text(C[0], C[1], 'C(3,5)', fontsize=12, ha='right')
plt.text(test_point[0], test_point[1], f'P{test_point}', fontsize=12, ha='right')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Plot of the Relation')
plt.legend()
plt.grid(True)
plt.show()

