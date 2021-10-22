#include <iostream>
using namespace std;

int gcdExtended(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

int main()
{
    int a, m;
    cin >> a >> m;

    int inv, y;
    int gcd = gcdExtended(a, m, inv, y); // Acha uma solução para a equação ax + my = 1

    inv %= m;

    if (inv < 0) // Se inv for negativo, precisamos torná-lo não-negativo
        inv += m;

    cout << "Inverso modular de " << a << " modulo " << m << " = " << inv << endl;
}
