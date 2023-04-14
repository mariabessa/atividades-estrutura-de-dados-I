#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Manter como especificado
void ordena(Aluno *alunos, int n) {
	int i, j, h ;
    Aluno aux;
    for (h = 1; h < n; h = 3 * h + 1) ; /* h inicial . */
    do {
        h = ( h - 1) / 3; /* atualiza h. */
        for (i = h ; i < n ; i ++) {
            strcpy(aux.nome, alunos[i].nome);
            j = i ;
        /* Comparações entre elementos com distância h: */
        while (compare(alunos[j-h].nome, aux.nome) < 0) {
            strcpy(alunos[j].nome, alunos[j-h].nome);
            j -= h;
            if (j < h) 
                break;
        }
        strcpy(alunos[j].nome, aux.nome);
        }
    } while (h != 1) ;
}

// Manter como especificado
int compare(const char* aluno1, const char* aluno2) {
    return strcmp(aluno1,aluno2);
    // PREENCHER AQUI
}

/* Manter como especificado */
void imprimeResposta(Aluno* alunos, int n, int k) {
    printf("%s\n", alunos[k-1].nome);
}

/* Manter como especificado */
Aluno* alocaAlunos(int n) {
    Aluno *alunos = malloc(sizeof(Aluno) * n);
    return alunos;
}

/* Manter como especificado */
void liberaAlunos(Aluno** alunos) {
    free(*alunos);
}

/* Manter como especificado */
void leAlunos(Aluno* alunos, int n) {
    for (int i = 0; i < n; i++){
		scanf("%s", alunos[i].nome);
	}
}

/* Manter como especificado */
void leQuantidades(int* n, int* k) {
    scanf("%d %d", n, k);
}

