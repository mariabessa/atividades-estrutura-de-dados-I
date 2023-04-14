#include "ordenacao.h"

void converteMinuscula(char *palavra, int tamanho){
    for (int i = 0; palavra[i] != '\0'; i++){
        if (palavra[i] >= 65 && palavra[i] <= 90)
            palavra[i] = palavra[i] + 32;
    }
}

void ordenaPalavra(char *palavra, int inicio, int final){
    int pivo, l, r;
    char aux;
    pivo = inicio;
    l = inicio;
    r = final;

    while (l <= r){
        while ((l < final) && (palavra[l] < palavra[pivo])){
            l++;
        }
        while ((r > inicio) && (palavra[r] > palavra[pivo])){
            r--;
        }

        if (l <= r){
            aux = palavra[l];
            palavra[l] = palavra[r];
            palavra[r] = aux;
            l++;
            r--;
        }
    }

    if(r > inicio){
        ordenaPalavra(palavra, inicio, r);
    }

    if(l < final){
        ordenaPalavra(palavra, l, final);
    }
}

int verificaOrdenacao(char *palavra, int tamanho){
    for (int i = 0; i < tamanho; i++){
        if(palavra[i] >= palavra[i+1])
            return 0;
    }
    return 1;
}