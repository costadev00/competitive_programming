// Estes dois operadores bitwise trabalham de uma forma muito semelhante.
// Ambos recebem um número x e um número k e devolvem o valor de x com os seus bits deslocados
// k vezes para a esquerda ou k vezes para a direita.
// Deslocar um número x k vezes para a direita pode ser visto como apagar os últimos k dígitos da representação binária de x,
// e deslocar um número x k vezes para a esquerda pode ser visto como adicionar k zeros no
// final da representação binária de x.Por exemplo,se a = 1010 e k = 2, então a << k = 101000​
//   e a >> k = 10 >> k = 10
// Note que aplicar o Leftshift a um número é o mesmo que multiplicá-lo por 2^k
//   e aplicar o Rightshift é o mesmo que realizar uma divisão inteira por 2^k

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 10;               // a é 1010 em binário
    cout << (a << 2) << endl; // Imprime 40, que é 101000 em binário
    cout << (a >> 2) << endl; // Imprime 2, que é 10 em binário
}