from ctypes import *
import matplotlib.pyplot as plt

# Load the shared object file (pgm.so)
pgm = CDLL('./pgm.so')

# Define the Point structure to match the C structure
class Point(Structure):
    _fields_ = [("x", c_float), ("y", c_float)]

# Define the findVertexC function from the shared library
findVertexC = pgm.findVertexC
findVertexC.restype = Point
findVertexC.argtypes = [c_float, c_float, c_float, c_float, c_float, c_float]

# Given input values for vertices A, B, and D
x1, y1 = 3.0, 1.0  # Vertex A
x2, y2 = 5.0, 1.0  # Vertex B
x4, y4 = 4.0, 3.0  # Vertex D

# Call the C function to calculate vertex C
C = findVertexC(c_float(x1), c_float(y1), c_float(x2), c_float(y2), c_float(x4), c_float(y4))

# Print the coordinates of vertex C
print(f"Coordinates of vertex C: ({C.x}, {C.y})")

# Plotting the parallelogram
x_coords = [x1, x2, C.x, x4, x1]
y_coords = [y1, y2, C.y, y4, y1]

plt.figure()
plt.plot(x_coords, y_coords, marker='o')
plt.text(x1, y1, 'A', fontsize=12, ha='right')
plt.text(x2, y2, 'B', fontsize=12, ha='right')
plt.text(C.x, C.y, 'C', fontsize=12, ha='right')
plt.text(x4, y4, 'D', fontsize=12, ha='right')

plt.title("Parallelogram ABCD")
plt.xlabel("X")
plt.ylabel("Y")
plt.grid(True)
plt.show()

