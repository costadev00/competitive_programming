#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q, n;
    cin >> q >> n;

    vector<bool> isPrime(n,true); // isPrime[i] = true se e somente se i for primo

    // for (int i = 2; i <= n; i++) // Inicializa o vetor isPrime
    //     isPrime[i] = true;

    for (int x = 2; x <= n; x++) // Itera pelo intervalo [2,n]
    {
        if (!isPrime[x]) // Checa se x é primo
            continue;

        for (int i = 2 * x; i <= n; i += x) // Itera por todo múltiplo de x maior que ele e menor ou igual a n
            isPrime[i] = false;
    }

    for (int i = 0; i < q; i++)
    {
        int v;
        cin >> v;

        if (isPrime[v])
            cout << v << " é um número primo" << endl;
        else
            cout << v << " não é um número primo" << endl;
    }
}
