import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import time

# TODO: Change values, plot different cases
# TODO: Format plot

A = 1
N = 500
w1, w2 = 1.001, 1
k1, k2 = 1.001, 1
l_env = 2*np.pi/((k1-k2)/2)
T_env = 2*np.pi/((w1-w2)/2)
x_range = np.linspace(0, l_env*2, N)
t_range = np.linspace(0, T_env*5, N)

#start_time = time.time()

envelope_ = [[2*A*np.cos((k1-k2)/2*x+(w1-w2)/2*t) for x in x_range] for t in t_range]
sum_wave_ = [[envelope_[i][j]*np.cos((k1+k2)/2*x-(w1+w2)/2*t) for j, x in enumerate(x_range)] for i, t in enumerate(t_range)]

""" end_time = time.time()
print(end_time - start_time) """

fig, ax = plt.subplots()
ln1, = ax.plot([], [], 'b')
ln2, = ax.plot([], [], 'r')

def init():
    ax.set_xlim(0, l_env*2)
    ax.set_ylim(-3*A, 3*A)
    return ln1, ln2,

def update(frame):
    ln1.set_data(x_range, envelope_[frame])
    ln2.set_data(x_range, sum_wave_[frame])
    return ln1, ln2,

ani = FuncAnimation(fig, update, frames=range(N), init_func=init, blit=True)
plt.show()
