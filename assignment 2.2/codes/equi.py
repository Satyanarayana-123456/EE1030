from ctypes import*
import matplotlib.pyplot as plt

# Load the shared object files
equi = CDLL('./equi.so')
verify = CDLL('./verify.so')

# Define argument and return types for the shared object functions
equi.calculate_relation.argtypes = (c_float, c_float, c_float, c_float,
                                    POINTER(c_float), POINTER(c_float),
                                    POINTER(c_float))

verify.verify_coordinates.argtypes = (c_float, c_float, c_float,
                                       POINTER(c_float), POINTER(c_int))

# Coordinates of points B and C
x1, y1 = 7.0, 1.0
x2, y2 = 3.0, 5.0

# Variables to hold the coefficients
m = c_float()
n = c_float()
p = c_float()

# Calculate the relation coefficients using equi.so
equi.calculate_relation(c_float(x1), c_float(y1),
                        c_float(x2), c_float(y2),
                        byref(m), byref(n), byref(p))

# Read coordinates from coordinates.txt
with open("coordinates.txt", "r") as file:
    coord1 = file.readline().strip().split(',')
    coord2 = file.readline().strip().split(',')
    coord3 = file.readline().strip().split(',')

x1_coord, y1_coord = float(coord1[0]), float(coord1[1])
x2_coord, y2_coord = float(coord2[0]), float(coord2[1])
x3_coord, y3_coord = float(coord3[0]), float(coord3[1])

# Prepare data for verification
coords_array = (c_float * 2)(x1_coord, y1_coord)
result = c_int()

# Verify the first coordinate using the shared object
verify.verify_coordinates(m.value, n.value, p.value, coords_array, byref(result))

# Print verification result for the first coordinate
print(f"Verification result for Point ({x1_coord}, {y1_coord}): {bool(result.value)}")

# Plotting
plt.figure()

# Plot the fully extended line corresponding to the relation
x_vals = [min(x1, x2) - 10, max(x1, x2) + 10]
y_vals = [(p.value - m.value * x) / n.value for x in x_vals]
plt.plot(x_vals, y_vals, label='Relation Line', color='blue')

# Plot the coordinates from coordinates.txt
plt.scatter([x1_coord, x2_coord, x3_coord], [y1_coord, y2_coord, y3_coord], color='green', label='Coordinates from file')

# Plot points B and C
plt.scatter([x1, x2], [y1, y2], color='red', label='B(7,1) & C(3,5)', marker='o')

# Avoid duplicate labels in legend
handles, labels = plt.gca().get_legend_handles_labels()
by_label = dict(zip(labels, handles))
plt.legend(by_label.values(), by_label.keys())

plt.xlabel('x')
plt.ylabel('y')
plt.title('Graph of the Relation and Points')
plt.grid(True)
plt.show()

