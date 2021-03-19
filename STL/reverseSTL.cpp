#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect(arr, arr + n);
    reverse(arr, arr + 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    cout << *max_element(arr, arr + n);
    return 0;
}