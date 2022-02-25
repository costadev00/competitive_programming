#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> h;
int n;

// finding height of each node.
// Argument p here is the parent of current node
int height(int curr, int p)
{
    for (auto it : g[curr])
    {
        if (it == p)
        {
            continue;
        }
        h[curr] = max(h[curr], height(it, curr));
    }
    h[curr] += 1;
    return h[curr];
}

// finding diameter
int diameter(int curr, int p)
{

    int mx1, mx2, mx_subtree;
    mx1 = mx2 = mx_subtree = INT_MIN;
    for (auto it : g[curr])
    {
        if (it == p)
        {
            continue;
        }
        if (mx1 < h[it])
        {
            mx2 = mx1;
            mx1 = h[it];
        }
        else
        {
            mx2 = h[it];
        }
    }
    for (auto it : g[curr])
    {
        if (it == p)
        {
            continue;
        }
        mx_subtree = max(mx_subtree, diameter(it, curr));
    }

    // diameter will be max of diameter in the subtrees or if it passes
    // through current node then it will be the sum of maximum heights
    // of any two of its children + 1(1 for current node).

    return max(mx_subtree, mx1 + mx2 + 1);
}

int main()
{
    cin >> n;
    g.resize(n + 1);
    h.resize(n + 1, 0);
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // choosing root to be 1.
    height(1, -1);
    cout << diameter(1, -1);
    return 0;
}