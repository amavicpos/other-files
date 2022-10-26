#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
const int n = 1000;
void Tridiag(double *a, double *b, double *c, double *f, double *x, int n);

int main()
{
    double *A, *f, *x, *a, *b, *c;
    A = new double[3];
    f = new double[n];
    x = new double[n];
    a = new double[n];
    b = new double[n];
    c = new double[n];
    cout << "Valor de a: ";
    cin >> A[0];
    cout << "Valor de b: ";
    cin >> A[1];
    cout << "Valor de c: ";
    cin >> A[2];
    for (int i = 0; i < n; i++)
    {
        f[i] = 200;
    }
    f[0] = 100;
    f[n - 1] = 100;
    for (int i = 1; i < n; i++)
    {
        a[i] = A[0];
    }
    for (int i = 0; i < n; i++)
    {
        b[i] = A[1];
    }
    for (int i = 0; i < n - 1; i++)
    {
        c[i] = A[2];
    }

    Tridiag(a, b, c, f, x, n);

    delete[] A;
    delete[] f;
    delete[] x;
    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}

void Tridiag(double *a, double *b, double *c, double *f, double *x, int n)
{
    double *q, *w, *s, *z;
    q = new double[n];
    w = new double[n];
    s = new double[n];
    z = new double[n];
    for (int i = 0; i < n - 1; i++)
    {
        q[i] = c[i];
    }
    w[0] = b[0];
    for (int i = 1; i < n; i++)
    {
        s[i] = a[i] / w[i - 1];
        w[i] = b[i] - s[i] * c[i - 1];
    }
    z[0] = f[0];
    for (int i = 1; i < n; i++)
    {
        z[i] = f[i] - s[i] * z[i - 1];
    }
    x[n - 1] = z[n - 1] / w[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        x[i] = (z[i] - c[i] * x[i + 1]) / w[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << endl;
    }
    ofstream fsalida("salidapr09.txt");
    for (int i = 0; i < n; i++)
    {
        fsalida << i << " " << x[i] << endl;
    }
    delete[] q;
    delete[] w;
    delete[] s;
    delete[] z;
}
