#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 10;
vector<int> t[N];
int in[N], out[N], n;

// finds the farthest node from u
void dfs1(int u = 1, int par = 0)
{
    in[u] = 0;
    for (auto v : t[u])
    {
        if (v == par)
        {
            continue;
        }
        dfs1(v, u);
        in[u] = max(in[u], in[v] + 1);
    }
}
void dfs2(int u = 1, int par = -1)
{
    int mx1 = -1, mx2 = -1;
    for (auto v : t[u])
    {
        if (v == par)
            continue;
        if (in[v] >= mx1)
        {
            mx2 = mx1;
            mx1 = in[v];
        }
        else if (in[v] > mx2)
        {
            mx2 = in[v];
        }
    }
    for (auto v : t[u])
    {
        if (v == par)
            continue;
        int longs = mx1;
        if (mx1 == in[v])
        {
            longs = mx2;
        }
        out[v] = 1 + max(out[u], 1 + longs);
        dfs2(v, u);
    }
}
void diameter()
{
    dfs1();
    dfs2();
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = max({ans, in[i], out[i]});
    }
    cout << "The diameter is " << ans << "\n";
}
int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        t[x].push_back(y);
        t[y].push_back(x);
    }
    diameter();
    return 0;
}