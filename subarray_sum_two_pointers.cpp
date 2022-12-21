// SUBARRAY SUM PROBLEM
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 8, k = 8;
    // cin >> n >> k;
    vector<int> v = {1, 3, 2, 5, 1, 1, 2, 3};

    int l = 0, r = 0;
    long long sum = 0;
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