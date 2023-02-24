import numpy as np
import matplotlib.pyplot as plt

# EXERCISE 5:

time, speed = np.loadtxt("data/particle_velocity.dat", skiprows=1, unpack=True)

h = (time[-1] - time[0])/(len(time) - 1)
dist = 0
distance = [dist]

for i in range(len(time) - 1):
    dist += abs(h * (speed[i] + speed[i+1]) / 2)
    distance.append(dist)

fig = plt.figure(figsize=(10,6))
ax1 = fig.add_subplot(1,2,1)
ax2 = fig.add_subplot(1,2,2)
ax1.plot(time, speed)
ax1.set_ylabel('Speed (m/s)')
ax1.set_xlabel('Time (s)')
ax2.plot(time, distance)
ax2.set_ylabel('Distance (m)')
ax2.set_xlabel('Time (s)')
plt.show()
