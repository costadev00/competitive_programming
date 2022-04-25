#include <iostream>
using namespace std;

const int MAXN = 1001;
const int INF = 1000000010;

int main()
{
    int n;
    int v[MAXN], dp[MAXN], opt[MAXN]; // opt[i] = índice mais a direita menor ou igual a i tal que s( opt(i) , i ) = dp(i)

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    dp[0] = v[0];
    opt[0] = 0;

    for (int i = 1; i < n; i++)
    {
        // Calculando opt[i]
        if (v[i] >= dp[i - 1] + v[i])
            opt[i] = i;
        else
            opt[i] = opt[i - 1];

        dp[i] = max(v[i], dp[i - 1] + v[i]);
    }

    int answer = -INF;
    int indexMaxDp = 0;

    for (int i = 0; i < n; i++)
    {
        if (dp[i] > answer)
        {
            answer = dp[i]; // Pegando a maior dp
            indexMaxDp = i; // Pegando o índice da maior dp
        }
    }

    cout << "Soma: " << answer;
    cout << "Intervalo: " << opt[indexMaxDp] +1 << ", " << indexMaxDp+1;
}
