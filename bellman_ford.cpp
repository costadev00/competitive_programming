#include <bits/stdc++.h>

using namespace std;

#define MAXN 10000
#define INF 100000001
int n;
int m;
int dist[MAXN];
vector<tuple<int, int, int>> edges;
bool negative_cycle = false;
// Executa-se uma série de passos. Um passo consiste em relaxar todas as arestas do nosso grafo.
//  Após o primeiro passo, vamos descobrir as distâncias de s a todos os vértices usando no máximo 1 aresta.
//  Após o segundo passo, descobriremos todas as distâncias de s a todos os vértices usando no máximo 2 arestas.
//   Em geral, após o i-ésimo passo, encontraremos o menor caminho entre s e todos os vértices, utilizando no máximo i arestas.
void bellman_ford(int x)
{
    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[x] = 0;
    // int dist_prev = dist[x];
    for (int i = 0; i < n; i++)
    {
        for (auto e : edges)
        {
            int a, b, w;
            tie(a, b, w) = e;
            dist[b] = min(dist[b], dist[a] + w);
        }

        // DETECTA SE TEM UM CICLO NEGATIVO
        for (int i = 0; i < (int)edges.size(); i++)
        {
            int a, b, w;
            // coloca os valores da tupla nas respectivas variáveis em ordem
            tie(a, b, w) = edges[i];
            if (dist[b] > dist[a] + w)
            {
                negative_cycle = true;
                break;
            }
        }
    }
}

int main()
{
    int s;
    cin >> n >> m >> s;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        // Lê a descrição de uma aresta
        cin >> u >> v >> w;

        edges.push_back({u, v, w});
        edges.push_back({v, u, w});
    }
    // verifica se temos um ciclo negativo
    bellman_ford(s);
    if (negative_cycle)
        cout << "Negative Cycle\n";
    else
        for (int i = 0; i < n; i++)
            cout << "A distancia entre " << s << " e " << i << " = " << dist[i] << endl;
}