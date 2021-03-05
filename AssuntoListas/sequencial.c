#include <stdio.h>
#include <stdlib.h>

double* criarListaSequencial(int n) {
    return (double *) malloc(n*sizeof(double));
}

void desalocarLista(double *L) {
    free(L);
}

int adicionaLista(double *L, int *cardinalidade, int tamanho, double x) {
    if(*cardinalidade == tamanho) return 0;
        else {
        L[*cardinalidade] = x;   // *(L+cardinalidade) = x
        (*cardinalidade)++;
        return 1;
    }
}

int buscaLista(double *L, int cardinalidade, double x) {
    for(int i = 0; i < cardinalidade; i++)
        if(L[i] == x) return i;
        return -1;
}

int removeLista(double *L, int *cardinalidade, double x) {
    int i = buscaLista(L,*cardinalidade,x);
        if(i > -1) {
        (*cardinalidade)--;
        L[i] = L[*cardinalidade];
    }
    return i;
}

void imprimir(double *L, int cardinalidade) {
    for(int i = 0; i < cardinalidade; i++)
        printf("%.0lf ", L[i]);
        printf("\n");
}

int main() {

    int tamanho = 0;
    int cardinalidade = 0;
    double *LS = NULL;

    printf("Digite o tamanho da lista sequencial: ");
    scanf("%d",&tamanho);
   
    LS = criarListaSequencial(tamanho);

    for(int i = 0; i < tamanho; i++){
        adicionaLista(LS, &cardinalidade, tamanho, i);
    }
        
    imprimir(LS, cardinalidade);
    removeLista(LS, &cardinalidade, 5);
    imprimir(LS, cardinalidade);

    desalocarLista(LS);

}