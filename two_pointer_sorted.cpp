#include <iostream>
using namespace std;

const int MAXN = 1000010;

int main()
{
    int n, k;
    int v[MAXN];

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    int i = 0, j = n - 1; // Os dois ponteiros

    while (i <= j)
    {
        if (v[i] + v[j] == k) // Primeiro caso
        {
            cout << "Resposta: (" << i << "," << j << ")" << endl;
            return 0;
        }
        else if (v[i] + v[j] < k) // Segundo caso
            i++;
        else // Terceiro caso
            j--;
    }

    cout << "Não há nenhum par com a soma desejada" << endl;
}
