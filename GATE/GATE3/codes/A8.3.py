import numpy as np
import matplotlib.pyplot as plt

# Define the time range
wt = np.linspace(0, 2*np.pi, 1000)

# Define the waveform
y = np.zeros_like(wt)
y[(wt <= 0.1931*np.pi) & (wt >= 0)] = 10 * np.sin(wt[(wt <= 0.1931*np.pi) & (wt >= 0)])
y[(wt > 0.1931*np.pi) & (wt < 0.807*np.pi)] = 5.7
y[(wt >= 0.807*np.pi) & (wt <= 2*np.pi)] = 10 * np.sin(wt[(wt >= 0.807*np.pi) & (wt <= 2*np.pi)])

# Plot the function
plt.plot(wt, y, color='black')

# Add labels and title
plt.xlabel(r'$wt$')

# Add x and y axes lines
plt.axhline(0, color='black', linewidth=1)
plt.axvline(0, color='black', linewidth=1)
plt.plot([3*np.pi/2, 0], [-10, -10], color='black', linewidth=1.5, linestyle=':')


plt.annotate(r'$0$', xy=(0+0.2, 0), xytext=(0, -0.5), textcoords='offset points', ha='center', fontsize=10, color='black')
plt.annotate(r'$\pi$', xy=(np.pi+0.2, 0), xytext=(0, -0.5), textcoords='offset points', ha='center', fontsize=10, color='black')
plt.annotate(r'$2\pi$', xy=(2 * np.pi+0.2, 0), xytext=(0, -0.5), textcoords='offset points', ha='center', fontsize=10, color='black')
plt.annotate(r'$+5.7 V$', xy=(0, 5.7), xytext=(-30, 5), textcoords='offset points', ha='center', fontsize=10, color='black')
plt.annotate(r'$-10 V$', xy=(0, -10), xytext=(-30, -5), textcoords='offset points', ha='center', fontsize=10, color='black')

# Add grid lines
plt.grid(True)

# Show the plot
plt.show()

