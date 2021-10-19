#include <iostream>
using namespace std;

// Dados x, y e m, ela retorna (x*y)%mod
long long int fastMultiplication(long long int x, long long int y, long long m)
{
    if (x == 0) // Caso base
        return 0;

    long long int answer = fastMultiplication(x / 2, y, m); // Acha a resposta do nosso subproblema
    answer = (2 * answer) % m;                              // Multiplica a nossa resposta por 2 e tira módulo m

    if (x % 2 == 0) // Checa se x é par
        return answer;

    return (answer + y) % m;
}

long long int fastExponentiation(long long int b, long long int e, long long int m)
{
    if (e == 0)
        return 1 % m;

    long long int answer = fastExponentiation(b, e / 2, m);
    answer = fastMultiplication(answer, answer, m); // Use our new function to find answer*answer

    if (e % 2 == 0)
        return answer;

    return fastMultiplication(answer, b, m); // Use our new function to find answer*b
}

int main()
{
    long long int b, e, m;
    cin >> b >> e >> m;

    cout << "Resposta: " << fastExponentiation(b, e, m) << endl;
    cout << fastMultiplication(2, 3, 4);
}
