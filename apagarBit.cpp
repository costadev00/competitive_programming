// Para apagar o kk-ésimo de um número, precisamos de subtrair 2^k
//   deste número, no caso do k-ésimo bit estar ligado, ou não fazer nada se não estiver, pois neste caso o k-ésimo bit já está desligado.
// Assim, atualizamos o número para o AND de si mesmo e um número a, onde a é um número com todos os bits, exceto o k-ésimo, iguais a 1.
//  Assim, o valor de a é o complemento de 1 de 2^k
void apagarBit(int &x, int k)
{
    x &= ~(1 << k);
}
