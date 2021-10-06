#include <bits/stdc++.h>
using namespace std;

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    int base = 1;

    int temp = num;
    while (temp)
    {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }

    return dec_value;
}

int main()
{
    int a, b, n1, n2;
    cin >> n1 >> n2;
    a = binaryToDecimal(n1);
    b = binaryToDecimal(n2);
    int n = a | b;
    bitset<4> x(n);
    cout << x << endl; // Imprime o AND de a e b
}