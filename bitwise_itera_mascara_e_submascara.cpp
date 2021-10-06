//O algoritmo a seguir itera por todas as sub-máscaras de cada máscara de nn bits com complexidade O(3^n)

//Para provar a afirmação anterior, vamos olhar para qualquer bit de um número mm de nn bits. Há três casos em que ele pode estar:
// 1 - O bit não está incluído em m;
// 2 - O bit está incluído em m mas não na submáscara atual;
// 3 - O bit está incluído tanto em mm como na submáscara atual.

// Como existem n bits e 3 possibilidades para cada um deles, a complexidade total é O(3 ^ n) O(3 n).
void todasAsSubmascaras(int n)
{
    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int submask = mask; submask > 0; submask = (submask - 1) & mask)
        {
            // faz algo
        }
    }
}
