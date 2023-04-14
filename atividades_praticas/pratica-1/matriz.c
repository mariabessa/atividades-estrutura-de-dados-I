#include "matriz.h"
#include<stdio.h>
#include<stdlib.h>

void lerOrdem(int *ordem) {
	scanf("%d", ordem);
	
}

//manter como especificado
double **alocaMatriz(int ordem) {
	double **M = (double**) malloc(sizeof(double*) * ordem);
	for (int i = 0; i < ordem; i++){
		M[i] = (double*) malloc(sizeof(double) * ordem);
	}
	return M;
}

//manter como especificado
void desalocaMatriz(double ***M, int ordem) {
	for (int i = 0; i < ordem; i++){ 
		free((*M)[i]);
	}
	free(*M);
}

//manter como especificado
void lerOperacao(char *operacao) {
	scanf(" %c", operacao);
}

void lerMatriz(double **M, int ordem) {
	for(int i = 0; i < ordem; i++){
		for(int j = 0; j < ordem; j++){
			scanf("%lf", &M[i][j]);
		}
	}
}

double somaMatriz(double **M, int ordem) {
	double soma = 0.0;
	for (int i = 0; i < ordem / 2; i++){ 
		for (int j = i + 1; j < ordem - 1 - i; j++){
			soma += M[i][j];
		}
	}
	return soma;		
}

double media(double resultado, int ordem) {
	int num = 0;
	while (ordem > 1){
		num += ordem - 2;
		ordem = ordem - 2;
	}
	double med = resultado / (double)num;
	return med;
}

void printResultado(double resultado) {
	printf("%.1f\n", resultado);
}
