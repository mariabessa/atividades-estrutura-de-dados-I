#include "ordenacao.h"

void leDados(Pedidos *pedidos, int n){
    for(int i = 0; i < n; i++){
        fgets(pedidos[i].nome, MAX_TAM, stdin);
        pedidos[i].nome[strlen(pedidos[i].nome) - 1] = '\0';
        char temp[100];
        fgets(temp, 100, stdin);
        char * token = strtok(temp, " ");
        strcpy(pedidos[i].cor, token);
        token = strtok(NULL, " ");
        pedidos[i].tamanho = token[0];
    }
}

int compare(Pedidos p1, Pedidos p2){
    if(strcmp(p1.cor, p2.cor) > 0)
        return 1;
    else if(strcmp(p1.cor, p2.cor) < 0)
        return 0;
    else if(p1.tamanho < p2.tamanho)
        return 1;
    else if(p1.tamanho > p2.tamanho)
        return 0;
    else if(strcmp(p1.nome, p2.nome) > 0)
        return 1;
    else
        return 0;
}

void heapRefaz(Pedidos *v, int l, int r){
    int i = l;
    int j = i*2 + 1; // j = prim eiro filho de i

    Pedidos aux = v[i]; // aux = no i (pai de j)

    while (j <= r){
        if (j < r && !compare(v[j], v[j+1]))
            j++ ; // j recebe o outro filho de i
        if (compare(aux, v[j]))
            break; // heap foi refeito corretam ente
        v[i] = v[j];
        i = j;
        j = i*2 + 1; // j = primeiro filho de i
    }
    v[i] = aux;
}

void heapConstroi(Pedidos *v, int n){
    int l = (n/2) - 1; 
    while (l >= 0){
        heapRefaz(v, l, n-1);
        l--;
    }
}

void heapSort(Pedidos *v, int n){
    heapConstroi(v,n);
    while(n>1){
        Pedidos aux = v[n-1];
        v[n-1]=v[0];
        v[0]=aux;
        n--;
        heapRefaz(v,0, n-1);
    }
}


void imprimir(Pedidos *pedidos, int n){
    for(int i = 0; i < n; i++){
            printf("%s %c %s\n", pedidos[i].cor, pedidos[i].tamanho, pedidos[i].nome);
        }
}