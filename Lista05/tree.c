#include <stdio.h>
#include <stdlib.h>


typedef struct NO{
    int key;
    struct NO *left;
    struct NO *right;
}NO;


NO *criar(){
    return NULL;
}


NO *inserir(NO *raiz, int x){

    if(raiz == NULL){
        NO *aux = (NO*)malloc(sizeof(NO));
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

NO *buscar(NO *raiz, int cod){
    if(raiz != NULL){
        if(raiz -> key == cod){
            return raiz;
        }else{
            if(cod > raiz -> key){
                return buscar(raiz -> right, cod);
            }else{
                return buscar(raiz -> left, cod);
            }
        }
    }

    return NULL;
}

void imprimir(NO *raiz){

    if(raiz != NULL){
        printf("%d ", raiz -> key);
        imprimir(raiz -> left);
        imprimir(raiz -> right);
    }
}

void freeArvore(NO *raiz){

    if(raiz != NULL){
        free(raiz -> left);
        free(raiz -> right);
        free(raiz);
    }
}


int main(){
    
    NO *tree = criar ();
    
    int value = 0;
    scanf("%d", &value);
    
    while(value != -1){
        tree = inserir(tree, value);
        scanf("%d", &value);
    }

    imprimir(tree);
    free(tree);

}