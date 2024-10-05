from ctypes import *
import matplotlib.pyplot as plt
import numpy as np

# Load the shared object file
parab = CDLL('./parab.so')

# Define the argument and return types for the C function
parab.find_intersection.argtypes = [c_float, c_float, c_float, c_float, c_float,
                                    POINTER(c_float), POINTER(c_float),
                                    POINTER(c_float), POINTER(c_float), POINTER(c_int)]

# Variables to hold intersection points
x1 = c_float()
y1 = c_float()
x2 = c_float()
y2 = c_float()
num_points = c_int()

# Parameters for y=4x (line) and y=x^2 (parabola)
m = 4.0  # Slope of line
c = 0.0  # Intercept of line
a = 1.0  # Coefficient of x^2 in parabola
b = 0.0  # Coefficient of x in parabola
c_p = 0.0  # Constant term in parabola

# Call the function to find intersection points
parab.find_intersection(m, c, a, b, c_p, byref(x1), byref(y1), byref(x2), byref(y2), byref(num_points))

# Read additional points from coordinates.txt (assumed to be formatted as x, y per line)
coords = []
with open('coordinates.txt', 'r') as file:
    for line in file:
        x, y = map(float, line.split(','))
        coords.append((x, y))

# Prepare the plot
x_vals = np.linspace(-5, 5, 400)
y_parabola = x_vals**2  # Parabola y = x^2
y_line = 4 * x_vals  # Line y = 4x

plt.plot(x_vals, y_parabola, label="y = x^2 (Parabola)", color="blue")
plt.plot(x_vals, y_line, label="y = 4x (Line)", color="red")

# Prepare shading variables outside the conditions
x_fill = np.linspace(-5, 5, 400)
y_fill_line = 4 * x_fill
y_fill_parabola = x_fill**2

# Plot intersection points and join them with a line if there are two points
if num_points.value == 1:
    plt.scatter([x1.value], [y1.value], color='green', label=f'Intersection: ({x1.value:.2f}, {y1.value:.2f})')
    plt.annotate(f'({x1.value:.2f}, {y1.value:.2f})', (x1.value, y1.value), textcoords="offset points", xytext=(0,10), ha='center')
    # Shade the area between the parabola and line
    plt.fill_between(x_fill, y_fill_parabola, y_fill_line, where=(y_fill_parabola < y_fill_line), color='yellow', alpha=0.5, label='Shaded Area')

elif num_points.value == 2:
    plt.scatter([x1.value, x2.value], [y1.value, y2.value], color='green', label=f'Intersections: ({x1.value:.2f}, {y1.value:.2f}) and ({x2.value:.2f}, {y2.value:.2f})')
    plt.annotate(f'({x1.value:.2f}, {y1.value:.2f})', (x1.value, y1.value), textcoords="offset points", xytext=(0,10), ha='center')
    plt.annotate(f'({x2.value:.2f}, {y2.value:.2f})', (x2.value, y2.value), textcoords="offset points", xytext=(0,10), ha='center')
    
    # Join the intersection points with a line
    plt.plot([x1.value, x2.value], [y1.value, y2.value], color='green', linestyle='--', label='Line through intersections')
    
    # Shade the area between the parabola and the line
    x_fill = np.linspace(x1.value, x2.value, 400)
    y_fill_parabola = x_fill**2
    y_fill_line = 4 * x_fill
    plt.fill_between(x_fill, y_fill_parabola, y_fill_line, where=(y_fill_parabola < y_fill_line), color='yellow', alpha=0.5, label='Shaded Area')

# Mark the vertex of the parabola
vertex_x = 0
vertex_y = 0
plt.scatter([vertex_x], [vertex_y], color='orange', label='Vertex (0, 0)')
plt.annotate(f'({vertex_x}, {vertex_y})', (vertex_x, vertex_y), textcoords="offset points", xytext=(0,10), ha='center')

# Plot additional points from coordinates.txt
if coords:
    for coord in coords:
        plt.scatter(coord[0], coord[1], color='purple')
        plt.annotate(f'({coord[0]}, {coord[1]})', (coord[0], coord[1]), textcoords="offset points", xytext=(0,10), ha='center')

# Labels and legend
plt.xlabel('x')
plt.ylabel('y')
plt.title('Area between Line and Parabola')
plt.legend()

# Show the plot
plt.grid(True)
plt.show()

