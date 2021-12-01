#include <iostream>
using namespace std;

const int MAXN = 1000010;

int parent[MAXN], size[MAXN]; // size[i] = número de valores que tem uma ligação direta ou indireta a iii

int find(int value)
{
    if (parent[value] == value)
        return value;
    return find(parent[value]);
}

void merge(int i, int j)
{
    i = find(i);
    j = find(j);

    if (i == j)
        return;

    if (size[i] >= size[j])
    {
        parent[j] = i;
        size[i] += size[j]; // Atualizando size[i] com sua nova ligação com j
    }
    else
    {
        parent[i] = j;
        size[j] += size[i]; // Atualizando size[j] com sua nova ligação com i
    }
}

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        size[i] = 1; // Inicialmente, apenas i é diretamente ou indiretamente ligado a si mesmo
        parent[i] = i;
    }

    for (int i = 0; i < q; i++)
    {
        int type, a, b;
        cin >> type >> a >> b;

        if (type == 1)
            merge(a, b);
        else
        {
            if (find(a) == find(b))
                cout << "Same set" << endl;
            else
                cout << "Different sets" << endl;
        }
    }
}
