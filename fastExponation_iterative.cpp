#include <iostream>
using namespace std;

// Dados b, e e m, ela retorna (b^e)%mod 
int fastExponentiation(int b, int e, int m)
{
	long long int p = b; // Armazena a atual potência de b
	long long int answer = 1; // Armazena a resposta atual

	while (e > 0)
	{
		if (e%2 == 1) // Checa se o primeiro bit de e está ativo
			answer = (answer*p)%m;

		e /= 2;
		p = (p*p)%m; // Vai para a próxima potência de b
	}

	return answer;
}

int main()
{
	int b, e, m;
	cin >> b >> e >> m;

	cout << "Resposta: " << fastExponentiation(b, e, m) << endl;
}
