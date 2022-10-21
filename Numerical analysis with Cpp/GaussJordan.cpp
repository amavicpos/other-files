#include <iostream>
#include <cmath>
using namespace std;
const int n = 4;
void GaussJordan(double a[n][n], double b[n], double x[n]);
void diagonalmentedominante(double a[n][n]);
void muestramatriz(double C[n][n]);

int main()
{
    double a[n][n] = {1, 4, 1, -1, -6, 0, 3, 1, 3, -2, 8, 1, 1, 2, 0, 3}, b[n] = {0, 0, 0}, x[n];
    muestramatriz(a);
    cout << endl;
    diagonalmentedominante(a);
    cout << endl;
    GaussJordan(a, b, x);
    cout << endl;
    muestramatriz(a);
    return (0);
}

void GaussJordan(double a[n][n], double b[n], double x[n])
{
    double pivote, temp;
    int filapivote;
    for (int j = 0; j <= n - 2; j++)
    {
        // bucle desde 0 hasta n-2 para recorrer todas las columnas excepto la �ltima.
        pivote = fabs(a[j][j]);
        filapivote = j;
        for (int i = j + 1; i <= n - 1; i++)
        { // encuentra la fila pivote dentro de cada columna. pivoteo
            if (fabs(a[i][j]) > pivote)
            {
                pivote = fabs(a[i][j]);
                filapivote = i;
            }
        } // final bucle en i
        if (filapivote != j)
        { // intercambia filas en caso de ser necesario
            for (int k = 0; k <= n - 1; k++)
            { // intercambia filas dadas por j y filapivote
                temp = a[j][k];
                a[j][k] = a[filapivote][k];
                a[filapivote][k] = temp;
            } // final bucle en k
            temp = b[j];
            b[j] = b[filapivote];
            b[filapivote] = temp;
        }
        for (int i = j + 1; i <= n - 1; i++)
        { // Calcula y almacena las razones de coeficientes. Matriz L.
            a[i][j] = a[i][j] / a[j][j];
            for (int k = j + 1; k <= n - 1; k++)
            { // calcula los otros terminos, resultantes de hacer la resta
                a[i][k] = a[i][k] - a[i][j] * a[j][k];
            } // final bucle en k
            b[i] = b[i] - a[i][j] * b[j];
        } // final bucle en i
    }     // final bucle en j (el del comienzo)
    // Sustituci�n regresiva -> Soluci�n
    x[n - 1] = b[n - 1] / a[n - 1][n - 1];
    for (int j = n - 2; j >= 0; j--)
    {
        x[j] = b[j];
        for (int k = j + 1; k <= n - 1; k++)
        {
            x[j] = x[j] - x[k] * a[j][k];
        } // final bucle en k
        x[j] = x[j] / a[j][j];
    } // final bucle en j
}

void diagonalmentedominante(double a[n][n])
{
    double pivote, temp;
    int filapivote;
    for (int j = 0; j <= n - 2; j++)
    {
        // bucle desde 0 hasta n-2 para recorrer todas las columnas excepto la �ltima.
        pivote = fabs(a[j][j]);
        filapivote = j;
        for (int i = j + 1; i <= n - 1; i++)
        { // encuentra la fila pivote dentro de cada columna. pivoteo
            if (fabs(a[i][j]) > pivote)
            {
                pivote = fabs(a[i][j]);
                filapivote = i;
            }
        } // final bucle en i
        if (filapivote != j)
        { // intercambia filas en caso de ser necesario
            for (int k = 0; k <= n - 1; k++)
            { // intercambia filas dadas por j y filapivote
                temp = a[j][k];
                a[j][k] = a[filapivote][k];
                a[filapivote][k] = temp;
            } // final bucle en k
        }
    }
}

void muestramatriz(double C[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}
