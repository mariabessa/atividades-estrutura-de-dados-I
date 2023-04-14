#include <stdio.h>
#include "r9.h"

int main (){
    int soma =0, n;
    scanf("%d", &n);
    while(n != 0){
        soma = soma_r9(n);
        while(soma > 9){
            soma = soma_r9(n);
        }if(soma == 9){
            printf("%d is a multiple of 9\n");
        }else{
            printf("%d is not a multiple of 9\n");
        }
        soma = 0;
        scanf("%d", &n);
    }
}