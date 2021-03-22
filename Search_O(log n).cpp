/*

*/
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    set<int> a;
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        a.insert(arr[i]);
    }
    if (binary_search(a.begin(), a.end(), 5))
    {
        cout << "The element was found\n";
        return 0;
    }
    cout << "The element was not found\n";
    return 0;
}