#include <iostream>
using namespace std;
// metodo de la burbuja
const int n = 7;
int main()
{
    int datos[n] = {34, 70, 5, 89, 6, 3220, 1};
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (datos[j] > datos[j + 1])
            {
                // intercambio
                temp = datos[j];
                datos[j] = datos[j + 1];
                datos[j + 1] = temp;
            }
        }
    }
    cout << "Despues de ordenar" << endl;
    for (int i = 0; i <= n - 1; i++)
    {
        cout << datos[i] << endl;
    }
    return 0;
}
