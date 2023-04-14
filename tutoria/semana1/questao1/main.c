#include "recursividade.h"

int main(){
    TLista * lista = (TLista*) malloc(sizeof(TLista));
    TLista_FazVazia(lista);
    TItem x;
    while (scanf("%d", &x.numero) != EOF ) {
        TLista_Insere(lista, x);
    }
    int soma = recursividade(lista, lista->ultimo );
    printf("%d\n", soma);
    free(lista);
    return 0;

}