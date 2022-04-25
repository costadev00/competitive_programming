//LONGEST COMMON SUBSEQUENCE BOTTOM-UP aproach
#include <iostream>
using namespace std;

const int MAXN = 1010; // A quantidade máxima de elementos que serão lidos

int main()
{
    int n, m;
    int dp[MAXN][MAXN]; // dp[i][j] = MSC entre os i primeiros números de A e os j primeiros de B
    int A[MAXN], B[MAXN];

    // Lê o tamanho das sequências A e B respectivamente
    cin >> n >> m;

    // Lê todos os inteiros da sequência A e armazena-os no vetor A
    for (int i = 0; i < n; i++)
        cin >> A[i];

    // Lê todos os inteiros da sequência B e armazena-os no vetor B
    for (int i = 0; i < m; i++)
        cin >> B[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // Calculando dp[i][j]
            if (A[i - 1] != B[j - 1])
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j - 1] + 1;
        }
    }

    cout << "Tamanho da maior subsequência comum: " << dp[n][m];
}
