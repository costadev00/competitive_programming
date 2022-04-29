#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100;
const int MAXS = 1010;
const int INF = 1000000010;

int main()
{
	int n, S;
	int w[MAXN], v[MAXN], dp[MAXN][MAXS];

	bool opt[MAXN][MAXS]; // opt[i][j] = o i-ésimo item será escolhido no subconjunto ótimo de dp[i][j] ou não

	cin >> n >> S;

	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	dp[0][0] = 0;

	for (int i = 1; i <= S; i++)
		dp[0][i] = -INF;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= S; j++)
		{
			if (w[i] > j) 
			{
				opt[i][j] = false;
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				if (dp[i - 1][j] <= dp[i - 1][j - w[i]] + v[i]) // A melhor opção é pegar o i-ésimo item
				{
					opt[i][j] = true;
					dp[i][j] = dp[i - 1][j - w[i]] + v[i];
				}
				else // A melhor opção é não pegar o i-ésimo item
				{
					opt[i][j] = false;
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
	}

	int s = 0; // ÍNdice que maximiza dp[n][s]
	int answer = 0;

	vector<int> items;

	for (int i = 1; i <= S; i++)
	{
		if (answer < dp[n][i])
		{
			s = i;
			answer = dp[n][i];
		}
	}

	for (int i = n; i > 0; i--)
	{
		if (opt[i][s]) // Nós usamos o item i na resposta ótima
		{
			s -= w[i];
			items.push_back(i);
		}
	}

	reverse(items.begin(), items.end()); // Revertendo a resposta para ela ficar em ordem crescente

	cout << "Soma máxima dos valores: " << answer << endl;

	cout << "Itens do subconjunto ótimo: ";

	for (int i = 0; i < (int)items.size(); i++)
		cout << items[i] << " ";
}
