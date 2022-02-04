// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

const int MAXX = 10000, INF = 1e9;

// Adjacency List: to represent graph
vector<vector<pair<int, int>>>
    adj(MAXX * 10 + 3);

// Distance Array: to store shortest
// distance to every node
vector<int> dist(MAXX * 10 + 3, INF);

// returns value which will
// represent even_x
int even(int x)
{
    return x * 10 + 2;
}
// returns value which will
// represent odd_x
int odd(int x)
{
    return x * 10 + 1;
}

// converting edge (a->b) to 2
// different edges i.e. (a->b)
// converts to (1). even_a -> odd_b
// (2). odd_a -> even_b
// since, graph is undirected, so we
// push them in reverse order too
// hence, 4 push_back operations are
// there.
void addEdge(int a, int b, int cost)
{
    adj[even(a)].push_back({odd(b), cost});
    adj[odd(a)].push_back({even(b), cost});
    adj[odd(b)].push_back({even(a), cost});
    adj[even(b)].push_back({odd(a), cost});
}

// Function calculates shortest
// distance to all nodes from
// "source" using Dijkstra
// Shortest Path Algorithm
// and returns shortest distance
// to "destination"
int dijkstra(int source, int destination)
{

    /* Priority Queue/min-heap
    to store and process
    (distance, node) */
    priority_queue<pair<int, int>> pq;

    // pushing source node to
    // priority queue and dist from
    // source to source is set to 0
    pq.push({0, even(source)});
    dist[even(source)] = 0;

    while (!pq.empty())
    {
        // U is the node at top
        // of the priority queue
        // note that pq.top().first
        // refers to the Distance
        // and pq.top().second
        // will refer to the Node
        int u = pq.top().second;
        pq.pop();

        // exploring all neighbours
        // of node u
        for (pair<int, int> p :
             adj[u])
        {

            /* v is neighbour node of u
        and c is the cost/weight
        of edge (u, v) */
            int v = p.first;
            int c = p.second;

            // relaxation: checking if there
            // is a shorter path to v via u
            if (dist[u] + c < dist[v])
            {

                // updating distance of v
                dist[v] = dist[u] + c;
                pq.push({-dist[v], v});
            }
        }
    }

    // returning shortest
    // distance to "destination"
    return dist[even(destination)];
}

// Driver function
int main()
{
    // n = number of Nodes,
    // m = number of Edges
    int n, m;
    while (cin >> n >> m)
    {
        while (m--)
        {
            int x, y, w;
            cin >> x >> y >> w;
            addEdge(x, y, w);
        }
        int source = 1;
        int destination = n;
        int ans = dijkstra(source, destination);

        // if ans is INF: There is no
        // even length path from source
        // to destination else path
        // exists and we print the
        // shortest distance
        if (ans == INF)
            cout << "-1"
                 << "\n";
        else
            cout << ans << "\n";
    }
    return 0;
}
