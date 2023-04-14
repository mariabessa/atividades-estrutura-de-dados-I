#include "ordenacao.h"
#include <string.h>
#include <stdio.h>
#define MAX 43
int main(){
    int p;
    scanf("%d", &p);
    for (int i = 0; i < p; i++){
        char palavra[MAX], palavraMinuscula[MAX], palavraCopia[MAX];
        scanf("%s", palavra);
        int tamanho = strlen(palavra) - 1;
        strcpy(palavraMinuscula, palavra);
        converteMinuscula(palavraMinuscula, tamanho);
        strcpy(palavraCopia, palavraMinuscula);
        ordenaPalavra(palavraMinuscula, 0, tamanho);
        if(strcmp(palavraCopia, palavraMinuscula) == 0 && (verificaOrdenacao(palavraMinuscula, tamanho))){
            printf("%s: O\n", palavra);
        }
        else{
            printf("%s: N\n", palavra);
        }
    }
    return 0;
}