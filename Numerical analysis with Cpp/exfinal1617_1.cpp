// Exam practice
// RK2 until z = 0

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
const int n = 4; // numero de ecuaciones de primer orden acopladas
const double PI = 2.0 * asin(1.0);
double f1(double t, double y[n]);
double f2(double t, double y[n]);
double f3(double t, double y[n]);
double f4(double t, double y[n]);
double (*Af[n])(double t, double y[n]) = {f1, f2, f3, f4}; // array de punteros a funciones
void RK2(double (*Af[n])(double t, double y[n]), double t0, double h, double y[n]);

int main()
{
    double t0 = 0, h = 0.1;
    double y[n] = {10000, 0, 0, 300}; // condiciones iniciales
    cout << setprecision(15);
    RK2(Af, t0, h, y); // llamada a la funcion RK4
    return 0;
}

double f1(double t, double y[n])
{
    return y[2];
}

double f2(double t, double y[n])
{
    return y[3];
}

double f3(double t, double y[n])
{
    double g = 9.80665, b = 0, m = 1, h = 9000;
    return (-g - b / m * exp(-y[0] / h) * y[2]);
}

double f4(double t, double y[n])
{
    double b = 0, m = 1, h = 9000;
    return (-b / m * exp(-y[0] / h) * y[2]);
}

void RK2(double (*Af[n])(double t, double y[n]), double t0, double h, double y[n])
{
    int j;
    // Hay que abrir el flujo en la funcion
    ofstream fsalida("exfinal1617_1.txt", ios::out);
    if (!fsalida)
    {
        cout << "No se puede abrir el archivo";
    }
    double t = t0, k1[n], k2[n], yy[n];
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
        // nueva aproximaci�n
        for (j = 0; j < n; j++)
        {
            y[j] = y[j] + k2[j];
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
    } while (!(y[0] < 0));
    fsalida.close();
}
