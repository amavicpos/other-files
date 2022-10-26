#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const int n = 3;
const double PI = 4.0 * atan(1.0), e = exp(1.0);
int contador = 0;
double tolerancia = 1e-8;
void lu(double A[n][n], double b[n], double x[n], int n);
void gauss(double a[n][n], double b[n], double x[n], int n);
double f1(double x[n]);
double f2(double x[n]);
double f3(double x[n]);
double derivada(double (*funcion)(double x[n]), int j, double x[n]);
double norma(double x[n], int n);

int main()
{

    double J[n][n], F[n], dx[n];
    // valores iniciales de partida
    double xold[n] = {1, 1, 1}, xnew[n] = {1, 1, 1};
    double (*Af[n])(double x[n]) = {f1, f2, f3};
    // array de punteros a funciones que retornan reales
    cout << setprecision(15);
    do
    {
        for (int i = 0; i <= n - 1; i++)
        {
            xold[i] = xnew[i];
        }
        // construimos -F
        for (int i = 0; i <= n - 1; i++)
        {
            F[i] = -Af[i](xold);
        }

        // construimos la matriz jacobiana, J
        for (int i = 0; i <= n - 1; i++)
        {
            for (int j = 0; j <= n - 1; j++)
            {
                J[i][j] = derivada(Af[i], j, xold);
            }
        }
        // resolvemos el sistema J�dx=F
        lu(J, F, dx, n);
        // gauss(J,F,dx,n);
        contador = contador + 1;
        cout << "Iteracion " << contador << endl;
        for (int i = 0; i <= n - 1; i++)
        {
            xnew[i] = xold[i] + dx[i];
            cout << xnew[i] << "   ";
        }
        cout << endl;
    } while (fabs(norma(xnew, n) - norma(xold, n)) > tolerancia);

    return 0;
}

double f1(double x[n])
{
    return (6.0 * x[0] - 2.0 * cos(x[1] * x[2]) - 1.0);
}

double f2(double x[n])
{
    return (9 * x[1] + sqrt(x[0] * x[0] + sin(x[2]) + 1.06) + 0.9);
}

double f3(double x[n])
{
    return (60.0 * x[2] + 3.0 * exp(-x[0] * x[1]) + 10.0 * PI - 3.0);
}

double derivada(double (*f)(double x[n]), int j, double x[n])
{
    double h[n], xh[n], ratio;
    for (int k = 0; k <= n - 1; k++)
    {
        if (k == j)
        {
            h[k] = 0.0001 * x[k];
        } // cuidado si x[k]=0
        else
        {
            h[k] = 0.0;
        }
        xh[k] = x[k] + h[k];
    }
    ratio = (f(xh) - f(x)) / h[j];
    return ratio;
}

double norma(double x[n], int n)
{
    double suma = 0.0;
    for (int i = 0; i <= n - 1; i++)
    {
        suma = suma + x[i] * x[i];
    }
    return (sqrt(suma));
}

void lu(double A[n][n], double b[n], double x[n], int n)
{
    // Resuelve ecuacion algebraica lineal por el metodo LU
    // Ax=b --> LUx=b --> Lz=b --> Ux=z --> x

    double U[n][n], L[n][n], z[n];
    double sum;
    int i, j, k;

    // Obtener L y U
    for (i = 0; i <= n - 1; i++)
    {
        for (j = 0; j <= n - 1; j++)
        {
            if (i <= j)
            {
                sum = 0.0;
                for (k = 0; k <= i - 1; k++)
                {
                    sum = sum + L[i][k] * U[k][j];
                }
                U[i][j] = A[i][j] - sum;
                if (i < j)
                {
                    L[i][j] = 0.0;
                }
                else
                {
                    L[i][j] = 1.0;
                }
            }
            else
            {
                sum = 0.0;
                for (k = 0; k <= j - 1; k++)
                {
                    sum = sum + L[i][k] * U[k][j];
                }
                L[i][j] = (A[i][j] - sum) / U[j][j];
                U[i][j] = 0.0;
            }
        }
    }

    // Obtener z
    for (i = 0; i <= n - 1; i++)
    {
        sum = 0.0;
        for (j = 0; j <= i - 1; j++)
        {
            sum = sum + L[i][j] * z[j];
        }
        z[i] = b[i] - sum;
    }

    // Obtener x
    for (i = n - 1; i >= 0; i--)
    {
        sum = 0.0;
        for (j = i + 1; j <= n - 1; j++)
        {
            sum = sum + U[i][j] * x[j];
        }
        x[i] = (z[i] - sum) / U[i][i];
    }
}

void gauss(double a[n][n], double b[n], double x[n], int n)
{
    double pivote, temp;
    int i, j, k, filapivote;
    for (int j = 0; j <= n - 2; j++)
    {
        // bucle desde 0 hasta n-2 para recorrer todas las columnas excepto la �ltima.
        pivote = fabs(a[j][j]);
        filapivote = j;
        for (i = j + 1; i <= n - 1; i++)
        { // encuentra la fila pivote dentro de cada columna. pivoteo
            if (fabs(a[i][j]) > pivote)
            {
                pivote = fabs(a[i][j]);
                filapivote = i;
            }
        } // final bucle en i
        if (filapivote != j)
        { // intercambia filas en caso de ser necesario
            for (k = 0; k <= n - 1; k++)
            { // intercambia filas dadas por j y filapivote
                temp = a[j][k];
                a[j][k] = a[filapivote][k];
                a[filapivote][k] = temp;
            } // final bucle en k
            temp = b[j];
            b[j] = b[filapivote];
            b[filapivote] = temp;
        }
        for (i = j + 1; i <= n - 1; i++)
        { // Calcula y almacena las razones de coeficientes. Matriz L.
            a[i][j] = a[i][j] / a[j][j];
            for (k = j + 1; k <= n - 1; k++)
            { // calcula los otros terminos, resultantes de hacer la resta
                a[i][k] = a[i][k] - a[i][j] * a[j][k];
            } // final bucle en k
            b[i] = b[i] - a[i][j] * b[j];
        } // final bucle en i
    }     // final bucle en j (el del comienzo)

    // Sustituci�n regresiva   Soluci�n
    x[n - 1] = b[n - 1] / a[n - 1][n - 1];
    for (j = n - 2; j >= 0; j--)
    {
        x[j] = b[j];
        for (int k = j + 1; k <= n - 1; k++)
        {
            x[j] = x[j] - x[k] * a[j][k];
        } // final bucle en k
        x[j] = x[j] / a[j][j];
    } // final bucle en j
}
