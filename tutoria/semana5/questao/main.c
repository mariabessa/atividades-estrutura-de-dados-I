#include "ordenacao.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    int n;
    scanf("%d", &n);
    while(n!=0){
        getchar();
        Pedidos *pedidos = malloc(sizeof(Pedidos) * n);
        leDados(pedidos, n);
        heapSort(pedidos, n);
        imprimir(pedidos, n);
        scanf("%d", &n);
        if(n!= 0){
            printf("\n");
        }
        free(pedidos);
    }
    return 0;
}
