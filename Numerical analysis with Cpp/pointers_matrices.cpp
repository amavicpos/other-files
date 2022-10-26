#include <iostream>
using namespace std;
double **crearmatriz(double **M, int f, int c);
double **multmat(double **A, double **B, double **C, int fa, int ca, int cb);
void leermatriz(double **M, int f, int c);
void muestramatriz(double **M, int f, int c);
void borrarmatriz(double **M, int f);
int main()
{
    int fa, fb, ca, cb;
    double **A, **B, **C;
    cout << " introduzca numero de filas de A : ";
    cin >> fa;
    cout << " introduzca numero de columnas de A : ";
    cin >> ca;
    cout << " introduzca numero de filas de B : ";
    cin >> fb;
    cout << " introduzca numero de columnas de B : ";
    cin >> cb;
    int fc = fa, cc = cb;
    A = crearmatriz(A, fa, ca);
    B = crearmatriz(B, fb, cb);
    C = crearmatriz(C, fc, cc);
    cout << "Introduce datos matriz A" << endl;
    cout << fa << "filas y " << ca << " columnas" << endl;
    leermatriz(A, fa, ca);
    muestramatriz(A, fa, ca);
    cout << "Introduce datos matriz B" << endl;
    cout << fb << "filas y " << cb << " columnas" << endl;
    leermatriz(B, fb, cb);
    muestramatriz(B, fb, cb);
    cout << endl;
    cout << "Matriz C:" << endl;
    double **P = multmat(A, B, C, fa, ca, cb);
    muestramatriz(P, fc, cc);
    // liberamos la memoria ocupada por A, B y C
    borrarmatriz(A, fa);
    borrarmatriz(B, fb);
    borrarmatriz(C, fc);
    return 0;
}
double **crearmatriz(double **M, int f, int c)
{
    M = new double *[f];
    for (int i = 0; i < f; i++)
    {
        M[i] = new double[c];
    }
    return M;
}
double **multmat(double **A, double **B, double **C, int fa, int ca, int cb)
{
    double suma;
    for (int i = 0; i < fa; i++)
    {
        for (int j = 0; j < cb; j++)
        {
            suma = 0.0;
            for (int k = 0; k < ca; k++)
            {
                suma = suma + A[i][k] * B[k][j];
            }
            C[i][j] = suma;
        }
    }
    return C;
}
void leermatriz(double **M, int f, int c)
{
    int i, j;
    for (i = 0; i < f; i++)
    {
        for (j = 0; j < c; j++)
        {
            cout << "INTRODUCE ELEMENTO [" << i << "]"
                 << "[" << j << "]" << endl;
            cin >> M[i][j];
        }
    }
}
void muestramatriz(double **M, int f, int c)
{
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}
void borrarmatriz(double **M, int f)
// libera memoria
{
    for (int i = 0; i < f; i++)
    {
        delete[] M[i];
    }
    delete[] M;
}
