from ctypes import*
import matplotlib.pyplot as plt

# Load the shared object file (verify.so)
verify = CDLL('./verify.so')

# Define the argument types and return type for the `are_perpendicular` function
verify.are_perpendicular.argtypes = (POINTER(c_float), POINTER(c_float), c_int)
verify.are_perpendicular.restype = c_int

# Input the line equation
line_equation = "2 + 3y = 7x"

# Extract coefficients from the line equation (2 + 3y = 7x -> 7x - 3y = -2)
A = 7  # Coefficient of x
B = -3  # Coefficient of y
C = -2  # Constant

# Direction vector is along the line
direction_vector = [1, - A / B]  # Using slope (-A/B)

# Normal vector is perpendicular to the line (A, B)
normal_vector = [A / B, 1]

# Convert Python lists to C-style arrays
n = len(direction_vector)
direction_vector_c = (c_float * n)(*direction_vector)
normal_vector_c = (c_float * n)(*normal_vector)

# Call the C function to check perpendicularity
result = verify.are_perpendicular(direction_vector_c, normal_vector_c, n)

if result == 1:
    print("The direction vector and normal vector are perpendicular.")
else:
    print("The direction vector and normal vector are not perpendicular.")

# Read points from coordinates.txt
points = []
with open("coordinates.txt", "r") as file:
    for line in file:
        x, y = map(float, line.strip().split(", "))
        points.append((x, y))

# Unpack the points for plotting
x_coords, y_coords = zip(*points)

# Plot the line using points from coordinates.txt
plt.plot(x_coords, y_coords, 'bo-', label="Line 2 + 3y = 7x")  # Blue line with markers for points
plt.scatter(x_coords, y_coords, color='red')  # Red dots at the points
for i, (x, y) in enumerate(points):
    plt.text(x, y, f"({x:.2f}, {y:.2f})", fontsize=9, ha='right')

# Label the plot
plt.title("Line 2 + 3y = 7x")
plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.grid(True)
plt.legend()

# Show the plot
plt.show()

