from C9_file import trapezium_integration

# EXERCISE 4:


def trapezium_integration_tol(func, a, h, tol) -> float:
    """
    Parameters
    ----------
    func : function
        Function to integrate.
    a : float
        Lower limit of integral.
    h : float
        Separation between evaluated x values.
        It is related to the precision of the integral.
    tol : float
        Tolerance, also related to the precision in a different way
        (sets limit in x values). When the program reaches a difference of
        two consecutive trial integrals smaller than this, the current
        result is returned.

    Returns
    -------
    float
    Value of the improper integral using the trapezium rule.

    """
    int1 = trapezium_integration(func, a, a+h, 1)
    b = a + 2*h
    int2 = trapezium_integration(func, a, b, 2)
    while (abs(int2 - int1) > tol):
        b += h
        int1 = int2
        int2 = trapezium_integration(func, a, b, int((b-a)/h))
    return int2


def my_func(x):
    return 1/(1+x**2)


print(trapezium_integration_tol(my_func, 0, 0.01, 1e-6))
# Sometimes it might seem like a larger h returns a higher precision,
# comparing the result with the analytical integral. This can happen
# because the trapezium rule is underestimating the integral and a larger
# h gives less trapeziums and, depending on the curvature of the function,
# this makes the trapezium rule to overestimate the integral.

# A higher tolerance forces a significantly higher runtime.
