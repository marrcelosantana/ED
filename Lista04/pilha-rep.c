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

void criar(PILHA *p){
    p -> topo = NULL;
}
void inserir(int x, PILHA *p){
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

int remover(PILHA *p){
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

PILHA* inverter(PILHA *p){
    PILHA *p2 = (PILHA*) malloc(sizeof(PILHA));
    criar(p2);
    NO* pilha = p -> topo;

    while(pilha -> prox != NULL){
        inserir(pilha -> key, p2);
        pilha = pilha -> prox;
    }
    inserir(pilha -> key, p2);
    return p2;
}

PILHA* removerRepetidos(PILHA *p){
    NO* novo_no = inverter(p) -> topo;
    int vet [999];
    PILHA *p2 = (PILHA*) malloc(sizeof(PILHA));
    criar(p2); 

    NO* aux = p2 -> topo;

    int size = 0;
    int tem = 0;
    int ultimo = 1;
    
    while(novo_no -> prox != NULL || ultimo == 1){
        tem = 0;
        for(int i = 0; i < size; i++){
            if(vet[i] == novo_no -> key){
                tem = 1;
                break;
            }     
        }
        if(tem == 0){
            vet[size] = novo_no -> key;
            size++;
            inserir(novo_no -> key, p2);
        }
        if(novo_no -> prox == NULL && ultimo == 1){
            ultimo = 0;
        }
        else{
            novo_no = novo_no -> prox;
        }
        
    }
    return p2;
}


int main(){

    PILHA *p1 = (PILHA*) malloc(sizeof(PILHA));

    int x = 0;
    scanf("%d", &x);

    criar(p1);
    while(x != -1){
        inserir(x, p1);
        scanf("%d", &x);
    }

    p1 = removerRepetidos(p1);
    imprimir(inverter(p1));
        
} 
 



