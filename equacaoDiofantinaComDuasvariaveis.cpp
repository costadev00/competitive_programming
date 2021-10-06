#include <iostream>
using namespace std;

int gcdExtended(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

bool findSolution(int a, int b, int c, int &x, int &y) // Retorna true se e somente se essa equação tem pelo menos uma solução
{
    if (a == 0 && b == 0) // Lida com o caso de borda quando a = b = 0
    {
        if (c == 0)
        {
            x = y = 0; // Qualquer solução é válida aqui
            return true;
        }

        return false;
    }

    int gcd = gcdExtended(abs(a), abs(b), x, y);

    if (a < 0)
        x = -x; // Multiplica x por -1 se a < 0
    if (b < 0)
        y = -y; // Multiplica y por -1 se b < 0

    if (c % gcd != 0) // Checa se existe alguma solução
        return false;

    int t = c / gcd;
    x *= t;
    y *= t;

    return true;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int x, y;

    if (!findSolution(a, b, c, x, y))
        cout << "Não existe solução" << endl;
    else
        cout << "Solução: " << x << " " << y << endl;
}