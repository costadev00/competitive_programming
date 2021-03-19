#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int arr[] = {1, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect(arr, arr + n);
    cout << accumulate(arr, arr + n, 0) << endl;
    cout << accumulate(vect.begin(), vect.end(), 0);
    return 0;
}