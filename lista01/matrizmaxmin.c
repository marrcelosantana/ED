#include <stdio.h>
#include <stdlib.h>

void ler(int **M, int lin, int col){
    for(int i = 0; i < lin; i++){
        for(int x = 0; x < col; x++){
            scanf("%i", &M[i][x]);
        }
    }
}

int calcularmin(int linha, int **M, int col){
    int min = 99999;
    for(int i = 0; i < col; i++){
        if(M[linha][i] < min){
            min = M[linha][i];
        }
    }
    return min;
}

int calcularmax(int **M, int lin, int col){
    int max = 0;
    int linha = 0;
    for(int i = 0; i < lin; i++){
        for(int x = 0; x < col; x++){
            if(M[i][x] > max){
                linha = i;
                max = M[i][x];
            }
        }
    }
    return linha;
}

int main(){
    int lin = 0;
    int col = 0;

    scanf("%i %i", &lin, &col);

    int **M = NULL;
    M = (int **)malloc(lin * sizeof(int *));
    for(int i = 0; i < lin; i++){
        M[i] = (int *)malloc(col * sizeof(int));

        ler(M, lin, col);
        printf("%i", calcularmin(calcularmax(M, lin, col), M, col));
    }

    for(int j = 0; j < lin; j++){
        free(M[j]);
    }
    free(M);
}
