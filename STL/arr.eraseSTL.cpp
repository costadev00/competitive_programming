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

    cout << "Vector is :";
    for (int i = 0; i < 6; i++)
        cout << vect[i] << " ";

    // Delete second element of vector
    vect.erase(vect.begin() + 1);
    cout << "\nVector after erasing the element: ";
    for (int i = 0; i < 5; i++)
        cout << vect[i] << " ";
    return 0;
}