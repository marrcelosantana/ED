#include <stdio.h>
#include <stdlib.h>

struct FILASEQ {
	double *V;
	int capacidade;
	int ini;
	int fim;
	int cardinalidade;
};
typedef struct FILASEQ FILA;

int criarFila(FILA *pF, int n) {	
	pF -> V = (double *) malloc(n*sizeof(double));
	if(pF -> V != NULL) {
		pF -> capacidade = n;
		pF -> ini = 0;
		pF -> fim = -1;
		pF -> cardinalidade = 0;
		return 1;
	}
	return 0;
}

int inserirFila(FILA *pF, double x) {
	if(pF -> cardinalidade == pF -> capacidade){
        return 0;
    } 
	pF -> fim = (pF -> fim+1) % pF -> capacidade;
	pF -> V[pF -> fim] = x;
	(pF -> cardinalidade)++;
	return 1;
}

int removerFila(FILA *pF) {
	if(pF -> cardinalidade == 0){
        return 0;
    } 
	pF -> ini = (pF -> ini + 1) % pF -> capacidade;
	(pF -> cardinalidade)--;
	return 1;
}

void desalocarFila(FILA *pF) {
	if(pF -> V != NULL){
        free(pF -> V);
    } 
	pF -> V = NULL;
}

void imprimir(FILA *pF) {
	if(pF -> cardinalidade > 0) {
		for(int i= pF -> ini; i <= pF -> fim; i=(i+1) % pF -> capacidade)
			printf("%.1lf ", pF -> V[i]);
        	printf("\n");
	} else printf("Vazia\n");
}

int main() {
   FILA F;

   criarFila(&F,5);
   inserirFila(&F,1.5);
   inserirFila(&F,2.5);
   imprimir(&F);
   removerFila(&F);
   removerFila(&F);
   removerFila(&F);
   imprimir(&F);

   return 0;
}