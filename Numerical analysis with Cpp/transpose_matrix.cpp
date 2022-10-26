#include <iostream>
using namespace std;
const int n = 3;
void transpuesta(float a[n][n], int n);
void muestramatriz(float a[n][n], int n);

int main()
{
    float a[n][n] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Matriz original" << endl;
    muestramatriz(a, n);
    cout << "Matriz transpuesta" << endl;
    transpuesta(a, n);
    muestramatriz(a, n);
    cout << endl;
    return 0;
}
void transpuesta(float a[n][n], int n)
{
    float aux;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
        {
            aux = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = aux;
        }
}
void muestramatriz(float a[n][n], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
