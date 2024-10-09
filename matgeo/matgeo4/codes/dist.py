from ctypes import*
import matplotlib.pyplot as plt

# Load the shared object (dist.so) compiled from dist.c
dist_lib = CDLL('./dist.so')

# Define argument and return types for the C distance function
dist_lib.distance.argtypes = [c_double, c_double, c_double, c_double]
dist_lib.distance.restype = c_double

# Points A(0,6) and B(0,-2)
x1, y1 = 0, 6
x2, y2 = 0, -2

# Calculate the distance using the C function
distance_AB = dist_lib.distance(x1, y1, x2, y2)

# Plot the points A and B
plt.plot([x1, x2], [y1, y2], 'bo-', label=f'Distance = {distance_AB:.2f}')
plt.text(x1, y1, 'A(0,6)', fontsize=12, verticalalignment='bottom', horizontalalignment='right')
plt.text(x2, y2, 'B(0,-2)', fontsize=12, verticalalignment='top', horizontalalignment='right')

# Plot settings
plt.title('Line joining A(0, 6) and B(0, -2)')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.axhline(0, color='black',linewidth=0.5)
plt.axvline(0, color='black',linewidth=0.5)
plt.grid(True)
plt.legend()
plt.show()

# Print the distance
print(f"Distance between A(0, 6) and B(0, -2) = {distance_AB:.2f}")

