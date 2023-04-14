# ifndef ordenacao_h
# define ordenacao_h
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int identificador;
    int pontos;
    int cestasFeitas;
    int cestasLevadas;
    float saldo; 
    int vitorias;
    int derrotas;
} Time;

// Manter como especificado
void ordenacao(Time *vetor, int n);

// Manter como especificado
Time *alocaVetor(int n);

// Manter como especificado
void desalocaVetor(Time **vetor);

// faz a comparacao utilizada para ordenar os times
int compare(Time t1, Time t2);

void heap_refaz(Time * times, int esquerda, int direita);

void heap_constroi(Time * v, int n);

void preencherDados(int time1, int pontos1, int time2, int pontos2, Time * times);

void calculaSaldo(Time * vetor, int n);
# endif
