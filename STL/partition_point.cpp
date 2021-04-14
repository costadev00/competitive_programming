#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Initializing vector
    vector<int> vect = {2, 1, 5, 6, 8, 7};

    // Declaring iterator
    vector<int>::iterator it1;
    stable_partition(vect.begin(), vect.end(), [](int x) {
        return x % 2 == 0;
    });
    // using partition_point() to get ending position of partition
    auto it = partition_point(vect.begin(), vect.end(), [](int x) {
        return x % 2 == 0;
    });

    // Displaying partitioned Vector
    cout << "The vector elements returning true for condition are : ";
    for (it1 = vect.begin(); it1 != it; it1++)
        cout << *it1 << " ";
    cout << endl;

    return 0;
}