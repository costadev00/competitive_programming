#include <bits/stdc++.h>
using namespace std;

bool isSubmascara(int a, int b)
{
    return (a & b) == a;
}

int main()
{
    cout << isSubmascara(2, 2);
    return 0;
}