#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int spf[n + 1];

    for (int i = 2; i <= n; i++)
        spf[i] = i;

    for (int x = 2; x <= n; x++) // Calcula o vetor spf
    {
        if (spf[x] != x)
            continue;

        for (int i = 2 * x; i <= n; i += x)
            spf[i] = min(spf[i], x);
    }

    int value = n;
    vector<int> primes; // Armazena a fatoração prima de n

    while (value != 1) // Itera enquanto ele tiver um fator primo
    {
        primes.push_back(spf[value]);
        value /= spf[value]; // Divide value pelo seu menor fator primo
    }

    cout << "Fatoracao prima de " << n << ": " << primes[0];

    for (int i = 1; i < (int)primes.size(); i++)
        cout << "*" << primes[i];
}
