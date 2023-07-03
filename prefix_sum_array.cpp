#include <iostream>
using namespace std;

const int MAXN = 10010;

int main()
{
    int n, q;
    int v[MAXN], psa[MAXN]; // psa[i] = v[0] + v[1] + ... + v[i] = psa[i - 1] + v[i]

    cin >> n >> q;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    psa[0] = v[0]; // The base case

    for (int i = 1; i < n; i++)
        psa[i] = psa[i - 1] + v[i]; // Calculating psa[i] based on our recurrence

    for (int i = 0; i < q; i++)
    {
        int L, R;
        cin >> L >> R;

        cout << "Sum of the interval: " << psa[R] - psa[L-1] << endl;
    }
    // print psa
    for (int i = 0; i < n; i++)
        cout << psa[i] << " ";
}
