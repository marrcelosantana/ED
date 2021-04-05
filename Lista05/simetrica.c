#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int key;
    struct NO *left;
    struct NO *right;
    struct NO* pai;
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
        aux -> pai = NULL;  
        return aux;
    }
    else{
        if(x > raiz -> key){
            raiz -> right = inserir(raiz -> right, x);
            raiz -> right -> pai = raiz;
        }
        else if(x < raiz -> key){
            raiz -> left = inserir(raiz -> left, x);
            raiz -> left -> pai = raiz;
        }
        
    }
    return raiz;
}

NO *encontrarMinimo(NO *raiz){

    NO* aux = raiz;

    if(aux != NULL){
        while(aux -> left != NULL){
            aux = aux -> left;
        }
        return aux;
    }

    return NULL;
}


NO* sucessor(NO* raiz){
    if(raiz -> right != NULL){
        return encontrarMinimo(raiz -> right);
    }    
    NO* u = raiz -> right;
    while(raiz != NULL && u == raiz -> right){
        u = raiz;
        raiz = raiz -> pai;
    }
    return raiz;
}

NO* percursoPreOrdem(NO* raiz){
        if(raiz != NULL){
            percursoPreOrdem(raiz -> left);
            printf("%d ", raiz -> key);
            percursoPreOrdem(raiz -> right);      
        }
        return NULL;
}

void imprimir(NO* raiz){

    if(raiz != NULL){
        printf("%d ", raiz -> key);
        imprimir(raiz -> left);
        imprimir(raiz -> right);
    }
}

void imprimirSimetrica(NO* raiz){
    NO* aux = encontrarMinimo(raiz);
    while(aux != NULL){
        printf("%d ", aux -> key);
        aux = sucessor(aux);
    }
}


void freeTree(NO* raiz){

    if(raiz != NULL){
        free(raiz -> left);
        free(raiz -> right);
        free(raiz -> pai);
        free(raiz);
    }
}

int main(){

    NO* tree = criar();

    int value = 0;
    scanf("%d", &value);


    while(value != -1){
        tree = inserir(tree, value);
        scanf("%d", &value);
    }
    
    imprimirSimetrica(tree);
}    