#include <stdio.h>
#include <stdlib.h>

int somatorio(int n){
    if(n == 0){
        return 0;
    }else{
        return n + somatorio (n-1);
    }
}

int main (){
    int n = 0;
    scanf("%i", &n);
    printf("%i\n", somatorio(n));
}
    
