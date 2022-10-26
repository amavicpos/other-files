// COMPUTACI�N II, Pr�ctica 17
// Resoluci�n de ecuaciones diferenciales de segundo orden con condiciones de contorno: M�todo de las diferencias finitas
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
const int n = 500;
void Tridiag(double a[], double b[], double c[], double d[], double w[], int n);
double p(double x), q(double x), r(double x);
double solucion(double x);
void diffinitas(double x[n + 1], double a[n + 1], double b[n + 1], double c[n + 1], double d[n + 1], double w[n + 1], double h, int n);

int main()
{
    double x[n + 1], a[n + 1], b[n + 1], c[n + 1], d[n + 1], w[n + 1], h;
    // los elementos 0 y n de los vector a, b, c y d no se utilizan
    // rellenamos los vectores a, b, c y d
    x[0] = 5.0;
    w[0] = 110.0; // condicion de contorno
    x[n] = 10.0;
    w[n] = 0; // condicion de contorno
    h = (x[n] - x[0]) / n;

    ofstream fsalida("resultado.dat", ios::out);
    if (!fsalida)
    {
        cout << "No se puede abrir el archivo";
    }

    diffinitas(x, a, b, c, d, w, h, n);

    // grabamos la solucion
    fsalida << setprecision(15);
    for (int i = 0; i <= n; i++)
    {
        fsalida << x[i] << "   " << w[i] << endl;
    }
    fsalida.close();

    // grabamos la solucion exacta en un fichero
    ofstream fsalida2("sexacta.dat", ios::out);
    if (!fsalida2)
    {
        cout << "No se puede abrir el archivo";
    }
    fsalida2 << setprecision(15);
    for (int i = 0; i <= n; i++)
    {
        fsalida2 << x[i] << "    " << solucion(x[i]) << "    " << w[i] - solucion(x[i]) << endl;
    }

    fsalida2.close();

    return 0;
}

void Tridiag(double a[], double b[], double c[], double d[], double w[], int n)
{
    /* funcion para resolver un sistema de n ecuaciones lineales que tengan una matriz
    de coeficientes tridiagonal. Tenemos n intervalos, n+1 puntos totales (contando los
    extremos), y n-1 puntos interiores -> n-1 ecuaciones
    La solucion se almacena en el vector w  */
    double beta[n + 1], gamma[n + 1];
    // los elementos 0 y n de los vector beta y gamma no se utilizan
    // calcula los arrays intermedios beta y gamma
    beta[1] = b[1];
    gamma[1] = d[1];
    for (int i = 2; i <= n - 1; i++)
    {
        beta[i] = b[i] - a[i] * c[i - 1] / beta[i - 1];
        gamma[i] = d[i] - a[i] * gamma[i - 1] / beta[i - 1];
        // cout << beta[i] << "  " << gamma[i] << endl;
    }
    // calculamos la solucion final w
    w[n - 1] = gamma[n - 1] / beta[n - 1];
    for (int i = n - 2; i >= 1; i--)
    {
        w[i] = (gamma[i] - c[i] * w[i + 1]) / beta[i];
    }
}

double p(double x)
{
    return (-2.0 / x);
}

double q(double x)
{
    return 0;
}

double r(double x)
{
    return 0;
}

double solucion(double x)
{
    return ((110.0 * 5.0 / x) * (10.0 - x) / (10.0 - 5.0));
}

void diffinitas(double x[n + 1], double a[n + 1], double b[n + 1], double c[n + 1], double d[n + 1], double w[n + 1], double h, int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        x[i] = x[0] + h * i;
        a[i] = -(1.0 + (h / 2.0) * p(x[i]));
        b[i] = 2.0 + pow(h, 2) * q(x[i]);
        c[i] = -(1.0 - (h / 2.0) * p(x[i]));
        d[i] = -pow(h, 2) * r(x[i]);
    }
    // los elementos a[1] y c[n-1] no existen en la matriz de coeficientes, ya que pasan a formar parte
    // del vector b de la derecha
    // los elementos d[1] y d[n-1] adoptan expresiones particulares, ver matriz
    d[1] = d[1] - a[1] * w[0];
    d[n - 1] = d[n - 1] - c[n - 1] * w[n];
    Tridiag(a, b, c, d, w, n);
}
