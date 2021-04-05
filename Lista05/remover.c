#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int key;
    struct NO *left;
    struct NO *right;
}NO;


NO* criar(){
    return NULL;
}


NO* inserir(NO *raiz, int x){

    if(raiz == NULL){
        NO* aux = (NO*)malloc(sizeof(NO));
        aux -> key = x;
        aux -> left = NULL;
        aux -> right = NULL;
        return aux;
    }
    else{
        if(x > raiz -> key){
            raiz -> right = inserir(raiz -> right, x);
        }
        else if(x < raiz -> key){
            raiz -> left = inserir(raiz -> left, x);
        }
        
    }
    return raiz;
}


void imprimir(NO* raiz){

    if(raiz != NULL){
        printf("%d ", raiz -> key);
        imprimir(raiz -> left);
        imprimir(raiz -> right);
    }
}

int tamanho(NO* raiz){
    if(raiz == NULL){
        return 0;
    }
    else{
        return 1 + tamanho(raiz -> left) + tamanho(raiz -> right);
    }
}

NO* remover(NO* raiz, int x){
    if(raiz == NULL){
        return NULL;
    }
    else{
        if(raiz -> key == x){
            if(raiz -> left == NULL && raiz -> right == NULL){
                free(raiz);
                return NULL;
            }
        
            else{
                if(raiz -> left == NULL || raiz -> right == NULL){
                    NO* aux;
                    if(raiz -> left != NULL){
                        aux = raiz -> left;
                    }
                    else{
                        aux = raiz -> right;
                    }
                    free(raiz);
                    return aux;
                }
                else{
                    NO* aux = raiz -> left;
                    while(aux -> right != NULL){
                        aux = aux -> right;
                    }
                    raiz -> key = aux -> key;
                    aux -> key = x;
                    raiz -> left = remover(raiz -> left, x);
                    return raiz;
                }
            }
        }
        else{
            if(x < raiz -> key){
                raiz -> left = remover(raiz -> left, x);
            }else{
                raiz -> right = remover(raiz -> right, x);
            }
            return raiz;
        }
    }
    return raiz;
}

void imprimirCrescente(NO* inicio, NO* raiz){
    if(inicio == NULL){
        printf("vazia");
        return;

    }
    if(raiz != NULL){
        imprimirCrescente(inicio, raiz -> left);
        printf("%d ", raiz -> key);
        imprimirCrescente(inicio, raiz -> right);
    }
}


void freeTree(NO* raiz){

    if(raiz != NULL){
        free(raiz -> left);
        free(raiz -> right);
        free(raiz);
    }
}

int main(){

    NO* tree = criar();

    int value = 0;
    scanf("%d", &value);

    int numRemove = 0;
    

    while(value != -1){
        tree = inserir(tree, value);
        scanf("%d", &value);
    }
    
    scanf("%d", &numRemove);
    
    tree = remover(tree, numRemove);
    imprimirCrescente(tree,tree);
}    