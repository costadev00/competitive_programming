#include <bits/stdc++.h>
using namespace std;
void reverseString(vector<char> &s)
{
    reverse(s.begin(), s.end());
    for (auto x : s)
    {
        cout << x;
    }
}
int main()
{
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    reverseString(s);
}