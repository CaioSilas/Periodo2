#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

//Manter como especificado
struct time *alocaVetor(int n){
    return calloc(n , sizeof(struct time));
}

//Manter como especificado
void desalocaVetor(struct time **vetor){
    free(*vetor);
}

void merge(struct time *v,int l,int m, int r){
    int tamE = m - l + 1;
    int i,j;
    int tamD = r - m;
    struct time *vetorE = malloc((tamE)*sizeof(struct time));
    struct time *vetorD= malloc((tamD)*sizeof(struct time));
    for (i = 0; i < tamE; i++){
        vetorE[i] = v[i + l]; 
    }
    for (j = 0; j < tamD; j++)
    {
        vetorD[j] = v[m + j + 1];
    }
    i = 0;
    j = 0;
    int k;
    for (k = l; k <= r; k++)
    {
        if (i == tamE){
            v[k] = vetorD[j++];
        }
        else if (j == tamD){
            v[k] = vetorE[i++];
        }
        else if (compare(vetorE[i],vetorD[j]) == 1){
            v[k] = vetorE[i++];
        }
        else {
            v[k] = vetorD[j++];
        }
        
    }
    free(vetorE);
    free(vetorD);
}

int mergeint(struct time *v, int l, int r,int n){
    int b;
    int esq,dir;
    b = 1;
    while (b < n){
        esq = 0;
        while ((esq + b) < n)
        {
            dir = esq + (2 * b);
            if (dir > n){
                dir = n;
            }
            merge(v,esq,(esq + b) - 1,dir - 1);
            esq = esq + (2 * b);
        }
        b = b * 2;
    }
    return 0;
}

//implemente sua funcao de ordenacao aqui, que deve invocar a funcao compare
void ordenacao(struct time *vetor, int n){
    mergeint(vetor,0,n,n);
}

//compara dois elementos do vetor de times, indicado se o metodo de ordenacao deve troca-los de lugar ou nao
int compare(const struct time t1, const struct time t2){
    double saldo1 = 0;
    double saldo2 = 0;

    if(t1.CestasRecebidos == 0){
        saldo1 = t1.CestasFeitos;
    }
    else{
        saldo1 = t1.CestasFeitos *1.0/t1.CestasRecebidos;
    }


    if(t2.CestasRecebidos == 0){
        saldo2 = t2.CestasFeitos;
    }
    else{
        saldo2 = (t2.CestasFeitos *1.0)/t2.CestasRecebidos;
    }


    if(t1.ponto < t2.ponto){
        return 0;
    }
    else if(t1.ponto > t2.ponto){
        return 1;
    }


    else if(saldo1 < saldo2){        
        return 0;
    }
    else if(saldo1 > saldo2){        
        return 1;
    }


    else if(t1.CestasFeitos < t2.CestasFeitos){        
        return 0;
    }
    else if(t1.CestasFeitos > t2.CestasFeitos){
        return 1;
    }


    else if(t1.time > t2.time){
        return 0;
    }
    else{
        return 1;
    }
}
