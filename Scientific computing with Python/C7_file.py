import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
import random as rd

# READING AND WRITING TO A FILE
rho, rad = np.loadtxt("data/data_1.dat", skiprows=1, unpack=True)
t, h, u = np.loadtxt("data/data_2.dat", skiprows=2,
                     delimiter=",", unpack=True)
out_array = np.array([t, h, u])
# np.savetxt("data/test_out.dat", out_array.T, fmt="%8.1f")


# GRAPH PLOTTING
plt.plot(t, h)
plt.show()

t = np.linspace(-10.0, 10.0, 200)            # create t array of theory data
v = np.sin(t) * np.exp(-(t/5.0)**2)  # "    v array      "    "

plt.figure(1, figsize=(8, 6))              # create plot, specifying size
plt.plot(t, v, "b-", label="theory")         # "b-", colour blue, solid line

plt.xlabel('Time (ms)')
plt.ylabel('Transverse Displacement (volts)')
plt.legend(loc="upper right")

plt.axhline(color="gray", zorder=-1)         # horizontal line
plt.axvline(color="gray", zorder=-1)         # vertical line

# saves file; could be .pdf, .jpg
plt.savefig("data/wavy_pulse.png")

plt.show()                                   # display plot on screen

t_data, v_data = np.loadtxt("data/pulse_data.dat", skiprows=2, unpack=True)
plt.plot(t_data, v_data, "ro")
plt.errorbar(t_data, v_data, fmt="ro", label="expt", xerr=0.5, ecolor="black")
plt.show()

x_data = np.random.uniform(0.0, 100.0, 20)
y_data = 3.0 * x_data + 35.0 + np.random.uniform(-15.0, 15.0, 20)
eb = np.repeat(15.0, 20)
plt.errorbar(x_data, y_data, yerr=eb, fmt="x")


# LINEAR REGRESSION

def str_line(x, m, c):
    return m * x + c


popt, pcov = curve_fit(str_line, x_data, y_data, sigma=None)
print("Linear Regression:")
print("a =", popt[0], "+/-", pcov[0, 0]**0.5)
print("b =", popt[1], "+/-", pcov[1, 1]**0.5)
x_line = np.linspace(0.0, 100.0, 100)  # define a set of x-values
plt.plot(x_line, str_line(x_line, *popt), 'r-')  # y-values using str_line()
plt.show()


# EXERCISES
# Monte Carlo
def estimation_pi(N):
    radius = 1
    x_points, y_points = [
        rd.uniform(-1, 1) for i in range(int(N))], [rd.uniform(-1, 1) for i in range(int(N))]
    circ = sum(1 for x, y in zip(x_points, y_points) if (x ** 2 + y ** 2) <= radius)
    x_circle = [np.cos(v) for v in np.arange(0, np.pi * 2, 0.01)]
    y_circle = [np.sin(v) for v in np.arange(0, np.pi * 2, 0.01)]
    plt.scatter(x_points, y_points)
    plt.plot(x_circle, y_circle, 'r')
    plt.axis('square')
    plt.show()
    return circ/N*4

estimate_e4 = estimation_pi(1e4)
print("\nMonte Carlo:")
print(f"Percentage of points inside circle: {round(estimate_e4/4*100, 1)}%")
print(f"Theoretical percentage: {round(np.pi/4*100, 1)}%")
print(f"Estimate of pi: {estimate_e4}\n")

# Stefan's Law
T, P = np.loadtxt("data/stefan.dat", skiprows=2, unpack=True)
logT, logP = np.log10(T), np.log10(P)
plt.plot(logT, logP)
plt.xlabel('log(T)')
plt.ylabel('log(P)')
plt.show()
popt, pcov = curve_fit(str_line, logT, logP, sigma=None)
print("Stefan's Law, linear regression, a is the calculated exponent of T:")
print("a =", popt[0], "+/-", pcov[0, 0]**0.5)
print("b =", popt[1], "+/-", pcov[1, 1]**0.5)

# Estimation of e
def estimation_e(epsilon):
    last_second_term = 1
    last_term = 2
    index = 2
    while(abs(last_second_term - last_term) > epsilon):
        last_second_term = last_term
        last_term += 1/np.math.factorial(index)
        index += 1
    return last_term

accuracy = 1e-4
print(f"\nEstimate of e: {round(estimation_e(accuracy), int(np.log10(1/accuracy)))}")
