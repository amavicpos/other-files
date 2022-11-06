import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

fig, ax = plt.subplots()
tdata, ydata = [], []
ln, = ax.plot([], [], 'ro')

w = 5

def wave_equation(x, t, A=1, k=2*np.pi, w=2*np.pi, phi=0, dir=-1):
    return A*np.cos(k*x + dir*w*t + phi)

def init():
    ax.set_xlim(0, 2*np.pi/w)
    ax.set_ylim(-1, 1)
    return ln,

def update(frame):
    tdata.append(frame)
    ydata.append(wave_equation(0, frame, w=w))
    ln.set_data(tdata, ydata)
    return ln,

ani = FuncAnimation(fig, update, frames=np.linspace(0, 2*np.pi/w, 20),
                    init_func=init, blit=True)
plt.show()

# TODO: Subplots: function of t and function of x
# TODO: Format plots