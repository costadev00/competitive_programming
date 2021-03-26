/*

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Initializing vector with array values
    int arr[] = {5, 10, 15, 20, 20, 23, 42, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect(arr, arr + n);
    sort(vect.begin(), vect.end());

    cout << "\nVector before removing duplicate "
            " occurrences: ";
    for (int i = 0; i < vect.size(); i++)
        cout << vect[i] << " ";

    // Deletes the duplicate occurrences
    vect.erase(unique(vect.begin(), vect.end()), vect.end());

    cout << "\nVector after deleting duplicates: ";
    for (int i = 0; i < vect.size(); i++)
        cout << vect[i] << " ";
    return 0;
}