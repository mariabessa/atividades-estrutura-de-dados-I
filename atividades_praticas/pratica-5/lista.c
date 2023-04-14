#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

bool ListaInicia(Lista* pLista) {
    pLista->cabeca = (Celula*) malloc(sizeof(Celula));
    if (pLista->cabeca == NULL)
        return false;
    pLista->ultimo = pLista->cabeca;
    pLista->cabeca->prox = NULL;
    return true;
}

bool ListaEhVazia(Lista* pLista) {
    if(pLista->cabeca == pLista->ultimo)
        return true;
    return false;
}

bool ListaInsereFinal(Lista* pLista, Item item) {
    Celula * novoitem = (Celula *) malloc(sizeof(Celula));
    if (novoitem == NULL)
        return false;
    novoitem->item = item;
    novoitem->prox = NULL;
    pLista->ultimo->prox = novoitem;
    pLista->ultimo = novoitem;
    return true;
}

bool ListaInsereInicio(Lista* pLista, Item item) {
    Celula * novoitem = (Celula *) malloc(sizeof(Celula));
     if (novoitem == NULL)
        return false;
    novoitem->item = item;
    novoitem->prox = pLista->cabeca->prox;
    pLista->cabeca->prox= novoitem;
    return true;
}

bool ListaRetiraPrimeiro(Lista* pLista, Item* pItem) {
    if(pLista->cabeca->prox == NULL){
        return false;
    }
    Celula * removido = pLista->cabeca->prox;
    *pItem = removido->item;
    pLista->cabeca->prox = removido->prox;
    free(removido);
    return true;
}

void ListaLibera(Lista* pLista) {
    Celula * aux1 = pLista->cabeca;
    Celula *aux2;
    while(aux1 != NULL){
        aux2 = aux1;
        aux1 = aux1->prox;
        free(aux2);
    }
}