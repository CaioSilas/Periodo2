#include "lista.h"
#include <stdio.h>
#include <stdlib.h>


int TListaCria(TLista* pL) {
    TCelula* pCabeca = (TCelula*)calloc(1,sizeof(TCelula));
    if (pCabeca == NULL)
        return 0;
    TCelula* pCalda = (TCelula*)calloc(1,sizeof(TCelula));
    if (pCalda == NULL) {
        free(pCabeca);
        return 0;
    }
    pCabeca->pProx = pCalda;
    pCalda->pPrev = pCabeca;
    pL->tamanho = 0;
    pL->pPrimeiro = pCabeca;
    pL->pUltimo = pCalda;
    return 1;
}

void TListaDestroi(TLista* pL) {
    TCelula* pCorrente = pL->pPrimeiro;
    while (pCorrente != NULL) {
        TCelula* pDestroi = pCorrente;
        pCorrente = pCorrente->pProx;
        free(pDestroi); pDestroi = NULL;
    }
    pL->tamanho = 0;
}

int TListaTamanho(const TLista* pL) {
    return pL->tamanho;
}

// Encontrando posição -- começa sempre da cabeca então até posicao
TCelula* apontadorPosicao(const TLista* pL, int pos) {
    int cont = 0;
    TCelula* pCorrente = pL->pPrimeiro;
    while ((cont <= pos) && (pCorrente != NULL)) {
        pCorrente = pCorrente->pProx;
        cont++;
    }
    return pCorrente;
}

int TListaAcessa(const TLista* pL, int pos, TAluno* pIt) {
    if ((pos < 0) || ( pos > TListaTamanho(pL)))
        return 0;
    TCelula* pCorrente = apontadorPosicao(pL, pos);
    *pIt = pCorrente->item;
    return 1;

}

int TListaInsereInicio(TLista* pL, const TAluno pIt) {
    // Criando novo elemento
    TCelula* pNovoTCelula = (TCelula* )calloc(1,sizeof(TCelula));
    if (pNovoTCelula == NULL) {
        return 0;
    }
    pNovoTCelula->item = pIt;

    TCelula *pPost = pL->pPrimeiro->pProx;
    TCelula *pAnt = pPost->pPrev;

    pNovoTCelula->pProx = pPost;
    pNovoTCelula->pPrev = pAnt;
    pAnt->pProx = pNovoTCelula;
    pPost->pPrev = pNovoTCelula;
    pL->tamanho++;
    return 1;
}

int TListaRetira(TLista* pL, int pos, TAluno* pIt) { 
    if ((pos < 0) || ( pos >= TListaTamanho(pL)))
        return 0;
    TCelula* pSai = apontadorPosicao(pL, pos);
    TCelula* pPost = pSai->pProx;
    TCelula* pAnt = pSai->pPrev;
    pPost->pPrev = pAnt;
    pAnt->pProx = pPost;
    *pIt = pSai->item;
    free(pSai);
    pSai = NULL;
    pL->tamanho--;
    return 1;
}

void TListaImprime(const TLista* pL) {
    TCelula* pCorrente = pL->pPrimeiro->pProx;
    printf("ordem direta < ");
    while(pCorrente != pL->pUltimo) {
        printf("[%s] ", pCorrente->item.nome);
        pCorrente = pCorrente->pProx;
    }
    printf(">\n");
}

void TListaImprimeInv(const TLista* pL) {
    TCelula* pCorrente = pL->pUltimo->pPrev;
    printf("ordem indireta < ");
    while (pCorrente != pL->pPrimeiro) {
        printf("[%s] ", pCorrente->item.nome);
        pCorrente = pCorrente->pPrev;
    }
    printf(">\n");
}
