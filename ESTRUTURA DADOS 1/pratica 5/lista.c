#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia as variaveis da lista
int TListaInicia(TLista *pLista) {
    // preencher semelhante ao visto em aula
    pLista->pPrimeiro = (TCelula*)malloc(sizeof(TCelula));
    if (pLista->pPrimeiro != NULL){
        pLista->pUltimo = pLista->pPrimeiro;
        pLista->pPrimeiro->pProx = NULL;
        return 1;
    }
    return 0;
}

//Retorna se a lista esta vazia
int TListaEhVazia(TLista *pLista) {
    // preencher semelhante ao visto em aula
    return (pLista->pPrimeiro->pProx == NULL);
}

// Insere um item no inicio da lista
int TListaInserePrimeiro(TLista *pLista, TItem item) {
    // preencher semelhante ao visto em aula
    TCelula *pAux;
    pAux = (TCelula*)malloc(sizeof(TCelula));
    pAux->iten = item;
    pAux->pProx = pLista->pPrimeiro->pProx;
    pLista->pPrimeiro->pProx = pAux;
    return 1;
}
// Retira o primeiro item da lista
int TListaRetiraPrimeiro(TLista *pLista, TItem *pItem) {
    // preencher semelhante ao visto em aula
    if (TListaEhVazia(pLista)){
        return 0;
    }
    TCelula *pAux;
    pAux = pLista->pPrimeiro->pProx;
    *pItem = pAux->iten;
    pLista->pPrimeiro->pProx = pAux->pProx;
    free(pAux);
    return 1;
}

// Imprime os elementos da lista
void TListaImprime(TLista *pLista) {
    // preencher semelhante ao visto em aula
    TCelula *pAux;
    pAux = pLista->pPrimeiro->pProx;
    while (pAux != NULL)
    {
        printf("%c ",pAux->iten);
        pAux = pAux->pProx;
    }
}

//Remove cada elemento de uma lista e libera a memória
void TListaEsvazia(TLista *pLista) {
    // preencher semelhante ao visto em aula
    TItem item;
    while(TListaRetiraPrimeiro(pLista,&item) == 1);
    free(pLista->pPrimeiro);
}

