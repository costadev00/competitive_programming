int search(int a[], int L, int R, int value)
{
    int mid = (L + R) / 2; // Meio do intervalo

    if (L > R)     // Intervalo invalido
        return -1; // Valor não encontrado

    if (a[mid] == value) // O valor foi encontrado
        return mid;

    if (a[mid] < value) // Descarto o intervalo à esquerda
        return search(a, mid + 1, R, value);
    else // Descarto o intervalo à direita
        return search(a, L, mid - 1, value);
}
