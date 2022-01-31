#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

typedef long long ll;
typedef long double ld;

#define endl "\n"
#define debug(args...) cout << (#args) << " = " << (args) << endl
#define MOD 1000000007
#define vi vector<int>
#define fl forward_list
#define pb push_back
#define pf push_front
#define read(st) getline(cin, st)
#define FOR(i, a, b) for (int i = a; i < b; i++)

int n;
bool is_cell_valid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= n)
        return false;
    return true;
}

int main()
{
    fastio;
    cin >> n;
    int mat[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    vector<int> adj[(n * n) + 1];

    int cont = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (is_cell_valid(i + 1, j)) // Checa se podemos ir para o sul
                adj[cont].push_back(cont + 4);

            if (is_cell_valid(i, j + 1)) // Checa se podemos ir para o leste
                adj[cont].push_back(cont + 1);

            if (is_cell_valid(i - 1, j)) // Checa se podemos ir para o norte
                adj[cont].push_back(cont - 4);

            if (is_cell_valid(i, j - 1)) // Checa se podemos ir para o oeste
                adj[cont].push_back(cont - 1);
            cont++;
        }
    }
    cout<<endl<<endl;
    for (int i = 0; i < n * n; i++)
    {
        cout<<i<<" ";
        for (auto u : adj[i])
            cout << u << " ";
        cout << endl;
    }
    return 0;
}