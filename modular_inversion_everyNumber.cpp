#include <iostream>
using namespace std;

int main()
{
	int a, m;
	cin >> a >> m;

	int inv[m]; // inv[i] = inverso modular de i
	inv[1] = 1; // Primeiro caso

	for (int i = 2; i < m; i++)
	{
		inv[i] = (-m/i)*inv[m%i];
		inv[i] %= m;

		if (inv[i] < 0) // Se inv[i] for negativo, precisamos torná-lo não-negativo
			inv[i] += m;
	}

	cout << "Inverso modular de " << a << " modulo " << m << " = " << inv[a] << endl;
}


