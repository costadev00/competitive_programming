#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

typedef long long ll;
typedef long double ld;

#define endl "\n"
#define debug(args...) cout << (#args) << " = " << (args) << endl
#define MOD 1000000007
#define vi vector<int>
#define fl forward_list
#define pb push_back
#define pf push_front
#define read(st) getline(cin, st)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define N 1000005

bool ready[N];
ll value[N];

ll fibo(ll n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    else
    {
        if (ready[n - 1] && ready[n - 2])
            return value[n - 1] + value[n - 2];
        else
        {
            ready[n - 1] = true;
            value[n - 1] = fibo(n - 1);
            ready[n - 2] = true;
            value[n - 2] = fibo(n - 2);
            return value[n - 1] + value[n - 2];
        }
    }
}
int main()
{
    fastio;
    ll n;
    ready[1] = true;
    ready[2] = true;
    value[1] = 1;
    value[2] = 1;
    cin >> n;
    cout << "Fib(" << n << ") = " << fibo(n) << endl;

    return 0;
}