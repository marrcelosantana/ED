#include <stdio.h>
#include <stdlib.h>

struct no{
    int key;
    struct no *prox;
};

typedef struct no No;

No* criarNo(){
    No *novo = (No*)malloc(sizeof(No));
    return novo;
}

No* inserirInicio (No* lista, int num){
    No *novo_no = criarNo();
    novo_no -> key = num;

    if(lista == NULL){
        lista = novo_no;
        novo_no -> prox = NULL;
    }else{
        novo_no -> prox = lista;
        lista = novo_no;
    }

    return lista;
}


void imprimir(No* lista){
    No *aux = lista;

    while(aux != NULL){
        printf("%d ", aux -> key);
        aux = aux -> prox;
    }
}


int main(){
    No *lista = NULL;

    int x = 0;
    scanf("%d", &x);

    while(x != -1){
        lista = inserirInicio(lista, x);
        scanf("%d", &x);
    }
    
    imprimir(lista);

    return 0;
}
