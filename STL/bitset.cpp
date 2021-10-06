#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    bitset<16> b;            // Cria um bitset de 16 bits.
    b |= (1 << 10);          // Acende o 10º bit de b.
    cout << b << endl;       // Imprime 0000010000000000.
    bitset<16> a(10);        // Cria um bitset de 16 bits iniciado com 0000000000001010.
    cout << (a | b) << endl; // Imprime 0000010000001010. Isso só funciona se a e b tiverem o mesmo tamanho.
    cout << ~a << endl;      // Imprime 1111111111110101.
}
