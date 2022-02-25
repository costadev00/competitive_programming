#include <bits/stdc++.h>
// Este é um algoritmo muito curto e eficiente quando
//  é necessário encontrar todas as distâncias mínimas entre todos os pares/vertices.

// EXEMPLO

// 5
// 6
// 1 5 1
// 1 2 5
// 1 4 9
// 2 3 2
// 3 4 7
// 4 5 2
using namespace std;
const int INF = 1000000010;
int main()
{
    int n, m;
    cin >> n >> m;
    int adj[n + 1][n + 1];
    int distance[n + 1][n + 1];
    int u, v, w;
    // Criando o grafo, utilizando a matriz de adjacencia como representacao
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }
    // Inicializa
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                distance[i][j] = 0;
            else if (adj[i][j])
                distance[i][j] = adj[i][j];
            else
                distance[i][j] = INF;
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {   
            if(i==j)
                continue;
            if (distance[i][j] == INF)
                cout << "Não ha nenhum caminho de " << i << " para " << j << endl;
            else
                cout << "O caminho minimo de " << j << " para " << i << " eh " << distance[j][i] << endl;
        }
        cout<<endl;
    }
    return 0;
}