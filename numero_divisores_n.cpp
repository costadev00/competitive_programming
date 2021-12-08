#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int value = n;
    int qtdDivisors = 1;

    for (int i = 2; i * i <= n; i++)
    {
        int exp = 0; // Acha o expoente de i na fatoração prima

        while (value % i == 0)
        {
            exp++;
            value /= i;
        }

        qtdDivisors *= exp + 1;
    }

    if (value != 1) // Se existir um primo restante, o seu expoente será 1
        qtdDivisors *= 2;

    cout << n << " tem " << qtdDivisors << " divisores" << endl;
}
