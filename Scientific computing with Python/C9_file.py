import numpy as np
import matplotlib.pyplot as plt


# CREATE THE FUNCTION FOR THE TRAPEZIUM INTEGRATION:

def trapezium_integration(func, a, b, N) -> float:
    """
    Parameters
    ----------
    func : function
        Function to integrate.
    a : float
        Lower limit of integral.
    b : float
        Upper limit of integral.
    N : int
        Number of trapeziums.

    Returns
    -------
    float
    Value of the integral using the trapezium rule.

    """
    x_values = np.linspace(a, b, N+1)
    return (b - a)/N * (0.5 * func(a) + 0.5 *
                        func(b) + sum(func(x_values[1:-1])))

# EXERCISE 2:

# Useful code:
# t = np.arange(0.01, 20.0, 0.01)             # evenly spaced set of t-values

# #linear plot
# plt.subplot(221)                            # 2x2 grid of plots; plot 1
# plt.plot(t, np.exp(-t/5.0))                 # linear plot of decaying exponential
# plt.title('linear plot')
# plt.grid(True)

# # log y axis
# plt.subplot(222)                            # 2x2 grid of plots; plot 2
# plt.semilogy(t, np.exp(-t/5.0))             # straight line on a log y plot
# plt.title('semi-log y')
# plt.grid(True)

# # log x axis
# plt.subplot(223)                           # 2x2 grid of plots; plot 3
# plt.semilogx(t, np.sin(2*np.pi*t))
# plt.title('semi-log x')
# plt.grid(True)

# # log x and y axis
# plt.subplot(224)                          # 2x2 grid of plots; plot 4
# plt.loglog(t, (3.0*t**1.5))               # straight line on a log-log plot
# plt.grid(True)
# plt.title('log-log plot')

# plt.tight_layout()               #  automatically adjusts space between plots

# plt.show()                       #  always put this at the end


def my_func(x):
    return x**4 - 2*x + 1


a, b = 0, 2
Ns = [100, 200, 400, 800]
answers = [trapezium_integration(my_func, a, b, N) for N in Ns]

plt.scatter(Ns, answers, marker='x')
plt.xlabel("N")
plt.ylabel("Answer")
plt.xlim(80, 1200)
plt.ylim(4.398, 4.402)
plt.xscale('log')
plt.axhline(y=4.40, ls='--')
plt.show()

# EXERCISE 3:


def my_func2(t):
    return np.exp(-t**2)


x_vals = np.arange(0, 3, 0.1)
E_vals = [trapezium_integration(my_func2, 0, x, 100) for x in x_vals]
plt.scatter(x_vals, E_vals)
plt.xlabel("x")
plt.ylabel("E")
plt.show()
