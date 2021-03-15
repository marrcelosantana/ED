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

No* concatenar(No *lista1, No *lista2){
    No* ponteiro = lista2;
    No* novo_no = NULL;
    while(ponteiro != NULL){
        novo_no = inserir(novo_no, ponteiro -> key);
        ponteiro = ponteiro -> prox;
    }
    ponteiro = lista1;
    while(ponteiro != NULL){
        novo_no = inserir(novo_no, ponteiro -> key);
        ponteiro = ponteiro -> prox;
    }
    return novo_no;
}

int main(){
    No *lista1 = NULL;
    No *lista2 = NULL;
    No *resultado = NULL;

    int x = 0;
    scanf("%d", &x);

    while(x != -1){
        lista1 = inserir(lista1, x);
        scanf("%d", &x);
    }  
    scanf("%d", &x);

    while(x != -1){
        lista2 = inserir(lista2, x);
        scanf("%d", &x);
    }  
    
    resultado = concatenar(lista1,lista2);

    imprimir(resultado);

    return 0;
}
