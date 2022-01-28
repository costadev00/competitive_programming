#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

#define INF 10000001
#define MAXN 1000
int dist[MAXN];
bool processed[MAXN];
vector<pair<int, int>> adj[MAXN];

priority_queue<pair<int, int>> q;
void dijkstra(int n, int x)
{

    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[x] = 0;
    q.push({0, x});
    while (!q.empty())
    {
        int a = q.top().second;
        q.pop();
        if (processed[a])
            continue;
        processed[a] = true;
        for (auto u : adj[a])
        {
            int b = u.first, w = u.second;
            if (dist[a] + w < dist[b])
            {
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
            }
        }
    }
}

int main()
{
    fastio;
    adj[0].push_back({1, 15});
    adj[0].push_back({2, 1});
    adj[1].push_back({0, 15});
    adj[1].push_back({3, 1});
    adj[2].push_back({3, 1});
    adj[2].push_back({0, 1});
    adj[3].push_back({1, 1});
    adj[3].push_back({2, 1});
    int n = 4;
    int s = 0;

    dijkstra(n, s);

    for (int i = 0; i < n; i++)
    {
        cout << "The shortest path from " << s << " to " << i << " is: " << dist[i] << endl;
    }

    return 0;
}