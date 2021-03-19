#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int arr[] = {1, 1, 1, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect(arr, arr + n);
    cout << count(vect.begin(), vect.end(), 1) << endl;
    cout << count(arr, arr + n, 4) << endl;
    return 0;
}