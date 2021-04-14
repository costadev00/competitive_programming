#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Initializing array
    int ar[6] = {1, 2, 3, 4, 5, -6};

    // Checking if all elements are positive
    bool is = all_of(ar, ar + 6, [](int x) { return x > 0; });
    if (is)
    {
        cout << "All are positive elements";
    }
    else
    {
        cout << "All are not positive elements";
    }

    return 0;
}
