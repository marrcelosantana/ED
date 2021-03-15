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

No* inserirFinal(No* lista, int num){
    No *last_no = criarNo();
    last_no -> key = num;

    if(lista == NULL){
        lista = last_no;
        last_no -> prox = NULL;
    }else{
        No* aux = lista;
        while(aux -> prox != NULL){
            aux = aux -> prox;
        }
        last_no -> prox = NULL;
        aux -> prox = last_no;
    }

    return lista;
}

void imprimirInverso(No* lista){
    if(lista == NULL){
        return;
    }
    imprimirInverso(lista -> prox);
    printf("%d ", lista -> key);
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
        lista = inserirFinal(lista, x);
        scanf("%d", &x);
    }
    
    imprimirInverso(lista);

    return 0;
}
