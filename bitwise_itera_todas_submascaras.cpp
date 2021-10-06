// À primeira vista, isto parece mágica. Mas compreendamos como funciona. Suponha que temos uma máscara ss e queremos passar para a seguinte.
// Ao subtrair 1 de ss estamos apagando o primeiro bit aceso (mais à direita) de s e colocando todos os bit à sua direita como 1.
// Depois, ao executar o AND desta máscara de bits e a original, estamos apagando todos os bits que não estão acesos em m e possivelmente ligando alguns bits
// à direita desse mesmo bit, que antes estavam desligados.
// Portanto, este algoritmo itera por todas as sub-máscaras de mm em ordem decrescente
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m = 10;
    for (int s = m; s > 0; s = (s - 1) & m)
    {
        cout << s << endl;
    }
    return 0;
}