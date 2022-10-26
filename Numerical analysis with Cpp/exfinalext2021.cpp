// Exam practice
// RK4 with second order ODE

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
const int n = 2; // numero de ecuaciones de primer orden acopladas
const double PI = 2.0 * asin(1.0);
double f1(double t, double y[n]);
double f2(double t, double y[n]);
double (*Af[n])(double t, double y[n]) = {f1, f2}; // array de punteros a funciones
void RK4(double (*Af[n])(double t, double y[n]), double t0, double tf, double h, double y[n]);

// OBSERVACIONES:
// 0 es punto de equilibrio, por lo que con CI (0,0), el sistema no cambia
//

int main()
{
    ofstream fborrar;
    fborrar.open("exfinalext_resultados.txt", ofstream::out | ofstream::trunc);
    fborrar.close();

    ofstream fsalida("exfinalext_resultados.txt", ios::app);
    if (!fsalida)
    {
        cout << "No se puede abrir el archivo";
    }
    double t01 = 0, tf1 = 3, h1 = 0.001;
    double y[n] = {1, -0.5}; // condiciones iniciales
    cout << "t:      z:         z':" << endl;
    fsalida << "t:      z:         z':" << endl;
    RK4(Af, t01, tf1, h1, y); // llamada a la funcion RK4

    cout << endl;
    fsalida << endl;

    double t02 = 0, tf2 = -3, h2 = -0.001;
    y[0] = 1, y[1] = -0.5; // condiciones iniciales
    cout << "t:      z:         z':" << endl;
    fsalida << "t:      z:         z':" << endl;
    RK4(Af, t02, tf2, h2, y); // llamada a la funcion RK4
    fsalida.close();
    return 0;
}

double f1(double t, double y[n])
{
    return y[1];
}

double f2(double t, double y[n])
{
    return (-t * y[1] - exp(t) * y[0]);
}

void RK4(double (*Af[n])(double t, double y[n]), double t0, double tf, double h, double y[n])
{
    int j;
    // Hay que abrir el flujo en la funcion
    ofstream fsalida("exfinalext_resultados.txt", ios::app);
    double t = t0, k1[n], k2[n], k3[n], k4[n], yy[n];
    cout << t;
    fsalida << t;
    for (j = 0; j < n; j++)
    {
        cout << "   " << y[j];
        fsalida << "   " << y[j];
    }
    cout << endl;
    fsalida << endl;
    do
    {
        for (j = 0; j < n; j++)
        {
            k1[j] = h * Af[j](t, y);
        }
        for (j = 0; j < n; j++)
        {
            yy[j] = y[j] + 0.5 * k1[j];
        }
        for (j = 0; j < n; j++)
        {
            k2[j] = h * Af[j](t + 0.5 * h, yy);
        }
        for (j = 0; j < n; j++)
        {
            yy[j] = y[j] + 0.5 * k2[j];
        }
        for (j = 0; j < n; j++)
        {
            k3[j] = h * Af[j](t + 0.5 * h, yy);
        }
        for (j = 0; j < n; j++)
        {
            yy[j] = y[j] + k3[j];
        }
        for (j = 0; j < n; j++)
        {
            k4[j] = h * Af[j](t + h, yy);
        }
        // nueva aproximaci�n
        for (j = 0; j < n; j++)
        {
            y[j] = y[j] + (1.0 / 6.0) * (k1[j] + 2.0 * k2[j] + 2.0 * k3[j] + k4[j]);
        }
        t = t + h;
        cout << t;
        fsalida << t;
        for (j = 0; j < n; j++)
        {
            cout << "   " << y[j];
            fsalida << "   " << y[j];
        }
        cout << endl;
        fsalida << endl;
    } while (fabs(t) <= fabs(tf));
    fsalida.close();
}
