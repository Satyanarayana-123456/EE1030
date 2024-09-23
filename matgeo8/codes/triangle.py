from ctypes import *
import matplotlib.pyplot as plt

# Load the shared object file
triangle = CDLL('./triangle.so')

# Define argument and return types for the C function
triangle.verifyPythagorasTheorem.argtypes = [c_double, c_double, 
                                             c_double, c_double, 
                                             c_double, c_double]
triangle.verifyPythagorasTheorem.restype = c_int

# Reading coordinates from coordinates.txt
with open('coordinates.txt', 'r') as file:
    A = list(map(float, file.readline().strip().split(',')))
    B = list(map(float, file.readline().strip().split(',')))
    C = list(map(float, file.readline().strip().split(',')))

Ax, Ay = A
Bx, By = B
Cx, Cy = C

# Call the C function to verify Pythagoras theorem
result = triangle.verifyPythagorasTheorem(Ax, Ay, Bx, By, Cx, Cy)

# Print result
if result == 1:
    print("Pythagoras theorem holds: b^2 = a^2 + c^2")
else:
    print("Pythagoras theorem does NOT hold.")

# Plot the triangle and label vertices with coordinates
x_vals = [Ax, Bx, Cx, Ax]  # Closing the triangle
y_vals = [Ay, By, Cy, Ay]

plt.plot(x_vals, y_vals, marker='o', color='b')  # Triangle edges and points

# Label vertices with coordinates
plt.text(Ax, Ay, f'A({Ax}, {Ay})', fontsize=12, ha='right')
plt.text(Bx, By, f'B({Bx}, {By})', fontsize=12, ha='right')
plt.text(Cx, Cy, f'C({Cx}, {Cy})', fontsize=12, ha='right')

plt.title("Triangle ABC")
plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.grid(True)
plt.show()

