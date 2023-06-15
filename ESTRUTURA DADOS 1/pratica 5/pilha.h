# ifndef pilha_h
# define pilha_h

#include "lista.h"

typedef TLista TPilha; // TPilha eh uma TLista

// Inicializa a pilha e retorna se foi possivel ou nao
int TPilhaInicia(TPilha *pPilha);

// Retorna se a pilha esta vazia
int TPilhaEhVazia(TPilha *pPilha);

// Insere um item na pilha
int TPilhaPush(TPilha *pPilha, TItem item);

// Retira um item da pilha
int TPilhaPop(TPilha *pPilha, TItem *item);

// Remove e libera memoria de cada elemento de uma pilha
void TPilhaEsvazia(TPilha *pPilha);
# endif