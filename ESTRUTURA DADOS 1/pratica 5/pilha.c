#include "pilha.h"

// Inicia as variaveis da lista
int TPilhaInicia(TPilha *pPilha) {
    // preencher usando as funcoes de TLista - 1 linha de codigo
    return TListaInicia(pPilha);
}

//Retorna se a lista esta vazia
int TPilhaEhVazia(TPilha *pPilha) {
    // preencher usando as funcoes de TLista - 1 linha de codigo
    return TListaEhVazia(pPilha);
}

// Insere um item no final da lista
int TPilhaPush(TPilha *pPilha, TItem item) {
    // preencher usando as funcoes de TLista - 1 linha de codigo
    return TListaInserePrimeiro(pPilha,item);
}

// Retira o primeiro item da lista
int TPilhaPop(TPilha *pPilha, TItem *pItem) {
    // preencher usando as funcoes de TLista - 1 linha de codigo
    return TListaRetiraPrimeiro(pPilha,pItem);
}

//Remove cada elemento de uma lista e libera a memória
void TPilhaEsvazia(TPilha *pPilha) {
    // preencher usando as funcoes de TLista - 1 linha de codigo
    TListaEsvazia(pPilha);
}