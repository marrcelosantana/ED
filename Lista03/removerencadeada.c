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

void imprimir(No* lista){
    No *aux = lista;
    
    if(aux == NULL){
        printf("vazia");
    }
    while(aux != NULL){
        printf("%d ", aux -> key);
        aux = aux -> prox;
    }
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

    tamanho++;
    return lista;
}

No* removeAll(No* lista, int num){
    No* ponteiro = lista;
    No* novo_no = NULL;
    while(ponteiro != NULL){
        if(ponteiro -> key != num){
            novo_no = inserirInicio(novo_no, ponteiro -> key);
        }
        
        ponteiro = ponteiro -> prox;
    }
    return novo_no;
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


void medirLista(){
    printf("%d", tamanho);

}

int main(){
    No *lista = NULL;
    
    int x = 0;
    scanf("%d", &x);

    while(x != -1){
        lista = inserirInicio(lista, x);
        scanf("%d", &x);
    }

    scanf("%d", &x);
    
    No *retorno = removeAll(lista, x);

    imprimir(retorno);
   

    return 0;
}
