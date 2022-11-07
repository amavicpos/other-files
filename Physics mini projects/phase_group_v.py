import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# TODO: Format plots
# TODO: Specify set t or x in plot automatically

w, w2 = 2*np.pi, 2*np.pi+0.1
k, k2 = 2*np.pi, 2*np.pi+0.1
T1, T2 = 2*np.pi/w, 2*np.pi/w2
l1, l2 = 2*np.pi/k, 2*np.pi/k2
N = 10

def wave_equation(x, t, A=1, k=2*np.pi, w=2*np.pi, phi=0, dir=-1):
    return A*np.cos(k*x + dir*w*t + phi)

""" for i, j in zip(np.linspace(0, l1, num=N), np.linspace(0, T1, num=N)):
    x1.append(i)
    t1.append(j)
for i, j in zip(np.linspace(0, l2, num=N), np.linspace(0, T2, num=N)):
    x2.append(i)
    t2.append(j)

for i in range(len(x1)):
    y1_x, y2_x = [], []
    for j in range(len(t1)):
        y1_x.append(wave_equation(x1[i], t1[j], k=k, w=w))
        y2_x.append(wave_equation(x2[i], t2[j], k=k2, w=w2))
    y1.append(y1_x)
    y2.append(y2_x) """

def data_gen():
    x1, t1, x2, t2, y1, y2 = [], [], [], [], [], []
    for i, j in zip(np.linspace(0, l1, num=N), np.linspace(0, T1, num=N)):
        x1.append(i)
        t1.append(j)
    for i, j in zip(np.linspace(0, l2, num=N), np.linspace(0, T2, num=N)):
        x2.append(i)
        t2.append(j)

    for i in range(len(x1)):
        y1_x, y2_x = [], []
        for j in range(len(t1)):
            y1_x.append(wave_equation(x1[i], t1[j], k=k, w=w))
            y2_x.append(wave_equation(x2[i], t2[j], k=k2, w=w2))
            yield x1[i], t1[j], x2[i], t2[j], y1_x[j], y2_x[j]
        y1.append(y1_x)
        y2.append(y2_x)

# create a figure with two subplots
fig, (ax1, ax2) = plt.subplots(2,1)

# intialize two line objects (one in each axes)
line1, = ax1.plot([], [], lw=2)
line2, = ax2.plot([], [], lw=2, color='r')
line = [line1, line2]

ax1.set_ylim(-1, 1)
ax1.set_xlim(0, 2*np.pi/w)
ax1.grid()
ax2.set_ylim(-1, 1)
ax2.set_xlim(0, 2*np.pi/k)
ax2.grid()

# initialize the data arrays 
tdata, xdata, y1data, y2data = [], [], [], []
def run(data):
    # update the data
    x1, t1, x2, t2, y1, y2 = data

    # axis limits checking. Same as before, just for both axes
    for ax in [ax1, ax2]:
        xmin, xmax = ax.get_xlim()
        if t1 >= xmax:
            ax.set_xlim(xmin, 2*xmax)
            ax.figure.canvas.draw()

    # update the data of both line objects
    line[0].set_data(t1, y1[0])
    line[1].set_data(t2, y2[0])

    return line

ani = animation.FuncAnimation(fig, run, data_gen, blit=True, interval=10,
    repeat=False)
plt.show()
