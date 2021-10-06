// Um número x é uma potência de dois se, e só somente se, o AND de x e x - 1 for igual a zero.
//  Para provar esta afirmação, vamos olhar para o maior (o mais à esquerda) bit de x.
//  Vamos chamar esse bit de kk-ésimo bit. Se xx não é uma potência de dois, os k-ésimos bits de x e x - 1 são iguais a
//  1. Assim, o and não é igual a zero. Se em vez disso, x é uma potência de dois, então x - 1 é um número
//  onde todos os bits à direita do k-ésimo são iguais a um, portanto o and de x e x - 1 é zero.
bool ehPotenciaDeDois(int x)
{
    return (x & (x - 1)) == 0;
}
