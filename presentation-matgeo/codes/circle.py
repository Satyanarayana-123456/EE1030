from ctypes import *
import numpy as np
import matplotlib.pyplot as plt

circle_lib = CDLL('./circle.so')

circle_lib.findCenter.argtypes = [c_float, c_float, c_float,
                                  c_float, c_float, c_float,
                                  POINTER(c_float), POINTER(c_float)]

circle_lib.calculateRadius.argtypes = [c_float]
circle_lib.calculateRadius.restype = c_float

a1, b1, c1 = 2.0, -3.0, -5.0  
a2, b2, c2 = 3.0, -4.0, -7.0  
area = 154.0  
centerX = c_float(0)
centerY = c_float(0)

circle_lib.findCenter(a1, b1, c1, a2, b2, c2, byref(centerX), byref(centerY))
centerX = centerX.value
centerY = centerY.value

radius = circle_lib.calculateRadius(area)

points = np.loadtxt("coordinates.txt", delimiter=",", unpack=False)

plt.figure()
plt.plot(points[:, 0], points[:, 1], color='green', label=f"Circle: (x - 1)^2 + (y + 1)^2 = 49")
plt.scatter(centerX, centerY, color='blue', s=100, label="Center", edgecolor='black')  
plt.text(centerX, centerY, f"({centerX:.2f}, {centerY:.2f})", fontsize=10, ha='right', color='black')

plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.title("Circle")
plt.legend(loc='upper right')
plt.gca().set_aspect('equal', adjustable='box')
plt.grid(True)
plt.show()

