// EULER
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
double f(double t, double y);
void euler(double (*f)(double t, double y), double t0, double y0, double h, int &n, double y[]);
int main()
{
    int n;
    double t0 = 0, y0 = 0, h, y[100000];
    cout << setprecision(15);
    ofstream fsalida("euler.dat", ios::out);
    if (!fsalida)
    {
        cout << "No se puede abrir el archivo";
        return 1;
    }
    cout << "Introduce valor de h" << endl;
    cin >> h;
    euler(f, t0, y0, h, n, y); // llamada a la funcion euler*
    for (int i = 0; i <= n; i++)
    {
        cout << t0 + h * i << "  " << y[i] << endl;
        fsalida << t0 + h * i << "  " << y[i] << endl;
    }

    fsalida.close(); // cerramos archivo de salida

    return 0;
}

double f(double t, double y)
{
    double g = 9.8, vlimite = 57, gamma = g / pow(vlimite, 2);
    return (g - gamma * pow(y, 2));
}

void euler(double (*f)(double t, double y), double t0, double y0, double h, int &n, double y[])
{
    // Resuelve ecuacion diferencial de primer orden por el metodo de Euler
    //    y'=f(t,y)
    //    y(t0)=y0
    // Argumentos:
    //   f
    //   t0,y0
    //   y[n] solucion de la ecuacion diferencial discretizada en
    //   n puntos en t espaciados por h.
    int i = 1;
    double t, vlimite = 57;
    y[0] = y0;
    t = t0;
    do
    {
        y[i] = y[i - 1] + h * f(t, y[i - 1]);
        t = t + h;
        i = i + 1;
        //   cout << i-1 << "  " << t << "  " << y[i-1] << endl;
    } while (y[i - 1] < (vlimite - (vlimite / 1e5)));
    n = i - 1;
}
