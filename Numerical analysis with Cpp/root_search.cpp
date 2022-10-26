#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
double f(double x);
double fprima(double x);
double newton(double (*f)(double), double (*fprima)(double), double x0, double tolerancia);
double secant(double (*f)(double), float x1, float x2, float EP);
double bisection(double (*f)(double), double a, double b, double EP);
double regulaFalsi(double (*f)(double), double a, double b, double tolerancia);

int main()
{
    if (remove("salida.dat"))
        printf("Remove error.....\n");
    freopen("salida.dat", "a+", stdout);
    double tolerancia, a, b, x0, raiz1, raiz2, raiz3, raiz4;

    cout << "Metodo de la biseccion:" << endl;
    cout << "Tolerancia: "
         << "Raiz:"
         << "           Numero de iteraciones:" << endl;

    for (tolerancia = 1e-3; tolerancia > 9e-14; tolerancia = tolerancia / 10)
    {
        a = 1.5;
        b = 1.7;
        raiz1 = bisection(f, a, b, tolerancia);
    }

    cout << endl;

    cout << "Metodo de la secante:" << endl;
    cout << "Tolerancia: "
         << "Raiz:"
         << "           Numero de iteraciones:" << endl;

    for (tolerancia = 1e-3; tolerancia > 9e-14; tolerancia = tolerancia / 10)
    {
        a = 1.5;
        b = 1.7;
        raiz2 = secant(f, a, b, tolerancia);
    }
    cout << endl;

    cout << "Metodo de Newton:" << endl;
    cout << "Tolerancia: "
         << "Raiz:"
         << "           Numero de iteraciones:" << endl;

    for (tolerancia = 1e-3; tolerancia > 9e-14; tolerancia = tolerancia / 10)
    {
        x0 = 1.5;
        raiz3 = newton(f, fprima, x0, tolerancia);
    }
    cout << endl;

    cout << "Metodo de la posici�n falsa:" << endl;
    cout << "Tolerancia: "
         << "Raiz:"
         << "           Numero de iteraciones:" << endl;

    for (tolerancia = 1e-3; tolerancia > 9e-14; tolerancia = tolerancia / 10)
    {
        a = 1.5;
        b = 1.7;
        raiz4 = regulaFalsi(f, a, b, tolerancia);
    }
    cout << endl;
    fclose(stdout);

    return 0;
}

double f(double x)
{
    return (-exp(-x) + 6 / pow(x, 7));
}

double fprima(double x)
{
    return (-42 / pow(x, 8) + exp(-x));
}

double newton(double (*f)(double), double (*fprima)(double), double x0, double tolerancia)
{
    double x1;
    int contador = 0;

    do
    {
        if ((f(x0) != 0) && (fprima(x0) != 0))
        {
            x1 = x0 - (f(x0) / fprima(x0));
            x0 = x1;
            contador = contador + 1;
        }
        else
        {
            cout << "No se pudo encontrar una raiz en el intervalo";
            break;
        }
    } while (fabs(f(x1)) > tolerancia);

    std::cout.precision(1);
    // Ajustar los espacios:
    if (tolerancia == 0.001)
    {
        cout << tolerancia << "       ";
    }
    else
    {
        cout << tolerancia << "      ";
    }
    // Precisi�n adecuada para la ra�z:
    std::cout.precision(14);
    cout << x1 << "      " << contador << endl;
    return x1;
}

double secant(double (*f)(double), float x1, float x2, float EP)
{
    float n = 0, xm, x0, c;
    if (f(x1) * f(x2) < 0)
    {
        do
        {
            x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
            c = f(x1) * f(x0);
            x1 = x2;
            x2 = x0;
            ++n;

            if (c == 0)
                break;
            xm = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
        } while (fabs(xm - x0) >= EP);
        std::cout.precision(1);
        if (EP == 0.001)
        {
            cout << EP << "       ";
        }
        else
        {
            cout << EP << "      ";
        }
        std::cout.precision(14);
        cout << x0 << "      " << n << endl;
        return x0;
    }
    else
    {
        cout << "No se pudo encontrar una raiz en el intervalo\n";
        return -1;
    }
}

double bisection(double (*f)(double), double a, double b, double EP)
{
    if (f(a) * f(b) >= 0)
    {
        cout << "No se pudo encontrar una raiz en el intervalo\n";
        return -1;
    }
    double c = a;
    int contador = 0;
    while ((b - a) >= EP)
    {
        c = (a + b) / 2;
        ++contador;
        if (f(c) == 0.0)
            break;
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }
    std::cout.precision(1);
    if (EP == 0.001)
    {
        cout << EP << "       ";
    }
    else
    {
        cout << EP << "      ";
    }
    std::cout.precision(14);
    cout << c << "      " << contador << endl;
    return c;
}

double regulaFalsi(double (*f)(double), double a, double b, double tolerancia)
{
    if (f(a) * f(b) >= 0)
    {
        cout << "No se pudo encontrar una raiz en el intervalo\n";
        return -1;
    }

    double c = a;
    int contador = 0;

    do
    {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        ++contador;

        if (f(c) == 0)
            break;

        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    } while (fabs(f(c)) >= tolerancia);
    std::cout.precision(1);
    if (tolerancia == 0.001)
    {
        cout << tolerancia << "       ";
    }
    else
    {
        cout << tolerancia << "      ";
    }
    std::cout.precision(14);
    cout << c << "      " << contador << endl;
    return c;
}
