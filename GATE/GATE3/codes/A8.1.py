import numpy as np
import matplotlib.pyplot as plt

# Generate the range for wt from 0 to 2π
wt = np.linspace(0, 2 * np.pi, 1000)

# Calculate the function 5sin(wt)
y = 5 * np.sin(wt)

# Plot the function
plt.plot(wt, y, color='black')

# Add labels and title
plt.xlabel(r'$wt$')


# Add x and y axes lines
plt.axhline(0, color='black', linewidth=1)
plt.axvline(0, color='black', linewidth=1)

# Add dashed lines from the top (y=5) and bottom (y=-5) of the curve to the y-axis
plt.plot([np.pi/2, 0], [5, 5], color='black', linewidth=1.5, linestyle=':')
plt.plot([3*np.pi/2, 0], [-5, -5], color='black', linewidth=1.5, linestyle=':')

#plt.scatter([0, np.pi, 2 * np.pi], [0, 0, 0], color='black')
plt.annotate(r'$0$', xy=(0+0.2, 0), xytext=(0, -0.5), textcoords='offset points', ha='center', fontsize=10, color='black')
plt.annotate(r'$\pi$', xy=(np.pi+0.2, 0), xytext=(0, -0.5), textcoords='offset points', ha='center', fontsize=10, color='black')
plt.annotate(r'$2\pi$', xy=(2 * np.pi+0.2, 0), xytext=(0, -0.5), textcoords='offset points', ha='center', fontsize=10, color='black')
plt.annotate(r'$+5 V$', xy=(0, 5), xytext=(-30, 5), textcoords='offset points', ha='center', fontsize=10, color='black')
plt.annotate(r'$-5 V$', xy=(0, -5), xytext=(-30, -5), textcoords='offset points', ha='center', fontsize=10, color='black')


# Show the grid and legend
plt.grid(True)

# Show the plot
plt.show()

