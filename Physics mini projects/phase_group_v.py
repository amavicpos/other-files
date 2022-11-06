import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# TODO: Format plots
# TODO: Specify set t or x in plot automatically

w = 5
k = 2*np.pi

def wave_equation(x, t, A=1, k=2*np.pi, w=2*np.pi, phi=0, dir=-1):
    return A*np.cos(k*x + dir*w*t + phi)

def data_gen():
    t = data_gen.t
    x = data_gen.x
    cnt = 0
    while cnt < 1e6:
        cnt+=1
        t += 2*np.pi/w/100
        x += 2*np.pi/k/100
        y1 = wave_equation(0, t)
        y2 = wave_equation(x, 0)
        # adapted the data generator to yield both sin and cos
        yield t, x, y1, y2

data_gen.t = 0
data_gen.x = 0

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
    t, x, y1, y2 = data
    tdata.append(t)
    xdata.append(x)
    y1data.append(y1)
    y2data.append(y2)

    # axis limits checking. Same as before, just for both axes
    for ax in [ax1, ax2]:
        xmin, xmax = ax.get_xlim()
        if t >= xmax:
            ax.set_xlim(xmin, 2*xmax)
            ax.figure.canvas.draw()

    # update the data of both line objects
    line[0].set_data(tdata, y1data)
    line[1].set_data(xdata, y2data)

    return line

ani = animation.FuncAnimation(fig, run, data_gen, blit=True, interval=10,
    repeat=False)
plt.show()