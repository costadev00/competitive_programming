/*

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    if (binary_search(arr, arr + n, 5))
        cout << "5 was found is the array\n";
    
    return 0;
}