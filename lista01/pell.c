#include <stdio.h>
#include <stdlib.h>

int pell(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }else{
        return 2 * pell(n - 1) + pell(n - 2);
    }
}

int main(){
    int n = 0;
    scanf("%i", &n);
    printf("%i", pell(n));
}