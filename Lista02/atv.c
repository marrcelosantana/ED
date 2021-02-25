#include <stdio.h>
#include <stdlib.h>

void criarPart(int *vet, int size, int piv)
{
    for (int i = 0; i < size; i++)
    {
        if (vet[i] > vet[piv] && i < piv)
        {
            int aux = vet[i];
            for (int j = i; j < piv; j++)
            {
                vet[j] = vet[j + 1];
            }
            vet[piv] = aux;
            piv--;
            i = 0;
        }
        else if (vet[i] < vet[piv] && i > piv)
        {
            int aux = vet[i];
            for (int x = i; x > piv; x--)
            {
                vet[x] = vet[x - 1];
            }
            vet[piv] = aux;
            piv++;
            i = 0;
            
        }
    }
}

int main()
{
    int size = 0;
    int piv = 0;
    scanf("%i %i", &size, &piv);

    int *vet = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        scanf("%i", &vet[i]);
    }

    criarPart(vet, size, piv);
    for (int i = 0; i < size; i++)
    {
        printf("%i ", vet[i]);
    }
}