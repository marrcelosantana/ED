#include <stdio.h>
#include <stdlib.h>

struct no{
    int key;
    struct no *prox;
};

typedef struct no No;

int tamanho = 0;

No* criarNo(){
    No *novo = (No*)malloc(sizeof(No));
    return novo;
}

No* inserir (No* lista, int num){
    No *novo_no = criarNo();
    novo_no -> key = num;

    if(lista == NULL){
        lista = novo_no;
        novo_no -> prox = NULL;
    }else{
        novo_no -> prox = lista;
        lista = novo_no;
    }

    tamanho++;
    return lista;
}

void imprimir(No* lista){
    No *aux = lista;

    while(aux != NULL){
        printf("%d ", aux -> key);
        aux = aux -> prox;
    }
}

void medirLista(){
    printf("%d", tamanho);
}

int main(){
    No *lista = NULL;

    int x = 0;
    scanf("%d", &x);

    while(x != -1){
        lista = inserir(lista, x);
        scanf("%d", &x);
    }  
    medirLista(tamanho);
}
