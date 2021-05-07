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
    vector<int>::iterator it;
    it = find(vect.begin(), vect.end(), 3);
    if (it != vect.end())
    {
        cout << "Founded at position: " << it - vect.begin() << endl;
    }
    else
    {
        cout << "Not founded!\n";
    }
    return 0;
}