#include "recursividade.h"

void TLista_FazVazia ( TLista * pLista ) {
    pLista->ultimo = -1;
}

int TLista_Insere ( TLista * pLista , TItem x) {
    if ( pLista -> ultimo == MAXTAM )
        return 0;
    pLista->item[++pLista->ultimo] = x;
    return 1;
}

int recursividade(TLista* pLista, int posicao){
    if (posicao == 0){
        return pLista->item[0].numero;
    }
    return pLista->item[posicao].numero + recursividade(pLista, posicao - 1);
    // return pLista->item[posicao].numero + (posicao == 0 ? 0 : recursividade(pLista, posicao - 1));
    // usando operador ternário

}