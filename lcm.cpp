#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    int answer = a * b;
    answer /= gcd(a, b);

    return answer;
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << "Mínimo múltiplo comum de " << a << " e " << b << ": " << lcm(a, b) << endl;
}