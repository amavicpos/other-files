import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# TODO: Plot more than one curve in same graph
# TODO: Plot oscillation inside and envelope separately
# TODO: Format plot

T1, T2 = 1, 1
l1, l2 = 1, 1
w1, w2 = 2*np.pi/T1, 2*np.pi/T2
k1, k2 = 2*np.pi/l1, 2*np.pi/l2
x_range = np.linspace(0, l1*100, 100)
t_range = np.linspace(0, T1*100, 100)
A=1

def sum_wave(x, t, A=1, k1=2*np.pi, k2=2*np.pi, w1=2*np.pi, w2=2*np.pi):
    return 2*A*np.cos((k1-k2)/2*x-(w1-w2)/2*t)*np.cos((k1+k2)/2*x-(w1+w2)/2*t)

matrix_ = np.matrix([[sum_wave(x, t, A, k1, k2, w1, w2) for x in x_range] for t in t_range])

fig, ax = plt.subplots()
xdata, ydata = [], []
ln, = ax.plot([], [], 'r')

def init():
    ax.set_xlim(0, l1*100)
    ax.set_ylim(-2*A, 2*A)
    return ln,

def update(frame):
    ln.set_data(x_range, matrix_[frame])
    return ln,

ani = FuncAnimation(fig, update, frames=range(len(matrix_)),
                    init_func=init, blit=True)
plt.show()
