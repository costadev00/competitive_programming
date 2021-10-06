#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << "Maior divisor comum de " << a << " e " << b << ": " << gcd(a, b) << endl;
}