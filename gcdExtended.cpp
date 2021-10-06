#include <iostream>
using namespace std;

int gcdExtended(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1; // Solução base para a = 0
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b % a, a, x1, y1); // Acha o mdc(a,b) e a solução para (b%a,a)

    // Calcula a solução baseada em x1 e y1
    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

int main()
{
    int a, b;
    cin >> a >> b;

    int x, y;
    int gcd = gcdExtended(a, b, x, y);

    cout << "Maior divisor comum: " << gcd << endl;
    cout << "(x,y) = (" << x << "," << y << ")" << endl;
}