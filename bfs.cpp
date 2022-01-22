queue<int> q;
bool visited[N + 1];
void bfs(int x, vector<int> adj[], int c, int p)
{
    visited[x] = true;
    int distance[c + 1];
    memset(distance, -1, sizeof(distance));
    distance[x] = 0;
    q.push(x);
    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        // process node s
        for (auto u : adj[s])
        {
            if (visited[u])
                continue;
            visited[u] = true;
            distance[u] = distance[s] + 1;
            q.push(u);
        }
    }
    for (int i = 1; i <= c; i++)
    {
        // cout << i << " " << distance[i] << endl;
        if (distance[i] <= p && i != x && distance[i] != -1)
            cout << i << " ";
    }
    cout << endl;
}