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
typedef long long ll;
int main()
{
    fastio;
    // int n = 8;
    int v[] = {1, 3, 2, 5, 1, 1, 2, 3};
    // int o = 8;
    // // int i = arr[0];
    // int j = 0;
    // int k;
    // int sum = 0;
    // int ans;
    // for (int i = 0; i < n; i++)
    // {
    //     sum=0;
    //     for (k = i; k < j; k++)
    //         sum += arr[k];
    //     if (sum == o)
    //     {
    //         cout<<sum;
    //         return 0;
    //     }
    //     if (sum <= o)
    //         j++;
    // }
    // cout << ans;

    int n = 8, k = 8;
    // cin >> n >> k;
    // vector<int> v(n);

    int l = 0, r = 0;
    ll sum = 0;
    while (r < n)
    {
        while (r < n && sum < k)
            sum += v[r], r++;
        while (l < r && sum > k)
            sum -= v[l], l++;
        if (sum == k)
        {
            cout << l << ' ' << r - 1 << '\n';
            break;
        }
    }

    return 0;
}