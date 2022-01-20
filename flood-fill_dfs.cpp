#include <iostream>
#include <vector>
using namespace std;
//SOLUCAO FLOOD-FILL COM DFS PARA O PROBLEMA DO TABULEIRO DESCONEXO

const int MAXN = 1010; // Maior tamanho de uma dimensão do tabuleiro que esperamos ler

int n, m;
int board[MAXN][MAXN]; // board[i][j] = 1, se e somente se a célula (i,j) está quebrada
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

void dfs(int x, int y)
{
    visited[x][y] = true;

    if (is_cell_valid(x + 1, y)) // Checa se podemos ir para o sul
        dfs(x + 1, y);

    if (is_cell_valid(x, y + 1)) // Checa se podemos ir para o leste
        dfs(x, y + 1);

    if (is_cell_valid(x - 1, y)) // Checa se podemos ir para o norte
        dfs(x - 1, y);

    if (is_cell_valid(x, y - 1)) // Checa se podemos ir para o oeste
        dfs(x, y - 1);
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
            if (visited[x][y] || board[x][y] == 1) // Checa se já visitamos essa célula anteriormente ou se ela está quebrada
                continue;

            // Nós achamos uma nova componente

            dfs(x, y);        // Marca todas as células da mesma componente da célula (x,y)
            qtd_components++; // Aumenta a nossa resposta em 1
        }
    }

    cout << "Número de componentes: " << qtd_components << endl;
}
