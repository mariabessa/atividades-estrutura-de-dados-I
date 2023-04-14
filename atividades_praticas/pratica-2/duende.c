#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "duende.h"
#define MAX_NOME 20

typedef struct duende{
    int idade;
    char nome[MAX_NOME + 1];
    ESCALADO estaEscalado;
} Duende;

typedef struct time{
    Duende lider;
    Duende confeiteiro;
    Duende entregador;
    Duende embrulhador;
} Time;

// Manter como especificado
void lerQuantidade(int *qtdDuendes){ 
    scanf("%d", qtdDuendes);
}

// Manter como especificado
Duende *alocaDuendes(int qtdDuendes){ 

    Duende *duendes = (Duende *) malloc(qtdDuendes * sizeof(Duende));

    return duendes;

}

// Manter como especificado
Time *alocaTimes(int qtdTimes){ 

    Time *times = (Time *) malloc(qtdTimes* sizeof(Time));

    return times;
}

// Manter como especificado
void desalocaDuendes(Duende **duendes){ 
    free(*duendes);
 }

// Manter como especificado
void desalocaTimes(Time **times){ 
    free(*times);
}

// Manter como especificado
void lerDuendes(Duende *duendes, int qtdDuendes){ 
    for(int i = 0; i < qtdDuendes; i++){
        scanf("%s %d", duendes[i].nome, &duendes[i].idade);
    }
}

// Manter como especificado
void escalarTimes(Duende *duendes, Time *times, int qtdDuendes){
    int i, index;
    int qtdTime = qtdDuendes/4;
    // Escalando os lideres
    for (i=0; i<qtdTime; i++) {
        index = proximoMaisVelho(duendes, qtdDuendes);
        duendes[index].estaEscalado = SIM;
        strcpy(times[i].lider.nome, duendes[index].nome);
        times[i].lider.idade = duendes[index].idade;
    }

    // Escalando os confeiteiros
    for (i=0; i<qtdTime; i++) {
        index = proximoMaisVelho(duendes, qtdDuendes);
        duendes[index].estaEscalado = SIM;
        strcpy(times[i].confeiteiro.nome, duendes[index].nome);
        times[i].confeiteiro.idade = duendes[index].idade;
    }

    // Escalando os entregador
    for (i=0; i<qtdTime; i++) {
        index = proximoMaisVelho(duendes, qtdDuendes);
        duendes[index].estaEscalado = SIM;
        strcpy(times[i].entregador.nome, duendes[index].nome);
        times[i].entregador.idade = duendes[index].idade;
    }

    // Escalando os embrulhador
    for (i=0; i<qtdTime; i++) {
        index = proximoMaisVelho(duendes, qtdDuendes);
        duendes[index].estaEscalado = SIM;
        strcpy(times[i].embrulhador.nome, duendes[index].nome);
        times[i].embrulhador.idade = duendes[index].idade;
    }
}

int proximoMaisVelho(Duende *duendes, int qtdDuendes){

    int maior = 0;
    int index;

    for (int i = 0; i < qtdDuendes; i++){

        if(maior < duendes[i].idade && duendes[i].estaEscalado != SIM){
            maior = duendes[i].idade;
            index = i;
        }
    }
    return index;
}

// Manter como especificado
void printTimes(Time *times, int qtdTimes){
    for (int i=0; i<qtdTimes; i++) {
        printf("Time %d\n", i+1);
        printf("PILOTO > %s %d\n", times[i].lider.nome, times[i].lider.idade);
        printf("CONFEI > %s %d\n", times[i].confeiteiro.nome, times[i].confeiteiro.idade);
        printf("ENTREG > %s %d\n", times[i].entregador.nome, times[i].entregador.idade);
        printf("EMBRUL > %s %d\n\n", times[i].embrulhador.nome, times[i].embrulhador.idade);
    }
}
