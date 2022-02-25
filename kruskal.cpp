#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

int n, m; // numero de vertices e arestas

vector<tuple<int, int, int>> edges; // grafo com a representacao de lista de arestas
// Implementação do DSU
int parent[MAXN], sz[MAXN];

void init_dsu(int n) // Initializa o DSU com n vértices
{
    for (int i = 0; i < n; i++)
    {
        sz[i] = 1;
        parent[i] = i;
    }
}
int find(int value)
{
    if (parent[value] == value)
        return value;
    return parent[value] = find(parent[value]);
}

void merge(int i, int j)
{
    i = find(i);
    j = find(j);

    if (i == j)
        return;

    if (sz[i] >= sz[j])
    {
        parent[j] = i;
        sz[i] += sz[j];
    }
    else
    {
        parent[i] = j;
        sz[j] += sz[i];
    }
}

//Funcao de comparacao, que ordena as arestas de acordo com seu peso(posicao 2 na tupla)
bool compare(tuple<int, int, int> e1, tuple<int, int, int> e2)
{
    return get<2>(e1) < get<2>(e2);
}

// Implementacao do algoritmo de Kruskal por Joseph Kruskal para gerar a árvore geradora mínima
int kruskal()
{
    sort(edges.begin(), edges.end(), compare); // Ordena as arestas por seu peso, usando a funcao sort e compare
    init_dsu(n);

    int mst_cost = 0;

    for (int i = 0; i < (int)edges.size(); i++) // Itera pela arestas
    {
        int u, v, w;
        tie(u, v, w) = edges[i];

        if (find(u) != find(v)) // Checa se u e v estão em componentes diferentes
        {
            merge(u, v);
            mst_cost += w; // Aumenta o custo da nossa MST
        }
    }

    return mst_cost;
}

int main()
{
    // Lê o número de vértices e o número de arestas respectivamente
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;

        // Lê a descrição de uma aresta
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        edges.push_back({v, u, w});
    }

    // int mst_cost = kruskal();

    cout << kruskal() << endl;
}
