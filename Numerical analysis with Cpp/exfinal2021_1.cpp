// Exam practice
// Simpson variando parametros
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;
const int N = 100;
double f(double x);
void derivada(double x[], double y[], int n, double h);
double simpson1(double (*f)(double), double a, double b, int n);
const double PI = 2.0 * asin(1.0);

int main()
{
    ofstream fsalida("exfinal_2021_1.dat", ios::out);
    if (!fsalida)
    {
        cout << "No se puede abrir el archivo";
        return 1;
    }
    fsalida << "Ejercicio 1.a):" << endl;
    fsalida << "x:     Integral:" << endl;
    double a = -4, bmin = -4, bmax = 4, h = 0.1;
    int s = (bmax - bmin) / h; // N�mero de particiones entre -4 y 4
    double F[s + 1], integral;
    int i;
    for (double b = bmin; b < bmax + h; b = b + h)
    {
        integral = simpson1(f, a, b, N);
        fsalida << b << "   " << integral << endl;
        i = (b - bmin) / h;
        F[i] = integral;
    }

    // Diff. centradas:
    double deriv[s + 1], error[s + 1], b;
    derivada(F, deriv, s + 1, h);
    fsalida << endl
            << "Ejercicio 1.b):" << endl;
    fsalida << "y:   Derivada numerica:   f(y):        Error relativo:" << endl;
    for (int i = 0; i <= s; ++i)
    {
        b = bmin + h * i;
        fsalida << b << "   " << deriv[i] << "          " << f(b) << "   ";
        error[i] = fabs((deriv[i] - f(b)) / f(b));
        fsalida << error[i] << endl;
    }

    h = 0.05;
    double G[s + 1];
    fsalida << endl
            << "Ejercicio 1.c):" << endl;
    fsalida << "h = " << h << endl;
    s = (bmax - bmin) / h;
    for (b = bmin; b < bmax + h; b = b + h)
    {
        integral = simpson1(f, a, b, N);
        int i = (b + 4) / h;
        G[i] = integral;
    }
    derivada(G, deriv, s + 1, h);
    fsalida << "x:      Error:" << endl;
    for (int i = 0; i <= s; ++i)
    {
        b = bmin + h * i;
        error[i] = fabs((deriv[i] - f(b)) / f(b));
        fsalida << b << "     " << error[i] << endl;
    }

    // Error para varios valores de h:
    for (h = 0.1; h <= 0.4; h = h + 0.1)
    {
        fsalida << endl
                << "h = " << h << endl;
        s = (bmax - bmin) / h;
        for (b = bmin; b < bmax + h; b = b + h)
        {
            integral = simpson1(f, a, b, N);
            int i = (b + 4) / h;
            F[i] = integral;
        }
        derivada(F, deriv, s + 1, h);
        fsalida << "x:      Error:" << endl;
        for (int i = 0; i <= s; ++i)
        {
            b = bmin + h * i;
            error[i] = fabs((deriv[i] - f(b)) / f(b)); // Donde la derivada cambia m�s es donde m�s error hay, hay que tener en cuenta que la
                                                       // funci�n F toma saltos de h, y en cada h puede cambiar bastante (dependiendo de la derivada)
                                                       // Adem�s, mientras el h es mayor, el error tambi�n, ya que la funci�n cambia m�s en cada salto
                                                       // En los extremos el error relativo es mayor porque la funci�n derivada tiene error de orden
                                                       // lineal y no cuadr�tico
            fsalida << b << "     " << error[i] << endl;
        }
    }
    return 0;
}

double f(double x)
{
    return (1 / (sqrt(2 * PI)) * exp(-pow(x, 2) / 2));
}

void derivada(double x[], double y[], int n, double h)
{
    double aux;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            y[i] = (x[i + 1] - x[i]) / h;
        } // diferencias progresivas i=0
        else if (i == n - 1)
        {
            y[i] = (x[i] - x[i - 1]) / h;
        } // diferencias regresivas i=n-1
        else
        {
            y[i] = (x[i + 1] - x[i - 1]) / (2.0 * h);
        } // diferencias centrales, formula de tres puntos
    }
}

double simpson1(double (*f)(double), double a, double b, int n)
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
        integral = integral + 4 * f(x);
        if (i != n / 2)
        {
            integral = integral + 2 * f(x + h);
        }
    }
    integral = (integral + (f(a) + f(b))) * h / 3.0;
    return integral;
}
