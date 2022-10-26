#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
double f(double x, double k);
double trapezoidal(double (*f)(double, double), double a, double b, double k, int n);
//(double (*f) (double, double) esto quiere decir que los argumentos de la funci�n f no son datos num�ricos
// sino una funci�n cuyos argumentos son n�meros decimales (double)
double simpson1(double (*f)(double, double), double a, double b, double k, int n);
double simpson2(double (*f)(double, double), double a, double b, double k, int n);
double cgaussiana1(double (*f)(double, double), double a, double b, double k);
double cgaussiana2(double (*f)(double, double), double a, double b, double k);
const double PI = 2.0 * asin(1.0), factor = PI / 180;
double k, a = 0, b = PI / 2, integral1, integral2, integral3, integral4, integral5;
int np;

int main()
{
    cout << setprecision(15);

    ofstream fsalida("resultados.dat", ios::out);
    if (!fsalida)
    {
        cout << "No se puede abrir el archivo";
        return 1;
    }
    for (double thetamax = 0; thetamax <= 150; thetamax = thetamax + 5)
    {
        // ojo: thetamax esta en grados. Factor de conversion.
        k = sin(factor * thetamax / 2.0);
        integral1 = trapezoidal(f, a, b, k, 20);
        integral2 = simpson1(f, a, b, k, 20);
        integral3 = simpson2(f, a, b, k, 21);
        integral4 = cgaussiana1(f, a, b, k);
        integral5 = cgaussiana2(f, a, b, k);

        cout << thetamax << "   " << integral1 << "   " << integral2 << "  " << integral3 << "  " << integral4 << "  " << integral5 << endl;
        fsalida << thetamax << "   " << integral1 << "   " << integral2 << "  " << integral3 << "  " << integral4 << "  " << integral5 << endl;
    }

    return 0;
}

double f(double x, double k)
{
    // las x estan en radianes
    return (2.0 / PI) * (1.0 / sqrt(1 - pow(k * sin(x), 2.0)));
}

double trapezoidal(double (*f)(double, double), double a, double b, double k, int n)
{
    // Integracion de la funcion f entre los limites a y b
    // haciendo uso del metodo trapezoidal con n intervalos, n+1 puntos
    // n puede ser cualquier n�mero natural
    double h, integral, x;
    h = (b - a) / n;
    integral = 0.0;
    for (int i = 1; i <= n - 1; i++)
    {
        x = a + i * h;
        integral = integral + f(x, k);
    }
    integral = (integral + ((f(a, k) + f(b, k)) / 2.0)) * h;
    return integral;
}

double simpson1(double (*f)(double, double), double a, double b, double k, int n)
{
    // Integracion de la funcion f entre los limites a y b
    // haciendo uso del metodo de Simpson 1/3 con n intervalos, n+1 puntos
    // n tiene que ser par
    double h, integral, x;
    h = fabs(b - a) / n;
    integral = 0.0;
    for (int i = 1; i <= n / 2; i++)
    {
        x = a + h * (2.0 * i - 1.0);
        integral = integral + 4 * f(x, k);
        if (i != n / 2)
        {
            integral = integral + 2 * f(x + h, k);
        }
    }
    integral = (integral + (f(a, k) + f(b, k))) * h / 3.0;
    return integral;
}

double simpson2(double (*f)(double, double), double a, double b, double k, int n)
{
    // n m�ltiplo de 3, Simpson 3/8
    double h, integral, x, sum = 0;
    h = fabs(b - a) / n;
    integral = 0.0;
    for (int i = 1; i < n; i++)
    {
        x = a + i * h;
        if (i % 3 == 0)
        {
            sum = sum + 2 * f(x, k);
        }
        else
        {
            sum = sum + 3 * f(x, k);
        }
    }
    integral = (3 * h / 8) * (f(a, k) + f(b, k) + sum);
    return integral;
}

double cgaussiana1(double (*f)(double, double), double a, double b, double k)
{
    double h1 = (b - a) / 2, h2 = (b + a) / 2, integral, w1 = 1, w2 = 1, x1 = -0.57735, x2 = 0.57735;
    integral = h1 * (w1 * f(h1 * x1 + h2, k) + w2 * f(h1 * x2 + h2, k));
    return integral;
}

double cgaussiana2(double (*f)(double, double), double a, double b, double k)
{
    double h1 = (b - a) / 2, h2 = (b + a) / 2, integral, w1 = 0.568889, w2 = 0.478629, w3 = 0.236927;
    double x1 = -0.90618, x2 = -0.538469, x3 = 0, x4 = 0.538469, x5 = 0.90618;
    integral = h1 * (w3 * f(h1 * x1 + h2, k) + w2 * f(h1 * x2 + h2, k) + w1 * f(h1 * x3 + h2, k) + w2 * f(h1 * x4 + h2, k) + w3 * f(h1 * x5 + h2, k));
    return integral;
}
