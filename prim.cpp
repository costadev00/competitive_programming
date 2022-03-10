#include <iostream>
#include <vector>
#include <queue> // Para a priority queue

using namespace std;

const int INF = 1000000010; // Número muito grande para representar o infinito positivo
#define MAXN 10000
int n, m;

vector<pair<int, int>> adj[MAXN];

int prim()
{
    vector<int> value;
    value.resize(n, INF);

    priority_queue<pair<int, int>> pq;

    bool mark[n]; // mark[i] = true se e somente se nós já tivermos incorporado v a nossa MST

    for (int i = 0; i < n; i++)
        mark[i] = false;

    int mst_cost = 0;

    value[0] = 0;    // Define o valor da nossa fonte para 0
    pq.push({0, 0}); // Adiciona a fonta a nossa priority queue

    for (int k = 0; k < n; k++)
    {
        int current;

        while (true) // Acha o vértice desejado
        {
            current = pq.top().second; // Pega o topo da nossa priority queue
            pq.pop();                  // Remove o topo da nossa priority queue

            if (!mark[current]) // Checa se o vértice atual não está marcado
                break;
        }

        // Adiciona o current na nossa MST
        mark[current] = true;
        mst_cost += value[current];

        for (int j = 0; j < adj[current].size(); j++)
        {
            int viz = adj[current][j].first;
            int w = adj[current][j].second;

            if (value[viz] > w)
            {
                value[viz] = w;
                pq.push({-value[viz], viz});
            }
        }
    }
    return mst_cost;
}

int main()
{
    // Lê o número de vértices e o número de arestas
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;

        // Lê a descrição de uma aresta
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int mst_cost = prim();

    cout << "MST tem custo " << mst_cost << endl;
}
