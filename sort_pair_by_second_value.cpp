// C++ program to demonstrate sorting in vector
// of pair according to 2nd element of pair
#include <bits/stdc++.h>
using namespace std;

// Driver function to sort the vector elements
// by second element of pairs
// acending order
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}

int main()
{
    vector<pair<int, int>> vet = {{100, 80}, {200, 40}, {300, 0}, {200, 50}, {200, 30}};
    sort(vet.begin(), vet.end(), sortbysec);

    for (auto u : vet)
        cout << u.first << " " << u.second << endl;
    return 0;
}
