#include <iostream>
#include <cmath>
using namespace std;
const int n = 20; // numero de ecuaciones del sistema
const double PI = 4.0 * atan(1.0);
double f2(double x);
double derivada1(double (*f)(double), double x);

int main()
{
    double x[n], b[n];
    for (int i = 0; i < n; ++i)
    {
        x[i] = i + 1;
        cout << x[i] << " ";
    }
    for (int i = 0; i < n; ++i)
    {
        b[i] = derivada1(f2, x[i]);
        cout << b[i] << " ";
    }
    return 0;
}

double f2(double x)
{
    return pow(x, 2);
}

double derivada1(double (*f)(double), double x)
{                               // como el prototipo de la funci�n, pero con el nombre de la funci�n entre ( ) y precedido de *
    double h = 0.0001 * x, aux; // x distinto de cero
    aux = (f(x + h) - f(x)) / h;
    return aux;
}
