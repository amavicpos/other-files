import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

fig, [ax1, ax2] = plt.subplots(nrows=2, ncols=1)
x1data, y1data, x2data, y2data = [], [], [], []
ln1, = ax1.plot([], [], 'ro')
ln2, = ax2.plot([], [], 'ko')

w = 5
k = 2*np.pi

def wave_equation(x, t, A=1, k=2*np.pi, w=2*np.pi, phi=0, dir=-1):
    return A*np.cos(k*x + dir*w*t + phi)

def init1():
    ax1.set_xlim(0, 2*np.pi/w)
    ax1.set_ylim(-1, 1)
    return ln1,

def update1(frame):
    x1data.append(frame)
    y1data.append(wave_equation(0, frame, w=w))
    ln1.set_data(x1data, y1data)
    return ln1,

def init2():
    ax2.set_xlim(0, 2*np.pi/k)
    ax2.set_ylim(-1, 1)
    return ln2,

def update2(frame):
    x2data.append(frame)
    y2data.append(wave_equation(frame, 0, k=k))
    ln2.set_data(x2data, y2data)
    return ln2,

ani1 = FuncAnimation(fig, update1, frames=np.linspace(0, 2*np.pi/w, 20),
                    init_func=init1, blit=True)
ani2 = FuncAnimation(fig, update2, frames=np.linspace(0, 2*np.pi/k, 20),
                    init_func=init2, blit=True)

ax1.set_xlabel('Time (s)')
ax1.set_ylabel('Amplitude (m)')

ax2.set_xlabel('Position x (m)')
ax2.set_ylabel('Amplitude (m)')

plt.show()

# TODO: Format plots
# TODO: Specify set t or x in plot automatically