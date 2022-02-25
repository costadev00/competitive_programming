// C++ program to find longest path of the tree
#include <bits/stdc++.h>
using namespace std;

// This class represents a undirected graph using adjacency list
class Graph
{
    int V;          // No. of vertices
    list<int> *adj; // Pointer to an array containing
                    // adjacency lists
public:
    Graph(int V);               // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void longestPathLength();   // prints longest path of the tree
    pair<int, int> bfs(int u);  // function returns maximum distant
                                // node from u with its distance
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v); // Since the graph is undirected
}

// method returns farthest node and its distance from node u
pair<int, int> Graph::bfs(int u)
{
    // mark all distance with -1
    int dis[V];
    memset(dis, -1, sizeof(dis));

    queue<int> q;
    q.push(u);

    // distance of u from u will be 0
    dis[u] = 0;

    while (!q.empty())
    {
        int t = q.front();
        q.pop();

        // loop for all adjacent nodes of node-t
        for (auto it = adj[t].begin(); it != adj[t].end(); it++)
        {
            int v = *it;

            // push node into queue only if
            // it is not visited already
            if (dis[v] == -1)
            {
                q.push(v);

                // make distance of v, one more
                // than distance of t
                dis[v] = dis[t] + 1;
            }
        }
    }

    int maxDis = 0;
    int nodeIdx;

    // get farthest node distance and its index
    for (int i = 0; i < V; i++)
    {
        if (dis[i] > maxDis)
        {
            maxDis = dis[i];
            nodeIdx = i;
        }
    }
    return make_pair(nodeIdx, maxDis);
}

// method prints longest path of given tree
void Graph::longestPathLength()
{
    pair<int, int> t1, t2;

    // first bfs to find one end point of
    // longest path
    t1 = bfs(0);

    // second bfs to find actual longest path
    t2 = bfs(t1.first);

    cout << "Longest path is from " << t1.first << " to "
         << t2.first << " of length " << t2.second;
}

// Driver code to test above methods
int main()
{
    // Create a graph given in the example
    Graph g(10);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 9);
    g.addEdge(2, 4);
    g.addEdge(4, 5);
    g.addEdge(1, 6);
    g.addEdge(6, 7);
    g.addEdge(6, 8);

    g.longestPathLength();
    return 0;
}
