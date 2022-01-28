#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> &dist, vector<int> &p)
{
    int n = adj.size();
    dist.assign(n, INF);
    p.assign(n, -1);
    vector<bool> mark(n, false);

    dist[s] = 0;
    for (int i = 0; i < n; i++)
    {
        int v = -1;
        for (int j = 0; j < n; j++)
        {
            if (!mark[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        }

        if (dist[v] == INF)
            break;

        mark[v] = true;
        for (auto edge : adj[v])
        {
            int actual = edge.first;
            int w = edge.second;
            // dist[actual] = min(dist[actual], dist[v] + w);
            if (dist[v] + w < dist[actual])
            {
                dist[actual] = dist[v] + w;
                p[actual] = v;
            }
        }
    }
}

int main()
{
    adj[0].push_back({1, 15});
    adj[0].push_back({2, 1});
    adj[1].push_back({0, 15});
    adj[1].push_back({3, 1});
    adj[2].push_back({3, 1});
    adj[2].push_back({0, 1});
    adj[3].push_back({1, 1});
    adj[3].push_back({2, 1});
    vector<int> dist, p;
    dijkstra(0, dist, p);
    cout<<dist[0];

    return 0;
}