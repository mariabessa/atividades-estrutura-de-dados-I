#include "ordenacao.h"
#include <stdio.h>

int main ()
{

	int *vetor;
	int i, n, movimentos;
	while(scanf("%d", &n), n)
	{	

		vetor = alocaVetor(vetor, n);
		for(i = 0; i < n; i++){
			scanf("%d", &vetor[i]);
		}
		ordenacao(vetor, n, &movimentos);
		if(movimentos%2==0){
			printf("Carlos\n");
		}else{
			printf("Marcelo\n");
		}
		movimentos = 0;
		vetor = desalocaVetor(vetor);
	}
	
	return 0;
}
