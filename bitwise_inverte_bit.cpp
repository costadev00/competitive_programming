// Para inverter o kk-ésimo bit de um número, precisamos de adicionar 2^k2
//   a este número se o kk-ésimo bit estiver apagado, ou subtrair 2^k2
//   se estiver aceso. Assim, atualizamos o número para o XOR de si mesmo e 2^k2
void inverterBit(int &x, int k)
{
    x ^= (1 << k);
}
