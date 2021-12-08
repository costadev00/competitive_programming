#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> divisors[n + 1]; // divisors[i] = armazena os divisores de i

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            divisors[j].push_back(i);

    for (int i = 1; i <= n; i++)
    {
        cout << "Todos os divisores de " << i << ": ";

        for (int j = 0; j < (int)divisors[i].size(); j++)
            cout << divisors[i][j] << " ";

        cout << endl;
    }
}
