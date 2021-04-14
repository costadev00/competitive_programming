#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Initializing vector
    vector<int> vect = {2, 1, 5, 6, 8, 7};

    // partitioning vector using stable_partition()
    // in sorted order
    stable_partition(vect.begin(), vect.end(), [](int x) {
        return x % 2 == 0;
    });

    // Displaying partitioned Vector
    cout << "The partitioned vector is : ";
    for (int &x : vect)
        cout << x << " ";
    cout << endl;
    return 0;
}