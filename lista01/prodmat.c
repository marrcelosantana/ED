#include <stdio.h>
#include <stdlib.h>

void ler(int **M, int lin, int col){
    for(int i = 0; i < lin; i++){
        for(int x = 0; x < col; x++){
            scanf("%i", &M[i][x]);
        }
    }
}

void printar(int **M, int lin, int col){
    for(int i = 0; i < lin; i++){
        for(int x = 0; x < col - 1; x++){
            printf("%i ", M[i][x]);
        }
        printf("%i\n", M[i][col - 1]);
    }
}

int** getprod(int **M1, int **M2, int lin, int col){
    int **M = NULL;
    M = (int **)malloc(lin * sizeof(int *));
    for(int i = 0; i < lin; i++){
        M[i] = (int *)malloc(col * sizeof(int));
    }

    for(int j = 0; j < lin; j++){
        for(int x = 0; x < col; x++){
            for(int i = 0; i < col; i++){
                M[j][x] += M1[j][i] * M2[i][x];
            }
        }
    }
    return M;
}

int main(){
    int lin = 0;
    int col = 0;

    scanf("%i", &lin);
    col = lin;

    int **M1 = NULL;
    M1 = (int **)malloc(lin * sizeof(int *));
    for(int i = 0; i < lin; i++){
        M1[i] = (int *)malloc(col * sizeof(int));
    }

    int **M2 = NULL;
    M2 = (int **)malloc(lin * sizeof(int *));
    for(int i = 0; i < lin; i++){
        M2[i] = (int *)malloc(col * sizeof(int));

    }

    ler(M1, lin, col);
    ler(M2, lin, col);
    printar(getprod(M1, M2, lin, col), lin, col);

    for(int i = 0; i < lin; i++){
        free(M1[i]);
    }
    free(M1);

    for(int j = 0; j < col; j++){
        free(M2[j]);
    }
    free(M2);


}