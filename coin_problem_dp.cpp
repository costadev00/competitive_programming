
#include <bits/stdc++.h>
using namespace std;
#define INF 1000005
#define N 3

int coins[] = {1,5};

bool ready[N];
int value[N];
int main()
{
    // int n = 10;
    int n;
    cin >> n;
    value[0] = 0;
    for (int x = 1; x <= n; x++)
    {
        value[x] = INF;
        for (auto c : coins)
        {
            if (x - c >= 0)
                value[x] = min(value[x], value[x - c] + 1);
        }
        cout << "solve(" << x << ") = " << value[x] << endl;
    }
    return 0;
}