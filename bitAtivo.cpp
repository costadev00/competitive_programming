// Para verificar se o k-ésimo bit de um número xx está ativo, é suficiente verificar se o AND deste número e 2^k
//   é diferente de 0. Isto porque 2^k
// é um número onde todos os seus bits, exceto um, são iguais a zero, portanto, para todos os bits 0, depois do operador AND, os bits resultantes nestas posições
// serão certamente 0's. O k - ésimo bit é um pouco diferente uma vez que é um 1; o k-ésimo bit resultante só será um 0 se o k-ésimo bit de x for também igual a 0.
// Assim, se todos os bits resultantes forem iguais a 0, significa que o k-ésimo bit de x não está ativo.
bool estaAtivo(int x, int k)
{
    return (x & (1 << k)) != 0;
}
