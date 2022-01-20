void dfs(int current)
{
    visited[current] = true; // Marca current como visitado

    for (int i = 0; i < adj[current].size(); i++) // Itera por todos os vizinhos de current
    {
        int neighbour = adj[current][i];

        if (!visited[neighbour]) // Checa se o vizinho atual já foi visitado anteriormente
            dfs(neighbour);
    }
}

