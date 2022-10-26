#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
const int n = 4;
double norma(double a[n], int n);
void jacobi(double a[n][n], double b[n], int n, double tolerancia);
void gauss_seidel(double a[n][n], double b[n], int n, double tolerancia);

int main()
{
    ifstream fentrada("matriz.txt");
    if (!fentrada)
    {
        cout << "No se puede abrir el archivo de entrada";
        return 1;
    }
    double A[n][n];
    int s = 0, q = 0;
    while (!fentrada.eof())
    {
        for (int r = 0; r < n; r++)
        {
            for (int m = 0; m < n; m++)
            {
                fentrada >> A[r][m];
            }
        }
    }
    fentrada.close(); // cerrar el archivo
    for (int r = 0; r < n; r++)
    {
        for (int m = 0; m < n; m++)
        {
            cout << A[r][m] << " ";
        }
        cout << endl;
    }
    double b[n] = {3, -4, 5, -2};
    double tolerancia = 1e-15;
    jacobi(A, b, n, tolerancia);
    gauss_seidel(A, b, n, tolerancia);
    return 0;
}

double norma(double a[n], int n)
{
    double aux = 0;
    for (int i = 0; i < n; i++)
        aux += a[i] * a[i];

    aux = sqrt(aux);
    return aux;
}

void jacobi(double a[n][n], double b[n], int n, double tolerancia)
{
    double c[n], d[n]; // old x, x
    int i = 0, j = 0, l = 0;
    for (int i = 0; i < n; i++)
    {
        d[i] = b[i] / a[i][i];
    } // initial guess
    do
    {
        for (int i = 0; i < n; i++)
        {
            c[i] = d[i];
        }
        for (int i = 0; i < n; i++)
        {
            d[i] = b[i] / a[i][i];
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    d[i] = d[i] - (a[i][j] / a[i][i]) * c[j];
                }
            }
        }
        l = l + 1;
    } while ((fabs(norma(d, n) - norma(c, n))) > tolerancia);
    for (int i = 0; i < n; i++)
    {
        cout << "d" << i + 1 << "= " << d[i] << endl;
    }
    cout << "Iteraciones realizadas con Jacobi: " << l << endl;
}

void gauss_seidel(double a[n][n], double b[n], int n, double tolerancia)
{
    double c[n], d[n];
    int i = 0, j = 0, l = 0;
    for (int i = 0; i < n; i++)
    {
        d[i] = b[i] / a[i][i];
    }
    do
    {
        for (int i = 0; i < n; i++)
        {
            c[i] = d[i];
        }
        for (int i = 0; i < n; i++)
        {
            d[i] = b[i] / a[i][i];
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    d[i] = d[i] - (a[i][j] / a[i][i]) * d[j];
                }
            }
        }
        l = l + 1;
    } while ((fabs(norma(d, n) - norma(c, n))) > tolerancia);
    for (int i = 0; i < n; i++)
    {
        cout << "d" << i + 1 << "= " << d[i] << endl;
    }
    cout << "Iteraciones realizadas con Gauss-Seidel: " << l << endl;
}
