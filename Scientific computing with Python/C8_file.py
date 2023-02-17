import numpy as np
import matplotlib.pyplot as plt

# Introduction, creating N-R function:


def Newton_Raphson(x1, n, func, deriv_func):
    x = x1
    for i in range(n - 1):
        delta = -func(x) / deriv_func(x)
        x += delta
    return x


def my_poly(x):
    return x**4 - 2 * x**3 - x**2 + 2 * x


def deriv_my_poly(x):
    return 4 * x**3 - 6 * x**2 - 2 * x + 2


x_values = np.linspace(-3, 3)
y_values = my_poly(x_values)

plt.plot(x_values, y_values)
plt.scatter((1 + np.sqrt(5)) / 2, my_poly((1 + np.sqrt(5)) / 2))
plt.show()

"""
If x1 = (1+np.sqrt(5))/2:
deriv_my_poly(x1) = 0 and Newton-Raphson diverges
"""

x1 = 3
n = 6

print(
    f"Root for first polynomial (x1 = {x1}, n = {n}): {Newton_Raphson(x1, n, my_poly, deriv_my_poly)}"
)

# First exercise:
def Newton_Raphson_acc(x1, acc, func, deriv_func):
    x = x1
    delta = -func(x) / deriv_func(x)
    while abs(delta) > acc:
        x += delta
        delta = -func(x) / deriv_func(x)
    return x


print(
    f"Square root of 17 (x1 = 4): {Newton_Raphson_acc(4, 1e-6, lambda x: x**2 - 17, lambda x: 2*x)}"
)
print(
    f"Cube root of 555 (x1 = 8): {Newton_Raphson_acc(8, 1e-6, lambda x: x**3 - 555, lambda x: 3*x**2)}\n"
)

# Second exercise:
def my_poly2(x):
    return (
        924 * x**6
        - 2772 * x**5
        + 3150 * x**4
        - 1680 * x**3
        + 420 * x**2
        - 42 * x
        + 1
    )


def deriv_my_poly2(x):
    return (
        5544 * x**5 - 13860 * x**4 + 12600 * x**3 - 5040 * x**2 + 840 * x - 42
    )


def numerical_deriv(x):
    h = 1e-4
    return (my_poly2(x + h / 2) - my_poly2(x - h / 2)) / h


for i in np.linspace(0, 1, num=6):
    print(
        f"Root for second polynomial (x1 = {i}, n = 6): {Newton_Raphson(i, 6, my_poly2, numerical_deriv)}"
    )

# Third exercise:
def secant_method(x_1, x_2, acc, func):
    x1 = x_1
    x2 = x_2
    delta = -func(x2) * (x2 - x1) / (func(x2) - func(x1))
    x3 = x2 + delta
    while abs(delta) > acc:
        x1 = x2
        x2 = x3
        delta = -func(x2) * (x2 - x1) / (func(x2) - func(x1))
        x3 = x2 + delta
    return x3


def Lagrange_point(r):
    G, R, M, m, w = 6.674e-11, 3.844e8, 5.974e24, 7.348e22, 2.662e-6
    return G * M * (R - r) ** 2 - G * m * r**2 - w**2 * r**3 * (R - r) ** 2


print(
    f"\nLagrange point (x1 = 1e6, x2 = 1e10): {secant_method(1e6, 1e10, 1e-4, Lagrange_point)} m"
)
