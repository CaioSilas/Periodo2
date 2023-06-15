#ifndef LISTA_H
#define	LISTA_H

typedef struct{
	char nome[20];
} TAluno;

typedef struct celula {
    TAluno item;
    struct celula*  pProx;    
    struct celula*  pPrev;
} TCelula;

/* Lista encadeada com cabeca e calda */
typedef struct {
    TCelula* pPrimeiro;
    TCelula* pUltimo;
    int tamanho;
} TLista;

/** 
 Operações básicas 
 **/
TCelula* apontadorPosicao(const TLista* pL, int pos);
int TListaCria(TLista*);
void TListaDestroi(TLista*);
int TListaTamanho(const TLista*);
int TListaAcessa(const TLista*, int, TAluno*);
int TListaInsereInicio(TLista*, const TAluno);
int TListaRetira(TLista*, int, TAluno*);
void TListaImprime(const TLista* pL);
void TListaImprimeInv(const TLista* pL);

#endif	/* LISTA_H */
