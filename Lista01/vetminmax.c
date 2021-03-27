#include <stdio.h>
#include <stdlib.h>

void ler(int **M, int lin, int col){
    for(int i = 0; i < lin; i++){
        for(int x = 0; x < col; x++){
            scanf("%i", &M[i][x]);
        }
    }
}

int calcularminimax(int **M, int lin, int col){
    int max = 0;
    int mini = 999999;
    int linhaMax = 0;
    for(int i = 0; i < lin; i++){
        for(int x = 0; x < col; x++){
            if(M[i][x] > max){
                linhaMax = i;
                max = M[i][x];
            }
        }
    }
    for(int i = 0; i < col; i++){
        if(M[linhaMax][i] < mini){
            mini = M[linhaMax][i];
        }

    }
    return mini;
}

int main(){
    int nlin = 0;
    int ncol = 0;

    scanf("%i %i", &nlin, &ncol);

    int **M = NULL;
    M = (int **)malloc(nlin * sizeof(int *));
    for (int i = 0; i < nlin; i++)
        M[i] = (int *)malloc(ncol * sizeof(int));

    ler(M, nlin, ncol);

    printf("%i", calcularminimax(M, nlin, ncol));

    for(int i = 0; i < nlin; i++){
        free(M[i]);
    }
    free(M);
}