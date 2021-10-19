#include <iostream>
using namespace std;
 
// Dados b, e e m, ela retorna (b^e)%mod
int fastExponentiation(int b, int e, int m)
{
	if (e == 0) // Caso base
		return 1%m;

	long long int answer = fastExponentiation(b, e/2, m); // Acha a resposta do nosso subproblema
	answer = (answer*answer)%m; // Eleva a resposta ao quadrado e tira módulo m

	if (e%2 == 0) // Checa se e é par
		return answer;

	return (answer*b)%m;
}

int main()
{
	int b, e, m;
	cin >> b >> e >> m;

	cout << "Resposta: " << fastExponentiation(b, e, m) << endl;
}