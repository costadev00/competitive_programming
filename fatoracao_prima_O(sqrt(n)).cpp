#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int value = n;
    vector<int> primes; // Armazena a fatoração prima

    for (int i = 2; i * i <= n; i++) // Itera pelo intervalo [2,sqrt(n)]
    {
        while (value % i == 0) // Divide value por i enquanto value dividir i
        {
            primes.push_back(i);
            value /= i;
        }
    }

    if (value != 1) // Checa se existe um primo restante em value
        primes.push_back(value);

    cout << "Fatoração prima de " << n << ": " << primes[0];

    for (int i = 1; i < (int)primes.size(); i++)
        cout << "*" << primes[i];
}
