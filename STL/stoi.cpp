#include <bits/stdc++.h>
using namespace std;
//CONVERTE QUALQUER BASE PARA INTEIRO

int main()
{
    string n = "10101011";
    //n = string
    // 0 = idx
    // 2 = base em que esta n
    int x = stoi(n, 0, 2);
    cout << x;
    return 0;
}