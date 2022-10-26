// Exam practice
// RK4 with first order ODE

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
const double PI = 2.0 * asin(1.0);
double f(double t, double r);
void RK4(double (*f)(double t, double y), double t0, double y0, double h, int &n, double y[]);
int main()
{
    int n;
    double R_p = 0.586, t0 = 0, r0 = 1.0001 * R_p, h = 0.01, r[100000];
    // Por la precisi�n de los datos y el c�lculo, en los puntos donde la velocidad da 0, da un n�mero complejo y por tanto, para seguir con
    // el c�lculo, necesitamos saltarnos esos puntos
    cout << setprecision(15);
    ofstream fsalida("exfinal_1819_2_resultados.txt", ios::out);
    if (!fsalida)
    {
        cout << "No se puede abrir el archivo";
        return 1;
    }

    RK4(f, t0, r0, h, n, r); // llamada a la funcion RK4
    for (int i = 0; i <= n; i++)
    {
        cout << t0 + h * i << "  " << r[i] << endl;
        fsalida << t0 + h * i << "  " << r[i] << endl;
    }

    fsalida.close(); // cerramos archivo de salida
    return 0;
}

double f(double t, double r)
{
    double R_p = 0.586, V_p = 11.513, L_p = R_p * V_p, GM = 4 * pow(PI, 2), E = 0.5 * pow(V_p, 2) - GM / R_p;
    return (sqrt(2 * E - pow(L_p, 2) / pow(r, 2) + 2 * GM / r));
}

void RK4(double (*f)(double t, double y), double t0, double y0, double h, int &n, double y[])
{
    // Resuelve ecuacion diferencial de primer orden por el metodo de Runge-Kutta de cuarto orden
    //    y'=f(t,y)
    //    y(t0)=y0
    // Argumentos:
    //   f
    //   t0,y0
    //   y[n] solucion de la ecuacion diferencial discretizada en
    //   n puntos en t espaciados por h.
    int i = 1;
    double t, k1, k2, k3, k4;
    y[0] = y0;
    t = t0;
    double R_p = 0.586, V_p = 11.513, L_p = R_p * V_p, GM = 4 * pow(PI, 2), E = 0.5 * pow(V_p, 2) - GM / R_p;
    double a;
    do
    {
        k1 = h * f(t, y[i - 1]);
        k2 = h * f(t + 0.5 * h, y[i - 1] + 0.5 * k1);
        k3 = h * f(t + 0.5 * h, y[i - 1] + 0.5 * k2);
        k4 = h * f(t + h, y[i - 1] + k3);
        y[i] = y[i - 1] + (1.0 / 6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
        t = t + h;
        i = i + 1;
    } while (y[i - 1] > 0);
    n = i - 1;
}
