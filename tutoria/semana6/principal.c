#include "busca.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int main(){
    int chave, pos;
    int *vetor = malloc(sizeof(int) * MAX);
    for(int i = 0; i < MAX; i++){
        scanf("%d", &vetor[i]);
    }
    scanf("%d", &chave);
    mergeSort(vetor, 0, MAX-1);
    pos = vetorFind(vetor, chave);
    printf("chave %d na posicao %d\n", chave, pos);
    free(vetor);
    return 0;
}