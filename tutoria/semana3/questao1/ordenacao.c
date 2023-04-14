#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_TAM 10

struct upa{
    char nome[MAX_TAM];
    int emergencia;
    int urgencia;
    int sem_urgencia;
    int medicos;
};

Upa *alocaUpas(int n) {
    Upa *upas=(Upa*) malloc(n * sizeof(Upa));
    return upas;
}

void lerUpas(Upa **upas, int n){
    for (int i = 0; i < n; i++){
        scanf("%s %d %d %d %d", (*upas)[i].nome, &(*upas)[i].emergencia, &(*upas)[i].urgencia, &(*upas)[i].sem_urgencia, &(*upas)[i].medicos);
    }
}

void imprime(Upa *upas, int n){
    for (int i = 0; i < n; i++){
        printf("%s %d %d %d %d\n", upas[i].nome, upas[i].emergencia, upas[i].urgencia, upas[i].sem_urgencia, upas[i].medicos);
    }
}

void mergeSort(Upa *upas, int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(upas, l, m);
        mergeSort(upas, m+1, r);
        merge(upas, l, r, m);
    }
}

void merge(Upa *upas, int l, int r, int m){
    int tam_l= m - l + 1;
    int tam_r = r - m;
    Upa *vL = copy(upas, tam_l, l);
    Upa *vR = copy(upas, tam_r, m+1);
    int i = 0, j = 0, k;
    for(k=l; k<=r; k++){
        if(i==tam_l){
            upas[k].emergencia = vR[j].emergencia; 
            upas[k].urgencia = vR[j].urgencia; 
            upas[k].sem_urgencia = vR[j].sem_urgencia; 
            upas[k].medicos = vR[j].medicos; 
            strcpy(upas[k].nome, vR[j++].nome); 
        }else if(j==tam_r){
            upas[k].emergencia = vL[i].emergencia; 
            upas[k].urgencia = vL[i].urgencia; 
            upas[k].sem_urgencia = vL[i].sem_urgencia; 
            upas[k].medicos = vL[i].medicos; 
            strcpy(upas[k].nome, vL[i++].nome); 
        }else if(vL[i].emergencia > vR[j].emergencia){
            upas[k].emergencia = vL[i].emergencia; 
            upas[k].urgencia = vL[i].urgencia; 
            upas[k].sem_urgencia = vL[i].sem_urgencia; 
            upas[k].medicos = vL[i].medicos; 
            strcpy(upas[k].nome, vL[i++].nome); 
        }else if(vL[i].emergencia == vR[j].emergencia){
            if(vL[i].urgencia > vR[j].urgencia){
                upas[k].emergencia = vL[i].emergencia; 
                upas[k].urgencia = vL[i].urgencia; 
                upas[k].sem_urgencia = vL[i].sem_urgencia; 
                upas[k].medicos = vL[i].medicos; 
                strcpy(upas[k].nome, vL[i++].nome); 
            }else if(vL[i].urgencia < vR[j].urgencia){
                upas[k].emergencia = vR[j].emergencia; 
                upas[k].urgencia = vR[j].urgencia; 
                upas[k].sem_urgencia = vR[j].sem_urgencia; 
                upas[k].medicos = vR[j].medicos; 
                strcpy(upas[k].nome, vR[j++].nome); 
            }else{
                if(vL[i].sem_urgencia > vR[j].sem_urgencia){
                    upas[k].emergencia = vL[i].emergencia; 
                    upas[k].urgencia = vL[i].urgencia; 
                    upas[k].sem_urgencia = vL[i].sem_urgencia; 
                    upas[k].medicos = vL[i].medicos; 
                    strcpy(upas[k].nome, vL[i++].nome); 
                }else if(vL[i].sem_urgencia < vR[j].sem_urgencia){
                    upas[k].emergencia = vR[j].emergencia; 
                    upas[k].urgencia = vR[j].urgencia; 
                    upas[k].sem_urgencia = vR[j].sem_urgencia; 
                    upas[k].medicos = vR[j].medicos; 
                    strcpy(upas[k].nome, vR[j++].nome); 
                }else{
                    if(vL[i].medicos < vR[j].medicos){
                        upas[k].emergencia = vL[i].emergencia; 
                        upas[k].urgencia = vL[i].urgencia; 
                        upas[k].sem_urgencia = vL[i].sem_urgencia; 
                        upas[k].medicos = vL[i].medicos; 
                        strcpy(upas[k].nome, vL[i++].nome); 
                    }else if(vL[i].medicos > vR[j].medicos){
                        upas[k].emergencia = vR[j].emergencia; 
                        upas[k].urgencia = vR[j].urgencia; 
                        upas[k].sem_urgencia = vR[j].sem_urgencia; 
                        upas[k].medicos = vR[j].medicos; 
                        strcpy(upas[k].nome, vR[j++].nome); 
                    }else{
                        if(strcmp(vL[i].nome, vR[j].nome) < 0){
                            upas[k].emergencia = vL[i].emergencia; 
                            upas[k].urgencia = vL[i].urgencia; 
                            upas[k].sem_urgencia = vL[i].sem_urgencia; 
                            upas[k].medicos = vL[i].medicos; 
                            strcpy(upas[k].nome, vL[i++].nome); 
                        }else{
                            upas[k].emergencia = vR[j].emergencia; 
                            upas[k].urgencia = vR[j].urgencia; 
                            upas[k].sem_urgencia = vR[j].sem_urgencia; 
                            upas[k].medicos = vR[j].medicos; 
                            strcpy(upas[k].nome, vR[j++].nome); 
                        }
                    }
                }
            }
        }else{
            upas[k].emergencia = vR[j].emergencia; 
            upas[k].urgencia = vR[j].urgencia; 
            upas[k].sem_urgencia = vR[j].sem_urgencia; 
            upas[k].medicos = vR[j].medicos; 
            strcpy(upas[k].nome, vR[j++].nome); 
        }
    }
    free(vR);
    free(vL);
}

void desalocaUpas(Upa** upas){
    free(*upas);
}

Upa *copy(Upa *upas, int tamanho, int n){
    Upa *aux = malloc(sizeof(Upa) * tamanho);
    for (int i = 0; i < tamanho; i++){ 
        aux[i].emergencia = upas[i+n].emergencia; 
        aux[i].urgencia = upas[i+n].urgencia; 
        aux[i].sem_urgencia = upas[i+n].sem_urgencia; 
        aux[i].medicos = upas[i+n].medicos; 
        strcpy(aux[i].nome, upas[i+n].nome); 
    }
    return aux;
}
