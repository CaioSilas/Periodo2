#include "ordenacao.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



/*
    ordem direta < [Lis] [Isadora] [Jasmine] [Verena] [Janine] [Yan] [Nathan] [Nala] [Ryan] [Thiago] >
    ordem direta < [Isadora] [Janine] [Jasmine] [Lis] [Nala] [Nathan] [Ryan] [Thiago] [Verena] [Yan] >
*/
void ordena(TLista *l, int n) {
	int flag = 0;
    int ind;
    TAluno nome;
    TCelula *aux1;
    TCelula *aux2;
    TCelula *troca;

    for (aux1 = l->pPrimeiro->pProx; aux1 != l->pUltimo->pPrev;aux1 = aux1->pProx){
        troca = aux1;
        for (aux2 = aux1->pProx; aux2 != l->pUltimo; aux2 = aux2->pProx){
            if (compare(troca->item,aux2->item) > 0){
                troca = aux2;
            }
        }
        if (troca != aux1){
            nome = aux1->item;
            aux1->item = troca->item;
            troca->item = nome;
        }
    }
}

int compare(const TAluno t1, const TAluno t2) {
    return strcmp(t1.nome,t2.nome);
}
