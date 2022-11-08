import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# TODO: Improve shape of function, ensure it's correct
# TODO: Format plot

A = 1
N = 100
w1, w2 = 1, 1.001
k1, k2 = 1, 1.001
T1, T2 = 2*np.pi/w1, 2*np.pi/w2
l1, l2 = 2*np.pi/k1, 2*np.pi/k2
x_range = np.linspace(0, l1*1000, N)
t_range = np.linspace(0, T1*1000, N)

def envelope(x, t, A=1, k1=2*np.pi, k2=2*np.pi, w1=2*np.pi, w2=2*np.pi):
    return 2*A*np.cos((k1-k2)/2*x+(w1-w2)/2*t)

def sum_wave(x, t, A=1, k1=2*np.pi, k2=2*np.pi, w1=2*np.pi, w2=2*np.pi):
    return envelope(x, t, A, k1, k2, w1, w2)*np.cos((k1+k2)/2*x-(w1+w2)/2*t)

envelope_ = np.zeros((N,)*2)
sum_wave_ = np.zeros((N,)*2)
for i, t in enumerate(t_range):
    for j, x in enumerate(x_range):
        envelope_[i][j] = envelope(x, t, A, k1, k2, w1, w2)
        sum_wave_[i][j] = sum_wave(x, t, A, k1, k2, w1, w2)

fig, ax = plt.subplots()
ln1, = ax.plot([], [], 'b')
ln2, = ax.plot([], [], 'r')

def init():
    ax.set_xlim(0, l1*1000)
    ax.set_ylim(-3*A, 3*A)
    return ln1, ln2,

def update(frame):
    ln1.set_data(x_range, envelope_[frame])
    ln2.set_data(x_range, sum_wave_[frame])
    return ln1, ln2,

ani = FuncAnimation(fig, update, frames=range(N), init_func=init, blit=True)
plt.show()
