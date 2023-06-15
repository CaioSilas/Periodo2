#include "ordenacao.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void ordena(TLista *l, int n) {
	int flag = 0;
    int ind;
    TAluno nome;
    TCelula *aux1;
    TCelula *aux2;


    for (int i = 0; i < n - 1;i++){
        ind = i;
        for (int j = i + 1;j < n;j++)
        {
            aux1 = apontadorPosicao(l,ind);
            aux2 = apontadorPosicao(l,j);
            flag = compare(aux1->item,aux2->item);
            
            if (flag > 0){
                ind = j;
            }
        }
        
        // strcpy(aux.nome,l[ind].pPrimeiro->item.nome);
        // strcpy(l[ind].pPrimeiro->item.nome,l[i].pPrimeiro->item.nome);
        // strcpy(l[i].pPrimeiro->item.nome,aux.nome);

        if(ind != i){
            aux1 = apontadorPosicao(l,i);
            aux2 = apontadorPosicao(l,ind);

            nome = aux1->item;
            aux1->item = aux2->item;
            aux2->item = nome; 
        }

    }

}

int compare(const TAluno t1, const TAluno t2) {
    return strcmp(t1.nome,t2.nome);
}
