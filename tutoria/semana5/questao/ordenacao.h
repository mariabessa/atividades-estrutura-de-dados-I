#ifndef ordenacao_h
#define ordenacao_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_TAM 50


typedef struct{
    char nome[MAX_TAM];
    char cor[9];
    char tamanho;
}Pedidos;

void leDados(Pedidos *pedidos, int n);
int compare(Pedidos, Pedidos);
void heapRefaz(Pedidos *, int, int);
void heapConstroi(Pedidos *, int);
void heapSort(Pedidos *v, int n);
void imprimir(Pedidos *pedidos, int n);
#endif