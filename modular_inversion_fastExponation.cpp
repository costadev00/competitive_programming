#include <iostream>
using namespace std;

int fastExponentiation(int b, int e, int m)
{
    if (e == 0)
        return 1 % m;

    long long int answer = fastExponentiation(b, e / 2, m);
    answer = (answer * answer) % m;

    if (e % 2 == 0)
        return answer;

    return (answer * b) % m;
}

int main()
{
    int a, m;
    cin >> a >> m;

    int inv = fastExponentiation(a, m - 2, m); // Acha (a^(m - 2))%m

    cout << "Inverso modular de " << a << " modulo " << m << " = " << inv << endl;
}
