#include <stdio.h>
#include <stdlib.h>

int* getMM(int* V, int size){
    int* mm = (int *) malloc(2*sizeof(int));
    int max = -999999, min = 99999;
    for(int x = 0; x < size; x++){
        if(V[x] <= min) min = V[x];
        if(V[x] >= max) max = V[x];

    }

    mm[0] = min, mm[1] = max;
    return mm;
}

int main(){
    int n = 0;
    scanf("%i", &n);
    int* V = (int *) malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%i", &V[i] );
    }
    printf("%i %i", getMM(V, n)[0], getMM(V, n)[1]);
}