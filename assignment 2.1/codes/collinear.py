from ctypes import*
import numpy as np
import matplotlib.pyplot as plt

# Load the shared library
collinear = CDLL('./collinear.so')

# Define the function signature for find_relation
# float find_relation(float x1, float y1, float x2, float y2, float x, float y)
collinear.find_relation.argtypes = (c_float, c_float, c_float, c_float, c_float, c_float)
collinear.find_relation.restype = c_float

# Given points B(-4, 6) and C(-2, 3)
x1, y1 = -4, 6
x2, y2 = -2, 3

# Find the relation for a range of x values
x_values = np.linspace(-10, 10, 400)
y_values = []

for x in x_values:
    # Assume some y value; we'll just use x itself for plotting purposes
    y = x  
    relation = collinear.find_relation(x1, y1, x2, y2, x, y)
    y_values.append(y - relation / (x2 - x1))  # Adjust y to satisfy the relation

y_values = np.array(y_values)

# Plotting the results
plt.figure(figsize=(8, 6))

# Plot the line of relation
plt.plot(x_values, y_values, label='Line of relation', color='blue')

# Highlight points B and C
plt.scatter([x1, x2], [y1, y2], color='red', zorder=5)
plt.text(x1, y1, 'B(-4, 6)', fontsize=12, ha='right')
plt.text(x2, y2, 'C(-2, 3)', fontsize=12, ha='right')

plt.axhline(0, color='black',linewidth=0.5)
plt.axvline(0, color='black',linewidth=0.5)

plt.xlabel('x')
plt.ylabel('y')
plt.title('Relation between x and y')
plt.legend()
plt.grid(True)
plt.show()

