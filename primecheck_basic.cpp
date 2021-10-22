#include <iostream>
using namespace std;

// O(p)
int main()
{
    int p;
    while (cin >> p)
    {

        bool isPrime = true;

        for (int i = 2; i < p; i++)
            if (p % i == 0)
                isPrime = false;

        if (isPrime)
            cout << p << " eh um numero primo" << endl;
        else
            cout << p << " nao eh um numero primo" << endl;
    }
}
