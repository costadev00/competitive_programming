//LONGEST COMMON SUBSEQUENCE BOTTOM-UP aproach printing the subsequence
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 101;

int main()
{
    int n, m;
    int dp[MAXN][MAXN];
    int A[MAXN], B[MAXN];

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> A[i];

    for (int i = 0; i < m; i++)
        cin >> B[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (A[i - 1] != B[j - 1])
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j - 1] + 1;
        }
    }

    cout << "Size of the Longest Commom Subsequence: " << dp[n][m] << endl;

    // Recuperando a resposta

    vector<int> MSC; // A MSC será guardado nesse vector

    int i = n, j = m;

    while (i != 0 && j != 0)
    {
        if (A[i - 1] == B[j - 1]) // A[i - 1] e B[j - 1] estão na MSC
        {
            MSC.push_back(A[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1]) // Decidindo qual é o melhor estado para ir
                i--;
            else
                j--;
        }
    }

    // Revertendo a resposta
    reverse(MSC.begin(), MSC.end());

    cout << "Maior subsequência comum: ";

    for (int i = 0; i < (int)MSC.size(); i++)
        cout << MSC[i] << " ";
}
