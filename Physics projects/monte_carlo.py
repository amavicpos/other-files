import numpy as np
from numpy import random as rd
import math
from matplotlib import pyplot as plt
import time

# Plot: https://youtu.be/iZ8RhlBq4g0
# Theory: https://youtu.be/EaR3C4e600k

# Develop: changeable radius/side size, format plots, give physical meaning

start_time = time.time()

N, circ = 200, 0
x_points, y_points = [None]*N, [None]*N
inside_circle = lambda x, y: (x ** 2 + y ** 2) <= 1

fig = plt.figure(figsize=(10,6))
ax1 = fig.add_subplot(2,1,1)
ax1.axis('square')
ax1.set_xlim(-1, 1)
ax1.set_ylim(-1, 1)
ax2 = fig.add_subplot(2,1,2)
ax2.plot(range(1, N+1, 1), [math.pi / 4 * 100]*N)

for i in range(1, N+1, 1):
    x = 2 * rd.rand() - 1
    y = 2 * rd.rand() - 1
    x_points[i-1] = x
    y_points[i-1] = y
    if inside_circle(x, y):
        circ += 1
        ax1.scatter(x, y, c='r')
    else: ax1.scatter(x, y, c='b')
    ax2.scatter(i, circ/i * 100, c='r', s=7)
    plt.pause(0.001)

end_time = time.time()
print('Time of execution:', end_time - start_time)
plt.show()

# To plot limiting circle
""" x_circle = [math.cos(v) for v in np.arange(0, math.pi * 2, 0.01)]
y_circle = [math.sin(v) for v in np.arange(0, math.pi * 2, 0.01)]
plt.plot(x_circle, y_circle, '-k') """

# To plot everything at once
""" coor_in = np.array([[x, y] for x, y in zip(x_points, y_points) if inside_circle(x, y)])
coor_out = np.array([[x, y] for x, y in zip(x_points, y_points) if not inside_circle(x, y)])
plt.scatter(coor_in[:, 0], coor_in[:, 1], c='r')
plt.scatter(coor_out[:, 0], coor_out[:, 1], c='b')
plt.axis('square')
print('How many points lie randomly inside the circle?')
print('Theoretical result:', math.pi / 4 * 100, '%')
print('Numerical result (number of points = {}):'.format(N), circ/N * 100, '%\n') """
