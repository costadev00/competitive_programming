#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

typedef long long ll;
typedef long double ld;

#define endl "\n"
#define MOD 1000000007
#define vi vector<int>
#define pb push_back
#define read(st) getline(cin, st)
#define FOR(i, a, b) for (int i = a; i < b; i++)

int main()
{
    fastio;
    vi vet;
    for (int i = 0; i < 17; i++)
    {
        vet.push_back(i + 1);
    }
    int x;
    for (int i = 0; i < vet.size(); i++)
    {
        if (x > vet.size())
        {
            x = x % vet.size();
        }
        vet[x] = 0;
        x += 5;
    }

    // cout << vet[x] << endl;
    for (int i = 0; i < vet.size(); i++)
    {
        cout << vet[i] << ' ';
    }
    // cout << vet.size();

    return 0;
}