#include <iostream>
using namespace std;

const int MAXN = 1010;
const int MAXS = 1010;      // O maior S que esperamos ler
const int INF = 1000000010; // Um número muito grande representando um valor positivo infinito

int main()
{
    int n, S;
    int w[MAXN], v[MAXN], dp[MAXN][MAXS]; // dp[i][s] = soma máxima dos valores dos itens utilizando apenas os primeiros i itens e que o seu peso total seja s

    cin >> n >> S;

    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    dp[0][0] = 0; // Primeiro caso base

    for (int i = 1; i <= S; i++)
        dp[0][i] = -INF; // Segundo caso base

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= S; j++)
        {
            if (w[i] > j) // Nós não podemos pegar o item i
                dp[i][j] = dp[i - 1][j];
            else // Nós podemos escolher se iremos pegar o item i ou não
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }

    int answer = 0;

    for (int i = 1; i <= S; i++)
        answer = max(answer, dp[n][i]); // Obtendo a resposta

    cout << "Soma máxima dos valores: " << answer;
}
