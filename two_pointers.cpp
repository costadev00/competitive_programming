#include <iostream>
using namespace std;

const int MAXN = 1000010;
//THIS ALGORITHM WORKS CONSIDERING A SORTED ARRAY
int main()
{
    int n, k;
    int v[MAXN];

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    int i = 0, j = n - 1;

    while (i <= j)
    {
        if (v[i] + v[j] == k) // The pair (i,j) is an answer
        {
            cout << "Answer: (" << i << "," << j << ")" << endl;
            return 0;
        }
        else if (v[i] + v[j] < k) // Our current sum is small
            i++;
        else // Our current sum is too large
            j--;
    }

    cout << "There's no such pair" << endl;
}
