#include "duende.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { NAO=0, SIM } ESCALADO;

struct duende {
    char nome[20];
    int idade;
    ESCALADO escalado;
};

// Manter como especificado
void lerQuantidade(int *qtd) { 
    scanf("%d", qtd);
}

// Manter como especificado
Duende *alocaDuendes(int n) { 
    Duende *duendes = (Duende *) malloc (n * sizeof(Duende));
    for (int i = 0; i < n; i++){
        duendes[i].escalado = NAO;
    }
    return duendes;
}

// Manter como especificado
Duende *copiaDuende(Duende *duendes, int i) {
    /* Aloca um novo duende baseado nos dados de um outro duende */ 
    Duende* duende = (Duende *) malloc (sizeof(Duende));
    duende->idade = duendes[i].idade;
    strcpy(duende->nome,duendes[i].nome);
    duende->escalado = duendes[i].escalado;
    return duende;
}

// Manter como especificado
void desalocaDuendes(Duende **duendes){
    free(*duendes);
}

// Manter como especificado
void lerDuendes(Duende *duendes, int n) {
    for (int i = 0; i < n; i++){
        scanf("%s %d", duendes[i].nome, &duendes[i].idade);
    }
}

// Manter como especificado
int proximoMaisVelho(Duende *duendes, int n) {
    int aux, maisVelho = 0;
    for (int i = 0; i < n; i++){
        if (duendes[i].idade > maisVelho && duendes[i].escalado != SIM){
            maisVelho = duendes[i].idade;
            aux = i;
        }
    }
    return aux;

}

// Manter como especificado
void escalarDuende(Duende *duendes, int index) {
    duendes[index].escalado = SIM;
    /* Dado um vetor de duendes, "seta" como escalado um duende */
    /* PREENCHER AQUI */ 
}

// Manter como especificado
void printDuende(Duende *duende) {
    printf("%s %d \n", duende->nome, duende->idade);
}