#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int MAXN = 1010;

int n, m;
int board[MAXN][MAXN];
bool visited[MAXN][MAXN];

bool is_cell_valid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if (board[x][y] == 1)
        return false;
    if (visited[x][y])
        return false;

    return true;
}

void bfs(int x, int y)
{
    queue<pair<int, int>> q;

    visited[x][y] = true;
    q.push({x, y});

    while (!q.empty())
    {
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();

        if (is_cell_valid(currentX + 1, currentY)) // Checa se podemos ir para o sul
        {
            visited[currentX + 1][currentY] = true;
            q.push({currentX + 1, currentY});
        }

        if (is_cell_valid(currentX, currentY + 1)) // Checa se podemos ir para o leste
        {
            visited[currentX][currentY + 1] = true;
            q.push({currentX, currentY + 1});
        }

        if (is_cell_valid(currentX - 1, currentY)) // Checa se podemos ir para o norte
        {
            visited[currentX - 1][currentY] = true;
            q.push({currentX - 1, currentY});
        }

        if (is_cell_valid(currentX, currentY - 1)) // Checa se podemos ir para o oeste
        {
            visited[currentX][currentY - 1] = true;
            q.push({currentX, currentY - 1});
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    int qtd_components = 0;

    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            if (visited[x][y] || board[x][y] == 1)
                continue;

            bfs(x, y);
            qtd_components++;
        }
    }

    cout << "Número de componentes: " << qtd_components << endl;
}
