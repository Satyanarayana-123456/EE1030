import matplotlib.pyplot as plt

# Reading coordinates from the file
coordinates = {}
with open("coordinates.txt", "r") as f:
    for line in f:
        name, coord = line.strip().split('(')
        x, y = map(int, coord[:-1].split(','))
        coordinates[name] = (x, y)

# Extracting the coordinates
A = coordinates['A']
B = coordinates['B']
C = coordinates['C']
D = coordinates['D']

# Plotting the parallelogram
plt.figure()
plt.plot([A[0], B[0], C[0], D[0], A[0]], [A[1], B[1], C[1], D[1], A[1]], 'bo-')

# Annotating the vertices
plt.text(A[0], A[1], f"A{A}", fontsize=12, ha='right')
plt.text(B[0], B[1], f"B{B}", fontsize=12, ha='right')
plt.text(C[0], C[1], f"C{C}", fontsize=12, ha='right')
plt.text(D[0], D[1], f"D{D}", fontsize=12, ha='right')

# Adding grid and labels
plt.grid(True)
plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.title("Parallelogram ABCD")
plt.axis('equal')

# Show plot
plt.show()

