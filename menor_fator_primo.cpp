#include <iostream>
using namespace std;

int main()
{
    int q, n;
    cin >> q >> n;

    int spf[n + 1]; // spf[i] = menor fator primo de i

    for (int i = 2; i <= n; i++) // Inicializa o vetor spf
        spf[i] = i;

    for (int x = 2; x <= n; x++)
    {
        if (spf[x] != x)
            continue;

        for (int i = 2 * x; i <= n; i += x)
            spf[i] = min(spf[i], x); // Atualiza o menor fator primo de i
    }

    for (int i = 0; i < q; i++)
    {
        int v;
        cin >> v;

        cout << "O menor fator primo de " << v << " é " << spf[v] << endl;
    }
}
