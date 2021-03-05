#include <stdio.h>
#include <stdlib.h>

struct NODE_ {
    double chave;
    struct NODE_ *prox;
};

typedef struct NODE_ NODE;

int cardinalidade = 0;
NODE *noCabeca = NULL;

int criarLista() {        // O(1)
    noCabeca = (NODE*) malloc(sizeof(NODE));
    if(noCabeca != NULL) {
        noCabeca -> chave = 0;
        noCabeca -> prox = NULL;
        cardinalidade = 0;
        return 1;

    } else{
        return 0;
    } 
}

int adicionar(double x) {    // O(1)
    NODE *novo = (NODE*) malloc(sizeof(NODE));
    
    if(novo != NULL) {
        novo -> chave = x;
        novo -> prox = noCabeca -> prox;
        noCabeca -> prox = novo;
        cardinalidade++;
        return 1;

    } else{
        return 0;
    } 
}

NODE* buscar(double x) {    // O(n)
    NODE *p = noCabeca;

    while(p -> prox != NULL && p -> prox -> chave != x){
        p = p -> prox;
    } 
    if(p -> prox != NULL){
        return p;
    } 
    else{
        return NULL;
    } 
}

int remover(double x) {        // O(n)

    NODE *anterior = buscar(x);

    if(anterior != NULL) {
        NODE *aux = anterior -> prox;
        anterior -> prox = anterior -> prox -> prox; 
        free(aux);
        return 1;

    } else{
        return 0;
    } 
}

void imprimir() {        // O(n)

    NODE *p = noCabeca -> prox;
    if(p == NULL){
        printf("Vazia!");
    } 
    while(p != NULL) {
        printf("%.0lf ", p -> chave);
        p = p -> prox;
    }
    printf("\n");
}

int main() {

    criarLista();
    adicionar(1);
    adicionar(2);
    adicionar(3);
    imprimir();
    remover(2);
    remover(1);
    remover(3);
    imprimir();

    return 0;
}