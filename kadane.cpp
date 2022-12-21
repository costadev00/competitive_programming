// C++ program to print largest contiguous array sum
#include <iostream>
#include <climits>
using namespace std;

int maxSubArraySum(int v[], int n)
{
    int best = 0, sum = 0, start = 0, end = 0, s = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     sum += v[i];

    //     if (sum > best)
    //     {
    //         best = sum;
    //         start = s;
    //         end = i;
    //     }

    //     if (sum < 0)
    //     {
    //         sum = 0;
    //         s = i + 1;
    //     }
    // }
    for (int i = 0; i < n; i++)
    {
        sum = max(v[i], sum + v[i]);
        if (sum > best)
        {
            best = sum;
            start = s;
            end = i;
        }
        if (sum < 0)
        {
            sum = 0;
            s = i + 1;
        }
        // best = max(best, sum);
    }
    cout << best << "\n";
    cout << "Maximum contiguous sum is "
         << best << endl;
    cout << "Starting index " << start
         << endl
         << "Ending index " << end << endl;
}

/*Driver program to test maxSubArraySum*/
int main()
{
    int n;
    cin >> n;
    int v[n + 1];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    // int n = sizeof(a) / sizeof(a[0]);
    int max_sum = maxSubArraySum(v, n);
    return 0;
}
