#include "busca.h"

int vetorFind(int* vetor, int x){
    return vetorBinario(vetor, 0, 999, x);
}

int vetorBinario(int * vetor, int esq, int dir, int x){
    int meio = (esq + dir) / 2;
   if (vetor[meio] != x && esq == dir)
        return -1;
    else if (x > vetor[meio])
        return vetorBinario(vetor, meio+1, dir, x);
    else if (x < vetor[meio])
        return vetorBinario(vetor, esq, meio - 1, x);
    else
        return meio;
}

void mergeSort(int *vetor, int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(vetor, l, m);
        mergeSort(vetor, m+1, r);
        merge(vetor, l, r, m);
    }
}

void merge(int *vetor, int l, int r, int m){
    int tam_l= m - l + 1;
    int tam_r = r - m;
    int *vL = copy(vetor, tam_l, l);
    int *vR = copy(vetor, tam_r, m+1);
    int i = 0, j = 0, k;
    for(k=l; k<=r; k++){
        if(i==tam_l){
            vetor[k] = vR[j++]; 
        }else if(j==tam_r){
            vetor[k] = vL[i++]; 
        }else if(vL[i] <= vR[j]){
            vetor[k] = vL[i++]; 
        }else{
            vetor[k] = vR[j++]; 
        }
    }
    free(vR);
    free(vL);
}

int *copy(int * vetor, int tamanho, int n){
    int *aux = malloc(sizeof(int) * tamanho);
    for (int i = 0; i < tamanho; i++){ 
        aux[i] = vetor[i+n]; 
    }
    return aux;
}