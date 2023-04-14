#include "ordenacao_linear.h"

#include <stdio.h>

// Manter como especificado
int char2int(char c) {
    /* Funcao auxiliar para converter um char em um inteiro */
    return (int) (c - '0');
}

// Manter como especificado
void le(Paciente* pacientes, int n) {
    for (int i = 0; i < n; i++){
        scanf("%s %s", pacientes[i].senha, pacientes[i].nome);
    }
}

// Manter como especificado
void imprime(Paciente* pacientes, int n){
    for (int i = 0; i < n; i++){
        printf("%s %s\n", pacientes[i].senha, pacientes[i].nome);
    }
    // PREENCHER AQUI
    /*
     * pacientes = vetor onde devem ser salvos os valores lidos
     * n = tamanho do vetor A
     */
}

// Manter como especificado
void coutingSort(Paciente* A, Paciente* B, int n, int i) {
    int C[10];
    int x[n];
    for(int k = 0; k < n; k++){
        x[k] = char2int(A[k].senha[i]);
    }
    for (int i = 0; i < 10; i++){
        C[i] = 0;
    }
    for (int j = 0; j < n; j++){
        C[x[j]] = C[x[j]] + 1;
    }
    for(int i = 1; i <  10; i++){
        C[i] = C[i] + C[i-1];
    }
    for(int j = n-1; j >= 0; j--){
        B[C[x[j]]-1] = A[j];
        C[x[j]] = C[x[j]] - 1;
    }
    for(int i = 0; i < n; i++){
        A[i] = B[i];
    }
    // PREENCHER AQUI
    /*
     * A = vetor a ser ordenado
     * B = vetor auxiliar para armazenar o vetor A ordenado
     * n = tamanho do vetor A
     * i = digito a ser usado na ordenacao
     */
}

// Manter como especificado
void radixSort(Paciente* pacientes, int n, int m) {
    Paciente B[MAX_N];
    for(int i = m-1; i >= 0; i--){
        coutingSort(pacientes, B, n, i);
        
    }
    /*
     * pacientes = vetor a ser ordenado
     * n = tamanho do vetor A
     * m = quantidade de digitos
     */
}
