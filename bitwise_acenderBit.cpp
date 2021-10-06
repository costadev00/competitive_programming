// Para acender o k-ésimo bit de um número, precisamos de adicionar 2^k
//   a este número no caso do k-ésimo bit estar apagado, ou não fazer nada se não estiver,
//  já que neste caso, o k-ésimo bit já está ligado. Por isso, atualizamos o número para o OR de si mesmo e 2^k
void acenderBit(int &x, int k)
{
    x |= (1 << k);
}
