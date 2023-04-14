#include "ordenacao.h"

// Manter como especificado
Time *alocaVetor(int n) {
 Time * times = (Time*) malloc(n * sizeof(Time));

    for(int i = 0; i < n; i++){
        times[i].identificador = i+1;
        times[i].pontos = 0;
        times[i].cestasFeitas = 0;
        times[i].cestasLevadas = 0;
        times[i].saldo = 0;
        times[i].vitorias = 0;
        times[i].derrotas = 0;
    }
    
    return times;
}

// Manter como especificado
void desalocaVetor(Time **vetor) {
    free(*vetor);
}

// implemente sua funcao de ordenacao aqui, que deve invocar a funcao compare
void ordenacao(Time *v, int n) {
   heap_constroi(v, n);
    while(n>1){
        Time aux = v[n-1];
        v[n-1] = v[0];
        v[0] = aux;
        n--;
        
        heap_refaz(v, 0, n-1);
    } 
}

// compara dois elementos do vetor de times, indicado se o metodo de ordenacao deve troca-los de lugar ou nao
int compare(const Time t1, const Time t2) {
    //pontos
    if(t1.pontos < t2.pontos)
        return 1;
    else if(t1.pontos > t2.pontos)
        return 0;
    
    //cestas
    else if(t1.saldo < t2.saldo)
        return 1;
    else if(t1.saldo > t2.saldo)
        return 0;

    //cesta
    else if(t1.cestasFeitas < t2.cestasFeitas)
        return 1;
    else if(t1.cestasFeitas > t2.cestasFeitas)
        return 0;

    //inscricao
    else if(t1.identificador > t2.identificador)
        return 1;
    else 
        return 0;
}

void heap_refaz(Time * times, int esquerda, int direita){
    int i = esquerda;
    int j = i*2 + 1;
    Time aux = times[i];
    
    while(j <= direita){
        
        if(j < direita && !compare(times[j], times[j+1]))
            j++;
        
        
        if(compare(aux, times[j]))
            break;
        
        times[i] = times[j];
        i = j;
        j = i*2 +1;
    }
    times[i] = aux;
}

void heap_constroi(Time * v, int n){
    int esquerda = (n/2)-1;
    while(esquerda >= 0 ){
        heap_refaz(v, esquerda, n-1);
        esquerda--;
    }
}

void preencherDados(int time1, int pontos1, int time2, int pontos2, Time * times){
    
    int posTime1 = time1-1;
    int posTime2 = time2-1;
    
    if(pontos1 > pontos2){
        times[posTime1].pontos+=2;
        times[posTime1].vitorias++;
        times[posTime2].pontos+=1;
        times[posTime2].derrotas++;
    }
    else{
        times[posTime2].pontos+=2;
        times[posTime2].vitorias++;
        times[posTime1].pontos+=1;
        times[posTime1].derrotas++;
    }



    times[posTime1].cestasFeitas += pontos1;
    times[posTime1].cestasLevadas += pontos2;

    times[posTime2].cestasFeitas += pontos2;
    times[posTime2].cestasLevadas += pontos1;

}

void calculaSaldo(Time * vetor, int n){
    int cestasFeitas;
    int cestasLevadas;
    float saldo; 

    for(int i = 0; i< n; i++){
        cestasFeitas = vetor[i].cestasFeitas;
        cestasLevadas = vetor[i].cestasLevadas;

        if(cestasLevadas == 0)
            saldo = vetor[i].cestasFeitas;
        
        else
            saldo = ((float)cestasFeitas)/cestasLevadas;
        
        vetor[i].saldo = saldo;
    }
}