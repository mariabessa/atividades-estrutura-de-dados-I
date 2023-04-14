#include <stdio.h>


#include "ordenacao.h"

int main() {
    int n;
    scanf("%d", &n);
    Upa* upas = alocaUpas(n);
    lerUpas(&upas, n);
    mergeSort(upas, 0, n - 1);
    imprime(upas, n);
    desalocaUpas(&upas);
    return 0; 
}