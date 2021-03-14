#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double *criarListaSequencial(int n)
{
    return (double *)malloc(n * sizeof(double));
}

void desalocarLista(double *L)
{
    free(L);
}

int adicionaLista(double *L, int *cardinalidade, int tamanho, double x)
{
    if (*cardinalidade == tamanho)
        return 0;
    else
    {
        L[*cardinalidade] = x;
        (*cardinalidade)++;
        return 1;
    }
}

int buscaLista(double *L, int cardinalidade, double x)
{
    for (int i = 0; i < cardinalidade; i++)
        if (L[i] == x)
            return i;
    return -1;
}

int removeLista(double *L, int *cardinalidade, double x)
{
    int i = buscaLista(L, *cardinalidade, x);
    if (i > -1)
    {
        (*cardinalidade)--;
        L[i] = L[*cardinalidade];
    }
    return i;
}

void imprimir(double *L, int cardinalidade)
{
    bool vazio = true;


    for (int i = 0; i < cardinalidade; i++)
        if (L[i] != -1)
        {
            printf("%.0lf ", L[i]);
            vazio = false;
        }
        if(vazio){
            printf("vazia");
        }
    printf("\n");
}

void removerAll(double *L, int *cardinalidade, int x)
{
    for (int i = 0; i < *cardinalidade; i++)
    {
        if (L[i] == x)
        {
            L[i] = -1;
        }
    }
}

int main()
{
    int tamanho = 99;
    int cardinalidade = 0;
    double *LS = NULL;
    int x = 0;

    LS = criarListaSequencial(tamanho);

    scanf("%d", &x);

    while (x != -1)
    {
        adicionaLista(LS, &cardinalidade, tamanho, x);
        scanf("%d", &x);
    }
    
    scanf("%d", &x);
    
    removerAll(LS, &cardinalidade, x);
    imprimir(LS, cardinalidade);
    desalocarLista(LS);
}