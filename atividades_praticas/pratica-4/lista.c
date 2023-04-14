#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia as variaveis da lista
void TLista_Inicia(TLista *pLista) {
    pLista ->pPrimeiro = (TCelula*) malloc (sizeof(TCelula));
    pLista->pUltimo = pLista -> pPrimeiro;
    pLista-> pPrimeiro -> pProx = NULL;
}

//Retorna se a lista esta vazia
int TLista_EhVazia(TLista *pLista) {
    return (pLista -> pUltimo == pLista->pPrimeiro);
}

// Insere um item no final da lista
int TLista_InsereFinal(TLista *pLista, TItem x) {
    pLista->pUltimo->pProx = (TCelula*)malloc(sizeof(TCelula));
    pLista->pUltimo = pLista->pUltimo->pProx;
    pLista->pUltimo->item = x;
    pLista->pUltimo->pProx = NULL;
return 1;
}

// Retira o primeiro item da lista
int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX) {
    if(TLista_EhVazia(pLista))
        return 0;
    TCelula *aX;
    aX = pLista->pPrimeiro->pProx;
    *pX= aX-> item;
    pLista->pPrimeiro->pProx = aX->pProx;
    free(aX);
    return 1;
}

// Imprime os elementos da lista
void TLista_Imprime(TLista *pLista) {
    if(TLista_EhVazia(pLista))
        return ;

    TCelula *aux;

    aux = pLista->pPrimeiro->pProx;

    while(aux!=NULL){
        printf("%s ", aux->item.nome);
        aux = aux->pProx;
    }
    printf("\n");

}

//Remove cada elemento de uma lista e libera a memória
void TLista_Esvazia(TLista *pLista) {
    TCelula *aux1, *aux2;

    aux1 = pLista->pPrimeiro;
    free(pLista->pPrimeiro);

    while(aux1!=NULL){
        aux2 = aux1;
        aux1 = aux1->pProx;
        free(aux2);
    }
}

// Acrescenta o conteudo de uma lista ao final de outra, apenas manipulando ponteiros
void TLista_append(TLista *pLista1, TLista *pLista2){
    pLista1->pUltimo->pProx = pLista2->pPrimeiro->pProx;
    free(pLista2->pPrimeiro);
}

// Inclui o conteudo de uma lista em outra, na posicao anterior a str, apenas manipulando ponteiros
void TLista_include(TLista *pLista1, TLista *pLista2, char *str){
//preencher
    TCelula *aux1;
    aux1 = pLista1->pPrimeiro;

    while(aux1 != NULL){
        TCelula *aux2; 
        aux2 = aux1;
        aux1= aux1->pProx;

        if(strcmp(aux1->item.nome, str) == 0){
            aux2->pProx = pLista2->pPrimeiro->pProx;
            pLista2->pUltimo->pProx = aux1;
            free(pLista2->pPrimeiro);
            return;
        }
    }


}
