#ifndef busca_h
#define busca_h
#include <stdio.h>
#include <stdlib.h>


int vetorFind(int* vetor, int x);
int vetorBinario(int * vetor, int esq, int dir, int x);
void mergeSort(int *vetor, int l, int r);
void merge(int *vetor, int l, int r, int m);
int *copy(int * vetor, int tamanho, int n);



#endif