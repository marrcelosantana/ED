#include <stdio.h>
#include <stdlib.h>

 typedef struct NO
 {
     int key;
     struct NO *prox;
 }NO;

 typedef struct PILHA
 {
     NO *topo;
 }PILHA;

void iniciarPilha(PILHA *p){
    p -> topo = NULL;
}

void empilhar(int x, PILHA *p){
    NO *novo_no = (NO*) malloc(sizeof(NO));
    if(novo_no == NULL){
        printf("Erro de alocação. \n");
        return;
    }
    else{
        novo_no -> key = x;
        novo_no -> prox = p -> topo;
        p -> topo = novo_no;
    }
}

int desempilhar(PILHA *p){
    NO* novo_no = p -> topo;
    int aux;
    if(novo_no == NULL){
        printf("Pilha vazia.\n");
        return 0;

    }else{
        p -> topo = novo_no -> prox;
        novo_no -> prox = NULL;
        aux = novo_no -> key;
        free(novo_no);
        return aux;
    }
}

void imprimir(PILHA *p){
    NO *novo_no = p -> topo;
    if(novo_no == NULL){
        printf("Pilha vazia.\n");
        return;

    }else{
        while(novo_no != NULL){
            printf("%d ", novo_no -> key);
            novo_no = novo_no -> prox;
        }
        printf("\n");
    }

}


int main(){

    PILHA *p1 = (PILHA*) malloc(sizeof(PILHA));
    if(p1 == NULL){
        printf("Erro de alocação da pilha\n");
        exit(0);
    }else{
        iniciarPilha(p1);
        empilhar(10, p1);
        empilhar(20, p1);
        empilhar(30, p1);
        empilhar(67, p1);
        imprimir(p1);

        desempilhar(p1);
        imprimir(p1);
    }

} 
 




