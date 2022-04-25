#include <iostream>
using namespace std;

// const int MAXN = 1000010;
const int MAXN = 1001;
const int INF = 1000000010;

int main()
{
    int n;
    int v[MAXN], dp[MAXN]; // dp[i] = maior soma de um intervalo terminando em i

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    dp[0] = v[0]; // O caso base

    for (int i = 1; i < n; i++)
        dp[i] = max(v[i], dp[i - 1] + v[i]); // Calculando a dp

    int answer = -INF;

    for (int i = 0; i < n; i++)
        answer = max(answer, dp[i]); // Achando a maior dp

    cout << "Soma: " << answer;
}
