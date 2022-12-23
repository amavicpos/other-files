import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import time

""" v_phase = (w1+w2)/(k1+k2) and v_group = (w1-w2)/(k1-k2)
Some cases to consider:
    - v_group < 0 and v_phase > 0
    - v_group > 0 and v_phase > 0
    - v_group = 0 and v_phase > 0: w1 very close to w2
    - v_group > v_phase
    - v_group < v_phase
    - v_group = v_phase """

A = 1
N = 500
w1, w2 = 1.001, 1
k1, k2 = 1.001, 1
try:
    l_env = np.abs(2*np.pi/((k1-k2)/2))
except:
    print("Equal k1 and k2 produce errors.")
    quit()
try:
    T_env = np.abs(2*np.pi/((w1-w2)/2))
except:
    print("Equal w1 and w2 produce errors.")
    quit()

x_lim = l_env*2
x_range = np.linspace(0, x_lim, N)
t_range = np.linspace(0, T_env*5, N)

#start_time = time.time()

envelope_ = [2*A*np.cos((k1-k2)/2*x_range+(w1-w2)/2*t) for t in t_range]
sum_wave_ = [envelope_[i]*np.cos((k1+k2)/2*x_range-(w1+w2)/2*t) for i, t in enumerate(t_range)]

""" end_time = time.time()
print(end_time - start_time) """

fig, ax = plt.subplots()
ln1, = ax.plot([], [], 'b')
ln2, = ax.plot([], [], 'r')

def init():
    ax.set_xlim(0, x_lim)
    ax.set_ylim(-3*A, 3*A)
    return ln1, ln2,

def update(frame):
    ln1.set_data(x_range, envelope_[frame])
    ln2.set_data(x_range, sum_wave_[frame])
    return ln1, ln2,

ani = FuncAnimation(fig, update, frames=range(N), init_func=init, blit=True)
plt.xlabel('x position')
plt.ylabel('y position')
plt.legend(['Envelope', 'Superposition of waves'])
plt.show()
