#include <iostream>
using namespace std;

const int MAXN = 1000010;

int main()
{
    int n, q;
    int v[MAXN], psa[MAXN];

    cin >> n >> q;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    psa[0] = v[0];

    for (int i = 1; i < n; i++)
        psa[i] = psa[i - 1] + v[i];

    for (int i = 0; i < q; i++)
    {
        int L, R;
        cin >> L >> R;

        int sum;

        if (L == 0)
            sum = psa[R]; // Versão mais fácil
        else
            sum = psa[R] - psa[L - 1];

        cout << "Soma do intervalo: " << sum << endl;
    }
}
